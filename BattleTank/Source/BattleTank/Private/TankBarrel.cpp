// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel is elevating at %f Degrees pre second"), RelativeSpeed);
	//elevate barrel towards hit location
}

