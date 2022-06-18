// Fill out your copyright notice in the Description page of Project Settings.


#include "MimiCharacter.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AMimiCharacter::AMimiCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void AMimiCharacter::BeginPlay()
{
	
	Super::BeginPlay();
}

void AMimiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FVector::Dist(GetActorLocation(), startpoint) <= 0.1f) {
		Nextdestination = MiddlePoint;
		currntpos = startpoint;
	}
	if (FVector::Dist(GetActorLocation(), MiddlePoint) <= 50.0f) {
		currntpos = MiddlePoint;
		speed = 0;
		Nextdestination = Endpoint;

	}
	SetActorLocation(FMath::Lerp(currntpos, Nextdestination, speed));
	if (speed <= 1) {
		speed += 0.001;
	}

	if (FVector::Dist(GetActorLocation(), Endpoint) <= 50.0f) {
		hittingg = true;
		TArray<AActor *> manger;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "manger", manger);
		if (manger.Num() > 0) {
			AMimicGameManager* x = Cast<AMimicGameManager>(manger[0]);
			x->_isGameStarted = true;
		}

	}



	

}

void AMimiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

