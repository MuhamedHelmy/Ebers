// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrumManger.h"
#include "DrumNPC.generated.h"

class UNiagaraSystem;
class USoundBase;
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
	UPROPERTY()
		ADrumManger* DManager;
protected:
	UPROPERTY(EditDefaultsOnly)
		UNiagaraSystem* NS_HitExplosion;
	UPROPERTY(EditDefaultsOnly)
		USoundBase* SB_HitSound;
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
	

private :
	FTimerHandle TimerHandle;
	void Kill();
};
