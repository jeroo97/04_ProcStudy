// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"

void AMyPlayerController::Tick(float DeltaTime)
{

}

void AMyPlayerController::RayCast(FVector& HitLocation)
{
	FHitResult HitResult;
	auto ForwardVector = GetPawn()->FindComponentByClass<UCameraComponent>()->GetForwardVector();
	auto StartLocation = GetPawn()->GetActorLocation();
	auto EndLocation = StartLocation + (ForwardVector * LineTraceRange);

	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, false, 1, 0, 1);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetPawn());
	GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility, // ECC_Camera for the UI bug.
		QueryParams
	);
	HitLocation = HitResult.Location;
}
