// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProcWall.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class PROCSTUDY_API AProcWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void CreateWall();

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	UInstancedStaticMeshComponent* ProcWall = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Setup")
	int NumberMeshesX = 0;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MeshLength = 400;
};
