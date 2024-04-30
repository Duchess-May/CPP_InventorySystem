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
		bool bFoundEmptySlot = InventoryFindEmptySlot(ItemIndex);
		if (bFoundEmptySlot)
		{
			bSuccess = InventoryAddItemToSlot(ItemInfo, ItemIndex);
		}
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
