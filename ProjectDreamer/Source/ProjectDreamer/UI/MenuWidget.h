// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/***************************************************************************************
Title:       MenuWidget
Author:      Joshua Griffis
Date:        2022/03/18
Description: Displays Menu
*****************************************************************************************/

class UButton;
class UTextBlock;
class UCanvasPanel;
class UWidgetSwitcher;
class UBorder;
class UImage;
class UListView;
class UGridPanel;
class UVerticalBox;
class UScrollBox;
class UInventorySlotWidget;
class UTextListItem;

class UPartyManager;
class UDatabaseManager;
class UItem;

UCLASS()
class PROJECTDREAMER_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	//UMenuWidget(const FObjectInitialiazer& ObjectInitializer);

public:
/**********************************************************
				Menu Switcher
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UWidgetSwitcher* MenuSwitcher;

/**********************************************************
				Menu Panels
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* MainMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* InventoryMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* EquipmentMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* CraftingMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* StatusMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* SkillsMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* QuestLogMenu;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* BestiaryMenu;

/**********************************************************
			Back Buttons
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_Inventory;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_Equipment;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_Crafting;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_Status;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_Skills;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_QuestLog;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_Back_Bestiary;

/**********************************************************
			MainMenu Buttons
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Inventory;

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Equipment;

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Crafting;

	UPROPERTY(meta = (BindWidget))
		UButton* Button_QuestLog;

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Status;

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Bestiary;

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Skills;

/**********************************************************
			MainMenu Properties
**********************************************************/

	//Displayed Misc Data
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_MoneyAmount;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_ButtonInformation;

	//Displayed Character Data 1
	UPROPERTY(meta = (BindWidget))
		UBorder* Border_Character_1;
	UPROPERTY(meta = (BindWidget))
		UImage* Image_Character_1;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Name_Character_1;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentHP_Character_1;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentSP_Character_1;

	//Displayed Character Data 2
	UPROPERTY(meta = (BindWidget))
		UBorder* Border_Character_2;
	UPROPERTY(meta = (BindWidget))
		UImage* Image_Character_2;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Name_Character_2;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentHP_Character_2;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentSP_Character_2;

	//Displayed Character Data 3
	UPROPERTY(meta = (BindWidget))
		UBorder* Border_Character_3;
	UPROPERTY(meta = (BindWidget))
		UImage* Image_Character_3;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Name_Character_3;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentHP_Character_3;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentSP_Character_3;

	//Displayed Character Data 4
	UPROPERTY(meta = (BindWidget))
		UBorder* Border_Character_4;
	UPROPERTY(meta = (BindWidget))
		UImage* Image_Character_4;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Name_Character_4;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentHP_Character_4;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentSP_Character_4;

/**********************************************************
			Inventory Buttons
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UButton* Button_InventoryUse;
	UPROPERTY(meta = (BindWidget))
		UButton* Button_InventoryDiscard;

	UPROPERTY(meta = (BindWidget))
		UButton* Inventory_Button_Character_1;
	UPROPERTY(meta = (BindWidget))
		UButton* Inventory_Button_Character_2;
	UPROPERTY(meta = (BindWidget))
		UButton* Inventory_Button_Character_3;
	UPROPERTY(meta = (BindWidget))
		UButton* Inventory_Button_Character_4;

/**********************************************************
			Inventory Properties
**********************************************************/

	UPROPERTY()
		UItem* SelectedItem;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<UInventorySlotWidget> InventorySlotClass;

	UPROPERTY(meta = (BindWidget))
		UBorder* Inventory_Character_Pick;
	UPROPERTY(meta = (BindWidget))
		UBorder* Border_ItemInfo;
	UPROPERTY(meta = (BindWidget))
		UBorder* Border_InventoryButtons;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_InventoryItemName;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_InventoryItemDescription;

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* List_Inventory;
	UPROPERTY(meta = (BindWidget))
		UScrollBox* List_InventoryScrollBox;

	UPROPERTY(meta = (BindWidget))
		UImage* Inventory_Image_Character_1;
	UPROPERTY(meta = (BindWidget))
		UImage* Inventory_Image_Character_2;
	UPROPERTY(meta = (BindWidget))
		UImage* Inventory_Image_Character_3;
	UPROPERTY(meta = (BindWidget))
		UImage* Inventory_Image_Character_4;

/**********************************************************
			Status Buttons
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UButton* Status_Button_Character_1;
	UPROPERTY(meta = (BindWidget))
		UButton* Status_Button_Character_2;
	UPROPERTY(meta = (BindWidget))
		UButton* Status_Button_Character_3;
	UPROPERTY(meta = (BindWidget))
		UButton* Status_Button_Character_4;

/**********************************************************
			Status Properties
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UImage* Status_Image_Character_1;
	UPROPERTY(meta = (BindWidget))
		UImage* Status_Image_Character_2;
	UPROPERTY(meta = (BindWidget))
		UImage* Status_Image_Character_3;
	UPROPERTY(meta = (BindWidget))
		UImage* Status_Image_Character_4;

	UPROPERTY(meta = (BindWidget))
		UImage* Image_CharacterBody;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Bio;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Name;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_HP;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_SP;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_GAUGE;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_MOVE;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_STR;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_MAG;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_DEF;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_RES;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_AGI;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_LUCK;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_LVL;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_WPN;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_ACC1;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text_Status_Character_ACC2;

/**********************************************************
			Crafting Buttons
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UButton* Button_Crafting_Craft;
	UPROPERTY(meta = (BindWidget))
		UButton* Crafting_Button_OK;

/**********************************************************
			Crafting Properties
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* Crafting_List;
	UPROPERTY(meta = (BindWidget))
		UScrollBox* Crafting_ScrollBox;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<UTextListItem> TextItemClass;
	
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Crafting_Text_Description;
	UPROPERTY(meta = (BindWidget))
		UVerticalBox* Crafting_IngredientList;

	UPROPERTY()
		UItem* SelectedCraft;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Crafting_Text_ItemCreated;

	UPROPERTY(meta = (BindWidget))
		UBorder* Crafting_Border_Created;
	UPROPERTY(meta = (BindWidget))
		UBorder* Crafting_Border_IngredientList;
	UPROPERTY(meta = (BindWidget))
		UBorder* Crafting_Border_Description;
	UPROPERTY(meta = (BindWidget))
		UBorder* Crafting_Border_Craft;

/**********************************************************
			Equipment Buttons
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Character_1;
	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Character_2;
	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Character_3;
	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Character_4;

	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Weapon;
	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Accessory_1;
	UPROPERTY(meta = (BindWidget))
		UButton* Equipment_Button_Accessory_2;

/**********************************************************
			Equipment Properties
**********************************************************/

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Equipment_Button_Text_Weapon;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Equipment_Button_Text_Accessory_1;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* Equipment_Button_Text_Accessory_2;

	UPROPERTY(meta = (BindWidget))
		UImage* Equipment_Image_Character;
	UPROPERTY(meta = (BindWidget))
		UImage* Equipment_Image_Character_1;
	UPROPERTY(meta = (BindWidget))
		UImage* Equipment_Image_Character_2;
	UPROPERTY(meta = (BindWidget))
		UImage* Equipment_Image_Character_3;
	UPROPERTY(meta = (BindWidget))
		UImage* Equipment_Image_Character_4;

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* Equipment_List;

	UPROPERTY(meta = (BindWidget))
		UBorder* Equipment_Border_List;

	UPROPERTY()
		int CurrentlySelectedMember;
	UPROPERTY()
		int EquipmentSlotNum;

public:

/**********************************************************
			MainMenu Functions
**********************************************************/

	UFUNCTION()
		void OnInventoryClicked();
	UFUNCTION()
		void OnEquipmentClicked();
	UFUNCTION()
		void OnCraftingClicked();
	UFUNCTION()
		void OnQuestLogClicked();
	UFUNCTION()
		void OnStatusClicked();
	UFUNCTION()
		void OnBestiaryClicked();
	UFUNCTION()
		void OnSkillsClicked();

	UFUNCTION()
		void OnInventoryHovered();
	UFUNCTION()
		void OnEquipmentHovered();
	UFUNCTION()
		void OnCraftingHovered();
	UFUNCTION()
		void OnQuestLogHovered();
	UFUNCTION()
		void OnStatusHovered();
	UFUNCTION()
		void OnBestiaryHovered();
	UFUNCTION()
		void OnSkillsHovered();

	UFUNCTION()
		void SetDefaultWidget();
	UFUNCTION()
		void SetMenuWidget(UCanvasPanel* canvas);
	UFUNCTION()
		void SetInformationText(FText text);
	UFUNCTION()
		void SetPlayerData();

/**********************************************************
			Inventory Functions
**********************************************************/

	UFUNCTION()
		void OnInventoryUseClicked();
	UFUNCTION()
		void OnInventoryDiscardClicked();

	UFUNCTION()
		void OnFirstInventoryCharacterClicked();
	UFUNCTION()
		void OnSecondInventoryCharacterClicked();
	UFUNCTION()
		void OnThirdInventoryCharacterClicked();
	UFUNCTION()
		void OnFourthInventoryCharacterClicked();
	UFUNCTION()
		void OnInventoryCharacterClicked(int character);

	UFUNCTION()
		void SetInventoryItems();
	UFUNCTION()
		void SetItemInfo(FString itemName);
	UFUNCTION()
		void SetInventoryCharacterImages();

/**********************************************************
			Crafting Functions
**********************************************************/

	UFUNCTION()
		void SetCraftingInfo(FString itemName);

/**********************************************************
			Equipment Functions
**********************************************************/

	UFUNCTION()
		void Equip(FString itemName);

protected:



protected:

	virtual bool Initialize() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

/**********************************************************
			Status Functions
**********************************************************/
	
	UFUNCTION()
		void SetStatusPanels();
	UFUNCTION()
		void SetStatusButtonImages();

	UFUNCTION()
		void ChangeCurrentStatusToFirst();
	UFUNCTION()
		void ChangeCurrentStatusToSecond();
	UFUNCTION()
		void ChangeCurrentStatusToThird();
	UFUNCTION()
		void ChangeCurrentStatusToFourth();
	UFUNCTION()
		void ChangeCurrentStatus(int num);

/**********************************************************
			Crafting Functions
**********************************************************/

	UFUNCTION()
		void SetCraftingList();
	UFUNCTION()
		void Craft();

/**********************************************************
			Equipment Functions
**********************************************************/

	UFUNCTION()
		void SetEquipmentPanels();
	UFUNCTION()
		void SetEquipmentButtonImages();

	UFUNCTION()
		void ChangeCurrentEquipmentToFirst();
	UFUNCTION()
		void ChangeCurrentEquipmentToSecond();
	UFUNCTION()
		void ChangeCurrentEquipmentToThird();
	UFUNCTION()
		void ChangeCurrentEquipmentToFourth();
	UFUNCTION()
		void ChangeCurrentEquipment(int num);

	UFUNCTION()
		void ShowWeaponList();
	UFUNCTION()
		void ClickedAccessory_1();
	UFUNCTION()
		void ClickedAccessory_2();
	UFUNCTION()
		void ShowAccessoryList(int num);

/**********************************************************
			QuestLog Functions
**********************************************************/



/**********************************************************
			Bestiary Functions
**********************************************************/



/**********************************************************
			Skills Functions
**********************************************************/




};
