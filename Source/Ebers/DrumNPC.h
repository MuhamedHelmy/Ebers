// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrumManger.h"
#include "DrumNPC.generated.h"

class ADrumManger;

UENUM(BlueprintType)
enum EExerciseSide {
	Right	UMETA(DisplayName = "RightSide"),
	Left	UMETA(DisplayNmae = "LeftSide")
};

UCLASS()
class EBERS_API ADrumNPC : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADrumNPC();
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;


private:
	FTimerHandle TimerHandle;

	EExerciseSide ExerciseSide;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& Hit);

	/*UPROPERTY()
		ADrumManger* DrumManager;*/
	UPROPERTY()
		ADrumManger* DManager;

	UFUNCTION()
		void SetExerciseSide(bool isRight);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Kill();
	//ADrumManager* GetManager();
	
};
