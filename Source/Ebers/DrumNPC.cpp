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

	
}

// Called when the game starts or when spawned
void ADrumNPC::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ADrumNPC::OnCollision);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrumNPC::Kill, 8.f, false, 8.0f);

	TArray<AActor*> Found;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "DrumManager", Found);
	if (Found.Num() > 0) {
		DManager = Cast<ADrumManger>(Found[0]);
	}
}

void ADrumNPC::Kill()
{
	DManager->SpawnNextExercise = true;
	if (ExerciseSide == EExerciseSide::Right) {
		/*UE_LOG(LogTemp, Error, TEXT("This is a right exercise "));
		UE_LOG(LogTemp, Error, TEXT("------------------------------------ "));*/
	}
	else {
		/*UE_LOG(LogTemp, Error, TEXT("This is a LEFT exercise "));
		UE_LOG(LogTemp, Error, TEXT("------------------------------------ "));*/
	}
	Destroy();
}

void ADrumNPC::SetExerciseSide(bool isRight)
{
	
	if (isRight) {
		ExerciseSide = EExerciseSide::Right;
	}
	else {
		ExerciseSide = EExerciseSide::Left;
	}
}

// Called every frame
void ADrumNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADrumNPC::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Error, TEXT("Drum have hit =====>  : %s "), *OtherActor->GetFName().ToString());
	if (ExerciseSide == EExerciseSide::Right) {
		/*UE_LOG(LogTemp, Error, TEXT("This is a right exercise "));
		UE_LOG(LogTemp, Error, TEXT("------------------------------------ "));*/
	}
	else {
		/*UE_LOG(LogTemp, Error, TEXT("This is a LEFT exercise "));
		UE_LOG(LogTemp, Error, TEXT("------------------------------------ "));*/
	}
	DManager->SetSpawnNextExercise(true);

	DManager->AddToScore(5.f);

	Destroy();
}



