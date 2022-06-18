// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include <Ebers/DrumNPC.h>
#include <Ebers/Cage.h>
#include "DrumManger.generated.h"
class ADrum;
class AEbersPlayer;
class ADrumNPC;
class ACage;






UCLASS()
class EBERS_API ADrumManger : public AActor
{
	GENERATED_BODY()

public:
	ADrumManger();

	UStaticMeshComponent* DrumMeshComponent;


	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ADrum> DrumClass;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ADrumNPC> DrumNPCClass;

	/*UPROPERTY(EditAnywhere)
		UMaterialInterface* DisolveMaterial;*/

	UPROPERTY()
		AEbersPlayer* PlayerClass;

	UPROPERTY()
		TArray<UStaticMeshComponent* > DrumArrows;

	UPROPERTY()
		ADrum* DrumActor;

	UPROPERTY()
		ADrumNPC* DrumNPC;

	UPROPERTY()
		ACage* Cage;

	UPROPERTY(EditAnywhere)
		UStaticMesh* DrumMesh;

	UPROPERTY(EditAnywhere)
		TArray<UStaticMesh*> MusicTrialMeshes;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* mycamera = nullptr;
	//AEbersPlayer* PlayerClass;




	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector leftDrumLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector RightDrumLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FRotator leftDrumRotationation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FRotator RightDrumRotationation;

	FActorSpawnParameters spawnParams;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADrum> drumClass;*/




protected:

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;


	void SpawnMusicTrailsAtLocation(TArray<FVector> Locations);

	bool GetScenePlayer();

	TArray<FVector> GetSplinePointsLocationsByTag(FName Tag);

	TArray<FVector> GetSplinePointsLocations( class USplineComponent * Spline);
	/*UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);*/
	void DisolveDoor();

	//void SpawnDrumHeadOneByOne(TArray<FVector> Locations);

	bool GetCage();
	
public :

	TArray<FVector> FirstExcersizeFirstLocation;
	TArray<FVector> FirstExcersizeSecondLocation;


	TArray<FVector> SecondExcersizeFirstLocation;
	TArray<FVector> SecondExcersizeSecondLocation;


	UPROPERTY(EditAnyWhere)
		TArray<FName> SplineTagsArray;
	UFUNCTION()
	void SetSpawnNextExercise(bool set);

	UFUNCTION()
		void SetNextPointSpawn(bool set);

	UFUNCTION()
		void UpdateCageDisolve(float Disolve , float OldDisolveValue);

	UFUNCTION()
		void AddToScore(float v);


	UFUNCTION( BlueprintCallable, meta = (BindWidget))
		float GetScore();

	UPROPERTY(EditAnywhere , BlueprintReadWrite, meta = (BindWidget))
		float Score = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bEndGame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsWin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bPause;
private :
	TQueue<FName> SplinesTagsQueue;
	FName CurrentTagName;
	TArray<FVector> SplineLocationsCompined; 
	int32 CompinedPointsCount = 0;

	bool SpawnNextExercise = true;
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandleTwo;
	FTimerHandle TimerHandleThree;
	float DisolveStep = -0.1f;
	int32 CurrentExerciseCount = 0;

	


	TArray<FVector> CurrentPointSet;
	FVector CurrentPointToSpawn; 
	bool IsFinalPoint();

	int32 PointsCount = 0;
	int32 CurrentPointIdx = 0;
	int32 CurrentArrowIdx = 1; 

	int32 **x;
	bool NextPointReady = true;
	
	void SpawnTrail(FVector Location);
	void SpawnNPC(FVector Location);
	void ShowNextArrows();
	void Temp();

	TArray<FVector> AllSpawnPoints;
};
