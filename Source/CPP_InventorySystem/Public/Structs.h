// 2024 Jilted Valkyrie

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "Structs.generated.h"

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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Type", MakeStructureDefaultValue = "Empty"))
	ESlotType Type;
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Damage", MakeStructureDefaultValue = "0.000000"))
	double Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Haste", MakeStructureDefaultValue = "0.000000"))
	double Haste;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Creds", MakeStructureDefaultValue = "0"))
	int32 Creds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "EXP", MakeStructureDefaultValue = "0"))
	int32 EXP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Level", MakeStructureDefaultValue = "1"))
	int32 Level;
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Type"))
	ESlotType Type;
};



USTRUCT(BlueprintType)
struct FS_Inventory
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Name"))
	FString Name;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Desc"))
	FString Desc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Type", MakeStructureDefaultValue = "Empty"))
	ESlotType Type;
	
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
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ActorClass", MakeStructureDefaultValue = "None"))
	TObjectPtr<UClass> ActorClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ExtraSlots", MakeStructureDefaultValue = "0"))
	int32 ExtraSlots;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Value", MakeStructureDefaultValue = "0"))
	int32 Value;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ConsumableInfo", MakeStructureDefaultValue = "(ConsumableType_12_F6F322D647DCD870CB7788AB11AB2BF9=None,HealAmount_6_935B5309415216AB43D47E8EAB0EEB91=0,EnergyAmount_7_AB0076DB462C8E5C78911A9488356913=0,AmmoAmount_8_4DABA39745A46FC4C0FA58B5C018BA33=0)"))
	FS_Consumable ConsumableInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Stats", MakeStructureDefaultValue = "(HP_2_3A8FE891429CA790DFA14797A1553A22=1.000000,EP_4_12214B5E42B00A23EF2ECDAC7F9871FB=1.000000,Damage_6_DC374940481959B33E241A88D4313818=1.000000,Haste_23_35EE1CFA405776330C5D398EA16CB61A=1.000000,Creds_19_7F0063A445E558E2DC1A8DB33865D7B9=0,EXP_17_005AB723423D69566FD8C6BBF28878E0=0,Level_21_6022F55D4E6669C69BBD0F8F1BC3A79E=1)"))
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemStats", MakeStructureDefaultValue = "(HP_2_3A8FE891429CA790DFA14797A1553A22=0.000000,EP_4_12214B5E42B00A23EF2ECDAC7F9871FB=0.000000,Damage_6_DC374940481959B33E241A88D4313818=0.000000,Haste_23_35EE1CFA405776330C5D398EA16CB61A=0.000000,Creds_19_7F0063A445E558E2DC1A8DB33865D7B9=0,EXP_17_005AB723423D69566FD8C6BBF28878E0=0,Level_21_6022F55D4E6669C69BBD0F8F1BC3A79E=0)"))
	FS_Stats ItemStats;
};
