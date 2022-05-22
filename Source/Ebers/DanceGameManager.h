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
		class UMaterial* StartMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* EnemyMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* EnemyMaterial_2;

	class UMaterial* MyEnemyMaterial;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADanceEnemy> MyDanceEnemy;

	UPROPERTY(EditAnywhere)
		FVector spawnLocation;

	UStaticMeshComponent* EnemyDanceMesh;

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
	 int spanLife_i;
	 float HorizontalAngle;
	 int VerticalAngle;
	 FString strInfoForDoctor;
	 int str_i_ForDoctor;

	// bool bTringle;
	 TArray<FString> strArrInfoForDoctor;

	 //int RandMatNum;
	 
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
	void SetEnemyMaterial(class UMaterial* mat, int EnemyNum);
	void RandMaterial(int randNum,int EnemyNum);

	
};
