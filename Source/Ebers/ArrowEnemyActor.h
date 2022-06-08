// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowEnemyActor.generated.h"

UCLASS()
class EBERS_API AArrowEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowEnemyActor();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Arrow;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ArrowCollision;
	//UBoxComponent* CollisionMesh;
	//UPROPERTY(EditAnywhere)
	//	UStaticMesh* ArrowMesh;
	//UPROPERTY(EditAnywhere)
	//	UStaticMesh* ArrowCollisionMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HitCurve = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
