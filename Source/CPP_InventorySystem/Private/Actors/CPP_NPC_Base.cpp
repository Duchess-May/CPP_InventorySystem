// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_NPC_Base.h"

// Sets default values
ACPP_NPC_Base::ACPP_NPC_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_NPC_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_NPC_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_NPC_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

