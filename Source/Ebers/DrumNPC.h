// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrumManger.h"
#include "DrumNPC.generated.h"

class ADrumManger;
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

	UPROPERTY(EditAnywhere)
		USkeletalMesh* Koko;

	UPROPERTY(EditAnywhere)
		UAnimationAsset* IDLEAnim;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//ADrumManager* GetManager();

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

private :
	FTimerHandle TimerHandle;
	void Kill();
};
