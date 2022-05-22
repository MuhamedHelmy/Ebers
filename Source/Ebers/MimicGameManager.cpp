// Fill out your copyright notice in the Description page of Project Settings.
#include "MimicGameManager.h"
#include "WallActor.h"
#include "MimicExSet.h"


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
	temprepet=repeatEx(Exrepeat);
	switch (setselectionEx)
	{
			case SetSelection::NONe :
			case  SetSelection::Set01:
		
				starter = 0;
				spawnWAllsets();
				break;
			case SetSelection::set02 :
					starter = 1;
					swapSetOfExersices(starter);
					spawnWAllsets();
					break;
			case SetSelection::set03:
				starter = 2;
				swapSetOfExersices(starter);
				spawnWAllsets();
				break;
			case SetSelection::set04:
				starter = 3;
				swapSetOfExersices(starter);
				spawnWAllsets();
				break;
			case SetSelection::set05:
				starter = 4;
				swapSetOfExersices(starter);
				spawnWAllsets();
				break;
			case SetSelection::randomsel:
				temprepet = 1;				spawnRandomSets();
	}
	

	//FTimerHandle SpawningManager;
	//	GetWorld()->GetTimerManager().SetTimer(SpawningManager, this, &AMimicGameManager::spawnWAlls, timebetweenSpawning, true);

	
}
void AMimicGameManager::spawnWAllsets() {
	while (iterations>0)
	{


		
			for (int32 i = 0; i < SpawnActors.Num(); i++)
			{

				int32 Rip;
				temp = Cast<AMimicExSet>(GetWorld()->SpawnActor<AMimicExSet>(SpawnActors[i], GetActorLocation() + FVector(pos, 0, 0), GetActorRotation()));
				temp->walls_distance = distance;

				if (i == repeatedIndex) {
				Rip = temprepet;
				temp->spawnWAlls(speed, temprepet);
				pos += temp->SpawnActors.Num()*Rip *temp->walls_distance;
				//
				UE_LOG(LogTemp,Error,TEXT("repeated index %d"),repeatedIndex)
				}
				else
				{
					Rip = 1;
					temp->spawnWAlls(speed, Rip);
					pos += temp->SpawnActors.Num()*Rip *temp->walls_distance;
					UE_LOG(LogTemp, Error, TEXT("_________________________________________"))
				}
			}
			iterations--;
		
	}
}

void AMimicGameManager::spawnRandomSets()
{

	while (iterations>0)
	{

		for (int32 i = 0; i < SpawnActors.Num(); i++)
		{

			float x = FMath::RandRange(0, SpawnActors.Num() - 1);
			temp = Cast<AMimicExSet>(GetWorld()->SpawnActor<AMimicExSet>(SpawnActors[x],
				GetActorLocation() + FVector(pos, 0, 0), GetActorRotation()));
			temp->walls_distance = distance;
			temp->spawnWAlls(speed, temprepet);
			pos += temp->SpawnActors.Num()*temprepet *temp->walls_distance;


		}
		iterations--;
	}
	
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

void AMimicGameManager::swapSetOfExersices(int32 num)
{
	SpawnActors.Swap(0, num);

	if (num == repeatedIndex) {
		repeatedIndex = 0;
	}
	else if (repeatedIndex == 0) {
		repeatedIndex = num;
	}
	
}

int32 AMimicGameManager::repeatEx(int32 num)
{

	switch (_repeatEx)
	{
			case RepeatEX::defval :
			{
				repeat = 1;
				repeatedIndex = -1;
				break;
			}
			case RepeatEX::ReSet01:
			{
				repeat = num;
				repeatedIndex = 0;
				break;

			}
			case RepeatEX::Reset02:
			{

				repeat = num;
				repeatedIndex = 1;
				break;

			}
			case RepeatEX::Reset03:
			{

				repeat = num;
				repeatedIndex = 2;
				break;
			}
			case RepeatEX::Reset04:
			{

				repeat = num;
				repeatedIndex = 3;
				break;
			}
			case RepeatEX::Reset05:
			{

				repeat = num;
				repeatedIndex = 4;
				break;

			}

			}
	

	UE_LOG(LogTemp, Error, TEXT("sdfsdf %d"), repeatedIndex)

	return repeat;
}



