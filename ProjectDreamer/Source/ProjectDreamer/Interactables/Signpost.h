// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PDInteractable.h"

#include "Signpost.generated.h"

/***************************************************************************************
Title:       Signpost
Author:      Joshua Griffis
Date:        2022/03/18
Description: an object the player can interact with for dialogue
*****************************************************************************************/

UCLASS()
class PROJECTDREAMER_API ASignpost : public AActor, public IPDInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASignpost();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* BoxComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		FString SignText;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
};
