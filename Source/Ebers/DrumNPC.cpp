#include "DrumNPC.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "DrumNPC.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ADrumNPC::ADrumNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	//Mesh->OnComponentBeginOverlap.AddDynamic(this  , &ADrum::OnOverlap);


	//UE_LOG(LogTemp, Error, TEXT("Doumy initiated !!! "));
}

// Called when the game starts or when spawned
void ADrumNPC::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetSkeletalMesh(Koko);
	Mesh->SetRelativeScale3D(GetActorScale() * 5.0f);
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ADrumNPC::OnCollision);
	TArray<AActor*> Found;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "DrumManager", Found);
	if (Found.Num() > 0) {
		DManager = Cast<ADrumManger>(Found[0]);
	}

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumNPC::Kill, 4.f, false, 4.0f);
}

// Called every frame
void ADrumNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADrumNPC::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Error, TEXT("Drum have hit =====>  : %s "), *OtherActor->GetFName().ToString());
	DManager->SetSpawnNextExercise(true);
	DManager->AddToScore(5.f);
	

	Destroy();
}

void ADrumNPC::Kill()
{
	DManager->SetSpawnNextExercise(true);
	Destroy();
}


