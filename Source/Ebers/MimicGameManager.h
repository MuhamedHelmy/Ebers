// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MimicGameManager.generated.h"

UCLASS()
class EBERS_API AMimicGameManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMimicGameManager();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWallActor> WallClass;

	UPROPERTY(EditAnywhere)
		FVector spawnLocation;
	UPROPERTY(EditAnywhere)
		float OffsetBetweenWalls = 500.f;



	/*UPROPERTY(EditAnywhere)
		bool StartMovingWalls ;*/

	UPROPERTY(EditAnywhere)
		float WallsMovementSpeed = 2;



	UPROPERTY(EditAnywhere)
		TArray<UStaticMesh*> MeshesOfTheWalls;
	/*UPROPERTY(VisibleAnywhere)
		USceneComponent* Root	;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;*/

	UPROPERTY(BlueprintReadWrite)
		FRotator wallRotation;



	TArray<AWallActor*> Walls;
	UWorld* world;
	int32 WallsCounter = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void InitializeWalls();
	//void MoveWalls(float speed);



	UFUNCTION(BlueprintCallable)
		void SpawnWalls();

	/*void MoveWalls(float speed);*/
};
