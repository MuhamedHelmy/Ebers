#include "DrumNPC.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "DrumNPC.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "NiagaraFunctionLibrary.h"


ADrumNPC::ADrumNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	//Mesh->OnComponentBeginOverlap.AddDynamic(this  , &ADrum::OnOverlap);
		

		
}

void ADrumNPC::BeginPlay()
{
	Super::BeginPlay();


	//SetLifeSpan(KillDelayTime +1.5f); 

	//Mesh->SetSkeletalMesh(Koko);

	//Mesh->SetRelativeScale3D(GetActorScale() * 2.0f);
	//Mesh->SetAnimation(IDLEAnim);

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ADrumNPC::OnCollision);
	TArray<AActor*> Found;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "DrumManager", Found);
	if (Found.Num() > 0) {
		DManager = Cast<ADrumManger>(Found[0]);
	}

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumNPC::Kill, KillDelayTime, false, KillDelayTime);

	UE_LOG(LogTemp, Error, TEXT("Doumy initiated !!! "));
	candoit = true;
	//TempArrow = 
	//HitVar = 0.0f;
}


void ADrumNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playHitAnim  && HitVar  < 2.5 ) {
		HitVar += AnimationSwitchRate;
	}

}
void ADrumNPC::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
		
	
	if ( (OtherComponent->GetFName().ToString() == "RightHand") || (OtherComponent->GetFName().ToString() == "LeftHand")) {
		if (candoit) {

		UE_LOG(LogTemp, Error, TEXT("Drum have hit =====>  : %s "), *OtherActor->GetFName().ToString());
		DManager->SetSpawnNextExercise(true);
		DManager->AddToScore(5.f);
		DManager->AddToNumOfNpcHit(1);
		playHitAnim = true;
		//GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumNPC::Despawn, AfterHitDelay, false, AfterHitDelay);
		Despawn();
		if (NS_HitExplosion) {
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NS_HitExplosion, GetActorLocation());
		}
		if (SB_HitSound) {
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), SB_HitSound, GetActorLocation());
		}
		candoit = false;
		DManager->SetSpawnNextExercise(true);
		//DManager->UpdateCageDisolve(0.f , 0.f);
	


		}
	}
	


	
}

void ADrumNPC::PlayHitAnimation()
{
}

void ADrumNPC::Kill()
{
	DManager->SetSpawnNextExercise(true);
	if (NS_HitExplosion) {
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld() , NS_HitExplosion , GetActorLocation());
	}
	if (SB_HitSound) {
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SB_HitSound, GetActorLocation());
	}
	Destroy();
}



void ADrumNPC::Despawn()
{

	Destroy();
}
