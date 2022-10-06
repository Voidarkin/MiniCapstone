// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialPickup.h"
#include "../Inventory.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../PDPlayerController.h"
#include "../PartyManager.h"

// Sets default values
AMaterialPickup::AMaterialPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	BoxComponent->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = BoxComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	if (UnpickedMesh)
	{
		MeshComponent->SetStaticMesh(UnpickedMesh);
	}
	MeshComponent->SetupAttachment(RootComponent);

	bObtained = false;
}

// Called when the game starts or when spawned
void AMaterialPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaterialPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMaterialPickup::Interact_Implementation()
{
	
	if (!bObtained)
	{
		//TODO: switch mesh to an obtained one or make disappear.
		UGameInstance* GameInstance = GetGameInstance();
		UPartyManager* PartyManager = GameInstance->GetSubsystem<UPartyManager>();
		PartyManager->AddInventoryItem(ItemName, ItemAmount);
		bObtained = !bObtained;

		if (PickedMesh)
		{
			MeshComponent->SetStaticMesh(PickedMesh);
		}
		else
		{
			MeshComponent->SetVisibility(false);
		}
		
	}
	
}