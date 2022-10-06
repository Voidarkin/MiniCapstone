// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PDInteractable.h"

#include "NPC.generated.h"

/***************************************************************************************
Title:       NPC
Author:      Joshua Griffis
Date:        2022/03/18
Description: Person for player to talk to using dialogue
*****************************************************************************************/

UCLASS()
class PROJECTDREAMER_API ANPC : public AActor, public IPDInteractable
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ANPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		TArray<FString> DialogueText;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
		TArray<FString> DialogueName;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
};
