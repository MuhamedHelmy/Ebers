// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrumManger.generated.h"
class ADrum;

UCLASS()
class EBERS_API ADrumManger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrumManger();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector leftDrumLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector RightDrumLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FRotator leftDrumRotationation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FRotator RightDrumRotationation;

	FActorSpawnParameters spawnParams;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADrum> drumClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
