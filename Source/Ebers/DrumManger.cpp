// Fill out your copyright notice in the Description page of Project Settings.
#include "DrumManger.h"
#include"Drum.h"


// Sets default values
ADrumManger::ADrumManger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.




}

// Called when the game starts or when spawned
void ADrumManger::BeginPlay()
{
	Super::BeginPlay();
	AActor* left = GetWorld()->SpawnActor<ADrum>(drumClass, leftDrumLocation, leftDrumRotationation, spawnParams);
	AActor* right = GetWorld()->SpawnActor<ADrum>(drumClass, RightDrumLocation, RightDrumRotationation, spawnParams);


}

// Called every frame


