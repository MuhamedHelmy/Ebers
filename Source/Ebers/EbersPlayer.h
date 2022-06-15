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
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//	UCameraComponent  *mycamera;
	void DrawLeser();
	FHitResult hit;
	FVector StartLaser;
	FVector EndLaser;
	UPROPERTY(BlueprintReadWrite)
	bool LaserChanged;

	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite , meta = (BindWidget))
	int32 MimicScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	int32 coins;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent * rightHandMesh;


	UPROPERTY()
		USplineComponent* MySpline;


	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool IsInCurve=true;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//FVector GetPlayerBodyPartLocation(int32 LegFlag);

	//TArray<FVector> GetSplinePointsLocation(FName TagName);
};

void DrawLeser();
