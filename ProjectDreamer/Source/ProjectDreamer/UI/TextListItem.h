// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"

#include "TextListItem.generated.h"

class UTextBlock;
class UButton;
class UInventory;
class UMenuWidget;

UCLASS()
class PROJECTDREAMER_API UTextListItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Item;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UMenuWidget* Menu;

	UFUNCTION()
		void SetMenu(UMenuWidget* menuWidget);

	virtual void NativeConstruct() override;

	UFUNCTION()
		void SetSelectedRecipe();
	UFUNCTION()
		void SetEquippedItem();

protected:

	virtual bool Initialize() override;

};
