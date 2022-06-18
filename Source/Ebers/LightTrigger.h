// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "LightTrigger.generated.h"

UCLASS()
class EBERS_API ALightTrigger : public AActor

{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	ALightTrigger();



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
