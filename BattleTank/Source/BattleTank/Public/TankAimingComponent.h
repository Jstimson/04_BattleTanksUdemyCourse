// Copyright John Stimson

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enums for tank aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Fireing")
	void Fire();

	void AimAt(FVector HitLocation);

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // sensible projectile speed

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float RelodTimeInSeconds = 3;
		
	double LastFireTime = 0;
};
