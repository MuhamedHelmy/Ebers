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
			/*DrumArrows[i]->GetFName().ToString();
			UE_LOG(LogTemp, Error, TEXT("3amr ====>%s ") ,* DrumArrows[i]->GetFName().ToString() );*/

			DrumArrows[i]->SetHiddenInGame(true);
		}

		/*for (int32 i = 0; i < SplineLocationsCompined.Num(); i++) {*/
			//UE_LOG(LogTemp, Warning, TEXT("3amr ====>%d ") , CompinedPointsCount );
	/*	}*/


		//CurrentPointIdx = 0;

		/*
		CurrentPointToSpawn = CurrentPointSet[CurrentPointIdx];*/







		/*FName temp;
		SplinesTagsQueue.Peek(temp);
		TArray<FVector> tempArray = GetSplinePointsLocationsByTag(temp);

		SpawnDrumHeadOneByOne(tempArray);*/

		//	UE_LOG(LogTemp, Warning, TEXT("Tag array is empty !! Enter some tags !"));



		/*for (int32 i = 0; i < 4 ; i++)
		{
			FName xx;
			SplinesTagsQueue.Peek(xx);
			UE_LOG(LogTemp, Warning, TEXT("Queue test : %s"), *xx.ToString()  );
			SplinesTagsQueue.Pop();	
		}*/
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumManger::Temp, 2.0f, true , 2.0f);

}
void ADrumManger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (SpawnNextExercise) {


		if (CurrentPointIdx < CompinedPointsCount) {
			SpawnNPC(SplineLocationsCompined[CurrentPointIdx]);
			CurrentPointIdx++;

			if (CurrentPointIdx % SplineTagsArray.Num() == 0) {
				UE_LOG(LogTemp, Error, TEXT(" aaaaaaaaaaah"));
				UE_LOG(LogTemp, Warning, TEXT(" CurrentExerciseCount : %d"), CurrentExerciseCount);
				// show next arrows !
				/*for (int32 i = 0; i < DrumArrows.Num(); i++) {
					DrumArrows[i]->SetHiddenInGame(true);
				}

				DrumArrows[CurrentArrowIdx]->SetHiddenInGame(false);*/
				ShowNextArrows();
			}

			/*UE_LOG(LogTemp, Warning, TEXT(" CurrentExerciseCount : %d"), CurrentExerciseCount)
			UE_LOG(LogTemp, Warning, TEXT(" CurrentPointIdx : %d"), CurrentPointIdx);
			UE_LOG(LogTemp, Warning, TEXT(" SplineTagsArray : %d"), SplineTagsArray.Num());*/
		}


		
		SpawnNextExercise = false;

	}

	





	if (NextPointReady) {
		/*
			1- spawn next trail .
		*/
	}

	if (SpawnNextExercise) {



		
		/*SplinesTagsQueue.Dequeue(CurrentTagName);
		TArray<FVector> SplineLocations = GetSplinePointsLocationsByTag(CurrentTagName);*/

		//if (NextPointReady) {
		//	// spawn trail point 
		//}
		//else {

		//}
		/*
		if -> last trail => spawn NPC{
			 1 - next tag
			 2 - reset NextPointReady to true}

		 
		*/


	/*	SpawnNPC(SplineLocations[0]);
		SpawnNextExercise = false;*/

		/*FName CurrentTag;
		SplinesTagsQueue.Peek(CurrentTag);*/

		// spawn domy one by one using the current tag 

		//SpawnExerciseOneByOne(CurrentTag);
	}



	//GetWorld()->LineTraceSingleByChannel(hit, StartLaser, EndLaser, ECollisionChannel::ECC_GameTraceChannel1);

	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoLeft"));
	
	//if (SpawnNextExercise) {

	//	CurrentExerciseCount++;

	//	if (!SplinesTagsQueue.IsEmpty()) {
	//		SplinesTagsQueue.Peek(TagName);
	//		TArray<FVector> Locations = GetSplinePointsLocationsByTag(TagName);
	//		SpawnMusicTrailsAtLocation(Locations);
	//		SplinesTagsQueue.Pop();
	//		//UE_LOG(LogTemp, Error, TEXT("Next Exercise Spawned : Exercise Cound ===> %d") , CurrentExerciseCount);
	//	}
	//	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumManger::DisolveDoor, 0.2f, false, 2.0f);

	//	SpawnNextExercise = false;
	//}


	//UE_LOG(LogTemp, Error, TEXT("Score ===> %f")  , Score);
	
}


void ADrumManger::SpawnMusicTrailsAtLocation(TArray<FVector> Locations)
{

	//GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumManger::DisolveDoor, 0.2f, false, 2.0f);

	//int32 j = 0;
	//UStaticMeshComponent* x;
	//for (int32 i = 0; i < Locations.Num(); i++)
	//{
	//	if (Locations.Num() -1 != i ) {
	//		DrumActor = GetWorld()->SpawnActor<ADrum>(DrumClass, Locations[i], FRotator(0, 0, 0));

	//		if (DrumActor) {
	//			x = Cast<UStaticMeshComponent>(DrumActor->Root->GetChildComponent(0));

	//			if (x) {
	//				if (j < MusicTrialMeshes.Num()) {
	//					x->SetStaticMesh(MusicTrialMeshes[j]);
	//					j++;
	//				}
	//				else if (j == MusicTrialMeshes.Num()) {
	//					j = 0;
	//				}
	//				else {
	//					//UE_LOG(LogTemp, Warning, TEXT("Music trail array is empty"));
	//				}
	//			}
	//		}
	//	}
	//	else {
	//		DrumNPC = GetWorld()->SpawnActor<ADrumNPC>(DrumNPCClass, Locations[i], FRotator(0, 0, 0));
	//	}
	//}
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

	if ((CurrentPointIdx ) == CurrentPointSet.Num())
		return true;
	else
		return false;
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
		DrumArrows[CurrentArrowIdx]->SetHiddenInGame(false);
	}
	CurrentArrowIdx++;


}

void ADrumManger::Temp() {
	//SpawnNextExercise = true;
}


//void ADrumManger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}



