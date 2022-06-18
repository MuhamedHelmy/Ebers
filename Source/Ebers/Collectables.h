// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EbersPlayer.h"
#include "Components/DrawSphereComponent.h"
#include "GameFramework/DefaultPawn.h"
#include "Collectables.generated.h"
UCLASS()
class EBERS_API ACollectables : public AActor
{
	GENERATED_BODY()	
public:
	ACollectables();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USceneComponent* sceneCompanent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		UStaticMeshComponent* rightmesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USphereComponent* rightmeshcollider;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
		USoundBase* overlapSound;
	UPROPERTY(EditAnywhere)
	 int32 _speed=3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		UStaticMeshComponent* leftmesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Companents")
		USphereComponent* leftmeshcollider;
	UPROPERTY(VisibleAnywhere)
		AEbersPlayer* mypalyer;
	virtual void Tick(float DeltaTime) override;
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void updateposition(float time);



protected:
	virtual void BeginPlay() override;

};
