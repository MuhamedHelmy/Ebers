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
	UE_LOG(LogTemp, Error, TEXT(" Cpasrt urrentPoxxxxxxxxxxxxxxxxxxxx"));
		if (SplineTagsArray.Num() > 0) { // Initializing the queue with the splines added from the BP
			for (int32 i = 0; i < SplineTagsArray.Num(); i++)
			{
				SplinesTagsQueue.Enqueue(SplineTagsArray[i]);
				UE_LOG(LogTemp, Warning, TEXT("Tag ! %s"), *SplineTagsArray[i].ToString());
			}
		}
		else {
		//	UE_LOG(LogTemp, Warning, TEXT("Tag array is empty !! Enter some tags !"));
		}


		

		PointsCount = CurrentPointSet.Num();
		UE_LOG(LogTemp, Warning, TEXT(""));
		
		for (int32 i = 0; i < SplineTagsArray.Num(); i++)
		{

			SplinesTagsQueue.Dequeue(CurrentTagName);
			TArray<FVector> TempSplineLocations = GetSplinePointsLocationsByTag(CurrentTagName);
			for (int32 j = 0; j < TempSplineLocations.Num(); j++) {
				SplineLocationsCompined.Add(TempSplineLocations[j]);
				CompinedPointsCount++;
			}

		}

		DrumArrows = PlayerClass->GetDrumArrows(4);

		for (int32 i = 1; i < DrumArrows.Num(); i++) {
			DrumArrows[i]->GetFName().ToString();
			UE_LOG(LogTemp, Error, TEXT("3amr ====>%s ") ,* DrumArrows[i]->GetFName().ToString() );

			DrumArrows[i]->SetHiddenInGame(true);
		}

		SetPointsCount = SplineLocationsCompined.Num() / SplineTagsArray.Num();

	
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumManger::Temp, 2.0f, true , 2.0f);

		bool gotCage = GetCage();

}
void ADrumManger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (!bPause) {
		//UE_LOG(LogTemp, Error, TEXT(" Cpasrt urrentPoxxxxxxxxxxxxxxxxxxxx"));
		if (SpawnNextExercise) {
			//UE_LOG(LogTemp, Error, TEXT(" CurrentPoxxxxxxxxxxxxxxxxxxxx"));
			if (CurrentPointIdx < CompinedPointsCount) {
				SpawnNPC(SplineLocationsCompined[CurrentPointIdx]);
				CurrentPointIdx++;
				//UE_LOG(LogTemp, Warning, TEXT(" CurrentPointIdx : %d"), CurrentPointIdx);
				if ((CurrentPointIdx - 1) == SetPointsCount || CurrentPointIdx == 1) {
					SetPointsCount += SplineTagsArray.Num();

					UE_LOG(LogTemp, Warning, TEXT(" Show Next called  "));
					ShowNextArrows();
				}
				else if (CurrentPointIdx == 5) {
					UE_LOG(LogTemp, Warning, TEXT(" Show second called "));
					for (int32 i = 0; i < DrumArrows.Num(); i++) {
						DrumArrows[i]->SetHiddenInGame(true);
					}
					DrumArrows[1]->SetHiddenInGame(false);

				}
				else if (CurrentPointIdx == CompinedPointsCount) {
					for (int32 i = 0; i < DrumArrows.Num(); i++) {
						DrumArrows[i]->SetHiddenInGame(true);
					}
				}
			}

			if (CurrentArrowIdx == CompinedPointsCount) {
				for (int32 i = 0; i < DrumArrows.Num(); i++) {
					DrumArrows[i]->SetHiddenInGame(true);
				}
			}

			SpawnNextExercise = false;
		}
		if (CurrentPointIdx == 16 && nOfNPCHit > CurrentPointIdx / 2) {
			bIsWin = true;
		}

		if (CurrentPointIdx == 16) {
			bEndGame = true;
		}
	}

}



void ADrumManger::SpawnMusicTrailsAtLocation(TArray<FVector> Locations)
{

	
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




void ADrumManger::DisolveDoor()
{
	//UE_LOG(LogTemp, Error, TEXT("helmy X/O"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneLeft"));
	//SpawnNextExercise = true;
	bool gotCage = GetCage();
	if (gotCage) {
		//UpdateCageDisolve(DisolveStep *  CurrentArrowIdx , DisolveStep * (CurrentArrowIdx -1));
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
		UE_LOG(LogTemp, Warning, TEXT("No Cage Found"));
		return false;
	}
}

void SpawnExerciseOneByOne(TArray<FVector> Locations) {

//	for (int32 i = 0; i < Locations.Num(); i++) {
		UE_LOG(LogTemp, Error, TEXT("NumOfLocations ===> %d"), Locations.Num());
	//}

}

void ADrumManger::SetSpawnNextExercise(bool set)
{
	SpawnNextExercise = set;
}

void ADrumManger::SetNextPointSpawn(bool set)
{

}

void ADrumManger::UpdateCageDisolve()
{
	Cage->OpenDoor(CompinedPointsCount);
}

void ADrumManger::AddToScore(float v)
{
	Score += v;
}

float ADrumManger::GetScore()
{
	return Score;
}

void ADrumManger::AddToNumOfNpcHit(int32 n)
{

	nOfNPCHit += n;

}



void ADrumManger::SpawnTrail(FVector Location)
{
	
}

void ADrumManger::SpawnNPC(FVector Location)
{
	DrumNPC = GetWorld()->SpawnActor<ADrumNPC>(DrumNPCClass, Location, FRotator(0, 90.f,0));
}

void ADrumManger::ShowNextArrows()
{

	for (int32 i = 0; i < DrumArrows.Num(); i++) {
		DrumArrows[i]->SetHiddenInGame(true);
	}

	if (CurrentArrowIdx < 4) {
		//UE_LOG(LogTemp, Warning, TEXT("CurrentArrowIdx == %d ::: CurrentPointIdx = %d") , CurrentArrowIdx , CurrentPointIdx);
		if (CurrentPointIdx == 1) {
			DrumArrows[0]->SetHiddenInGame(false);

		}
		else {
			DrumArrows[CurrentArrowIdx]->SetHiddenInGame(false);
		}
	}
	CurrentArrowIdx++;


}

void ADrumManger::Temp() {
	//SpawnNextExercise = true;
}


//void ADrumManger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}



