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
	//UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(DisolveMaterial, this);



	GetScenePlayer();
	//DisolveMaterial->set
		//UE_LOG(LogTemp, Warning, TEXT("Musssssssssssssstagfa %s") , *DisolveMaterial->GetFlags());
	//TArray<UActorComponent* > Found;
	
	//TArray<AActor* > Found;
	//Found = PlayerClass->GetComponentsByTag(UActorComponent::StaticClass(), TEXT("Camera"));
	//UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player");
	//mycamera =  Cast<UCameraComponent>(Found[0]);

		//UE_LOG(LogTemp, Warning, TEXT("Camera Location  : %s"), *mycamera->GetComponentLocation().ToString());

	
	
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneRight"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoLeft"));
	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoRight"));
	FTimerHandle FuzeTimerHandle;
	GetWorldTimerManager().SetTimer(FuzeTimerHandle, this, &ADrumManger::TimerFunction, 2.0f, false , 3.0f);



}
void ADrumManger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GetWorld()->LineTraceSingleByChannel(hit, StartLaser, EndLaser, ECollisionChannel::ECC_GameTraceChannel1);

	//SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("ETwoLeft"));
	
	
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
			if (j < MusicTrialMeshes.Num()) {
				x->SetStaticMesh(MusicTrialMeshes[j]);
				j++;
			}
			else if (j == MusicTrialMeshes.Num()) {
				j = 0;
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Music trail array is empty"));
			}
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




void ADrumManger::TimerFunction()
{
	UE_LOG(LogTemp, Error, TEXT("helmy X/O"));
	SpawnMusicTrailsAtLocation(GetSplinePointsLocationsByTag("EOneLeft"));


}


//void ADrumManger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}



