// Fill out your copyright notice in the Description page of Project Settings.


#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "DrumNPC.h"

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


	UE_LOG(LogTemp, Error, TEXT("Doumy initiated !!! "));
}

// Called when the game starts or when spawned
void ADrumNPC::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ADrumNPC::OnCollision);
	TArray<AActor*> Found;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "DrumManager", Found);
	if (Found.Num() > 0) {
		DManager = Cast<ADrumManger>(Found[0]);
	}
}

// Called every frame
void ADrumNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADrumNPC::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	// spawn next set 
	//ADrumManager* DManager;
	
	
	DManager->SetSpawnNextExercise(true);
}



