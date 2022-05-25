// Fill out your copyright notice in the Description page of Project Settings.


#include "MimiCharacter.h"

// Sets default values
AMimiCharacter::AMimiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawnpos=FVector(1760, 170, 80);
	rotation = FRotator(90, 0, 0);
}

// Called when the game starts or when spawned
void AMimiCharacter::BeginPlay()
{
	Super::BeginPlay();


}

void AMimiCharacter::startGame()
{
}

// Called every frame
void AMimiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 if (FVector::Dist(GetActorLocation(), startpoint)<= 0.1f) {
		Nextdestination = MiddlePoint;
		currntpos = startpoint;
		UE_LOG(LogTemp, Error, TEXT("Start"));
	 }
    if (FVector::Dist(GetActorLocation(), MiddlePoint) <= 50.0f) {
		currntpos = MiddlePoint;
		speed = 0;
		Nextdestination = Endpoint;
		UE_LOG(LogTemp, Error, TEXT("midle"));

	}
   if (FVector::Dist(GetActorLocation(), Endpoint) <=50.0f) {
		hittingg = true;
		UE_LOG(LogTemp, Error, TEXT("endpoint"));
		if (!_startGame)
		{
		manger = GetWorld()->SpawnActor<AMimicGameManager>(mangerspawner,spawnpos, rotation);
		_startGame = true;
		}

	}

	 UE_LOG(LogTemp, Error, TEXT("esef %f"), FVector::Dist(GetActorLocation(), Endpoint));
     SetActorLocation(FMath::Lerp(currntpos, Nextdestination, speed));
	 if (speed <= 1) {
		 speed += 0.001;
	 }


	

}

// Called to bind functionality to input
void AMimiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

