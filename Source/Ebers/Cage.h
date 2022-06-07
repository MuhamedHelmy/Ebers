// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Cage.generated.h"



UCLASS()
class EBERS_API ACage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void setDisolveValue(float newDis  , float oldDis);

	

private :
		/*UPROPERTY(EditAnywhere)
			UStaticMesh* CageDoorMesh;*/

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* CageDoorMeshComponent;
	//UPROPERTY(VisibleAnywhere)
	//	UStaticMeshComponent* CageBodyComponent;
	/*UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Root;*/

	UMaterialInterface *CageDoorMaterial; 
	UMaterialInstanceDynamic* CageDoorDynamicMat;


	bool startdesolve = false;
	float DisolveValue; 
	float  OldDisolveValue;
};
