// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_ItemBase.h"

// Sets default values
ACPP_ItemBase::ACPP_ItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Item Data Variables
	bIsEquipped = false;

	ItemType = EItemType::Consumable;
	Rarity = ERarity::Common;
	SlotType = ESlotType::Material;

	Stats.HP = 0;
	Stats.EP = 0;
	Stats.STR = 0;
	Stats.VIT = 0;
	Stats.DEX = 0;
	Stats.HST = 0;
	Stats.EXP = 0;
	Stats.Level = 0;

	LevelRequirement = 0;

}

// Called when the game starts or when spawned
void ACPP_ItemBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_ItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACPP_ItemBase::SetVariablesFromData(UDataTable* DataTable)
{
	if (RowName != "")
	{
		if (DataTable)
		{
			Rarity = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Rarity;
			SlotType = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->SlotType;

			Stats.HP = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.HP;
			Stats.EP = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.EP;
			Stats.STR = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.STR;
			Stats.VIT = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.VIT;
			Stats.DEX = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.DEX;
			Stats.HST = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.HST;
			Stats.EXP = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.EXP;

			LevelRequirement = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->Stats.Level;
			SellValue = DataTable->FindRow<FS_Inventory>(RowName, TEXT("Context String"))->SellValue;
		}
	}
	else
	{
		FString message = TEXT("DataTable is not valid!");
		UE_LOG(LogTemp, Error, TEXT("%s"), *message);
	}
}
