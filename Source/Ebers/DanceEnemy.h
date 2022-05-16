// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DanceEnemy.generated.h"

UCLASS()
class EBERS_API ADanceEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADanceEnemy();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DanceEnemyHealth = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	bool canAttack = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
