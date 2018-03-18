// Copyright John Stimson
#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * Responsible for driving the tank tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForeward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveTurnRight(float Throw);

private:
	// call from pathfinding logic to move tank 
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
};
