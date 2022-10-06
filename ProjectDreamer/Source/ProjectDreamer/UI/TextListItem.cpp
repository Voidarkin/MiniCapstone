// Fill out your copyright notice in the Description page of Project Settings.


#include "TextListItem.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MenuWidget.h"

void UTextListItem::SetMenu(UMenuWidget* menuWidget)
{
	Menu = menuWidget;
}

void UTextListItem::NativeConstruct()
{
	Super::NativeConstruct();

}

bool UTextListItem::Initialize()
{
	bool bResult = Super::Initialize();
	if (!bResult)
	{
		return false;
	}

	return bResult;
}

void UTextListItem::SetSelectedRecipe()
{
	Menu->SetCraftingInfo(Text_ItemName->Text.ToString());
}

void UTextListItem::SetEquippedItem()
{
	Menu->Equip(Text_ItemName->Text.ToString());
}