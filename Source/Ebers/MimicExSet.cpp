// Fill out your copyright notice in the Description page of Project Settings.


#include "MimicExSet.h"

// Sets default values
AMimicExSet::AMimicExSet()
{
	Spawnrotation = GetActorRotation();
	Spawnrotation.Yaw = 90;
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
		for (counter = 0; counter < SpawnActors.Num(); counter++)
		{

			 walls = GetWorld()->SpawnActor<AWallActor>(SpawnActors[counter], GetActorLocation() + FVector(_Npos, 0, 0), Spawnrotation);
			 walls->WallMovementSpeed = wallspeed;
			_Npos += walls_distance;
			UE_LOG(LogTemp, Error, TEXT("name : %s"), *walls->GetFName().ToString());
		
		}
	rep--;
	}
		
	


}

void AMimicExSet::spawnWAlls(float wallspeed)
{

	for (counter = 0; counter < SpawnActors.Num(); counter++)
	{

		walls = GetWorld()->SpawnActor<AWallActor>(SpawnActors[counter], GetActorLocation() + FVector(_Npos, 0, 0), Spawnrotation);
		walls->WallMovementSpeed = wallspeed;
		_Npos += walls_distance;
		UE_LOG(LogTemp, Error, TEXT("name : %s"), *walls->GetFName().ToString());

	}
}






