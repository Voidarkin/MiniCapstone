// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PDPlayerState.generated.h"

/***************************************************************************************
Title:       PDPlayerState
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to store relevant data 
*****************************************************************************************/

UCLASS()
class PROJECTDREAMER_API APDPlayerState : public APlayerState
{
	GENERATED_BODY()
		//TODO: Put variables for bCanMove and bInDialogue here and store a TArray of FStrings and a DialogueProgress variable. Anytime the dialogue window is shown, it will clear the Tarray and reset the Dialogue progress to 0 and then insert the text into the array and toggle the bCanMove, and bInDialogue until the progress is past the range of the array, then close the dialogue window and toggle the variables again.

public:

	APDPlayerState();

	UPROPERTY(EditAnywhere, Category = "Dialogue")
		TArray<FString> DialogueText;

	UPROPERTY(EditAnywhere, Category = "Dialogue")
		TArray<FString> DialogueName;

	UPROPERTY(EditAnywhere, Category = "Dialogue")
		int DialogueProgress;

	//States
	bool bCanMove;
	bool bInDialogue;
	bool bInMenu;	

protected:



public:

	//Get State Bools
	bool IsPlayerAbleToMove() { return bCanMove; }
	bool IsPlayerInDialogue() { return bInDialogue; }
	bool IsPlayerInMenu() { return bInMenu; }

	//Set State Bools
	void SetPlayerAbleToMove(bool b) { bCanMove = b; }
	void SetPlayerInDialogue(bool b) { bInDialogue = b; }
	void SetPlayerInMenu(bool b) { bInMenu = b; }

	//Toggle State Bools
	void TogglePlayerAbleToMove() { bCanMove = !bCanMove; }
	void TogglePlayerInDialogue() { bInDialogue = !bInDialogue; }
	void TogglePlayerInMenu() { bInMenu = !bInMenu; }

	//Dialogue
	//ClearDialogue: empties all dialogue arrays and sets progress to zero
	void ClearDialogue();
	//SetDialogueText: Stores currently dialogue text data for conversations
	void SetDialogueText(TArray<FString> text);
	//SetDialogueText: Stores currently dialogue text data for conversations
	void SetDialogueText(FString text);
	
	TArray<FString> GetDialogueText() { return DialogueText; }
	//GetMaxDialogueNum: Returns max amount of dialogue lines
	int GetMaxDialogueNum() { return DialogueText.Num(); }
	//GetDialogueProgress: Gets current position in conversation
	int GetDialogueProgress() { return DialogueProgress; }
	void IncrementDialogueProgress() { DialogueProgress++; }
	void SetName(FString Name);
	void SetName(TArray<FString> Name);
	TArray<FString> GetName() { return DialogueName; }

};
