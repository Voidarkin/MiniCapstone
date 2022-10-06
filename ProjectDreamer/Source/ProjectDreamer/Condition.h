
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enums.h"

#include "Condition.generated.h"

/***************************************************************************************
Title:       Condition
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to apply, remove the actual effects of a condition
*****************************************************************************************/

class UStatTable;
class UParticleSystem;
class UPaperSpriteComponent;

UCLASS()
class PROJECTDREAMER_API UCondition : public UDataAsset
{
	GENERATED_BODY()
		
public:

		UCondition();

		~UCondition();

protected:

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			FString Name;

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			FString Description;

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			UPaperSpriteComponent* Sprite;

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			UStatComponent* StatTable;

		EEffect ConditionEffect;

		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			float SuccessChance;
		
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
			UParticleSystem* EffectFX;

public:

	UFUNCTION()
		FString GetConditionName() { return Name; }

	UFUNCTION()
		FString GetConditionDescription() { return Description; }

	UFUNCTION()
		UPaperSpriteComponent* GetConditionSprite() { return Sprite; }

	UFUNCTION()
		UStatComponent* GetConditionStatChanges() { return StatTable; }

	UFUNCTION()
		float GetConditionSuccessChance() { return SuccessChance; }

	UFUNCTION()
		UParticleSystem* GetConditionFX() { return EffectFX; }

};
