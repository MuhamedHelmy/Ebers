// Fill out your copyright notice in the Description page of Project Settings.
#include "EbersPlayer.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEbersPlayer::AEbersPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEbersPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	
	//MimicScore = 50;
	//FName x = "ExerciseOneRightLeg";
		
		//UE_LOG(LogTemp, Error, TEXT("first %s"), *GetSplinePointsLocation(x)[0].ToString());
	//MySpline->GetLocationAtSplinePoint(0);

}



// Called every frame
void AEbersPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MimicScore = 200;

	//GetWorld()->LineTraceSingleByChannel(hit, StartLaser, EndLaser, ECollisionChannel::ECC_GameTraceChannel1);

	
	
}

// Called to bind functionality to input//
void AEbersPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void DrawLeser()
{
//FVector   Location;
//FRotator Rotation;
//
//OwnerController->GetPlayerViewPoint(Location, Rotation);
//
//FVector End = Location + Rotation.Vector() * MaxRange;
//
//FHitResult hit;
//
//if (GetWorld()->LineTraceSingleByChannel(hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1)) {
//	FVector ShotDirection = -Rotation.Vector();
//	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, hit.Location, ShotDirection.Rotation());
//
//	if (hit.GetActor() != nullptr) {
//		FPointDamageEvent DamageEvent(Damage, hit, ShotDirection, nullptr);
//		hit.GetActor()->TakeDamage(Damage, DamageEvent, OwnerController, this);
//
//	}
//
//
//}

}

/*
FVector AEbersPlayer::GetPlayerBodyPartLocation(int32 LegFlag)
{




	return FVector();
}*/
//
//TArray<FVector> AEbersPlayer::GetSplinePointsLocation(FName TagName)
//{
//	TArray<FVector> SplinePointsLocation;
//	TArray<UActorComponent*>Arr = GetComponentsByTag(UPrimitiveComponent::StaticClass(), TagName);
//
//	if (Arr.Num() > 0) {
//		if (Arr[0] != nullptr) {
//			MySpline = Cast<USplineComponent>(Arr[0]);
//			//UE_LOG(LogTemp, Warning, TEXT("Spline Loaded !!"));
//		}
//	}
//
//	for (int32 i = 0; i < MySpline->GetNumberOfSplinePoints(); i++)
//	{
//		SplinePointsLocation.Add(MySpline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Type::Local));
//	}
//
//	/*UE_LOG(LogTemp, Error, TEXT("N of splines %d"), MySpline->GetNumberOfSplinePoints());
//
//	FVector SplinePoint1 = MySpline->GetLocationAtSplinePoint(4, ESplineCoordinateSpace::Type::Local);
//
//	UE_LOG(LogTemp, Error, TEXT("Spline location %s"), *SplinePoint1.ToString());*/
//
//	return SplinePointsLocation;
//}
//
