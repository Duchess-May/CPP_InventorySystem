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
enum class EWeaponType : uint8
{
	TwoHanded    UMETA(DisplayName = "TwoHanded"),
	OneHanded    UMETA(DisplayName = "OneHanded"),
	Ranged       UMETA(DisplayName = "Ranged"),
	Unequipped   UMETA(DisplayName = "Unequipped")
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
	ArmAccessory	UMETA(DisplayName = "03-ArmAccessory"),
	HeadAccessory	UMETA(DisplayName = "04-HeadAccessory"),
	WaistAccessory	UMETA(DisplayName = "05-WaistAccessory"),
	HealthItem      UMETA(DisplayName = "06-HealthItem"),
	EnergyItem      UMETA(DisplayName = "07-EnergyItem"),
	FoodItem        UMETA(DisplayName = "08-FoodItem"),
	MedicineItem    UMETA(DisplayName = "09-MedicineItem"),
	Cloth           UMETA(DisplayName = "10-Cloth"),
	Seed            UMETA(DisplayName = "11-Seed"),
	Root            UMETA(DisplayName = "12-Root"),
	Spice           UMETA(DisplayName = "13-Spice"),
	Liquid          UMETA(DisplayName = "14-Liquid"),
	Hide            UMETA(DisplayName = "15-Hide"),
	Leather         UMETA(DisplayName = "16-Leather"),
	Bone            UMETA(DisplayName = "17-Bone"),
	Fur             UMETA(DisplayName = "18-Fur"),
	Scale           UMETA(DisplayName = "19-Scale"),
	Shell           UMETA(DisplayName = "20-Shell"),
	Log             UMETA(DisplayName = "21-Log"),
	Plank           UMETA(DisplayName = "22-Plank"),
	MetalOre        UMETA(DisplayName = "23-MetalOre"),
	MetalPlate      UMETA(DisplayName = "24-MetalPlate"),
	Gemstone        UMETA(DisplayName = "25-Gemstone"),
	EnchantedGem    UMETA(DisplayName = "26-EnchantedGem"),
	Clay            UMETA(DisplayName = "27-Clay"),
	Ceramic         UMETA(DisplayName = "28-Ceramic"),
	Porcelain       UMETA(DisplayName = "29-Porcelain"),
	Flora           UMETA(DisplayName = "30-Flora"),
	Herbs           UMETA(DisplayName = "31-Herbs"),
	Fungi           UMETA(DisplayName = "32-Fungi"),
	Divine          UMETA(DisplayName = "33-Divine"),
	Magic           UMETA(DisplayName = "34-Magic"),
	Energy          UMETA(DisplayName = "35-Energy"),
	Furniture       UMETA(DisplayName = "36-Furniture"),
	Tool            UMETA(DisplayName = "37-Tool"),
	Essence         UMETA(DisplayName = "38-Essence"),
	Extract         UMETA(DisplayName = "39-Extract"),
	Mount			UMETA(DisplayName = "40-Mount"),
	Currency        UMETA(DisplayName = "90-Currency"),
	Misc            UMETA(DisplayName = "99-Misc")
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Consumable	UMETA(DisplayName = "Consumable"),
	Weapon		UMETA(DisplayName = "Weapon"),
	Armour		UMETA(DisplayName = "Armour"),
	Accessory	UMETA(DisplayName = "Accessory")
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
enum class EWidgetType : uint8
{
	Inventory		UMETA(DisplayName = "Inventory"),
	Quest			UMETA(DisplayName = "Quest"),
	Shop			UMETA(DisplayName = "Shop"),
	Crafting		UMETA(DisplayName = "Crafting"),
	Talking         UMETA(DisplayName = "Conversation")
};