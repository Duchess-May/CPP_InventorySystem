// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_CharacterBase.h"
#include "CPP_NPC_Base.generated.h"

UCLASS()
class CPP_INVENTORYSYSTEM_API ACPP_NPC_Base : public ACPP_CharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_NPC_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
