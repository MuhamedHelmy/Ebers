// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEbersPlayer> MyEbersPlayer;


	AEbersPlayer* CharacterRef;
	UPROPERTY(EditAnywhere)

		ACharacter* MyPlayer;
	//UPROPERTY(EditAnywhere)
	//	float OffsetBetweenWalls = 500.f;



	///*UPROPERTY(EditAnywhere)
	//	bool StartMovingWalls ;*/

	//UPROPERTY(EditAnywhere)
	//	float WallsMovementSpeed = 2;



	//UPROPERTY(EditAnywhere)
	//	TArray<UStaticMesh*> MeshesOfTheWalls;
	///*UPROPERTY(VisibleAnywhere)
	//	USceneComponent* Root	;

	//UPROPERTY(VisibleAnywhere)
	//	USkeletalMeshComponent* Mesh;*/

	UPROPERTY(BlueprintReadWrite)
		FRotator spawnRotation;


     UPROPERTY(EditAnywhere, BlueprintReadWrite)

	TArray<ADanceEnemy*> DanceEnemies;

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
