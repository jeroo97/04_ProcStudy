// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcFloor.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AProcFloor::AProcFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProcFloor = CreateDefaultSubobject<UInstancedStaticMeshComponent>(FName(TEXT("Floor")));
	
}

// Called when the game starts or when spawned
void AProcFloor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProcFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProcFloor::CreateFloor() 
{
	for (int iX = 0; iX < NumberMeshesX - 1; iX++)
	{
		for (int iY = 0; iY < NumberMeshesY - 1; iY++)
		{
			FVector FloorPositionLocation = FVector(MeshWidth * iX, MeshLength * iY, 0.f);
			FRotator RotationProc = FRotator(0, 0, 0);
			FVector ScaleProc = FVector(1, 1, 1);
			FTransform FloorLocation = FTransform(RotationProc, FloorPositionLocation, ScaleProc);
			ProcFloor->AddInstance(FloorLocation);
		}
	}
}