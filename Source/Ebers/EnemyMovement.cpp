// Fill out your copyright notice in the Description page of Project Settings.
#include "EnemyMovement.h"

#include "DanceEnemy.h"
#include <Editor/SceneOutliner/Public/SceneOutlinerVisitorTypes.h>

// Sets default values
AEnemyMovement::AEnemyMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyMovement::BeginPlay()
{
	Super::BeginPlay();
	StartIndex = 0;
	EndIndex = 1;
	UWorld* WorldRef = GetWorld();
	//StartVector = MyDanceGameManager->DanceEnemies[StartIndex]->GetActorLocation();
	//EndVector = MyDanceGameManager->DanceEnemies[EndIndex]->GetActorLocation();


}

// Called every frame
void AEnemyMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MyDanceGameManager) {
		//	UE_LOG(LogTemp, Error, TEXT("khokho %d"), MyDanceGameManager->DanceEnemies[0]);

		if (MyDanceGameManager->DanceEnemies.IsValidIndex(EndIndex)) {

			//UE_LOG(LogTemp, Error, TEXT("khokho %d"), StartIndex);

			StartVector = MyDanceGameManager->DanceEnemies[StartIndex]->GetActorLocation();
		//	UE_LOG(LogTemp, Error, TEXT("khokho %s"), *StartVector.ToString());

			EndVector = MyDanceGameManager->DanceEnemies[EndIndex]->GetActorLocation();
			FVector Movement = FMath::Lerp(StartVector, EndVector, lerppram);
			lerppram += 0.1;
			SetActorLocation(Movement);
		//	86.603 Y = 50.000 Z = 300.000

		}
	}
	if (MyDanceGameManager->DanceEnemies.IsValidIndex(EndIndex+1)&&EndVector.X >= GetActorLocation().X-0.5f&& EndVector.Y >= GetActorLocation().Y - 0.5f&& EndVector.Z >= GetActorLocation().Z - 0.5f) {
		StartIndex++;
		lerppram = 0;
		EndIndex++;
		UE_LOG(LogTemp, Error, TEXT("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh %d"), StartIndex);

	}
}

