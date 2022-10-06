// Fill out your copyright notice in the Description page of Project Settings.


#include "PDPlayerState.h"

void APDPlayerState::ClearDialogue()
{
	DialogueProgress = 0;
	DialogueText.Empty();
	DialogueName.Empty();
}

APDPlayerState::APDPlayerState()
{

	bCanMove = true;
	bInDialogue = false;

	DialogueProgress = 0;

}

void APDPlayerState::SetDialogueText(TArray<FString> text)
{
	ClearDialogue();

	for (int i = 0; i < text.Num(); i++)
	{
		DialogueText.Push(text[i]);
	}

}

void APDPlayerState::SetDialogueText(FString text)
{
	ClearDialogue();

	DialogueText.Push(text);

}


void APDPlayerState::SetName(TArray<FString> Name)
{
	for (int i = 0; i < Name.Num(); i++)
	{
		DialogueName.Push(Name[i]);
	}
}

void APDPlayerState::SetName(FString Name)
{
	DialogueName.Push(Name);
}

