// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "../Inventory.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../PDPlayerController.h"
#include "../PartyManager.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	BoxComponent->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = BoxComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	if (ClosedMesh)
	{
		MeshComponent->SetStaticMesh(ClosedMesh);
	}
	MeshComponent->SetupAttachment(RootComponent);

	bOpened = false;
}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	
	CheckIfOpened();

	if (!bOpened)
	{
		if (ClosedMesh)
		{
			MeshComponent->SetStaticMesh(ClosedMesh);
		}
	}
	else
	{
		if (OpenedMesh)
		{
			MeshComponent->SetStaticMesh(OpenedMesh);
		}
	}

}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChest::CheckIfOpened()
{
	//Check the opened chest list if this chest is in it, if it is, set it to value of true
	UGameInstance* GameInstance = GetGameInstance();
	UPartyManager* PartyManager = GameInstance->GetSubsystem<UPartyManager>();
	
	bOpened = PartyManager->IsChestInList(ChestID);
}


void AChest::Interact_Implementation()
{
	if (!bOpened)
	{
		APDPlayerController* PlayerController = Cast<APDPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

		if (ItemAmount > 1)
		{
			ChestText = FString::Printf(TEXT("You found %d %ss"), ItemAmount, *ItemName);
		}
		else
		{
			ChestText = FString::Printf(TEXT("You found %d %s"), ItemAmount, *ItemName);
		}

		PlayerController->SetDialogueText(ChestText);
		PlayerController->SetDialogueName();

		PlayerController->ShowDialogue();

		// Add item to inventory below
		UGameInstance* GameInstance = GetGameInstance();
		UPartyManager* PartyManager = GameInstance->GetSubsystem<UPartyManager>();
		PartyManager->AddInventoryItem(ItemName, ItemAmount);
		bOpened = !bOpened;

		if (OpenedMesh)
		{
			MeshComponent->SetStaticMesh(OpenedMesh);
		}

		// Add chest to opened chest list
		PartyManager->AddChestToList(ChestID);

	}
	
}