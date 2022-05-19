// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"EbersPlayer.h"
#include "DanceGameManager.generated.h"

UCLASS()
class EBERS_API ADanceGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADanceGameManager();
	UWorld* world;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADanceEnemy> MyDanceEnemy;

	UPROPERTY(EditAnywhere)
		FVector spawnLocation;

	float MaxAngle=70;
	float angle = 0;
	float angleDirection = 1;
	void MoveFromCurveToAnother();
	int CurveNum=0;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEbersPlayer> MyEbersPlayer;


	AEbersPlayer* CharacterRef;
	UPROPERTY(EditAnywhere)

		ACharacter* MyPlayer;

	UPROPERTY(BlueprintReadWrite)
		FRotator spawnRotation;

	ACharacter* tempchar;
	AEbersPlayer* tchar;

	AEbersPlayer* player;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)

	TArray<ADanceEnemy*> DanceEnemies;

	 float PlayerLen = 300;
	 float PlayerLenH=200;
	 float FarPlayer=100;
		int EnemyIndex;
	//int32 WallsCounter = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnDanceEnemyHorizontal(float maxAngle, bool direction);
	void SpawnDanceEnemyVertical(float maxAngle, bool direction);
	void SpawnDanceEnemyTriangle(float maxAngle, bool direction);

	
};
