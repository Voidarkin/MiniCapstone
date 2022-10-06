// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"


#include "PartyManager.generated.h"

/***************************************************************************************
Title:       PartyManager
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to store current characters, inventory, and other information that 
is constantly monitored.
*****************************************************************************************/

class UInventory;
class AChest;
class UCharacterData;

UCLASS()
class PROJECTDREAMER_API UPartyManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UPartyManager();

protected:

	void OnRegistryLoaded();

protected:

	UPROPERTY()
		UInventory* inventory;
	
	UPROPERTY()
		TArray<FString> KnownRecipes;

	UPROPERTY()
		TArray<UCharacterData*> CurrentPartyMembers;

	UPROPERTY()
		TArray<UCharacterData*> PartyMembers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "4"))
		int CurrentPartySize;

	//List to store all opened chests to prevent chests being able to be reopened.
	UPROPERTY()
		TArray<int> OpenedChestList;

public:
	
	void AddInventoryItem(FString name, int amount);
	void RemoveInventoryItem(FString name, int amount);
	UInventory* GetInventory() { return inventory; }

	void AddChestToList(int chestNum);
	bool IsChestInList(int chestNum);

	TArray<UCharacterData*> GetCurrentPartyMembers() { return CurrentPartyMembers; }
	TArray<UCharacterData*> GetPartyMembers() { return PartyMembers; }
	UCharacterData* GetPartyMember(FString name);
	void AddPartyMember(UCharacterData* character);
	void RemovePartyMember(UCharacterData* character);

	int GetCurrentPartyNum() { return CurrentPartySize; }

	TArray<FString> GetKnownRecipes() { return KnownRecipes; }

};
