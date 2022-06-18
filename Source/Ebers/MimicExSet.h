// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallActor.h"
#include "MimicExSet.generated.h"


UCLASS()
class EBERS_API AMimicExSet : public AActor
{
	GENERATED_BODY()

public:
	    AMimicExSet();

#pragma region Uproperties
		UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<AWallActor>> wallsShapes;    //array of spawning walls
	    UPROPERTY(EditAnywhere)
	    float walls_distance=300;                     // the distance between every wall

#pragma endregion Uproperties

#pragma region publicFunctions

	void spawnWAlls(float wallspeed,float rep); // spawn walls with repeating number 
	void spawnWAlls(float wallspeed);        // spawn walls without repeating 
	FString GetEXerciseName(AWallActor * wall) ;
#pragma endregion publicFunctions

#pragma  region privatesVariables
private:
	float _Npos = 0;
	int32 iterations;
	int32 counter;
	AWallActor* walls;
	FVector Spawnpos;
	FRotator Spawnrotation;
	float setIterations=1;
    TArray<AWallActor*>wallArray;
#pragma endregion  privatesVariables

#pragma region protectedFunction
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void returnJason();
	void returnwallsnames();
#pragma endregion  protectedFunction
};