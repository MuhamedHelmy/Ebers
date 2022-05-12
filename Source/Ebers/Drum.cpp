// Fill out your copyright notice in the Description page of Project Settings.
#include "Drum.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADrum::ADrum()
{
	sceneCompanent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComapanent"));
	RootComponent = sceneCompanent;

	collider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	collider->SetupAttachment(RootComponent);
	collider->SetCollisionProfileName(TEXT("OverLapeOnly pawn"));

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh"));
	staticMesh->SetupAttachment(collider);
	staticMesh->SetCollisionProfileName(TEXT("OverLap only Pawn"));

}

// Called when the game starts or when spawned
void ADrum::BeginPlay()
{
	Super::BeginPlay();
	collider->OnComponentBeginOverlap.AddDynamic(this, &ADrum::OnOverlapBegin);

	
}
void ADrum::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if (overlapSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), overlapSound, GetActorLocation());
	}

	if (OtherComp->GetFName().ToString() == "RightHandCollider") {

		UE_LOG(LogTemp, Warning, TEXT("biiiiiii %s"), *OtherComp->GetFName().ToString());
		//ChangePos();
	}

}

// Called every frame


