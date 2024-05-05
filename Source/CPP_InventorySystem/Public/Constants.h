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
};