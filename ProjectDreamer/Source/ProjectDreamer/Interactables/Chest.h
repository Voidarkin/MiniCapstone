// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PDInteractable.h"

#include "Chest.generated.h"

/***************************************************************************************
Title:       Chest
Author:      Joshua Griffis
Date:        2022/03/18
Description: An interactable to store an item into the inventory
*****************************************************************************************/

class UInventory;

UCLASS()
class PROJECTDREAMER_API AChest : public AActor, public IPDInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChest();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "ID")
		int ChestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMesh* ClosedMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMesh* OpenedMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* BoxComponent;

	UPROPERTY(BlueprintReadWrite)
		FString ChestText;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		FString ItemName;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		int ItemAmount;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		int bOpened;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CheckIfOpened();

	virtual void Interact_Implementation() override;

};
