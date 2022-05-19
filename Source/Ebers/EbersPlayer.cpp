// Fill out your copyright notice in the Description page of Project Settings.


#include "EbersPlayer.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AEbersPlayer::AEbersPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEbersPlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEbersPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GetWorld()->LineTraceSingleByChannel(hit, StartLaser, EndLaser, ECollisionChannel::ECC_GameTraceChannel1);
}

// Called to bind functionality to input
void AEbersPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void DrawLeser()
{
//FVector   Location;
//FRotator Rotation;
//
//OwnerController->GetPlayerViewPoint(Location, Rotation);
//
//FVector End = Location + Rotation.Vector() * MaxRange;
//
//FHitResult hit;
//
//if (GetWorld()->LineTraceSingleByChannel(hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1)) {
//	FVector ShotDirection = -Rotation.Vector();
//	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, hit.Location, ShotDirection.Rotation());
//
//	if (hit.GetActor() != nullptr) {
//		FPointDamageEvent DamageEvent(Damage, hit, ShotDirection, nullptr);
//		hit.GetActor()->TakeDamage(Damage, DamageEvent, OwnerController, this);
//
//	}
//
//
//}
}