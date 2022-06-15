// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DrawSphereComponent.h"
#include "GameFramework/DefaultPawn.h"
#include "DrumManger.h"
#include "Drum.generated.h"
class ADrumManger;
UCLASS()
class EBERS_API ADrum : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY()
		ADrumManger* DManager;
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USceneComponent* sceneCompanent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		UStaticMeshComponent* staticMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USphereComponent* collider;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
		USoundBase* overlapSound;
	void changePos();*/

	

protected:
	virtual void BeginPlay() override;
	//void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		
	UFUNCTION()
		void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& Hit);

	FTimerHandle TimerHandle;

	void Kill();
public:
	ADrum();
	//void SetMesh(UStaticMesh* mesh);
};
