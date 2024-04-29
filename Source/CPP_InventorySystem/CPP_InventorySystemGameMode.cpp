// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_InventorySystemGameMode.h"
#include "CPP_InventorySystemPlayerController.h"
#include "CPP_InventorySystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPP_InventorySystemGameMode::ACPP_InventorySystemGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACPP_InventorySystemPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}