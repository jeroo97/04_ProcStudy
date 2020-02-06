// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProcFloor.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class PROCSTUDY_API AProcFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void CreateFloor();

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	UInstancedStaticMeshComponent* ProcFloor = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Setup")
	int NumberMeshesX = 1;

	UPROPERTY(EditAnywhere, Category = "Setup")
	int NumberMeshesY = 1;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MeshWidth = 400;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MeshLength = 400;
};
