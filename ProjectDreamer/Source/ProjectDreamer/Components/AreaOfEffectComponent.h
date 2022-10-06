// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "DataComponent.h"

#include "AreaOfEffectComponent.generated.h"

/***************************************************************************************
Title:       AreaOfEffectComponent
Author:      Joshua Griffis
Date:        2022/03/18
Description: The Area of effect component stores data needed to determine the shape 
and range of skills, items, etc.
*****************************************************************************************/

UCLASS(BlueprintType)
class PROJECTDREAMER_API UAreaOfEffectComponent : public UDataComponent
{
	GENERATED_BODY()

public:

	static const FString GetStaticType() { return "UAreaOfEffectComponent"; }
	virtual const FString GetType() override { return GetStaticType(); }

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETargetShape Shape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Distance;
};
