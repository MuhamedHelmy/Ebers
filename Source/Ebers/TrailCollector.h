// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DrawSphereComponent.h"
#include "GameFramework/DefaultPawn.h"
#include "TrailCollector.generated.h"

UCLASS()
class EBERS_API ATrailCollector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrailCollector();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USceneComponent* sceneCompanent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		UStaticMeshComponent* staticMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USphereComponent* collider;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
		USoundBase* overlapSound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
