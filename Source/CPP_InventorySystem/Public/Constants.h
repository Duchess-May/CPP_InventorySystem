// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>

/**
 * 
 */
class CPP_INVENTORYSYSTEM_API Constants
{
public:
    // Static constant for Inventory Data Table name for Data Table StaticLoadObject lookup
    static constexpr const TCHAR* InventoryDataTableLocation = TEXT("(/Game/Data/CDT_Inventory.CDT_Inventory)");

    /* Usage: UDataTable* InventoryDataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, Constants::InventoryDataTableForStaticLoad)); */
    static constexpr const TCHAR* InventoryDataTableForStaticLoad = TEXT("DataTable'/Game/Data/CDT_Inventory.CDT_Inventory'");

    // Static constant for Inventory Data Table name for Struct Default
    static constexpr const char* InventoryDataTableForStruct = "(DataTable=\"/Script/Engine.DataTable'/Game/Data/CDT_Iventory.CDT_Inventory'\",RowName=\"Empty\")";

    // Inventory Equipment Slot Reservations
	static constexpr const int32 Slot_Weapon = 0;
	static constexpr const int32 Slot_Shield = 1;
	static constexpr const int32 Slot_Armour = 2;
	static constexpr const int32 Slot_Head = 3;
	static constexpr const int32 Slot_Arms = 4;
	static constexpr const int32 Slot_Ring = 5;
	static constexpr const int32 Slot_Waist = 6;
	static constexpr const int32 Slot_Attachment = 7;
	static constexpr const int32 Slot_Mount = 8;
};