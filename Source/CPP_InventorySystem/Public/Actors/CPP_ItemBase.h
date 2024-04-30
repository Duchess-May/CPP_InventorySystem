// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "Actors/CPP_CharacterBase.h"
#include "Structs.h"
#include "Engine/World.h"
#include "CPP_ItemBase.generated.h"

UCLASS()
class CPP_INVENTORYSYSTEM_API ACPP_ItemBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_ItemBase();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetVariablesFromData(UDataTable* DataTable);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data", meta = (ExposeOnSpawn = "true"))
	FS_Slots ItemInfo;

	//UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default", meta = (ExposeOnSpawn = "true"))
	FName RowName;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default", meta = (MultiLine = "true"))
	EItemType ItemType;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	FString ItemName;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	FString Description;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UTexture2D> ItemIcon;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	ERarity Rarity;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	TObjectPtr<UClass> ItemClass;

	//UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Default", meta = (ExposeOnSpawn = "true"))
	TObjectPtr<ACharacter> ItemOwner;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	bool bIsEquipped;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	ESlotType SlotType;

	//UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default", meta = (ExposeOnSpawn = "true"))
	FS_Stats Stats;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Limits")
	int32 LevelRequirement;

	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Limits")
	int32 SellValue;

};
