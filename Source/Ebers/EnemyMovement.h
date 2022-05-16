// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DanceGameManager.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyMovement.generated.h"

UCLASS()
class EBERS_API AEnemyMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyMovement();

	UPROPERTY(EditAnywhere)
	ADanceGameManager* MyDanceGameManager;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ADanceGameManager* MyDanceGameManager;*/

	FVector StartVector;
	FVector EndVector;
	int StartIndex;
	int EndIndex;
	float lerppram = 0;
	void move();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
