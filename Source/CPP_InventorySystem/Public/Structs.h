// 2024 Jilted Valkyrie

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "Structs.generated.h"

// Forward declarations
class ACPP_ItemBase;

/** Item Category */
USTRUCT(BlueprintType)
struct FS_Category
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Category"))
	EItemCategory Category;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Description"))
	FText Description;
};


USTRUCT(BlueprintType)
struct FS_Levels
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Level", MakeStructureDefaultValue = "1"))
	int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EXP", MakeStructureDefaultValue = "0"))
	int32 EXP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "AddedDamage", MakeStructureDefaultValue = "0.000000"))
	double AddedDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "AddedHP", MakeStructureDefaultValue = "0.000000"))
	double AddedHP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "AddedEP", MakeStructureDefaultValue = "0.000000"))
	double AddedEP;
};


USTRUCT(BlueprintType)
struct FS_QuestHandle
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "QuestDT", MakeStructureDefaultValue = ""))
	FDataTableRowHandle QuestDT;
};


USTRUCT(BlueprintType)
struct FS_Slots
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Item", MakeStructureDefaultValue = ""))
	FDataTableRowHandle Item;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Amount", MakeStructureDefaultValue = "0"))
	int32 Amount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "SortingType_Slot", MakeStructureDefaultValue = "Empty"))
	ESlotType SlotType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "SortingType_Weapon"))
	EWeaponType WeaponType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "SortingType_Accessory"))
	EAccessoryType AccessoryType;
};


USTRUCT(BlueprintType)
struct FS_Rewards
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Creds", MakeStructureDefaultValue = "0"))
	int32 Creds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EXP", MakeStructureDefaultValue = "0"))
	int32 EXP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Loot", MakeStructureDefaultValue = "(())"))
	TArray<FS_Slots> Loot;
};


USTRUCT(BlueprintType)
struct FS_Stats
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "HP", MakeStructureDefaultValue = "0.000000"))
	double HP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EP", MakeStructureDefaultValue = "0.000000"))
	double EP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "STR", MakeStructureDefaultValue = "0.000000"))
	double STR;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "VIT", MakeStructureDefaultValue = "0.000000"))
	double VIT;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "DEX", MakeStructureDefaultValue = "0.000000"))
	double DEX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "HST", MakeStructureDefaultValue = "0.000000"))
	double HST;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EXP", MakeStructureDefaultValue = "0"))
	int32 EXP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "LVL", MakeStructureDefaultValue = "1"))
	int32 Level;
};


USTRUCT(BlueprintType)
struct FS_Currencies
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Creds", MakeStructureDefaultValue = "0"))
	int32 Creds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Tomes", MakeStructureDefaultValue = "0"))
	int32 Tomes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Ancient Coins", MakeStructureDefaultValue = "0"))
	int32 ACoins;

};


USTRUCT(BlueprintType)
struct FS_Task
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ID", MakeStructureDefaultValue = "task_"))
	FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Type", MakeStructureDefaultValue = "Interact"))
	ETaskType Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Name", MakeStructureDefaultValue = "Facilisis leo vel"))
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Description", MakeStructureDefaultValue = "Nec ultrices dui sapien eget mi. Facilisis leo vel fringilla est ullamcorper eget. Convallis posuere morbi leo urna molestie at elementum eu."))
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ActorToSpawn"))
	TArray<UClass*> ActorToSpawn;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (DisplayName = "SpawnPoint", MakeStructureDefaultValue = "None"))
	TObjectPtr<AActor> SpawnPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ObjectiveStatus"))
	EQuestStatus ObjectiveStatus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "MapAllowedActive"))
	FString MapAllowedActive;
};


USTRUCT(BlueprintType)
struct FS_Consumable
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ConsumableType"))
	EConsumableType ConsumableType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "HealAmount", MakeStructureDefaultValue = "0"))
	int32 HealAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EnergyAmount", MakeStructureDefaultValue = "0"))
	int32 EnergyAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "AmmoAmount", MakeStructureDefaultValue = "0"))
	int32 AmmoAmount;
};


USTRUCT(BlueprintType)
struct FS_Equipment
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (DisplayName = "Actor", MakeStructureDefaultValue = "None"))
	TObjectPtr<AActor> Actor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "SlotType"))
	ESlotType SlotType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "WeaponType"))
	EWeaponType WeaponType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "AccessoryType"))
	EAccessoryType AccessoryType;
};



USTRUCT(BlueprintType)
struct FS_Inventory : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Name"))
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Desc"))
	FString Desc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "SlotType", MakeStructureDefaultValue = "Empty"))
	ESlotType SlotType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EquipmentInfo"))
	FS_Equipment EquipmentInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Category", MakeStructureDefaultValue = "Default"))
	EItemCategory Category;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Rarity", MakeStructureDefaultValue = "Common"))
	ERarity Rarity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Icon", MakeStructureDefaultValue = "None"))
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Mesh", MakeStructureDefaultValue = "None"))
	TObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "CanStack", MakeStructureDefaultValue = "False"))
	bool CanStack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "CanCraft", MakeStructureDefaultValue = "False"))
	bool CanCraft;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Recipe"))
	TArray<FS_Slots> Recipe;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "OutCraftAmount", MakeStructureDefaultValue = "0"))
	int32 OutCraftAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ActorClass", AllowedClasses = "CPP_ItemBase"))
	TSubclassOf<ACPP_ItemBase> ActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ExtraSlots", MakeStructureDefaultValue = "0"))
	int32 ExtraSlots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Value", MakeStructureDefaultValue = "0"))
	int32 SellValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ConsumableInfo"))
	FS_Consumable ConsumableInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Stats"))
	FS_Stats Stats;
};


USTRUCT(BlueprintType)
struct FS_Items
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemClass"))
	TObjectPtr<UClass> ItemClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemIcon", MakeStructureDefaultValue = "None"))
	TObjectPtr<UTexture2D> ItemIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemName"))
	FString ItemName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Description"))
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemType", MakeStructureDefaultValue = "Consumable"))
	EItemType ItemType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Rarity", MakeStructureDefaultValue = "Common"))
	ERarity Rarity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemStats"))
	FS_Stats ItemStats;
};
