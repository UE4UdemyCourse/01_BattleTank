// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

private:
	
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot will hit where 
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	
	// return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;

};
