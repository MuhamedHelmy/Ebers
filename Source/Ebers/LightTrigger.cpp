// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PointLightComponent.h"
#include "LightTrigger.h"

// Sets default values
ALightTrigger::ALightTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	//PointLight->bVisualizeComponent = false;
	PointLight->SetVisibility(false);
	RootComponent = PointLight;
	
}

// Called when the game starts or when spawned
void ALightTrigger::BeginPlay()
{
	Super::BeginPlay();
	

}

void ALightTrigger::lighttriggeron()
{
	    PointLight->SetVisibility(true);
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ALightTrigger::lighttriggerOff, 0.5, false, 0.5f);

}

void ALightTrigger::lighttriggerOff()
{
	PointLight->SetVisibility(false);

}

// Called every frame


