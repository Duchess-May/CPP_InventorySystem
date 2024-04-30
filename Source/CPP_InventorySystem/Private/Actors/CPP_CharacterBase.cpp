// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_CharacterBase.h"

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
