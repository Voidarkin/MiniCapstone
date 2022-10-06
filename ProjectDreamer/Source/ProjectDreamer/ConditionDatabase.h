// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "ConditionDatabase.generated.h"



class UCondition;

UCLASS()
class PROJECTDREAMER_API UConditionDatabase : public UDataAsset
{
	GENERATED_BODY()

public:

	UConditionDatabase();
	~UConditionDatabase();

	UFUNCTION()
		UCondition* GetCondition(FString pName);


	//ApplyConditionEffect(CharacterData* character, EConditions condition);
	//ApplyConditionEffect(Battler* battler, EConditions condition);

protected:
	TArray<UCondition*> database;

};
