// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../PDPlayerController.h"


// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("OverlapComp"));
	//CapsuleComponent->Radius
	RootComponent = CapsuleComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANPC::Interact_Implementation()
{
	//TODO: GetPlayerController->DialogueWidget->SetDialogueText("")
	APDPlayerController* PlayerController = Cast<APDPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	PlayerController->SetDialogueText(DialogueText);
	if (DialogueName.Num() != 0)
	{
		if (DialogueName[0] != "")
		{
			PlayerController->SetDialogueName(DialogueName);
		}
	}
	PlayerController->ShowDialogue();
}

