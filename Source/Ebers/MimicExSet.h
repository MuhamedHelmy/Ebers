// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MimicExSet.generated.h"

UCLASS()
class EBERS_API AMimicExSet : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<AWallActor>> SpawnActors;
	UPROPERTY(EditAnywhere)
		float wavesnum = 5;
	UPROPERTY(EditAnywhere)
		FVector Spawnpos;
	UPROPERTY(EditAnywhere)
		FRotator Spawnrotation;
	UPROPERTY(EditAnywhere)
		float speed = 5;
	UPROPERTY(EditAnywhere)
		float distance = 100;

	UPROPERTY(EditAnywhere)
		float timebetweenSpawning = 5;

private:
	float pos = 0;
	float iterations;
	AWallActor* temp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void spawnWAlls();
	void returnJason();
};