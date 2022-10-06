// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "DataComponent.h"

#include "SkillComponent.generated.h"


/***************************************************************************************
Title:       SkillComponent
Author:      Joshua Griffis
Date:        2022/03/18
Description: Gives Skill to components owner
*****************************************************************************************/

UCLASS(BlueprintType)
class PROJECTDREAMER_API USkillComponent : public UDataComponent
{
	GENERATED_BODY()

public:

	static const FString GetStaticType() { return "USkillComponent"; }
	virtual const FString GetType() override { return GetStaticType(); }

public:

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	Skill* SkillToGive;
};
