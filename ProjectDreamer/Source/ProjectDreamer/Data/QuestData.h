// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/UnrealMathUtility.h"

#include "QuestData.generated.h"

/***************************************************************************************
Title:       QuestData
Author:      Joshua Griffis
Date:        2022/03/22
Description: The stored data on Quest information
*****************************************************************************************/

USTRUCT(BlueprintType)
struct FRewardItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "100"))
		int32 amount = 0;

};

UCLASS(Blueprintable)
class PROJECTDREAMER_API UQuestData : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UQuestData();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0"))
		int RewardMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FRewardItem> RewardItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bComplete;

public:

	UFUNCTION()
		FString GetQuestName() { return Name; }

	UFUNCTION()
		FString GetQuestDescription() { return Description; }

	UFUNCTION()
		int GetRewardMoney() { return RewardMoney; }

	UFUNCTION()
		TArray<FRewardItem> GetRewardItems() { return RewardItems; }

	UFUNCTION()
		bool IsComplete() { return bComplete; }

};
