// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "../Inventory.h"
#include "MenuWidget.h"

void UInventorySlotWidget::SetItemFields(FText name, FText amount)
{
	Text_Name->SetText(name);
	Text_Amount->SetText(amount);
}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button_Item)
	{
		//Button_Item->OnClicked.AddDynamic(this, &UInventorySlotWidget::OnButtonClicked);
		//Button_Item->OnClicked.AddDynamic(this, &UMenuWidget::SetItemInfo("d"));
	}
}

bool UInventorySlotWidget::Initialize()
{
	bool bResult = Super::Initialize();
	if (!bResult)
	{
		return false;
	}

	

	return bResult;
}

void UInventorySlotWidget::SetMenu(UMenuWidget* menuWidget)
{
	Menu = menuWidget;
}

void UInventorySlotWidget::OnButtonClicked()
{
	Menu->SetItemInfo(Text_Name->Text.ToString()); //Causing errors
}
