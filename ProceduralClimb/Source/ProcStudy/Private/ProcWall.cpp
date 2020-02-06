// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcWall.h"
#include "..\Public\ProcWall.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AProcWall::AProcWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProcWall = CreateDefaultSubobject<UInstancedStaticMeshComponent>(FName(TEXT("ProcWall")));

}

// Called when the game starts or when spawned
void AProcWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProcWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProcWall::CreateWall()
{
	for (int i = 0; i < NumberMeshesX; i++)
	{
		FVector WallPosition = FVector(i * MeshLength, 0, 0);
		FRotator RotationProc = FRotator(0, 0, 0);
		FVector ScaleProc = FVector(1, 1, 1);
		FTransform WallLocation = FTransform(RotationProc, WallPosition, ScaleProc);
		ProcWall->AddInstance(WallLocation);
	}
}

