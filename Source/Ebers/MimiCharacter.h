// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MimicGameManager.h"
#include "MimiCharacter.generated.h"

UCLASS()
class EBERS_API AMimiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMimiCharacter();
	UPROPERTY(EditAnywhere)
	FVector startpoint;
	UPROPERTY(EditAnywhere)
	FVector MiddlePoint;
	UPROPERTY(EditAnywhere)
	FVector Endpoint;

	UPROPERTY(BlueprintReadWrite)
	bool hittingg;
	UPROPERTY(EditAnywhere)
	float speed = 0;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AMimicGameManager> mangerspawner;    

	FVector currntpos;
	FVector Nextdestination;
	FVector spawnpos;
	FRotator rotation;
	AMimicGameManager*manger;
	bool _startGame;
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void startGame();
	
	// Called every frame
	

};
