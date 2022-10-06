// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "../ProjectDreamerCharacter.h"
#include "Kismet/GameplayStatics.h"


bool UDialogueWidget::Initialize()
{
	bool bResult = Super::Initialize();
	if (!bResult)
	{
		return false;
	}

	UTextBlock* DialogueWidget = Cast<UTextBlock>(GetWidgetFromName("DialogueText"));

	if (DialogueWidget != nullptr)
	{
		DialogueWidget->SetText(FText::FromString("Hello World"));
	}

	UTextBlock* NameWidget = Cast<UTextBlock>(GetWidgetFromName("DialogueName"));

	if (NameWidget != nullptr)
	{
		NameWidget->SetText(FText::FromString(""));
		NameWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	UBorder* NameBorderWidget = Cast<UBorder>(GetWidgetFromName("BorderName"));

	if (NameBorderWidget != nullptr)
	{
		NameBorderWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	return bResult;
}

void UDialogueWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UTextBlock* Widget = Cast<UTextBlock>(GetWidgetFromName("DialogueText"));

	if (Widget != nullptr)
	{

		AProjectDreamerCharacter* player = Cast<AProjectDreamerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (player)
		{

			//Widget->SetText(FText::FromString(FString::Printf(TEXT("Grenades: %d"), player->NumGrenades)));
		}

	}
}

void UDialogueWidget::SetDialogueText(FString Text)
{
	UTextBlock* Widget = Cast<UTextBlock>(GetWidgetFromName("DialogueText"));

	if (Widget != nullptr)
	{
		Widget->SetText(FText::FromString(Text));
	}
}

void UDialogueWidget::SetDialogueName(FString Name, bool ShowName)
{
	UTextBlock* NameWidget = Cast<UTextBlock>(GetWidgetFromName("DialogueName"));

	if (NameWidget != nullptr)
	{
		if (ShowName)
		{
			NameWidget->SetVisibility(ESlateVisibility::Visible);
			NameWidget->SetText(FText::FromString(Name));

		}
		else
		{
			NameWidget->SetVisibility(ESlateVisibility::Collapsed);
		}	
	}

	UBorder* NameBorderWidget = Cast<UBorder>(GetWidgetFromName("BorderName"));

	if (NameBorderWidget != nullptr)
	{
		if (ShowName)
		{
			NameBorderWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			NameBorderWidget->SetVisibility(ESlateVisibility::Collapsed);
		}	
	}
}
