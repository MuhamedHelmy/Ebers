// Fill out your copyright notice in the Description page of Project Settings.
#include "MimicGameManager.h"
#include "WallActor.h"


// Sets default values
AMimicGameManager::AMimicGameManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (wavesnum != 5) { iterations = wavesnum; }
	else { iterations = 5; }

}

void AMimicGameManager::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle SpawningManager;


	while (iterations > 0)
	{


		GetWorld()->GetTimerManager().SetTimer(SpawningManager, this, &AMimicGameManager::spawnWAlls, timebetweenSpawning, true);

	}
}
void AMimicGameManager::spawnWAlls() {



	for (int32 i = 0; i < SpawnActors.Num(); i++)
	{
		if (randomGeneration) {
			float x = FMath::RandRange(0, SpawnActors.Num() - 1);
			temp = GetWorld()->SpawnActor<AWallActor>(SpawnActors[x], GetActorLocation() + FVector(0, pos, 0), GetActorRotation());

		}
		else {
			temp = GetWorld()->SpawnActor<AWallActor>(SpawnActors[i], GetActorLocation() + FVector(0, pos, 0), GetActorRotation());

		}
		temp->WallMovementSpeed = speed;
		pos += distance;
	}
	iterations--;
	pos = 0;

	UE_LOG(LogTemp, Error, TEXT("saddsfd %f"), iterations);

}

void AMimicGameManager::returnJason()
{
	/*TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("key1", string_value);
	JsonObject->SetNumberField("key2", int_value);
	JsonObject->SetBoolField("key3", boolean_value);

	TSharedRef<TJsonWriter<>> json_writer = TJsonWriterFactory<>::Create(&data_to_send);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), json_writer);*/
}

