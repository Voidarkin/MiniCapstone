// Fill out your copyright notice in the Description page of Project Settings.


#include "PDPlayerController.h"
#include "ProjectDreamerCharacter.h"
#include "PDPlayerState.h"
#include "UI/DialogueWidget.h"
#include "UI/MenuWidget.h"
#include "Interactables/PDInteractable.h"


APDPlayerController::APDPlayerController()
{

}


void APDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	

	if (DialogueWindowBP != nullptr)
	{
		DialogueWidget = CreateWidget<UDialogueWidget>(this, DialogueWindowBP);
	}

	if (MenuWindowBP != nullptr)
	{
		MenuWidget = CreateWidget<UMenuWidget>(this, MenuWindowBP);
	}
}

void APDPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
}

void APDPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

void APDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent != nullptr)
	{

		InputComponent->BindAxis("MoveForward", this, &APDPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &APDPlayerController::MoveRight);
		//InputComponent->BindAction("Speed", IE_Pressed, this, &APDPlayerController::SlowDown);
		//InputComponent->BindAction("Speed", IE_Released, this, &APDPlayerController::SpeedUp);

		InputComponent->BindAction("Interact", IE_Pressed, this, &APDPlayerController::Interact);
		InputComponent->BindAction("Menu", IE_Pressed, this, &APDPlayerController::ToggleMenu);

		InputComponent->BindAxis("Turn", MyPawn, &APawn::AddControllerYawInput);
		InputComponent->BindAxis("TurnRate", this, &APDPlayerController::TurnAtRate);
		InputComponent->BindAxis("LookUp", MyPawn, &APawn::AddControllerPitchInput);
		InputComponent->BindAxis("LookUpRate", this, &APDPlayerController::LookUpAtRate);

	}

}

void APDPlayerController::AcknowledgePossession(APawn* PossesedPawn)
{
	Super::AcknowledgePossession(PossesedPawn);
	MyPawn = Cast<AProjectDreamerCharacter>(PossesedPawn);

	
	MyPlayerState = Cast<APDPlayerState>(PlayerState);
	if (MyPlayerState)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class %s"), TEXT("AMyPlayerController::BeginPlay: MyPlayerState Set"));
	}
	
	if (InputComponent != nullptr)
	{
		InputComponent->BindAxis("Turn", MyPawn, &APawn::AddControllerYawInput);
		InputComponent->BindAxis("TurnRate", this, &APDPlayerController::TurnAtRate);
		InputComponent->BindAxis("LookUp", MyPawn, &APawn::AddControllerPitchInput);
		InputComponent->BindAxis("LookUpRate", this, &APDPlayerController::LookUpAtRate);
	}
}

void APDPlayerController::MoveForward(float value)
{
	if (MyPawn)
		MyPawn->MoveForward(value);
}

void APDPlayerController::MoveRight(float value)
{
	if (MyPawn)
		MyPawn->MoveRight(value);
}

void APDPlayerController::SpeedUp()
{

}

void APDPlayerController::SlowDown()
{

}

void APDPlayerController::Interact()
{
	if (MyPawn)
		MyPawn->Interact();
}

void APDPlayerController::ContinueText()
{
	//TODO: Set up the way to continue the text if multiple lines of dialogue
	MyPlayerState->IncrementDialogueProgress();
	if (MyPlayerState->GetDialogueProgress() >= MyPlayerState->GetMaxDialogueNum())
	{
		DialogueWidget->RemoveFromViewport();

		MyPlayerState->TogglePlayerAbleToMove();
		MyPlayerState->TogglePlayerInDialogue();

	}
	else
	{
		SetCurrentDialogueText(MyPlayerState->GetDialogueText()[MyPlayerState->GetDialogueProgress()]);

		if (MyPlayerState->GetName().Num()-1 < MyPlayerState->GetDialogueProgress())
		{
			SetCurrentDialogueName(MyPlayerState->GetName()[MyPlayerState->GetName().Num() - 1], true);
		}
		else
		{
			if (MyPlayerState->GetName()[MyPlayerState->GetDialogueProgress()] != "")
			{
				SetCurrentDialogueName(MyPlayerState->GetName()[MyPlayerState->GetDialogueProgress()], true);
			}
			else
			{
				SetCurrentDialogueName(MyPlayerState->GetName()[MyPlayerState->GetDialogueProgress()], false);

			}
		}
	}
	
}

void APDPlayerController::TurnAtRate(float Rate)
{
	if (MyPawn)
		MyPawn->TurnAtRate(Rate);
}

void APDPlayerController::LookUpAtRate(float Rate)
{
	if (MyPawn)
		MyPawn->LookUpAtRate(Rate);
}

void APDPlayerController::ShowDialogue()
{
	MyPlayerState->TogglePlayerAbleToMove();
	MyPlayerState->TogglePlayerInDialogue();

	DialogueWidget->AddToViewport();
}

void APDPlayerController::SetDialogueText(TArray<FString> text)
{
	MyPlayerState->SetDialogueText(text);
	SetCurrentDialogueText(text[0]);
}

void APDPlayerController::SetDialogueText(FString text)
{
	MyPlayerState->SetDialogueText(text);
	SetCurrentDialogueText(text);

}

void APDPlayerController::SetDialogueName(FString name)
{
	MyPlayerState->SetName(name);
	SetCurrentDialogueText(name);

}

void APDPlayerController::SetDialogueName(TArray<FString> name)
{
	MyPlayerState->SetName(name);
	SetCurrentDialogueName(name[0], true);

}

void APDPlayerController::SetDialogueName()
{
	MyPlayerState->SetName("");
	SetCurrentDialogueName("", false);

}

void APDPlayerController::SetCurrentDialogueText(FString text)
{
	DialogueWidget->SetDialogueText(text);
	DialogueWidget->SetDialogueName("", false);
}

void APDPlayerController::SetCurrentDialogueName(FString Name, bool ShowName)
{
	DialogueWidget->SetDialogueName(Name, ShowName);
}

void APDPlayerController::ToggleMenu()
{
	if (!IsPlayerInMenu())
	{
		ShowMenu();
	}
	else
	{
		CloseMenu();
	}
}

void APDPlayerController::ShowMenu()
{
	MyPlayerState->TogglePlayerAbleToMove();
	MyPlayerState->TogglePlayerInMenu();

	MenuWidget->SetDefaultWidget();

	MenuWidget->AddToViewport();
	SetInputModeUI(EGameInputMode::GameAndUI);
}

void APDPlayerController::CloseMenu()
{
	MyPlayerState->TogglePlayerAbleToMove();
	MyPlayerState->TogglePlayerInMenu();

	SetInputModeUI(EGameInputMode::GameOnly);
	MenuWidget->RemoveFromViewport();
}

bool APDPlayerController::IsPlayerAbleToMove()	{ return MyPlayerState->IsPlayerAbleToMove(); }
bool APDPlayerController::IsPlayerInDialogue()	{ return MyPlayerState->IsPlayerInDialogue(); }
bool APDPlayerController::IsPlayerInMenu()		{ return MyPlayerState->IsPlayerInMenu(); }

void APDPlayerController::SetInputModeUI(EGameInputMode InputMode)
{
	
	switch (InputMode)
	{
	case EGameInputMode::UIOnly:
	{
		SetInputMode(FInputModeUIOnly());
		SetShowMouseCursor(true);
		break;
	}
	case EGameInputMode::GameAndUI:
	{
		SetInputMode(FInputModeGameAndUI());
		SetShowMouseCursor(true);
		break;
	}
	case EGameInputMode::GameOnly:
	{
		SetInputMode(FInputModeGameOnly());
		SetShowMouseCursor(false);
		break;
	}
	default:
		break;
	}

}