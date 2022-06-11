// Fill out your copyright notice in the Description page of Project Settings.
#include "DrumManger.h"
#include "EbersPlayer.h"
#include "Kismet/GameplayStatics.h"
#include"Drum.h"


// Sets default values
ADrumManger::ADrumManger()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ADrumManger::BeginPlay()
{
	Super::BeginPlay();
	



	GetScenePlayer();
	
	
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneRight"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoLeft"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoRight"));
	// 
	 
	

		/*SplinesTagsQueue.Enqueue("EOneLeft");
		SplinesTagsQueue.Enqueue("EOneRight");
		SplinesTagsQueue.Enqueue("ETwoLeft");
		SplinesTagsQueue.Enqueue("ETwoRight");*/


				
		if (SplineTagsArray.Num() > 0) { // Initializing the queue with the splines added from the BP
			for (int32 i = 0; i < SplineTagsArray.Num(); i++)
			{
				SplinesTagsQueue.Enqueue(SplineTagsArray[i]);
			}
		}
		else {
		//	UE_LOG(LogTemp, Warning, TEXT("Tag array is empty !! Enter some tags !"));
		}





		/*for (int32 i = 0; i < 4 ; i++)
		{
			FName xx;
			SplinesTagsQueue.Peek(xx);
			UE_LOG(LogTemp, Warning, TEXT("Queue test : %s"), *xx.ToString()  );
			SplinesTagsQueue.Pop();	
		}*/
	

}
void ADrumManger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GetWorld()->LineTraceSingleByChannel(hit, StartLaser, EndLaser, ECollisionChannel::ECC_GameTraceChannel1);

	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoLeft"));
	
	if (SpawnNextExercise) {

		CurrentExerciseCount++;

		if (!SplinesTagsQueue.IsEmpty()) {
			SplinesTagsQueue.Peek(TagName);
			TArray<FVector> Locations = GetSplinePointsLocationsByTag(TagName);
			SpawnMusicTrailsAtLocation(Locations);
			SplinesTagsQueue.Pop();
			//UE_LOG(LogTemp, Error, TEXT("Next Exercise Spawned : Exercise Cound ===> %d") , CurrentExerciseCount);
		}
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumManger::DisolveDoor, 0.2f, false, 2.0f);

		SpawnNextExercise = false;
	}
	

	//UE_LOG(LogTemp, Error, TEXT("Score is  ===> %f") , Score);
	

	
}


void ADrumManger::SpawnMusicTrailsAtLocation(TArray<FVector> Locations)
{
	int32 j = 0;
	UStaticMeshComponent* TrailMeshComponent;
	for (int32 i = 0; i < Locations.Num(); i++)
	{
		if (Locations.Num() -1 != i ) {
			DrumActor = GetWorld()->SpawnActor<ADrum>(DrumClass, Locations[i], FRotator(0, 0, 0));

			if (DrumActor) {
				TrailMeshComponent = Cast<UStaticMeshComponent>(DrumActor->Root->GetChildComponent(0));

				if (TrailMeshComponent) {
					if (j < MusicTrialMeshes.Num()) {
						TrailMeshComponent->SetStaticMesh(MusicTrialMeshes[j]);
						j++;
					}
					else if (j == MusicTrialMeshes.Num()) {
						j = 0;
					}
					else {
						//UE_LOG(LogTemp, Warning, TEXT("Music trail array is empty"));
					}
				}
			}
		}
		else {
			DrumNPC = GetWorld()->SpawnActor<ADrumNPC>(DrumNPCClass, Locations[i], FRotator(0, 0, 0));
			DrumNPC->SetExerciseSide(isRightExercise);
			isRightExercise = (!isRightExercise);
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
		UE_LOG(LogTemp, Error, TEXT("Player Not Found "));
		return false;
		
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

			//UE_LOG(LogTemp, Error, TEXT("Saraaaaaa3 * %s *  found"), *Locations[0].ToString());
			return Locations;
		}
		else {
			//UE_LOG(LogTemp, Error, TEXT("Spline By The Tag * %s *  was not found"), *Tag.ToString());
			return TArray<FVector>();
		}
	}
	else {
		//UE_LOG(LogTemp, Error, TEXT("Player was not found"));
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




void ADrumManger::DisolveDoor()
{
	//UE_LOG(LogTemp, Error, TEXT("helmy X/O"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneLeft"));
	//SpawnNextExercise = true;
	bool gotCage = GetCage();
	if (gotCage) {
		UpdateCageDisolve(DisolveStep *  CurrentExerciseCount , DisolveStep * (CurrentExerciseCount-1));
		//UE_LOG(LogTemp, Warning, TEXT("Disolve Step =  %f  => %d") , DisolveStep , CurrentExerciseCount);
	}
}

bool ADrumManger::GetCage()
{
	TArray<AActor*> Found;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Cage", Found);
	if (Found.Num() > 0) {
		Cage = Cast<ACage>(Found[0]);
		return true;
	}
	else {
		return false;
	}
}

void ADrumManger::SetSpawnNextExercise(bool set)
{
	SpawnNextExercise = set;
}

void ADrumManger::UpdateCageDisolve(float Disolve ,float OldDisolveValue)
{
	Cage->setDisolveValue(Disolve , OldDisolveValue);
}

void ADrumManger::AddToScore(float v)
{
	Score += v;
}

float ADrumManger::GetScore()
{
	return Score;
}




//void ADrumManger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}



