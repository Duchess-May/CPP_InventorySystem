// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_CharacterBase.h"
#include "Engine/DataTable.h"

ACPP_CharacterBase::ACPP_CharacterBase()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Inventory
	InventorySpaces = 100;
	InitialiseEquipmentSlots();
}

void ACPP_CharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool ACPP_CharacterBase::InventoryAddItem(const FS_Slots& ItemInfo)
{
	bool bSuccess = false;

	// Check for stacking or add a new slot for the item
	int32 ItemIndex = 0;
	int32 ExistingAmount = 0;
	bool bFoundStack = InventoryFindStack(ItemInfo.Item.RowName, ItemInfo.Amount, ItemIndex, ExistingAmount);

	if (bFoundStack)
	{
		bSuccess = InventoryAddItemToSlot(ItemInfo, ItemIndex);
	}
	else
	{
		//bool bFoundEmptySlot = InventoryFindEmptySlot(ItemIndex);
		//if (bFoundEmptySlot)
		//{
		//	bSuccess = InventoryAddItemToSlot(ItemInfo, ItemIndex);
		//}
		bSuccess = InventoryCreateSlot(ItemInfo);
	}

	return bSuccess;
}

bool ACPP_CharacterBase::InventoryFindStack(const FName RowName, const int32 Amount, int32& OutIndex, int32& OutAmount)
{
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i].Item.RowName == RowName)
		{
			OutIndex = i; // found the index of the item in the array
			OutAmount = Inventory[i].Amount; // found how many
			return true;
		}
	}

	OutIndex = -1;
	OutAmount = 0;
	return false; // stack not found
}

bool ACPP_CharacterBase::InventoryAddItemToSlot(const FS_Slots ItemInfo, const int32 Index)
{
	bool bSuccess = false;

	if (Inventory[Index].Item.RowName == "Empty")
	{
		Inventory[Index].Item = ItemInfo.Item;
		Inventory[Index].Amount = ItemInfo.Amount;

		bSuccess = true;
	}
	else
	{
		bool bCanStack = ItemInfo.Item.DataTable->FindRow<FS_Inventory>(ItemInfo.Item.RowName, TEXT("Context String"))->CanStack;
		if (bCanStack)
		{
			if (Inventory[Index].Item.RowName == ItemInfo.Item.RowName)
			{
				Inventory[Index].Amount += ItemInfo.Amount;

				bSuccess = true;
			}
		}
	}

	return bSuccess;
}

bool ACPP_CharacterBase::InventoryRemoveAmountAtIndex(const int32 Index, const int32 Amount)
{
	// First, check if the index is valid to prevent out-of-bounds errors
	if (Index >= 0 && Index < Inventory.Num())
	{
		// Ensure there is something to remove and the amount isn't negative
		if (Inventory[Index].Amount > 0 && Amount > 0)
		{
			Inventory[Index].Amount -= Amount;
			// Remove if empty
			if (Inventory[Index].Amount <= 0)
			{
				Inventory.RemoveAt(Index);
			}
			return true;
		}
	}
	return false; // Nothing to remove or bad index
}

bool ACPP_CharacterBase::InventoryRemoveItemAtIndex(const int32 Index)
{
	// Check if the index is valid
	if (Index >= 0 && Index < Inventory.Num())
	{
		// Optionally, you might want to check if the item at the index is valid or not
		// This depends on what 'valid' means in your context
		// For example, check if the Amount is more than 0 or any other validity condition
		if (Inventory[Index].Amount > 0) // Assuming 'valid' means Amount > 0
		{
			Inventory.RemoveAt(Index);
			return true;
		}
	}
	return false; // Invalid index or not a valid item
}

bool ACPP_CharacterBase::InventoryCreateSlot(const FS_Slots ItemData)
{
	// Check if there's space in the inventory
	if (Inventory.Num() < InventorySpaces)
	{
		int32 OutIndex = -1;
		// Try to find an empty slot
		if (InventoryFindEmptySlot(OutIndex) && OutIndex != -1)
		{
			Inventory[OutIndex] = ItemData; // Set the item in the found empty slot
			return true;
		}
		else
		{
			// If no empty slot is found, add the item at the end of the list
			Inventory.Add(ItemData);
			return true;
		}
	}
	return false; // No space in the inventory
}

bool ACPP_CharacterBase::InventoryFindEmptySlot(int32& OutIndex)
{
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		bool bFoundEmptySlot = Inventory[i].Item.RowName == "Empty";
		if (bFoundEmptySlot)
		{
			OutIndex = i;
			return true;
		}
	}

	OutIndex = -1;
	return false;
}

bool ACPP_CharacterBase::EquipItem(int32 InventoryIndex, FS_Inventory InventoryData)
{
	int32 invindex = InventoryIndex;

	UDataTable* EquipmentDataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, TEXT("DataTable'/Game/Blueprints/Inventory/DT_Inventory.DT_Inventory'")));

	if (EquipmentDataTable)
	{
		int32 EquipmentIndex = GetEquipmentIndex(InventoryData.SlotType, InventoryData.AccessoryType);
		if ((invindex < 0 || invindex >= Inventory.Num()) && EquipmentIndex != -1)
			return false; // Invalid indices

		// Retrieve the item from the inventory
		FS_Slots InventoryItem = Inventory[invindex];

		// If accessory, then validate
		if (InventoryData.SlotType == ESlotType::Accessory)
		{
			if (Equipment[EquipmentIndex].SlotType != InventoryItem.SlotType ||
				(Equipment[EquipmentIndex].SlotType == ESlotType::Accessory &&
					Equipment[EquipmentIndex].AccessoryType != InventoryItem.AccessoryType))
			{
				return false; // Type mismatch
			}
		}

		// Swap the items
		FS_Slots Temp = Equipment[EquipmentIndex];

		Equipment[EquipmentIndex] = InventoryItem;
		//Equipment[EquipmentIndex].SlotType = InventoryItem.SlotType;
		Equipment[EquipmentIndex].WeaponType = InventoryItem.WeaponType;
		//Equipment[EquipmentIndex].AccessoryType = InventoryItem.AccessoryType;
		Equipment[EquipmentIndex].Amount = 1;
		Equipment[EquipmentIndex].Item.DataTable = EquipmentDataTable;

		if (Temp.SlotType != ESlotType::Empty)
		{
			Inventory[invindex] = Temp;
		}

		return true;
	}
	return false;
}

void ACPP_CharacterBase::RemoveItemFromEquipment(int32 EquipmentIndex)
{
	if (EquipmentIndex < 0 || EquipmentIndex >= Equipment.Num())
		return; // Invalid index

	// Move the item from the equipment slot back to the inventory
	InventoryAddItem(Equipment[EquipmentIndex]);

	// Reset the slot while keeping the type constraints
	FS_Slots EmptySlot;
	EmptySlot.Item.RowName = "Empty";
	EmptySlot.Amount = 0;
	EmptySlot.SlotType = Equipment[EquipmentIndex].SlotType;
	EmptySlot.AccessoryType = Equipment[EquipmentIndex].AccessoryType;
	Equipment[EquipmentIndex] = EmptySlot;
}

void ACPP_CharacterBase::InitialiseEquipmentSlots()
{
	Equipment.SetNum(8); // Configure Equipment Size
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableFinder(TEXT("DataTable'/Game/Blueprints/Inventory/DT_Inventory.DT_Inventory'"));
	UDataTable* EquipmentDataTable = DataTableFinder.Object;

	if (DataTableFinder.Succeeded())
	{
		for (int32 i = 0; i < Equipment.Num(); i++)
		{
			Equipment[i].Amount = 0;
			Equipment[i].Item.DataTable = EquipmentDataTable;
		}

		// Initialize each slot with the appropriate type
		Equipment[0].SlotType = ESlotType::Weapon; Equipment[0].WeaponType = EWeaponType::Bare;
		Equipment[1].SlotType = ESlotType::Armour; 
		Equipment[2].SlotType = ESlotType::Accessory; Equipment[2].AccessoryType = EAccessoryType::Head;
		Equipment[3].SlotType = ESlotType::Accessory; Equipment[3].AccessoryType = EAccessoryType::Arms;
		Equipment[4].SlotType = ESlotType::Accessory; Equipment[4].AccessoryType = EAccessoryType::Waist;
		Equipment[5].SlotType = ESlotType::Accessory; Equipment[5].AccessoryType = EAccessoryType::Shield;
		Equipment[6].SlotType = ESlotType::Accessory; Equipment[6].AccessoryType = EAccessoryType::WeaponAtt;
		Equipment[7].SlotType = ESlotType::Mount; 
	}
	else
	{
		FString message = TEXT("CPP_CharacterBase.cpp --> InitialiseEquipmentSlots.EquipmentDataTable is not valid!");
		UE_LOG(LogTemp, Error, TEXT("%s"), *message);
	}
}

int32 ACPP_CharacterBase::GetEquipmentIndex(ESlotType SlotType, EAccessoryType AccessoryType)
{
	switch (SlotType)
	{
	case ESlotType::Weapon:
		return 0;
	case ESlotType::Armour:
		return 1;
	case ESlotType::Accessory:
		switch (AccessoryType)
		{
		case EAccessoryType::Head:
			return 2;
		case EAccessoryType::Arms:
			return 3;
		case EAccessoryType::Waist:
			return 4;
		case EAccessoryType::Shield:
			return 5;
		case EAccessoryType::WeaponAtt:
			return 6;
		default:
			return -1; // Accessory type not handled
		}
	case ESlotType::Mount:
		return 7;
	default:
		return -1; // Slot type not handled
	}
}
