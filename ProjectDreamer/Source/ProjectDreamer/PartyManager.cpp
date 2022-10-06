// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyManager.h"
#include "Inventory.h"
#include "Interactables/Chest.h"
#include "CharacterData.h"
//#include "Data/PDAssetManager.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "DatabaseManager.h"
#include "ItemDatabase.h"
#include "Engine/DataAsset.h"
#include <string>
#include "UObject/UObjectGlobals.h"

UPartyManager::UPartyManager()
{
	inventory = Cast<UInventory>(UInventory::StaticClass()->GetDefaultObject());
	
	UAssetManager* AssetManager = UAssetManager::GetIfValid();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	// Must wait until all assets are discovered before populating list of other GameInfoBase assets.
	if (AssetRegistry.IsLoadingAssets()) {
		AssetRegistry.OnFilesLoaded().AddUObject(this, &UPartyManager::OnRegistryLoaded);
	}
	else {
		OnRegistryLoaded();
	}

	//Add Party members to current party
	if (PartyMembers.Num() != 0)
	{
		CurrentPartyMembers.Add(GetPartyMember("Player"));
		CurrentPartyMembers.Add(GetPartyMember("Ilyana"));
	}
	
	//Starter Recipes
	KnownRecipes.Add("Potion");

}

void UPartyManager::OnRegistryLoaded()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	FARFilter Filter;
	Filter.ClassNames = { TEXT("Blueprint") }; //MyPrimaryDataAsset
	Filter.bRecursiveClasses = true;

	TArray<FAssetData> AssetList;
	// This data could be stored as static and processed in Default___CharacterClass's UObject,
	// but I think the performance hit is negligible and it's easier this way.   Blueprint'/Game/BP_MyMyPrimaryDataAsset.BP_MyMyPrimaryDataAsset'
	AssetRegistry.GetAssets(Filter, AssetList);

	TArray<UCharacterData*> MyTArray;
	//Blueprint'/Game/BP_MyMyPrimaryDataAsset.BP_MyMyPrimaryDataAsset'
	std::string PathName = "Blueprint'";
	////////////////////////
	for (const FAssetData& Asset : AssetList) {
		FString AssetFullPath(PathName.c_str() + Asset.ObjectPath.ToString() + "'");

		auto dataAsset = StaticLoadObject(UObject::StaticClass(), NULL, *AssetFullPath);

		UBlueprint* bp = Cast<UBlueprint>(dataAsset);
		TSubclassOf<class UCharacterData> whatIWant = (UClass*)bp->GeneratedClass;

		//Testing if successfull - setting mesh or printing error
		if (whatIWant)
		{
			if (whatIWant->ClassDefaultObject->IsA<UCharacterData>()) { //IsChildOf(UMyPrimaryDataAsset::StaticClass()

				UCharacterData* MyAsset = Cast<UCharacterData>(whatIWant->ClassDefaultObject);// NewObject<UMyPrimaryDataAsset>(whatIWant->ClassDefaultObject);
				if (MyAsset->GetCharacterName() != "CharacterTemplate") {
					UCharacterData* character = DuplicateObject(MyAsset, NULL);
					PartyMembers.Add(character);
					//PartyMembers.Add(MyAsset);
					UE_LOG(LogTemp, Error, TEXT(" loaded"));
				}
			}	
		}
	}
}

void UPartyManager::AddInventoryItem(FString name, int amount)
{
	inventory->AddItem(name, amount);
}

void UPartyManager::RemoveInventoryItem(FString name, int amount)
{
	inventory->RemoveItem(name, amount);
}

void UPartyManager::AddChestToList(int chestNum)
{
	OpenedChestList.Add(chestNum);
}

bool UPartyManager::IsChestInList(int chestNum)
{
	for (int openedChest : OpenedChestList)
	{
		if (openedChest == chestNum)
		{
			return true;
		}
	}
	return false;
}

UCharacterData* UPartyManager::GetPartyMember(FString name)
{
	for (UCharacterData* character : PartyMembers)
	{
		if (character->GetCharacterName() == name)
		{
			return character;
		}
	}
	return nullptr;
}

void UPartyManager::AddPartyMember(UCharacterData* character)
{
	CurrentPartyMembers.Add(character);
	CurrentPartySize++;
}

void UPartyManager::RemovePartyMember(UCharacterData* character)
{
	CurrentPartyMembers.RemoveSingle(character);
	CurrentPartySize--;
}
