// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	//auto Elevation = FMath::Clamp<float>(RawNewElevation, MinDegreesOfElevation, MaxDegreesOfElevation);
	SetRelativeRotation(FRotator(0, Rotation, 0));
	
}


