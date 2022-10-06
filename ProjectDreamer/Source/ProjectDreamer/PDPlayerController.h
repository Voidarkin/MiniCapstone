// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "PDPlayerController.generated.h"

/***************************************************************************************
Title:       PDPlayerController
Author:      Joshua Griffis
Date:        2022/03/18
Description: Controller used to move around the player and interact with different features
*****************************************************************************************/

class UDialogueWidget;
class UMenuWidget;
class APDPlayerState;

UENUM(BlueprintType)
enum class EGameInputMode : uint8
{
	UIOnly = 0 UMETA(DisplayName = "UI Only"),
	GameAndUI = 1  UMETA(DisplayName = "Game And UI"),
	GameOnly = 2     UMETA(DisplayName = "Game Only"),
	Count
};

UCLASS()
class PROJECTDREAMER_API APDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	APDPlayerController();

	UPROPERTY()
		UDialogueWidget* DialogueWidget;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UDialogueWidget> DialogueWindowBP;
	
	UPROPERTY()
		UMenuWidget* MenuWidget;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UMenuWidget> MenuWindowBP;
	
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void AcknowledgePossession(APawn* PossesedPawn) override;

	
	void MoveForward(float value);
	void MoveRight(float value);
	void SpeedUp();
	void SlowDown();

	void Interact();
	

	//void AddControllerYawInput(float Val);
	void TurnAtRate(float Rate);
	//void AddControllerPitchInput(float Val);
	void LookUpAtRate(float Rate);

	class APDPlayerState* MyPlayerState;
	class AProjectDreamerCharacter* MyPawn;

public:

	//Dialogue
	//ShowDialogue: Displays the dialogue UI
	void ShowDialogue();
	//SetDialogueText: Stores currently dialogue text data for conversations
	void SetDialogueText(TArray<FString> text);
	//SetDialogueText: Stores currently dialogue text data for conversations
	void SetDialogueText(FString text);
	//SetDialogueName: Stores currently dialogue name data for conversations
	void SetDialogueName(TArray<FString> name);
	//SetDialogueName: Stores currently dialogue name data for conversations
	void SetDialogueName(FString name);
	//SetDialogueName: Stores empty dialogue name data for conversations
	void SetDialogueName();	
	//SetCurrentDialogueText: Sets current dialogue text data into Dialogue UI
	void SetCurrentDialogueText(FString text);
	//SetCurrentDialogueName: Sets current dialogue name data into Dialogue UI
	void SetCurrentDialogueName(FString Name, bool ShowName);
	//ContinueText: Checks and either continues or ends dialogue.
	void ContinueText();

	//Menu
	//ToggleMenu: Calls either display or close on the menu UI based on its current state
	void ToggleMenu();
	//ShowMenu: Displays UI for menu
	void ShowMenu();
	//CloseMenu: Closes UI for menu
	void CloseMenu();


	//States
	bool IsPlayerAbleToMove();
	bool IsPlayerInDialogue();
	bool IsPlayerInMenu();
	void SetInputModeUI(EGameInputMode InputMode);
};
