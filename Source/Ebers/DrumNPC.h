// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DrumNPC.generated.h"

class UNiagaraSystem;
class USoundBase;
class ADrumManger;
class ACage;
UCLASS()
class EBERS_API ADrumNPC : public APawn
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
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
		float HitVar;

	UPROPERTY(EditAnywhere)
		float KillDelayTime = 3.0f;
	UPROPERTY(EditAnywhere)
		float AnimationSwitchRate = 0.08;

	UPROPERTY(EditAnywhere)
		float AfterHitDelay = 1.0f;
	bool candoit;

	UPROPERTY()
		ACage* Cage;
protected:
	UPROPERTY(EditDefaultsOnly)
		UNiagaraSystem* NS_HitExplosion;
	UPROPERTY(EditDefaultsOnly)
		USoundBase* SB_HitSound;

	UPROPERTY()
		UStaticMeshComponent* TempArrow; 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Despawn();
	bool GotCage = false;

	//ADrumManager* GetManager();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
		void PlayHitAnimation();
	/*UPROPERTY()
		ADrumManger* DrumManager;*/
	

private :
	FTimerHandle TimerHandle;
	FTimerHandle KillTimerHandle;
	void Kill();

	bool playHitAnim = false; 


	bool GetCage();

	
};
