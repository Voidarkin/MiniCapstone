// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PDInteractable.generated.h"

/***************************************************************************************
Title:       PDInteractable
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to give interaction functionality to objects
*****************************************************************************************/

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPDInteractable : public UInterface
{
	GENERATED_BODY()
};

class PROJECTDREAMER_API IPDInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//Interact: the function called when the player uses the Interact button on an object that inherits from this interface.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Interact();

};
