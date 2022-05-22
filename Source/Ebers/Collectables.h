// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectables.generated.h"

UCLASS()
class EBERS_API ACollectables : public AActor
{
	GENERATED_BODY()

	
public:
	ACollectables();
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		float WallMovementSpeed;

	virtual void Tick(float DeltaTime) override;
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void updateposition(float time);



protected:
	virtual void BeginPlay() override;

};
