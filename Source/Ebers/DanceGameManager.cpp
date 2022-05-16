// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceGameManager.h"
#include "DanceEnemy.h"
#include "EbersPlayer.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
// Sets default values
ADanceGameManager::ADanceGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADanceGameManager::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();
	spawnLocation.Z = 300;
	spawnLocation.X = 100.0f;

	SpawnDanceEnemyHorizontal(90,true);
	SpawnDanceEnemyHorizontal(90,false);
	SpawnDanceEnemyHorizontal(90, true);
	spawnLocation.Z = 300.0f;
	spawnLocation.X = 100.0f;
	spawnLocation.Y = 0.0f;
	angle = 0;

	SpawnDanceEnemyVertical(60, true);
	SpawnDanceEnemyVertical(60, false);
	SpawnDanceEnemyVertical(60, true);

	spawnLocation.Z = 100; //Down
	spawnLocation.X = 100.0f;
	spawnLocation.Y = 0.0f;
	angle = 0;

	SpawnDanceEnemyHorizontal(90, true);
	SpawnDanceEnemyHorizontal(90, false);
	SpawnDanceEnemyHorizontal(90, true);

	spawnLocation.Z = 300; 
	spawnLocation.X = 100.0f;
	spawnLocation.Y = 0.0f;
	angle = 0;



	SpawnDanceEnemyTriangle(90, true);
	SpawnDanceEnemyTriangle(90, false);
	SpawnDanceEnemyTriangle(90, true);

	//UE_LOG(LogTemp, Warning, TEXT("----------------BeginPlayGameDance---------------"));
//	CharacterRef = Cast<AEbersPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//UE_LOG(LogTemp, Warning, TEXT("hiiiiii : %f"), getplayerpawn);
	//if(GetWorld()->GetFirstPlayerController()->GetActorLocation())
	if (CharacterRef) {
		UE_LOG(LogTemp, Warning, TEXT("----------------MyCharacter---------------"));

		spawnLocation.X = CharacterRef->mycamera->GetComponentLocation().X + 100;
		spawnLocation.Y = 0;
		spawnLocation.Z = CharacterRef->mycamera->GetComponentLocation().Z + 100;

	}

	DanceEnemies[EnemyIndex]->canAttack = true;

}
// Called every frame
void ADanceGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CharacterRef) {

		spawnLocation.Z = CharacterRef->mycamera->GetComponentLocation().Z + 100;
		UE_LOG(LogTemp, Warning, TEXT("----------------caaaam---------------"));

	}
	if (DanceEnemies.IsValidIndex(EnemyIndex))
	{

		if (DanceEnemies[EnemyIndex]->DanceEnemyHealth == 0) {

			EnemyIndex += 1;
			UE_LOG(LogTemp, Warning, TEXT("----------------indeeeex---------------%d"), EnemyIndex);

			if (DanceEnemies.IsValidIndex(EnemyIndex))
			DanceEnemies[EnemyIndex]->canAttack = true;
		}
}

}
void ADanceGameManager::SpawnDanceEnemyHorizontal(float maxAngle,bool direction)
{
	//spawnLocation.Z = 20;
	MaxAngle = maxAngle;
	if (direction)angleDirection = 1;
	else angleDirection = -1;
	if (MyDanceEnemy) {

	while (abs(angle)<=MaxAngle)
	{
		UE_LOG(LogTemp, Warning, TEXT("%f"), angle);

			
			FActorSpawnParameters spawnParams;


			AActor* temp = world->SpawnActor<ADanceEnemy>(MyDanceEnemy, spawnLocation, spawnRotation, spawnParams);

			ADanceEnemy* t = Cast<ADanceEnemy>(temp);


			DanceEnemies.Add(t);
			angle += 30 * angleDirection;

			spawnLocation.Y = 100 * sin(angle*PI/180);
			spawnLocation.X = 100 * cos(angle * PI / 180);


		}
	}
	angle = MaxAngle * angleDirection;
	spawnLocation.Y = 100 * sin(angle * PI / 180);
	spawnLocation.X = 100 * cos(angle * PI / 180);
}

void ADanceGameManager::SpawnDanceEnemyVertical(float maxAngle, bool direction)
{
	//spawnLocation.Z = 20;
	MaxAngle = maxAngle;
	if (direction)angleDirection = 1;
	else angleDirection = -1;
	if (MyDanceEnemy) {

		while (abs(angle) <= MaxAngle)
		{
			UE_LOG(LogTemp, Warning, TEXT("%f"), angle);


			FActorSpawnParameters spawnParams;


			AActor* temp = world->SpawnActor<ADanceEnemy>(MyDanceEnemy, spawnLocation, spawnRotation, spawnParams);

			ADanceEnemy* t = Cast<ADanceEnemy>(temp);


			DanceEnemies.Add(t);
			angle += 30 * angleDirection;

			spawnLocation.Z = 100 * sin(angle * PI / 180)+300;
			spawnLocation.X = 100 * cos(angle * PI / 180);


		}
	}
	angle = MaxAngle * angleDirection;
	spawnLocation.Z = 100 * sin(angle * PI / 180)+300;
	spawnLocation.X = 100 * cos(angle * PI / 180);
}

void ADanceGameManager::SpawnDanceEnemyTriangle(float maxAngle, bool direction)
{
	//spawnLocation.Z = 20;
	MaxAngle = maxAngle;
	if (direction)angleDirection = 1;
	else angleDirection = -1;
	if (MyDanceEnemy) {

		while (abs(angle) <= MaxAngle)
		{
			UE_LOG(LogTemp, Warning, TEXT("%f"), angle);


			FActorSpawnParameters spawnParams;


			AActor* temp = world->SpawnActor<ADanceEnemy>(MyDanceEnemy, spawnLocation, spawnRotation, spawnParams);

			ADanceEnemy* t = Cast<ADanceEnemy>(temp);


			DanceEnemies.Add(t);
			angle += 30 * angleDirection;

			spawnLocation.Z = 100 * cos(angle * PI / 180) + 200;
			spawnLocation.Y = 100 * sin(angle * PI / 180);

			UE_LOG(LogTemp, Warning, TEXT("----------------tttttttttttttttttttttttttttt---------------"));

		}
	}
	UE_LOG(LogTemp, Warning, TEXT("----------------tttttttttttttttttttttttttttt---------------"));

	angle = MaxAngle * angleDirection;
	spawnLocation.Z = 100 * cos(angle * PI / 180) + 200;
	spawnLocation.Y = 100 * sin(angle * PI / 180);
}