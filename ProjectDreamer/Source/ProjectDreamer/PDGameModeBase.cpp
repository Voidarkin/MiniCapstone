// Fill out your copyright notice in the Description page of Project Settings.


#include "PDGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Pawn.h"
#include "PDPlayerController.h"
#include "PDPlayerState.h"


APDGameModeBase::APDGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerController(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_PDPlayerController"));

	static ConstructorHelpers::FClassFinder<APlayerState> PlayerState(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_PDPlayerState"));

	if (PawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PawnBPClass.Class;
	}
	if (PlayerController.Class != NULL)
	{
		PlayerControllerClass = PlayerController.Class;
	}
	if (PlayerState.Class != NULL)
	{
		PlayerStateClass = PlayerState.Class;
	}
}
