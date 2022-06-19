// Fill out your copyright notice in the Description page of Project Settings.


#include "MimicExSet.h"

// Sets default values
AMimicExSet::AMimicExSet()
{
	PrimaryActorTick.bCanEverTick = true;
	Spawnrotation = GetActorRotation();
	Spawnrotation.Yaw = -180;            //the wall rotation
}

// Called when the game starts or when spawned
void AMimicExSet::BeginPlay()
{
	Super::BeginPlay();
 
}



void AMimicExSet::spawnWAlls(float wallspeed,float rep)
{
	while (rep>0)
	{
		for (counter = 0; counter < wallsShapes.Num(); counter++)
		{
			 walls = GetWorld()->SpawnActor<AWallActor>(wallsShapes[counter], GetActorLocation() + FVector(0,_Npos, 0), Spawnrotation);
			 walls->WallMovementSpeed = wallspeed;
			 _Npos += walls_distance;
		     wallArray.Add_GetRef(walls);
			
		}
	rep--;
	}
	
	lastwall = walls;
	lastwallpos = walls->GetActorLocation();

}

void AMimicExSet::spawnWAlls(float wallspeed)
{

	for (counter = 0; counter < wallsShapes.Num(); counter++)
	{

		walls = GetWorld()->SpawnActor<AWallActor>(wallsShapes[counter], GetActorLocation() + FVector(_Npos, 0, 0), Spawnrotation);
		walls->WallMovementSpeed = wallspeed;
		_Npos += walls_distance; 
		wallArray.Add_GetRef(walls);
	
	}
	//walls = lastwall;
}
FString AMimicExSet::GetEXerciseName(AWallActor * wall) {
	    FString exnam;
		for (int32 i = 0;i < wallArray.Num();i++)
		{
			if (wallArray[i]->GetFName().ToString() == wall->GetFName().ToString()) {
				exnam = GetFName().ToString();
				UE_LOG(LogTemp, Error, TEXT("name : %s"), *exnam);
			}
		}
	return exnam;

}


void AMimicExSet::Tick(float DeltaTime)
{
	lastwallpos = walls->GetActorLocation();

}







