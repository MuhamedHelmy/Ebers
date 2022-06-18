// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
<<<<<<<< HEAD:Source/Ebers/LightTrigger.h
#include "LightTrigger.generated.h"

UCLASS()
class EBERS_API ALightTrigger : public AActor
========
#include "DrumStick.generated.h"

UCLASS()
class EBERS_API ADrumStick : public AActor
>>>>>>>> Drum:Source/Ebers/DrumStick.h
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
<<<<<<<< HEAD:Source/Ebers/LightTrigger.h
	ALightTrigger();
========
	ADrumStick();
>>>>>>>> Drum:Source/Ebers/DrumStick.h

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class UPointLightComponent* PointLight;
	void lighttriggeron();
	void lighttriggerOff();
	FTimerHandle TimerHandle;


};
