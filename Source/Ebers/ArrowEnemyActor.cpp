// Fill out your copyright notice in the Description page of Project Settings.


#include "ArrowEnemyActor.h"

// Sets default values
AArrowEnemyActor::AArrowEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	Arrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arrow"));
	ArrowCollision = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArrowCollision"));
	Arrow->SetupAttachment(RootComponent);
	ArrowCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AArrowEnemyActor::BeginPlay()
{

	Super::BeginPlay();
	////Arrow->SetStaticMesh(ArrowMesh);
	//Arrow->SetMaterialByName("Opacity",0);
	////ArrowCollision->SetStaticMesh("Horizontal_Verticall_Arrow");
	//Arrow->SetStaticMesh (Cast <UStaticMesh>(GetDefaultSubobjectByName(TEXT("Horizontal_Verticall_Arrow"))));
	//

}

// Called every frame
void AArrowEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

