// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "UObject/Object.h"


#include "DataComponent.generated.h"

/***************************************************************************************
Title:       DataComponent
Author:      Joshua Griffis
Date:        2022/03/18
Description: Base class for components used in the system.
*****************************************************************************************/

UCLASS(ABSTRACT, EditInlineNew, BlueprintType, Blueprintable)
class PROJECTDREAMER_API UDataComponent : public UObject
{
	GENERATED_BODY()

public:

		virtual const FString GetType() { return ""; }

};
