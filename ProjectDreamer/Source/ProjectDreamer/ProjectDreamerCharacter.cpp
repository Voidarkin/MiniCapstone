// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectDreamerCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "NavigationSystem.h"
#include "Interactables/PDInteractable.h"
#include "PDPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


//////////////////////////////////////////////////////////////////////////
// AProjectDreamerCharacter

AProjectDreamerCharacter::AProjectDreamerCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

}

//////////////////////////////////////////////////////////////////////////
// Input
/*
void AProjectDreamerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{	
	//PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);	
}
*/

void AProjectDreamerCharacter::Interact()
{

	bool bInDialogue = IsPlayerInDialogue();
	bool bCanMove = IsPlayerAbleToMove();
	//player is in dialogue or not
	if (bInDialogue)
	{
		APDPlayerController* controller = Cast<APDPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		controller->ContinueText();
	}
	else if (!bInDialogue)
	{
		//TODO: possibly switch from raycast to checking within sphere around player and checking first one in front.

		FVector Start = GetActorLocation();
		//FVector End = Start + (FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X) * 200.0f);
		FVector End = Start + (FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::X) * 200.0f);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		FHitResult HitResult;
		if (GetWorld()->LineTraceSingleByObjectType(HitResult, Start, End, FCollisionObjectQueryParams(), QueryParams))
		{
			DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 3.f);
			if (AActor* Actor = HitResult.GetActor())
			{
				GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Hit - Something");
				if (Actor->Implements<UPDInteractable>())
				{
					GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Hit Object Has Interactable");
					IPDInteractable::Execute_Interact(Actor);
				}


			}
		}
	}
	
}

void AProjectDreamerCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AProjectDreamerCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AProjectDreamerCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AProjectDreamerCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AProjectDreamerCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AProjectDreamerCharacter::MoveForward(float Value)
{
	bool bCanMove = IsPlayerAbleToMove();
	if ((Controller != nullptr) && (Value != 0.0f) && bCanMove)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		CheckNavigation(Direction, Value);

	}
}

void AProjectDreamerCharacter::MoveRight(float Value)
{
	bool bCanMove = IsPlayerAbleToMove();
	if ( (Controller != nullptr) && (Value != 0.0f) && bCanMove)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction

		CheckNavigation(Direction, Value);
		
	}
}

void AProjectDreamerCharacter::CheckNavigation(const FVector& Direction, float Value)
{
	//NavSystem
	FNavLocation navLocation;
	FVector projectionExtent = FVector(15, 15, 130);
	FVector location = GetCharacterMovement()->GetActorLocation() + (Direction * Value * 17);
	bool bOnNavMesh = UNavigationSystemV1::GetCurrent(GetWorld())->ProjectPointToNavigation(GetCharacterMovement()->GetActorLocation() + (Direction * Value * 17), navLocation, projectionExtent);

	//DrawDebugSphere(GetWorld(), navLocation, 50, 32, FColor::Red, false, 3.0f);
	DrawDebugBox(GetWorld(), location, projectionExtent, FColor::Red, false, 1.0f);

	if (bOnNavMesh)
	{
		AddMovementInput(Direction, Value);
	}
}

bool AProjectDreamerCharacter::IsPlayerAbleToMove()
{
	APDPlayerController* controller = Cast<APDPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	return controller->IsPlayerAbleToMove();
}

bool AProjectDreamerCharacter::IsPlayerInDialogue()
{
	APDPlayerController* controller = Cast<APDPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	return controller->IsPlayerInDialogue();
}