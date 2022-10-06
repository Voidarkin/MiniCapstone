// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */

class UTextBlock;
class UButton;
class UInventory;
class UMenuWidget;

UCLASS(Blueprintable)
class PROJECTDREAMER_API UInventorySlotWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Item;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Name;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Amount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UMenuWidget* Menu;


	UFUNCTION()
		void SetItemFields(FText name, FText amount);
	UFUNCTION()
		void SetMenu(UMenuWidget* menuWidget);

	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnButtonClicked();

protected:

	virtual bool Initialize() override;


};
