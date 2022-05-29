// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrumManger.generated.h"
class ADrum;
class AEbersPlayer;
UCLASS()
class EBERS_API ADrumManger : public AActor
{
	GENERATED_BODY()

public:
	ADrumManger();

	UStaticMeshComponent* DrumMeshComponent;


	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ADrum> DrumClass;

	
	UPROPERTY()
		AEbersPlayer* PlayerClass;

	UPROPERTY()
		ADrum* DrumActor;

	UPROPERTY(EditAnywhere)
		UStaticMesh* DrumMesh;

	UPROPERTY(EditAnywhere)
		TArray<UStaticMesh*> MusicTrialMeshes;


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

	void SpawnMusicTrailsAtLocation(TArray<FVector> Locations);

	bool GetScenePlayer();

	TArray<FVector> GetSplinePointsLocationsByTag(FName Tag);

	TArray<FVector> GetSplinePointsLocations( class USplineComponent * Spline);


public :

	TArray<FVector> FirstExcersizeFirstLocation;
	TArray<FVector> FirstExcersizeSecondLocation;


	TArray<FVector> SecondExcersizeFirstLocation;
	TArray<FVector> SecondExcersizeSecondLocation;


};
