// 2024 Jilted Valkyrie

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EThisThatElse : uint8
{
	This		UMETA(DisplayName = "This"),
	That		UMETA(DisplayName = "That"),
	Neither		UMETA(DisplayName = "Neither")
};

UENUM(BlueprintType)
enum class EContextButtonAction : uint8
{
	None		UMETA(DisplayName = "None"),
	Sort		UMETA(DisplayName = "Sort"),
	Drop		UMETA(DisplayName = "Drop"),
	Equip		UMETA(DisplayName = "Equip"),
	Unequip		UMETA(DisplayName = "Unequip"),
	Split		UMETA(DisplayName = "Split"),
	OrderUp		UMETA(DisplayName = "Move Up"),
	OrderDown	UMETA(DisplayName = "Move Down"),
	DropConfirm UMETA(DisplayName = "Confirm Drop")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None		 UMETA(DisplayName = "N/A"),
	Bare		 UMETA(DisplayName = "Bare"),
	TwoHanded    UMETA(DisplayName = "Two-Handed"),
	OneHanded    UMETA(DisplayName = "One-Handed"),
	Ranged       UMETA(DisplayName = "Ranged")
};


UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	None		UMETA(DisplayName = "None"),
	Damage		UMETA(DisplayName = "Damage"),
	Buff		UMETA(DisplayName = "Buff"),
	Debuff		UMETA(DisplayName = "Debuff"),
	Heal		UMETA(DisplayName = "Heal")
};

UENUM(BlueprintType)
enum class EConsumableType : uint8
{
	None		UMETA(DisplayName = "None"),
	Health		UMETA(DisplayName = "Health"),
	Energy		UMETA(DisplayName = "Energy"),
	Ammo		UMETA(DisplayName = "Ammo")
};

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Default         UMETA(DisplayName = "00-Default"),
	Weapon          UMETA(DisplayName = "01-Weapon"),
	BodyArmour		UMETA(DisplayName = "02-BodyArmour"),
	HeadAccessory	UMETA(DisplayName = "03-HeadAccessory"),
	ArmAccessory	UMETA(DisplayName = "04-ArmAccessory"),
	WaistAccessory	UMETA(DisplayName = "05-WaistAccessory"),
	ShieldAccessory	UMETA(DisplayName = "06-ShieldAccessory"),
	WeaponAccessory	UMETA(DisplayName = "07-WeaponAccessory"),
	HealthItem      UMETA(DisplayName = "10-HealthItem"),
	EnergyItem      UMETA(DisplayName = "11-EnergyItem"),
	FoodItem        UMETA(DisplayName = "12-FoodItem"),
	MedicineItem    UMETA(DisplayName = "13-MedicineItem"),
	Cloth           UMETA(DisplayName = "14-Cloth"),
	Seed            UMETA(DisplayName = "15-Seed"),
	Root            UMETA(DisplayName = "16-Root"),
	Spice           UMETA(DisplayName = "17-Spice"),
	Liquid          UMETA(DisplayName = "18-Liquid"),
	Hide            UMETA(DisplayName = "19-Hide"),
	Leather         UMETA(DisplayName = "20-Leather"),
	Bone            UMETA(DisplayName = "21-Bone"),
	Fur             UMETA(DisplayName = "22-Fur"),
	Scale           UMETA(DisplayName = "23-Scale"),
	Shell           UMETA(DisplayName = "24-Shell"),
	Log             UMETA(DisplayName = "25-Log"),
	Plank           UMETA(DisplayName = "26-Plank"),
	MetalOre        UMETA(DisplayName = "27-MetalOre"),
	MetalPlate      UMETA(DisplayName = "28-MetalPlate"),
	Gemstone        UMETA(DisplayName = "29-Gemstone"),
	EnchantedGem    UMETA(DisplayName = "30-EnchantedGem"),
	Clay            UMETA(DisplayName = "31-Clay"),
	Ceramic         UMETA(DisplayName = "32-Ceramic"),
	Porcelain       UMETA(DisplayName = "33-Porcelain"),
	Flora           UMETA(DisplayName = "34-Flora"),
	Herbs           UMETA(DisplayName = "35-Herbs"),
	Fungi           UMETA(DisplayName = "36-Fungi"),
	Divine          UMETA(DisplayName = "37-Divine"),
	Magic           UMETA(DisplayName = "38-Magic"),
	Energy          UMETA(DisplayName = "39-Energy"),
	Furniture       UMETA(DisplayName = "40-Furniture"),
	Tool            UMETA(DisplayName = "41-Tool"),
	Essence         UMETA(DisplayName = "42-Essence"),
	Extract         UMETA(DisplayName = "43-Extract"),
	Currency        UMETA(DisplayName = "90-Currency"),
	Mount			UMETA(DisplayName = "91-Mount"),
	Misc            UMETA(DisplayName = "99-Misc")
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Empty		UMETA(DisplayName = "Empty"),
	Consumable	UMETA(DisplayName = "Consumable"),
	Weapon		UMETA(DisplayName = "Weapon"),
	Armour		UMETA(DisplayName = "Armour"),
	Accessory	UMETA(DisplayName = "Accessory")
};

UENUM(BlueprintType)
enum class EAccessoryType : uint8
{
	None		UMETA(DisplayName = "---"),
	Head		UMETA(DisplayName = "Head"),
	Arms		UMETA(DisplayName = "Arms"),
	Waist		UMETA(DisplayName = "Waist"),
	Shield		UMETA(DisplayName = "Shield"),
	WeaponAtt	UMETA(DisplayName = "WeaponAttachment")
};

UENUM(BlueprintType)
enum class ERarity : uint8
{
	Common		UMETA(DisplayName = "0-Common"),
	Rare		UMETA(DisplayName = "1-Rare"),
	VeryRare	UMETA(DisplayName = "2-VeryRare"),
	Epic		UMETA(DisplayName = "3-Epic"),
	Legendary	UMETA(DisplayName = "4-Legendary"),
	Mythic		UMETA(DisplayName = "5-Mythic"),
	Relic		UMETA(DisplayName = "6-Relic")
};

UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
	NotStarted		UMETA(DisplayName = "Not Started"),
	InProgress		UMETA(DisplayName = "In Progress"),
	Completed		UMETA(DisplayName = "Completed"),
	Failed			UMETA(DisplayName = "Failed")
};

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	Main		UMETA(DisplayName = "Main"),
	Side		UMETA(DisplayName = "Side"),
	Event		UMETA(DisplayName = "Event"),
	Other	    UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class ETaskType : uint8
{
	Interact	 UMETA(DisplayName = "Interact"),
	Fetch		 UMETA(DisplayName = "Fetch"),
	Subjugation  UMETA(DisplayName = "Subjugation"),
	Destination  UMETA(DisplayName = "Destination")
};

UENUM(BlueprintType)
enum class ESlotType : uint8
{
	Empty			UMETA(DisplayName = "Empty"),
	Weapon			UMETA(DisplayName = "Weapon"),
	Armour			UMETA(DisplayName = "Armour"),
	Accessory		UMETA(DisplayName = "Accessory"),
	Health			UMETA(DisplayName = "Health"),
	Energy			UMETA(DisplayName = "Energy"),
	KeyItem			UMETA(DisplayName = "Key Item"),
	Material        UMETA(DisplayName = "Material"),
	Mount			UMETA(DisplayName = "Mount")
};


UENUM(BlueprintType)
enum class EItemPanelType : uint8
{
	None			UMETA(DisplayName = "None"),
	InventoryPanel	UMETA(DisplayName = "Inventory Panel"),
	EquipmentPanel	UMETA(DisplayName = "Equipment Panel"),
	KeyItemPanel	UMETA(DisplayName = "Key Item Panel"),
	MountPanel		UMETA(DisplayName = "Mount Panel")
};

UENUM(BlueprintType)
enum class EWidgetType : uint8
{
	Equipment		UMETA(DisplayName = "Equipment"),
	Inventory		UMETA(DisplayName = "Inventory"),
	Consumable		UMETA(DisplayName = "Consumable"),
	Quest			UMETA(DisplayName = "Quest"),
	Shop			UMETA(DisplayName = "Shop"),
	Crafting		UMETA(DisplayName = "Crafting"),
	Talking         UMETA(DisplayName = "Conversation")
};