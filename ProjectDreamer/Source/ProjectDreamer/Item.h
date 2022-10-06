// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enums.h"

#include "Item.generated.h"

/***************************************************************************************
Title:       Item
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to store the data on Items to be used in the game
*****************************************************************************************/

//TODO: Change TO ItemData, and move to Data folder
class UDataComponent;
class UStatTable;

UCLASS(Blueprintable)
class PROJECTDREAMER_API UItem : public UDataAsset
{
	GENERATED_BODY()

public:

	UItem();
	UItem(FString n, FString d, int v);
	~UItem();

	UFUNCTION()
		const FString GetItemName() { return Name; }

	UFUNCTION()
		const FString GetItemDescription() { return Description; }

	UFUNCTION()
		const int GetSaleValue() { return SaleValue; }

	UFUNCTION()
		EUsable GetWhereUsable() { return UsableWhere; }

	//UPaperSprite* GetSprite() { return itemSprite; }

	template <class Type>
	Type* GetComponent()
	{
		for (UDataComponent* pComponent : Components)
		{
			if (pComponent->GetType() == Type::GetStaticType())
			{
				if (pComponent)
				{
					return static_cast<Type*>(pComponent);
				}
			}
		}
		return nullptr;
	}

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EUsable UsableWhere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SaleValue;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category = "Components")
		TArray<UDataComponent*> Components;

	//Image
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//UPaperSprite* itemSprite;

};
