// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/Character.h"
#include "Components/SplineComponent.h"
#include "EbersPlayer.generated.h"


UCLASS()
class EBERS_API AEbersPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEbersPlayer();

	UPROPERTY()
		USplineComponent* MySpline;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* mycamera;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	FVector GetPlayerBodyPartLocation(int32 LegFlag);

	TArray<FVector> GetSplinePointsLocation(FName TagName);
};
