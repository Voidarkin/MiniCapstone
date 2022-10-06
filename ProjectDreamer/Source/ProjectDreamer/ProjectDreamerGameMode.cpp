// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectDreamerGameMode.h"
#include "ProjectDreamerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectDreamerGameMode::AProjectDreamerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
