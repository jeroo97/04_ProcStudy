// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROCSTUDY_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = -5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = -5;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	void RayCast(FVector& HitLocation);
};
