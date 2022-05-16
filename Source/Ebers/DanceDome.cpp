// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceDome.h"

// Sets default values
ADanceDome::ADanceDome()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADanceDome::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADanceDome::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DomeHealth -= 0.1;
	//UE_LOG(LogTemp, Warning, TEXT("%f"), DomeHealth);

}

