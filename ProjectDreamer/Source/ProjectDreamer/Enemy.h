// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/UnrealMathUtility.h"

#include "Enemy.generated.h"

/***************************************************************************************
Title:       Enemy
Author:      Joshua Griffis
Date:        2022/03/18
Description: The stored data on enemies
*****************************************************************************************/

//TODO: Change TO EnemyData, and move to Data folder

class UStatTableComponent;
class UConditionTableComponent;
class UDamageTableComponent;
class UPaperSpriteComponent;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FItemDrop
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "100"))
		int32 chance = 0;


};

UCLASS(Blueprintable)
class PROJECTDREAMER_API UEnemy : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UEnemy();
	//UEnemy(FString n); //add more later

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0"))
		int EXP;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UStatComponent* Stats;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UConditionTableComponent* ConditionResistances;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UDamageTableComponent* DamageResistances;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FItemDrop> ItemDrops;


	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//	TArray<Skill*> Skills;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperSpriteComponent* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* Mesh;

public:

	UFUNCTION()
		FString GetEnemyName() { return Name; }

	UFUNCTION()
		FString GetEnemyDescription() { return Description; }

	UFUNCTION()
		int GetExperience() { return EXP; }

	UFUNCTION()
		UStatComponent* GetEnemyStats() { return Stats; }

	UFUNCTION()
		UConditionTableComponent* GetEnemyConditionResistances() { return ConditionResistances; }

	UFUNCTION()
		UDamageTableComponent* GetEnemyDamageResistances() { return DamageResistances; }

	//UFUNCTION()
	//	TArray<Skill*> GetEnemySkills() { return Skills; }

	UFUNCTION()
		UPaperSpriteComponent* GetEnemyImage() { return Image; }

	UFUNCTION()
		UStaticMesh* GetEnemyMesh() { return Mesh; }

};
