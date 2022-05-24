// Fill out your copyright notice in the Description page of Project Settings.
#include "DrumManger.h"
#include "EbersPlayer.h"
#include "Kismet/GameplayStatics.h"
#include"Drum.h"


// Sets default values
ADrumManger::ADrumManger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.




}

// Called when the game starts or when spawned
void ADrumManger::BeginPlay()
{
	Super::BeginPlay();

	
	TArray<UActorComponent*> ExerciseOneSplines;
	TArray<UActorComponent*> ExerciseOTwoSplines;





	if (GetScenePlayer()) {
		 ExerciseOneSplines = PlayerClass->GetComponentsByTag(USplineComponent::StaticClass(), TEXT("ExerciseOneSpline"));
		 ExerciseOTwoSplines = PlayerClass->GetComponentsByTag(USplineComponent::StaticClass(), TEXT("ExerciseTwoSpline"));
		 
	}

	if (ExerciseOneSplines.Num() > 0) {

		FirstExcersizeFirstLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOneSplines[0]));
		FirstExcersizeSecondLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOneSplines[1]));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("spline not found"));
	}
	if (ExerciseOTwoSplines.Num() > 0) {
		SecondExcersizeFirstLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOTwoSplines[0]));
		SecondExcersizeSecondLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOTwoSplines[1]));

	}
	else {
		UE_LOG(LogTemp, Error, TEXT("spline not found 2 "));
	}


	

	if (ExerciseOneSplines.Num() > 0) {

		SpawnMusicTrailsAtLocation(FirstExcersizeFirstLocation);
		SpawnMusicTrailsAtLocation(FirstExcersizeSecondLocation);
		UE_LOG(LogTemp, Error, TEXT("helmy shhh"));

	}
	if (ExerciseOTwoSplines	.Num() > 0) {
		SpawnMusicTrailsAtLocation(SecondExcersizeFirstLocation);
		SpawnMusicTrailsAtLocation(SecondExcersizeSecondLocation);
		UE_LOG(LogTemp, Error, TEXT("helmy simp"));
	}
	
	//GetSplinePointsLocationsAbod(Spline);
	//Spline->GetLocationAndTangentAtSplinePoint(0 ,);


	/**/
	//DrumActor = Cast<ADrum>(GetWorld()->SpawnActor<ADrum>(DrumClass, PlayerSplinePoints[0]  , FRotator(0,0,0) ));
	//UE_LOG(LogTemp, Warning, TEXT("Location %s"), *PlayerSplinePoints[0].ToString());



	//AActor* left = GetWorld()->SpawnActor<ADrum>(drumClass, leftDrumLocation, leftDrumRotationation, spawnParams);
	//AActor* right = GetWorld()->SpawnActor<ADrum>(drumClass, RightDrumLocation, RightDrumRotationation, spawnParams);


}

void ADrumManger::SpawnMusicTrailsAtLocation(TArray<FVector> Locations)
{
	int32 j = 0;
	UStaticMeshComponent* x;
	for (int32 i = 0; i < Locations.Num(); i++)
	{
		DrumActor = GetWorld()->SpawnActor<ADrum>(DrumClass , Locations[i] , FRotator(0, 0, 0));
		x = Cast<UStaticMeshComponent>(DrumActor->Root ->GetChildComponent(0));
		if (x) {
			x->SetStaticMesh(MusicTrialMeshes[j]);
			UE_LOG(LogTemp, Error, TEXT("helmy sumbpl"));
		}
		if (j < MusicTrialMeshes.Num()) {
			j++;
		}
		else {
			j = 0;
		}
	}
}

bool ADrumManger::GetScenePlayer()
{
	UE_LOG(LogTemp, Error, TEXT("got the player 0069 "));
	TArray<AActor*> Found;
	
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", Found);
		UE_LOG(LogTemp, Error, TEXT("got the player 22  %d"), Found.Num());
	if (Found.Num() > 0) {
		PlayerClass = Cast<AEbersPlayer>(Found[0]);
		return true;
		UE_LOG(LogTemp, Error, TEXT("got the player 11 "));
	}
	else {
		return false;
		UE_LOG(LogTemp, Error, TEXT("got the player 22 "));
	}
	
}

TArray<FVector> ADrumManger::GetSplinePointsLocations( USplineComponent* Spline)
{
	TArray<FVector> Locations;
	
	FVector TempLocation;

	FVector Tangent;
	for (int32 i = 0; i < Spline->GetNumberOfSplinePoints()  ; i++)
	{
		Spline->GetLocationAndTangentAtSplinePoint(i , TempLocation , Tangent  , ESplineCoordinateSpace::Type::World);
		Locations.Add(TempLocation);
		//UE_LOG(LogTemp, Error, TEXT("helmy"));
	}
	
	return  Locations;
}



