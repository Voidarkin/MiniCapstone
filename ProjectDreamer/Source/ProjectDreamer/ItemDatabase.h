// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Engine/DataAsset.h"

#include "ItemDatabase.generated.h"

/***************************************************************************************
Title:       ItemDatabase
Author:      Joshua Griffis
Date:        2022/03/30
Description: Stores all the data for items
*****************************************************************************************/

class UItem;

UCLASS()
class PROJECTDREAMER_API UItemDatabase : public UObject
{
	GENERATED_BODY()

public:
	UItemDatabase();
	~UItemDatabase();

	UItem* GetItem(FString pName);

protected:

	TArray<UItem*> database;

	void OnRegistryLoaded();
};
