// Fill out your copyright notice in the Description page of Project Settings.


#include "MimicCharacter.h"

// Sets default values
AMimicCharacter::AMimicCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	myroot = CreateDefaultSubobject<USceneComponent>(TEXT("MYScene"));
	
}

// Called when the game starts or when spawned
void AMimicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMimicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

