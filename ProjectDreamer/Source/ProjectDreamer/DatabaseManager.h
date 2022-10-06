// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DatabaseManager.generated.h"

//class ItemDatabase;



/**
 * 
 */

UCLASS()
class PROJECTDREAMER_API UDatabaseManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UDatabaseManager();

	class UItemDatabase* GetItemDatabase() { return ItemDatabase; }

protected:

	class UItemDatabase* ItemDatabase;

};
