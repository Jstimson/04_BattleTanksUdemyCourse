// Copyright John Stimson
#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"



UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Sets default values for this pawn's properties
	ATank();
};
