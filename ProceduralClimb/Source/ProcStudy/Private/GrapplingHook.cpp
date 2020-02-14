// Fill out your copyright notice in the Description page of Project Settings.


#include "GrapplingHook.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGrapplingHook::AGrapplingHook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhyisicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	Hook = CreateDefaultSubobject<USphereComponent>(FName("Hook"));
	SetRootComponent(Hook);
	Hook->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void AGrapplingHook::BeginPlay()
{
	Super::BeginPlay();
	
	ControllingActor = Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn());
	Hook->ResetRelativeTransform();
}

// Called every framea
void AGrapplingHook::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);

	if (!IsValid(ControllingActor))
		return;

	UE_LOG(LogTemp, Warning, TEXT("i'm beeing controlled by: %s"), *ControllingActor->GetName());
	SetupConstraints();
}

void AGrapplingHook::SetupConstraints()
{
	PhyisicsConstraint->SetConstrainedComponents(Hook, NAME_None, ControllingActor->FindComponentByClass<UCapsuleComponent>(), NAME_None);
}

