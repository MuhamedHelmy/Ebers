// Fill out your copyright notice in the Description page of Project Settings.
#include "MimicGameManager.h"
#include "WallActor.h"


// Sets default values
AMimicGameManager::AMimicGameManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);*/

}

// Called when the game starts or when spawned
void AMimicGameManager::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();

	//StartMovingWalls = true;


	SpawnWalls();



}

// Called every frame
void AMimicGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


void AMimicGameManager::InitializeWalls()
{
	//spawnLocation.Z = 20;
	for (size_t i = 0; i < 10; i++)
	{
		if (WallClass) {

			FActorSpawnParameters spawnParams;


			AActor* temp = world->SpawnActor<AWallActor>(WallClass, spawnLocation, wallRotation, spawnParams);

			AWallActor* t = Cast<AWallActor>(temp);

			/*FVector newLocation = t->GetActorLocation();
			newLocation.Z += 20 ;
			t->SetActorLocation(newLocation);*/

			UStaticMeshComponent* x = Cast<UStaticMeshComponent>(t->Root->GetChildComponent(0));

			//	if (MeshesOfTheWalls[i] != nullptr) {
			x->SetStaticMesh(MeshesOfTheWalls[i]);
			//}

			// t->SetActorHiddenInGame(true);

			Walls.Add(t);
			

			spawnLocation.X += OffsetBetweenWalls;
		}

		UE_LOG(LogTemp, Warning, TEXT("Y Location : %f"), Walls[i]->GetActorLocation().Y);

	}
	UE_LOG(LogTemp, Warning, TEXT("-------------------------------"));




	/*for (AWallActor* Actor : Walls)
	{
		UE_LOG(LogTemp, Warning, TEXT("Location "), Actor->GetActorLocation());
	}*/
	//UE_LOG(LogTemp, Warning, TEXT("Location ") , Walls[0]->GetActorLocation());
}
//void AMimicGameManager::MoveWalls(float speed) {
//	for (int32 i = 0; i < Walls.Num(); i++)
//	{
//
//		
//		//FVector newLocation = Walls[i]->GetActorLocation();
//
//		//if (Walls[i]) {
//		//	newLocation.X = newLocation.X - speed;
//		//	Walls[i]->SetActorLocation(newLocation);
//		//}
//
//
//	}
//
//	//	WallsCounter++;
//
//	
//}

void AMimicGameManager::SpawnWalls()
{
	InitializeWalls();
	/*if (WallClass) {

		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			AActor* temp = world->SpawnActor<AWallActor>(WallClass, spawnLocation, wallRotation, spawnParams);
			AWallActor* wall = Cast<AWallActor>(temp);

			if (wall) {

			}
		}
	}*/

}
