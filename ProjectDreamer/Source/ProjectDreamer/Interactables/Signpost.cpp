// Fill out your copyright notice in the Description page of Project Settings.


#include "Signpost.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../PDPlayerController.h"


// Sets default values
ASignpost::ASignpost()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	BoxComponent->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = BoxComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASignpost::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASignpost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASignpost::Interact_Implementation()
{
	//TODO: GetPlayerController->DialogueWidget->SetDialogueText("")
	APDPlayerController* PlayerController = Cast<APDPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	PlayerController->SetDialogueText(SignText);
	PlayerController->SetDialogueName();

	PlayerController->ShowDialogue();
}

