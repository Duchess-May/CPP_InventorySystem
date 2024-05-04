// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Structs.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "CPP_CharacterBase.generated.h"

/**
 *
 */
UCLASS()
class CPP_INVENTORYSYSTEM_API ACPP_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACPP_CharacterBase();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }


	// Inventory Functions
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InventoryAddItem(const FS_Slots& ItemInfo, bool bIgnoreStack);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InventoryFindStack(const FName RowName, const int32 Amount, int32& OutIndex, int32& OutAmount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InventoryAddItemToSlot(const FS_Slots ItemData, const int32 Index);

	/* Remove a specified amount of stacked items (or single) at inventory array index */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InventoryRemoveAmountAtIndex(const FName RowName, const int32 Index, const int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InventoryRemoveItemAtIndex(const FName RowName, const int32 Index);

	UFUNCTION(BlueprintCallable, Category = "inventory")
	bool InventoryCreateSlot(const FS_Slots ItemData);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InventoryFindEmptySlot(int32& OutIndex);

	// Equipment

	UFUNCTION(BlueprintCallable, Category = "Inventory|Equipment")
	bool EquipItem(int32 InventoryIndex, FS_Inventory InventoryData);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Equipment")
	void RemoveItemFromEquipment(int32 EquipmentIndex, EItemPanelType ReturnPanel);

	// Key Items

	UFUNCTION(BlueprintCallable, Category = "Inventory|Key Items")
	bool AddToKeyItems(const FS_Slots& ItemInfo);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Key Items")
	void RemoveItemFromKeyItems(int32 KeyItemIndex);

	// Mounts

	UFUNCTION(BlueprintCallable, Category = "Inventory|Key Items")
	bool UnequipMount(const FS_Slots& ItemInfo);


	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 InventorySpaces;

	int32 EquipmentSlots;

protected:

	/* Change to VisibleAnywhere, BlueprintReadOnly when done testing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<FS_Slots> Equipment;

	/* Change to VisibleAnywhere, BlueprintReadOnly when done testing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<FS_Slots> Inventory;

	/* Change to VisibleAnywhere, BlueprintReadOnly when done testing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<FS_Slots> KeyItems;

	/* Change to VisibleAnywhere, BlueprintReadOnly when done testing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<FS_Slots> Mounts;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	void InitialiseEquipmentSlot(int32 SlotNumber);

	int32 GetEquipmentIndex(ESlotType SlotType, EAccessoryType AccessoryType);
};
