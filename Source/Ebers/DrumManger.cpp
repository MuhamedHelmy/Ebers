// Fill out your copyright notice in the Description page of Project Settings.
#include "DrumManger.h"
#include "EbersPlayer.h"
#include "Kismet/GameplayStatics.h"
#include"Drum.h"


// Sets default values
ADrumManger::ADrumManger()
{


}

// Called when the game starts or when spawned
void ADrumManger::BeginPlay()
{
	Super::BeginPlay();

	GetScenePlayer();
	

	
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneLeft"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneRight"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoLeft"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoRight"));


	/*TArray<UActorComponent*> ExerciseOneSplines;
	TArray<UActorComponent*> ExerciseOTwoSplines;


	if (GetScenePlayer()) {
		 ExerciseOneSplines = PlayerClass->GetComponentsByTag(USplineComponent::StaticClass(), TEXT("ExerciseOneSpline"));
		 ExerciseOTwoSplines = PlayerClass->GetComponentsByTag(USplineComponent::StaticClass(), TEXT("ExerciseTwoSpline"));	 
	}

	if (ExerciseOneSplines.Num() > 0) {
		FirstExcersizeFirstLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOneSplines[0]));
		FirstExcersizeSecondLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOneSplines[1]));
		
		SpawnMusicTrailsAtLocation(FirstExcersizeFirstLocation);
		SpawnMusicTrailsAtLocation(FirstExcersizeSecondLocation);
		

	}
	else {
		UE_LOG(LogTemp, Error, TEXT("spline1 not found"));
	}
	if (ExerciseOTwoSplines	.Num() > 0) {

		SecondExcersizeFirstLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOTwoSplines[0]));
		SecondExcersizeSecondLocation = GetSplinePointsLocations(Cast<USplineComponent>(ExerciseOTwoSplines[1]));

		SpawnMusicTrailsAtLocation(SecondExcersizeFirstLocation);
		SpawnMusicTrailsAtLocation(SecondExcersizeSecondLocation);
		
	}

	else {
		UE_LOG(LogTemp, Error, TEXT("spline2 not found "));
	}*/
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
		UE_LOG(LogTemp, Error, TEXT("yasser %s"), *Locations[i].ToString());


		//Locations[i].Z -= 70;
		DrumActor = GetWorld()->SpawnActor<ADrum>(DrumClass , Locations[i] , FRotator(0, 0, 0));

		UE_LOG(LogTemp, Error, TEXT("5allleeeeeeeeeed %s"), *DrumActor->GetActorLocation().ToString());
		UE_LOG(LogTemp, Error, TEXT("5allleeeeeeeeeed2222 %s"), *Locations[i].ToString());

		x = Cast<UStaticMeshComponent>(DrumActor->Root ->GetChildComponent(0));

		UE_LOG(LogTemp, Error, TEXT("5allleeeeeeeeeed %s"), *DrumActor->GetActorLocation().ToString());
		UE_LOG(LogTemp, Error, TEXT("5allleeeeeeeeeed2222 %s"), *Locations[i].ToString());

		UE_LOG(LogTemp, Error, TEXT(""));
		if (x) {
			x->SetStaticMesh(MusicTrialMeshes[j]);
			
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
	
	TArray<AActor*> Found;
	
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", Found);
		
	if (Found.Num() > 0) {
		PlayerClass = Cast<AEbersPlayer>(Found[0]);
		return true;
		
	}
	else {
		return false;
		UE_LOG(LogTemp, Error, TEXT("got the player 22 "));
	}
	
}

TArray<FVector> ADrumManger::GetSplinePointsLocationsByTag(FName Tag)
{
	TArray<UActorComponent*> Splines; 
	TArray<FVector> Locations;
	if (GetScenePlayer()) {
		Splines = PlayerClass->GetComponentsByTag(USplineComponent::StaticClass(),Tag);
		if (Splines.Num() > 0) {
			Locations = GetSplinePointsLocations(Cast<USplineComponent>(Splines[0]));

			UE_LOG(LogTemp, Error, TEXT("Saraaaaaa3 * %s *  found"), *Locations[0].ToString());
			return Locations;
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Spline By The Tag * %s *  was not found"), *Tag.ToString());
			return TArray<FVector>();
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Player was not found"));
		return TArray<FVector>();
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
	}
	
	return  Locations;
}



