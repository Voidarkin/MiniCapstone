// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/GridPanel.h"
#include "Components/Image.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"
#include "Engine/Texture2D.h"
#include "InventorySlotWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TextListItem.h"
#include "../CharacterData.h"
#include "../Components/CraftableComponent.h"
#include "../Components/EquipmentComponent.h"
#include "../Components/StatComponent.h"
#include "../DatabaseManager.h"
#include "../Inventory.h"
#include "../Item.h"
#include "../ItemDatabase.h"
#include "../PartyManager.h"
#include "../ProjectDreamerCharacter.h"

void UMenuWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	//If in menu
	if (MenuSwitcher->GetActiveWidget() == InventoryMenu)
	{
		if (List_Inventory->IsSelected())
		{
			//UInventorySlotWidget* invSlot = Cast<UInventorySlotWidget>(List_Inventory->GetSelectedItem());
			//SetItemInfo("Pot");
		}
	}

}
bool UMenuWidget::Initialize()
{
	bool bResult = Super::Initialize();
	if (!bResult)
	{
		return false;
	}

	//PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	//DatabaseManager = GetGameInstance()->GetSubsystem<UDatabaseManager>();

	//FStringClassReference MyWidgetClassRef(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_InventorySlot.BP_InventorySlot_C"));
	//InventorySlotClass = MyWidgetClassRef.TryLoadClass<UInventorySlotWidget>();
	//ConstructorHelpers::FClassFinder<UInventorySlotWidget> SlotBP(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_InventorySlot"));
	//InventorySlot = SlotBP.Class;

/**********************************************************
			MainMenu Buttons
**********************************************************/
	if (Button_Inventory)
	{
		Button_Inventory->OnClicked.AddDynamic(this, &UMenuWidget::OnInventoryClicked);
		Button_Inventory->OnHovered.AddDynamic(this, &UMenuWidget::OnInventoryHovered);
	}
	if (Button_Equipment)
	{
		Button_Equipment->OnClicked.AddDynamic(this, &UMenuWidget::OnEquipmentClicked);
		Button_Equipment->OnHovered.AddDynamic(this, &UMenuWidget::OnEquipmentHovered);
	}
	if (Button_Crafting)
	{
		Button_Crafting->OnClicked.AddDynamic(this, &UMenuWidget::OnCraftingClicked);
		Button_Crafting->OnHovered.AddDynamic(this, &UMenuWidget::OnCraftingHovered);
	}
	if (Button_QuestLog)
	{
		Button_QuestLog->OnClicked.AddDynamic(this, &UMenuWidget::OnQuestLogClicked);
		Button_QuestLog->OnHovered.AddDynamic(this, &UMenuWidget::OnQuestLogHovered);
	}
	if (Button_Status)
	{
		Button_Status->OnClicked.AddDynamic(this, &UMenuWidget::OnStatusClicked);
		Button_Status->OnHovered.AddDynamic(this, &UMenuWidget::OnStatusHovered);
	}
	if (Button_Bestiary)
	{
		Button_Bestiary->OnClicked.AddDynamic(this, &UMenuWidget::OnBestiaryClicked);
		Button_Bestiary->OnHovered.AddDynamic(this, &UMenuWidget::OnBestiaryHovered);
	}
	if (Button_Skills)
	{
		Button_Skills->OnClicked.AddDynamic(this, &UMenuWidget::OnSkillsClicked);
		Button_Skills->OnHovered.AddDynamic(this, &UMenuWidget::OnSkillsHovered);
	}

/**********************************************************
			Back Buttons
**********************************************************/

	if (Button_Back_Inventory)	{	Button_Back_Inventory->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }
	if (Button_Back_Equipment)	{	Button_Back_Equipment->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }
	if (Button_Back_Crafting)	{	Button_Back_Crafting->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }
	if (Button_Back_Status)		{	Button_Back_Status->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }
	if (Button_Back_Skills)		{	Button_Back_Skills->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }
	if (Button_Back_QuestLog)	{	Button_Back_QuestLog->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }
	if (Button_Back_Bestiary)	{	Button_Back_Bestiary->OnClicked.AddDynamic(this, &UMenuWidget::SetDefaultWidget); }

/**********************************************************
			Inventory Buttons
**********************************************************/

	if (Button_InventoryUse)			{	Button_InventoryUse->OnClicked.AddDynamic(this, &UMenuWidget::OnInventoryUseClicked);			}
	if (Button_InventoryDiscard)		{	Button_InventoryDiscard->OnClicked.AddDynamic(this, &UMenuWidget::OnInventoryDiscardClicked);	}
	if (Inventory_Button_Character_1)	{ Inventory_Button_Character_1->OnClicked.AddDynamic(this, &UMenuWidget::OnFirstInventoryCharacterClicked); }
	if (Inventory_Button_Character_2)	{ Inventory_Button_Character_2->OnClicked.AddDynamic(this, &UMenuWidget::OnSecondInventoryCharacterClicked); }
	if (Inventory_Button_Character_3)	{ Inventory_Button_Character_3->OnClicked.AddDynamic(this, &UMenuWidget::OnThirdInventoryCharacterClicked); }
	if (Inventory_Button_Character_4)	{ Inventory_Button_Character_4->OnClicked.AddDynamic(this, &UMenuWidget::OnFourthInventoryCharacterClicked); }

/**********************************************************
			Status Buttons
**********************************************************/

	if (Status_Button_Character_1) { Status_Button_Character_1->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentStatusToFirst); }
	if (Status_Button_Character_2) { Status_Button_Character_2->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentStatusToSecond); }
	if (Status_Button_Character_3) { Status_Button_Character_3->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentStatusToThird); }
	if (Status_Button_Character_4) { Status_Button_Character_4->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentStatusToFourth); }

/**********************************************************
			Crafting Buttons
**********************************************************/

	if (Button_Crafting_Craft)	{ Button_Crafting_Craft->OnClicked.AddDynamic(this, &UMenuWidget::Craft); }
	if (Crafting_Button_OK)		{ Crafting_Button_OK->OnClicked.AddDynamic(this, &UMenuWidget::SetCraftingList); }

/**********************************************************
			Equipment Buttons
**********************************************************/

	if (Equipment_Button_Character_1)	{ Equipment_Button_Character_1->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentEquipmentToFirst); }
	if (Equipment_Button_Character_2)	{ Equipment_Button_Character_2->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentEquipmentToSecond); }
	if (Equipment_Button_Character_3)	{ Equipment_Button_Character_3->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentEquipmentToThird); }
	if (Equipment_Button_Character_4)	{ Equipment_Button_Character_4->OnClicked.AddDynamic(this, &UMenuWidget::ChangeCurrentEquipmentToFourth); }

	if (Equipment_Button_Weapon)		{ Equipment_Button_Weapon->OnClicked.AddDynamic(this, &UMenuWidget::ShowWeaponList); }
	if (Equipment_Button_Accessory_1)	{ Equipment_Button_Accessory_1->OnClicked.AddDynamic(this, &UMenuWidget::ClickedAccessory_1); }
	if (Equipment_Button_Accessory_2)	{ Equipment_Button_Accessory_2->OnClicked.AddDynamic(this, &UMenuWidget::ClickedAccessory_2); }

/**********************************************************
			Skills Buttons
**********************************************************/



/**********************************************************
			QuestLog Buttons
**********************************************************/


/**********************************************************
			Bestiary Buttons
**********************************************************/

	return bResult;
}

/**********************************************************
			Multi-Use Functions
**********************************************************/

void UMenuWidget::SetDefaultWidget()					
{
	MenuSwitcher->SetActiveWidget(MainMenu); 
	SetPlayerData();
}
void UMenuWidget::SetMenuWidget(UCanvasPanel* canvas)	{	MenuSwitcher->SetActiveWidget(canvas); }

/**********************************************************
			MainMenu Functions
**********************************************************/

void UMenuWidget::OnInventoryClicked()	
{	
	SetMenuWidget(InventoryMenu); 
	SetInventoryItems();
}
void UMenuWidget::OnEquipmentClicked()	
{	
	SetMenuWidget(EquipmentMenu); 
	SetEquipmentPanels();
}
void UMenuWidget::OnCraftingClicked()	
{	
	SetMenuWidget(CraftingMenu);
	SetCraftingList();
}
void UMenuWidget::OnQuestLogClicked()	{	SetMenuWidget(QuestLogMenu); }
void UMenuWidget::OnStatusClicked()		
{	
	SetMenuWidget(StatusMenu); 
	SetStatusButtonImages();
	SetStatusPanels();
}
void UMenuWidget::OnBestiaryClicked()	{	SetMenuWidget(BestiaryMenu); }
void UMenuWidget::OnSkillsClicked()		{	SetMenuWidget(SkillsMenu); }

void UMenuWidget::OnInventoryHovered()	{	SetInformationText(FText::FromString("Display the inventory")); }
void UMenuWidget::OnEquipmentHovered()	{	SetInformationText(FText::FromString("Display and change the equipment of the characters")); }
void UMenuWidget::OnCraftingHovered()	{	SetInformationText(FText::FromString("Navigate to the crafting menu where you can combine materials to make items")); }
void UMenuWidget::OnQuestLogHovered()	{	SetInformationText(FText::FromString("Display current quests"));}
void UMenuWidget::OnStatusHovered()		{	SetInformationText(FText::FromString("Display detailed information on each character")); }
void UMenuWidget::OnBestiaryHovered()	{	SetInformationText(FText::FromString("Show detailed information on bad dreams and nightmares")); }
void UMenuWidget::OnSkillsHovered()		{	SetInformationText(FText::FromString("Currently Out of Order")); }

void UMenuWidget::SetInformationText(FText text)	{	Text_ButtonInformation->SetText(text); }
void UMenuWidget::SetPlayerData()
{

	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();

	if (Party.Num() >= 1)
	{
		Image_Character_1->SetBrushFromTexture(Party[0]->GetCharacterFaceImage());
		Name_Character_1->SetText(FText::FromString(Party[0]->GetCharacterName()));

		FString hpNumbers
			= FString::FromInt(Party[0]->GetCharacterStats()->GetStat("currentHP"))
			+ FString(" / ") 
			+ FString::FromInt(Party[0]->GetCharacterStats()->GetStat("maxHP"));
		CurrentHP_Character_1->SetText(FText::FromString(hpNumbers));

		FString spNumbers 
			= FString::FromInt(Party[0]->GetCharacterStats()->GetStat("currentSP")) 
			+ FString(" / ") 
			+ FString::FromInt(Party[0]->GetCharacterStats()->GetStat("maxSP"));
		CurrentSP_Character_1->SetText(FText::FromString(spNumbers));
		Border_Character_1->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Border_Character_1->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (Party.Num() >= 2)
	{
		Image_Character_2->SetBrushFromTexture(Party[1]->GetCharacterFaceImage());
		Name_Character_2->SetText(FText::FromString(Party[1]->GetCharacterName()));
		FString hpNumbers 
			= FString::FromInt(Party[1]->GetCharacterStats()->GetStat("currentHP")) 
			+ FString(" / ") 
			+ FString::FromInt(Party[1]->GetCharacterStats()->GetStat("maxHP"));
		CurrentHP_Character_2->SetText(FText::FromString(hpNumbers));

		FString spNumbers 
			= FString::FromInt(Party[1]->GetCharacterStats()->GetStat("currentSP")) 
			+ FString(" / ") 
			+ FString::FromInt(Party[1]->GetCharacterStats()->GetStat("maxSP"));
		CurrentSP_Character_2->SetText(FText::FromString(spNumbers));
		Border_Character_2->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Border_Character_2->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (Party.Num() >= 3)
	{
		Image_Character_3->SetBrushFromTexture(Party[2]->GetCharacterFaceImage());
		Name_Character_3->SetText(FText::FromString(Party[2]->GetCharacterName()));
		FString hpNumbers 
			= FString::FromInt(Party[2]->GetCharacterStats()->GetStat("currentHP"))
			+ FString(" / ") 
			+ FString::FromInt(Party[2]->GetCharacterStats()->GetStat("maxHP"));
		CurrentHP_Character_3->SetText(FText::FromString(hpNumbers));

		FString spNumbers 
			= FString::FromInt(Party[2]->GetCharacterStats()->GetStat("currentSP")) 
			+ FString(" / ") 
			+ FString::FromInt(Party[2]->GetCharacterStats()->GetStat("maxSP"));
		CurrentSP_Character_3->SetText(FText::FromString(spNumbers));
		Border_Character_3->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Border_Character_3->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (Party.Num() >= 4)
	{
		Image_Character_4->SetBrushFromTexture( Party[3]->GetCharacterFaceImage() );
		Name_Character_4->SetText(FText::FromString(Party[3]->GetCharacterName()));
		FString hpNumbers 
			= FString::FromInt(Party[3]->GetCharacterStats()->GetStat("currentHP")) 
			+ FString(" / ") 
			+ FString::FromInt(Party[3]->GetCharacterStats()->GetStat("maxHP"));
		CurrentHP_Character_4->SetText(FText::FromString(hpNumbers));

		FString spNumbers 
			= FString::FromInt(Party[3]->GetCharacterStats()->GetStat("currentSP")) 
			+ FString(" / ") 
			+ FString::FromInt(Party[3]->GetCharacterStats()->GetStat("maxSP"));
		CurrentSP_Character_4->SetText(FText::FromString(spNumbers));
		Border_Character_4->SetVisibility(ESlateVisibility::Visible);
	}
	else 
	{
		Border_Character_4->SetVisibility(ESlateVisibility::Collapsed);
	}

	Text_MoneyAmount->Text = FText::AsNumber(PartyManager->GetInventory()->GetMoney());
	SetInformationText(FText::FromString("Display the inventory"));
}

/**********************************************************
			Inventory Functions
**********************************************************/

void UMenuWidget::OnInventoryUseClicked()
{
	Inventory_Character_Pick->SetVisibility(ESlateVisibility::Visible);
	SetInventoryCharacterImages();
}

void UMenuWidget::OnInventoryDiscardClicked()
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	UInventory* Inventory = PartyManager->GetInventory();

	if (SelectedItem)
	{
		if (Inventory->CheckIfHasItem(SelectedItem->GetItemName()))
		{
			Inventory->RemoveItem(SelectedItem->GetItemName(), 1);
		}
	}

	SetInventoryItems();
}

void UMenuWidget::OnFirstInventoryCharacterClicked()	{	OnInventoryCharacterClicked(0); }
void UMenuWidget::OnSecondInventoryCharacterClicked()	{	OnInventoryCharacterClicked(1); }
void UMenuWidget::OnThirdInventoryCharacterClicked()	{	OnInventoryCharacterClicked(2); }
void UMenuWidget::OnFourthInventoryCharacterClicked()	{	OnInventoryCharacterClicked(3); }

void UMenuWidget::OnInventoryCharacterClicked(int character)
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	UCharacterData* partyMember = PartyManager->GetCurrentPartyMembers()[character];
	UInventory* Inventory = PartyManager->GetInventory();

	Inventory->UseItem(SelectedItem, partyMember);

	SetInventoryItems();
}

void UMenuWidget::SetInventoryItems()
{
	Border_ItemInfo->SetVisibility(ESlateVisibility::Collapsed);
	Border_InventoryButtons->SetVisibility(ESlateVisibility::Collapsed);
	Inventory_Character_Pick->SetVisibility(ESlateVisibility::Collapsed);
	List_Inventory->ClearChildren();
	SelectedItem = nullptr;

	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	UInventory* Inventory = PartyManager->GetInventory();

	for (FInventorySlot slot : Inventory->GetInventory())
	{
		UInventorySlotWidget* InventoryEntry = CreateWidget<UInventorySlotWidget>(List_Inventory, InventorySlotClass);
		FText name = FText::FromString(slot.name);
		FText amount = FText::AsNumber(slot.amount);		
		InventoryEntry->SetItemFields(name, amount);
		InventoryEntry->SetMenu(this);
		if (InventoryEntry->Button_Item) { InventoryEntry->Button_Item->OnClicked.AddDynamic(InventoryEntry, &UInventorySlotWidget::OnButtonClicked); }
		List_Inventory->AddChildToVerticalBox(InventoryEntry);
	}
}

void UMenuWidget::SetItemInfo(FString itemName)
{
	SelectedItem = nullptr;
	UDatabaseManager* DatabaseManager = GetGameInstance()->GetSubsystem<UDatabaseManager>();
	SelectedItem = DatabaseManager->GetItemDatabase()->GetItem(itemName);
	if (SelectedItem)
	{
		Text_InventoryItemName->SetText(FText::FromString(SelectedItem->GetItemName()));
		Text_InventoryItemDescription->SetText(FText::FromString(SelectedItem->GetItemDescription()));
		Border_ItemInfo->SetVisibility(ESlateVisibility::Visible);
		Border_InventoryButtons->SetVisibility(ESlateVisibility::Visible);
	}
}

void UMenuWidget::SetInventoryCharacterImages()
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();
	if (Party.Num() >= 1)
	{
		Inventory_Button_Character_1->SetVisibility(ESlateVisibility::Visible);
		Inventory_Image_Character_1->SetBrushFromTexture(Party[0]->GetCharacterFaceImage());
	}
	else
	{
		Inventory_Button_Character_1->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 2)
	{
		Inventory_Button_Character_2->SetVisibility(ESlateVisibility::Visible);
		Inventory_Image_Character_2->SetBrushFromTexture(Party[1]->GetCharacterFaceImage());
	}
	else
	{
		Inventory_Button_Character_2->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 3)
	{
		Inventory_Button_Character_3->SetVisibility(ESlateVisibility::Visible);
		Inventory_Image_Character_3->SetBrushFromTexture(Party[2]->GetCharacterFaceImage());
	}
	else
	{
		Inventory_Button_Character_3->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 4)
	{
		Inventory_Button_Character_4->SetVisibility(ESlateVisibility::Visible);
		Inventory_Image_Character_4->SetBrushFromTexture(Party[3]->GetCharacterFaceImage());
	}
	else
	{
		Inventory_Button_Character_4->SetVisibility(ESlateVisibility::Collapsed);
	}

}

/**********************************************************
			Equipment Functions
**********************************************************/

void UMenuWidget::SetEquipmentPanels()
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();

	SetEquipmentButtonImages();

	//Set Default
	if (Party.Num() > 0)
	{
		ChangeCurrentEquipment(0);
	}
}

void UMenuWidget::SetEquipmentButtonImages()
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();
	if (Party.Num() >= 1)
	{
		Equipment_Button_Character_1->SetVisibility(ESlateVisibility::Visible);
		Equipment_Image_Character_1->SetBrushFromTexture(Party[0]->GetCharacterFaceImage());
	}
	else
	{
		Equipment_Button_Character_1->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 2)
	{
		Equipment_Button_Character_2->SetVisibility(ESlateVisibility::Visible);
		Equipment_Image_Character_2->SetBrushFromTexture(Party[1]->GetCharacterFaceImage());
	}
	else
	{
		Equipment_Button_Character_2->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 3)
	{
		Equipment_Button_Character_3->SetVisibility(ESlateVisibility::Visible);
		Equipment_Image_Character_3->SetBrushFromTexture(Party[2]->GetCharacterFaceImage());
	}
	else
	{
		Equipment_Button_Character_3->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 4)
	{
		Equipment_Button_Character_4->SetVisibility(ESlateVisibility::Visible);
		Equipment_Image_Character_4->SetBrushFromTexture(Party[3]->GetCharacterFaceImage());
	}
	else
	{
		Equipment_Button_Character_4->SetVisibility(ESlateVisibility::Collapsed);
	}

}

// Changing Displayed Status
void UMenuWidget::ChangeCurrentEquipmentToFirst()	{ ChangeCurrentEquipment(0); }
void UMenuWidget::ChangeCurrentEquipmentToSecond()	{ ChangeCurrentEquipment(1); }
void UMenuWidget::ChangeCurrentEquipmentToThird()	{ ChangeCurrentEquipment(2); }
void UMenuWidget::ChangeCurrentEquipmentToFourth()	{ ChangeCurrentEquipment(3); }

void UMenuWidget::ChangeCurrentEquipment(int num)
{

	Equipment_Border_List->SetVisibility(ESlateVisibility::Collapsed);

	EquipmentSlotNum = 0;
	CurrentlySelectedMember = num;
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();

	Equipment_Image_Character->SetBrushFromTexture(Party[num]->GetCharacterBodyImage());

	Equipment_Button_Text_Weapon->SetText(FText::FromString(Party[num]->GetWeapon()));
	Equipment_Button_Text_Accessory_1->SetText(FText::FromString(Party[num]->GetFirstAccessory()));
	Equipment_Button_Text_Accessory_2->SetText(FText::FromString(Party[num]->GetSecondAccessory()));

}

void UMenuWidget::ShowWeaponList()
{
	Equipment_List->ClearChildren();
	EquipmentSlotNum = 1;
	Equipment_Border_List->SetVisibility(ESlateVisibility::Visible);

	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	UInventory* Inventory = PartyManager->GetInventory();
	UItemDatabase* database = GetGameInstance()->GetSubsystem<UDatabaseManager>()->GetItemDatabase();

	for (FInventorySlot slot : Inventory->GetInventory())
	{
		UItem* item = database->GetItem(slot.name);
		UEquipmentComponent* EquipComp = item->GetComponent<UEquipmentComponent>();
		if (EquipComp)
		{
			if (EquipComp->GetSlot() == EEquipSlot::Weapon)
			{
				UTextListItem* listItem = CreateWidget<UTextListItem>(Equipment_List, TextItemClass);
				listItem->Text_ItemName->SetText(FText::FromString(slot.name));
				listItem->SetMenu(this);
				if (listItem->Button_Item) { listItem->Button_Item->OnClicked.AddDynamic(listItem, &UTextListItem::SetEquippedItem); }
				Equipment_List->AddChildToVerticalBox(listItem);
			}
		}
	}
}

void UMenuWidget::ClickedAccessory_1()	{ ShowAccessoryList(2); }
void UMenuWidget::ClickedAccessory_2()	{ ShowAccessoryList(3); }
void UMenuWidget::ShowAccessoryList(int num)
{
	Equipment_List->ClearChildren();
	EquipmentSlotNum = num;
	Equipment_Border_List->SetVisibility(ESlateVisibility::Visible);

	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	UInventory* Inventory = PartyManager->GetInventory();
	UItemDatabase* database = GetGameInstance()->GetSubsystem<UDatabaseManager>()->GetItemDatabase();

	for (FInventorySlot slot : Inventory->GetInventory())
	{
		UItem* item = database->GetItem(slot.name);
		UEquipmentComponent* EquipComp = item->GetComponent<UEquipmentComponent>();
		if (EquipComp)
		{
			if (EquipComp->GetSlot() == EEquipSlot::Accessory)
			{
				UTextListItem* listItem = CreateWidget<UTextListItem>(Equipment_List, TextItemClass);
				listItem->Text_ItemName->SetText(FText::FromString(slot.name));
				listItem->SetMenu(this);
				if (listItem->Button_Item) { listItem->Button_Item->OnClicked.AddDynamic(listItem, &UTextListItem::SetEquippedItem); }
				Equipment_List->AddChildToVerticalBox(listItem);
			}
		}
	}
}

void UMenuWidget::Equip(FString itemName)
{

	Equipment_Border_List->SetVisibility(ESlateVisibility::Collapsed);

	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	UInventory* Inventory = PartyManager->GetInventory();
	UCharacterData* Character = PartyManager->GetCurrentPartyMembers()[CurrentlySelectedMember];
	UItemDatabase* database = GetGameInstance()->GetSubsystem<UDatabaseManager>()->GetItemDatabase();

	FString CurrentEquip;
	switch (EquipmentSlotNum)
	{
	case 1:
		CurrentEquip = Character->GetWeapon();
		break;
	case 2:
		CurrentEquip = Character->GetFirstAccessory();
		break;
	case 3:
		CurrentEquip = Character->GetSecondAccessory();
		break;
	}
	FString ReplacingEquip = itemName;

	if (!(CurrentEquip == "Empty"))
	{
		//remove held item
		Inventory->AddItem(CurrentEquip, 1);

		UItem* EquippedItem = database->GetItem(CurrentEquip);
		if (EquippedItem)
		{
			UStatComponent* StatComp = EquippedItem->GetComponent<UStatComponent>();
			if (StatComp)
			{
				Character->GetCharacterStats()->RemoveTable(*StatComp);
				CurrentEquip = "Empty";
			}
		}
	}

	//add replacing item
	Inventory->RemoveItem(ReplacingEquip, 1);

	UItem* ReplacingItem = database->GetItem(ReplacingEquip);
	if (ReplacingItem)
	{
		UStatComponent* StatComp = ReplacingItem->GetComponent<UStatComponent>();
		if (StatComp)
		{
			Character->GetCharacterStats()->AddTable(*StatComp);
			switch (EquipmentSlotNum)
			{
			case 1:
				Character->SetWeapon(ReplacingEquip);
				break;
			case 2:
				Character->SetFirstAccessory(ReplacingEquip);	
				break;
			case 3:
				Character->SetSecondAccessory(ReplacingEquip);
				break;
			}
		}
	}

	ChangeCurrentEquipment(CurrentlySelectedMember);

}

/**********************************************************
			Crafting Functions
**********************************************************/

void UMenuWidget::SetCraftingList()
{
	Crafting_Border_Created->SetVisibility(ESlateVisibility::Collapsed);
	Crafting_Border_IngredientList->SetVisibility(ESlateVisibility::Collapsed);
	Crafting_Border_Craft->SetVisibility(ESlateVisibility::Collapsed);
	Crafting_Border_Description->SetVisibility(ESlateVisibility::Collapsed);

	if (Crafting_List)
	{
		Crafting_List->ClearChildren();
	}
	TArray<FString> Recipes = GetGameInstance()->GetSubsystem<UPartyManager>()->GetKnownRecipes();

	if (Crafting_ScrollBox)
	{
		for (FString item : Recipes)
		{
			UTextListItem* listItem = CreateWidget<UTextListItem>(Crafting_List, TextItemClass);
			listItem->Text_ItemName->SetText(FText::FromString(item));
			listItem->SetMenu(this);
			if (listItem->Button_Item) { listItem->Button_Item->OnClicked.AddDynamic(listItem, &UTextListItem::SetSelectedRecipe); }
			Crafting_List->AddChildToVerticalBox(listItem);

		}
		
	}
}

void UMenuWidget::SetCraftingInfo(FString itemName)
{
	Crafting_IngredientList->ClearChildren();
	SelectedCraft = nullptr;

	UItemDatabase* database = GetGameInstance()->GetSubsystem<UDatabaseManager>()->GetItemDatabase();
	SelectedCraft = database->GetItem(itemName);

	if (SelectedCraft)
	{
		Crafting_Text_Description->SetText(FText::FromString(SelectedCraft->GetItemDescription()));
		UCraftableComponent* CraftingComp = SelectedCraft->GetComponent<UCraftableComponent>();
		TArray<FCraftingMaterial> ingredients = CraftingComp->GetMaterials();
		for (FCraftingMaterial ingredient : ingredients)
		{
			//UTextListItem* listItem = CreateWidget<UTextListItem>(Crafting_List, TextItemClass);
			//listItem->Text_ItemName->SetText(FText::FromString(ingredient.name));
			//listItem->SetMenu(this);
			//Crafting_IngredientList->AddChildToVerticalBox(listItem);

			UInventorySlotWidget* listItem = CreateWidget<UInventorySlotWidget>(Crafting_IngredientList, InventorySlotClass);
			FText name = FText::FromString(ingredient.name);
			FText amount = FText::AsNumber(ingredient.amount);
			listItem->SetItemFields(name, amount);
			listItem->SetMenu(this);
			Crafting_IngredientList->AddChildToVerticalBox(listItem);

		}

		Crafting_Border_IngredientList->SetVisibility(ESlateVisibility::Visible);
		Crafting_Border_Craft->SetVisibility(ESlateVisibility::Visible);
		Crafting_Border_Description->SetVisibility(ESlateVisibility::Visible);
	}

}

void UMenuWidget::Craft()
{
	if (SelectedCraft)
	{

		UCraftableComponent* CraftingComp = SelectedCraft->GetComponent<UCraftableComponent>();
		TArray<FCraftingMaterial> ingredients = CraftingComp->GetMaterials();

		UInventory* inventory = GetGameInstance()->GetSubsystem<UPartyManager>()->GetInventory();
		bool bHasIngredients = true;
		for (FCraftingMaterial ingredient : ingredients)
		{
			bHasIngredients = inventory->CheckIfHasItem(ingredient.name, ingredient.amount);
			if (!bHasIngredients)
			{
				return;
			}
		}
		for (FCraftingMaterial ingredient : ingredients)
		{
			inventory->RemoveItem(ingredient.name, ingredient.amount);
		}
		//Currently only creates 1 of the item, expand later to possibly craft more than 1 item
		inventory->AddItem(SelectedCraft->GetItemName(), 1);

		FString createdText = "1 " + SelectedCraft->GetItemName() + " has been created.";
		Crafting_Text_ItemCreated->SetText(FText::FromString(createdText));
		Crafting_Border_Created->SetVisibility(ESlateVisibility::Visible);
	}
}

/**********************************************************
			Status Functions
**********************************************************/

void UMenuWidget::SetStatusPanels()
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();

	//Set Default
	if (Party.Num() > 0)
	{
		ChangeCurrentStatus(0);
	}	
}

void UMenuWidget::SetStatusButtonImages()
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();
	if (Party.Num() >= 1)
	{
		Status_Button_Character_1->SetVisibility(ESlateVisibility::Visible);
		Status_Image_Character_1->SetBrushFromTexture(Party[0]->GetCharacterFaceImage());
	}
	else
	{
		Status_Button_Character_1->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 2)
	{
		Status_Button_Character_2->SetVisibility(ESlateVisibility::Visible);
		Status_Image_Character_2->SetBrushFromTexture(Party[1]->GetCharacterFaceImage());
	}
	else
	{
		Status_Button_Character_2->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 3)
	{
		Status_Button_Character_3->SetVisibility(ESlateVisibility::Visible);
		Status_Image_Character_3->SetBrushFromTexture(Party[2]->GetCharacterFaceImage());
	}
	else
	{
		Status_Button_Character_3->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Party.Num() >= 4)
	{
		Status_Button_Character_4->SetVisibility(ESlateVisibility::Visible);
		Status_Image_Character_4->SetBrushFromTexture(Party[3]->GetCharacterFaceImage());
	}
	else
	{
		Status_Button_Character_4->SetVisibility(ESlateVisibility::Collapsed);
	}

}

// Changing Displayed Status
void UMenuWidget::ChangeCurrentStatusToFirst()	{	ChangeCurrentStatus(0); }
void UMenuWidget::ChangeCurrentStatusToSecond()	{	ChangeCurrentStatus(1); }
void UMenuWidget::ChangeCurrentStatusToThird()	{	ChangeCurrentStatus(2); }
void UMenuWidget::ChangeCurrentStatusToFourth()	{	ChangeCurrentStatus(3); }

void UMenuWidget::ChangeCurrentStatus(int num)
{
	UPartyManager* PartyManager = GetGameInstance()->GetSubsystem<UPartyManager>();
	TArray<UCharacterData*> Party = PartyManager->GetCurrentPartyMembers();

	Image_CharacterBody->SetBrushFromTexture(Party[num]->GetCharacterBodyImage());
	Text_Status_Bio->SetText(FText::FromString(Party[num]->GetCharacterDescription()));
	Text_Status_Name->SetText(FText::FromString(Party[num]->GetCharacterName()));

	FString hpNumbers
		= FString::FromInt(Party[num]->GetCharacterStats()->GetStat("currentHP"))
		+ FString(" / ")
		+ FString::FromInt(Party[num]->GetCharacterStats()->GetStat("maxHP"));
	Text_Status_Character_HP->SetText(FText::FromString(hpNumbers));
	FString spNumbers
		= FString::FromInt(Party[num]->GetCharacterStats()->GetStat("currentSP"))
		+ FString(" / ")
		+ FString::FromInt(Party[num]->GetCharacterStats()->GetStat("maxSP"));
	Text_Status_Character_SP->SetText(FText::FromString(spNumbers));
	FString gaugeNumbers
		= FString::FromInt(Party[num]->GetCharacterStats()->GetStat("currentGauge"))
		+ FString(" / ")
		+ FString::FromInt(Party[num]->GetCharacterStats()->GetStat("maxGauge"));
	Text_Status_Character_GAUGE->SetText(FText::FromString(gaugeNumbers));

	Text_Status_Character_MOVE->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Movement")));
	Text_Status_Character_STR->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Strength")));
	Text_Status_Character_MAG->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Magic")));
	Text_Status_Character_DEF->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Defense")));
	Text_Status_Character_RES->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Resilience")));
	Text_Status_Character_AGI->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Agility")));
	Text_Status_Character_LUCK->SetText(FText::AsNumber(Party[num]->GetCharacterStats()->GetStat("Luck")));

	Text_Status_Character_LVL->SetText(FText::AsNumber(Party[num]->GetLevel()));
	
	Text_Status_Character_WPN->SetText(FText::FromString(Party[num]->GetWeapon()));
	Text_Status_Character_ACC1->SetText(FText::FromString(Party[num]->GetFirstAccessory()));
	Text_Status_Character_ACC2->SetText(FText::FromString(Party[num]->GetSecondAccessory()));

}

/**********************************************************
			QuestLog Functions
**********************************************************/



/**********************************************************
			Bestiary Functions
**********************************************************/



/**********************************************************
			Skills Functions
**********************************************************/



