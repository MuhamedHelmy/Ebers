// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PointLightComponent.h"
#include "LightTrigger.h"

// Sets default values
ALightTrigger::ALightTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->bVisualizeComponent = false;
	RootComponent = PointLight;
	
}

// Called when the game starts or when spawned
void ALightTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


