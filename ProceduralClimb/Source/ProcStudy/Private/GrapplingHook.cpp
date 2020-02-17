// Fill out your copyright notice in the Description page of Project Settings.


#include "GrapplingHook.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGrapplingHook::AGrapplingHook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhyisicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));

	Hook = CreateDefaultSubobject<UStaticMeshComponent>(FName("Hook"));
	SetRootComponent(Hook);

	ActorAttach = CreateDefaultSubobject<UStaticMeshComponent>(FName("ActorAttach"));
	ActorAttach->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void AGrapplingHook::BeginPlay()
{
	Super::BeginPlay();
	
	ControllingActor = Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn());

	SetupConstraints();
}

// Called every frame
void AGrapplingHook::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);

}

void AGrapplingHook::SetupConstraints()
{
	PhyisicsConstraint->SetConstrainedComponents(Hook, NAME_None, ActorAttach, NAME_None);
}

