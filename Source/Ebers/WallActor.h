// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include<Ebers//EbersPlayer.h>
#include "GameFramework/Actor.h"
#include <Ebers/LightTrigger.h>
#include "Components/BoxComponent.h"
#include "WallActor.generated.h"

USTRUCT()
struct FAccuracyData
{
	GENERATED_BODY()
public:
	FString ErrorExerciseName;
	int32 Accurcy;
	bool  rightHandeCollision;
	bool  leftHandeCollision;
	bool classCompleted;
	FAccuracyData() {
		ErrorExerciseName = "";
		Accurcy = 100;
		rightHandeCollision = false;
		leftHandeCollision = false;
		classCompleted = false;
	}
};

UCLASS()
class EBERS_API AWallActor : public AActor
{
	GENERATED_BODY()

public:
	AWallActor();
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		float WallMovementSpeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent * rightHand ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent * leftHand;
	UPROPERTY(VisibleAnywhere)
	AEbersPlayer* mypalyer;
	UPROPERTY()
	TArray<FAccuracyData>data;
	class AMimicGameManager * temp11;
	//class AlightTrigger* lightt;
	UPROPERTY(VisibleAnywhere)
	ALightTrigger *light;

	bool getNamed;
	virtual void Tick(float DeltaTime) override;
	void updateposition(float time);
	UFUNCTION()
	void leftHandOnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void lefthandendoverlape(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private :
	bool righthandcollision;
	bool lefthandcolllision;
	bool rightHandscored;
	bool leftHandScored;
	
	FAccuracyData  acdata;
protected:
	virtual void BeginPlay() override;

	
	//UFUNCTION()
	//	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//UFUNCTION()
	//	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

		//void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
