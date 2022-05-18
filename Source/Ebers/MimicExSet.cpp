// Fill out your copyright notice in the Description page of Project Settings.


#include "MimicExSet.h"

// Sets default values
AMimicExSet::AMimicExSet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMimicExSet::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMimicExSet::spawnWAlls()
{
	for (int32 i = 0; i < SpawnActors.Num(); i++)
	{
		
			temp = GetWorld()->SpawnActor<AWallActor>(SpawnActors[i], GetActorLocation() + FVector(0, pos, 0), GetActorRotation());
		temp->WallMovementSpeed = speed;
		pos += distance;
	}
	iterations--;
	pos = 0;

	UE_LOG(LogTemp, Error, TEXT("saddsfd %f"), iterations);
}

// Called every frame
void AMimicExSet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

