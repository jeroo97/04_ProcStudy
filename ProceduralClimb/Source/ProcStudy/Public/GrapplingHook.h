// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrapplingHook.generated.h"

class UPhysicsConstraintComponent;
class UStaticMeshComponent;

UCLASS()
class PROCSTUDY_API AGrapplingHook : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrapplingHook();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Setup")
	UPhysicsConstraintComponent* PhyisicsConstraint = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	UStaticMeshComponent* Hook = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	UStaticMeshComponent* ActorAttach = nullptr;

	AActor* ControllingActor = nullptr;

	void SetupConstraints();

};
