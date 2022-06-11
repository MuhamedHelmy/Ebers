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

USTRUCT(BlueprintType)
struct FAccuracy {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RightHandAccuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LeftHandAccuracy;

	FAccuracy() {
		RightHandAccuracy = 0.0f;
		LeftHandAccuracy = 0.0f;
	}

		
};

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

	bool GetCage();
	
public :

	TArray<FVector> FirstExcersizeFirstLocation;
	TArray<FVector> FirstExcersizeSecondLocation;


	TArray<FVector> SecondExcersizeFirstLocation;
	TArray<FVector> SecondExcersizeSecondLocation;

	UPROPERTY(EditAnywhere)
		bool SpawnNextExercise = true;

	UPROPERTY(EditAnyWhere)
		TArray<FName> SplineTagsArray;
	UFUNCTION()
	void SetSpawnNextExercise(bool set);

	UFUNCTION()
		void UpdateCageDisolve(float Disolve , float OldDisolveValue);
	UFUNCTION()
	void AddToScore(float v);
	UFUNCTION(BlueprintCallable , meta = (BindWidget))
		float GetScore();
private :
	TQueue<FName> SplinesTagsQueue;
	FName TagName;
	
	FTimerHandle TimerHandle;
	float DisolveStep = -0.1f;
	int32 CurrentExerciseCount = 0;

	FAccuracy FPlayerAccuracy;


	float Score = 0.0f;

	bool isRightExercise = true;

	
};
