// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

/***************************************************************************************
Title:       DialogueWidget
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to display dialogue
*****************************************************************************************/

UCLASS()
class PROJECTDREAMER_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//SetDialogueText: Updates dialogue UI with dialogue text
	void SetDialogueText(FString Text);
	//SetDialogueName: Updates dialogue UI with name
	void SetDialogueName(FString Name = "", bool ShowName = false);

protected:
	
	virtual bool Initialize() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

};
