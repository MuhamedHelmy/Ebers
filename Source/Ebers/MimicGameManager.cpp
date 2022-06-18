#include "MimicGameManager.h"
// Fill out your copyright notice in the Description page of Project Settings.
#include "MimicGameManager.h"
#include "WallActor.h"
#include "MimicExSet.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>


// Sets default values
AMimicGameManager::AMimicGameManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

void AMimicGameManager::BeginPlay()
{
	Super::BeginPlay();
	//FTimerHandle SpawningManager;
	//	GetWorld()->GetTimerManager().SetTimer(SpawningManager, this, &AMimicGameManager::spawnWAlls, timebetweenSpawning, true);
	TArray<AActor*> player;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", player);
	if (player.Num() > 0) {
		mypalyer = Cast<AEbersPlayer>(player[0]);

	}

}
void AMimicGameManager::Tick(float DeltaTime)
{
	if (_isGameStarted) {
		selectExersice();
		_isGameStarted = false;
	}
	
}
void AMimicGameManager::spawnWAllsets() {
	while (wavesnum > 0)
	{
	for (int32 i = 0; i < mimcEXsets.Num(); i++)
		{

			int32 Rip;
			float collectablesdis = 0;
			temp = Cast<AMimicExSet>(GetWorld()->SpawnActor<AMimicExSet>(mimcEXsets[i], GetActorLocation() + FVector(0,pos, 0), GetActorRotation()));
			temp->walls_distance = distance;
			Spawnedwalles.Add(temp);
			if (i == repeatedIndex) {
				Rip = temprepet;
				temp->spawnWAlls(speed, temprepet);
				collectablesdis+=pos+distance/2;
				tempcollectables = Cast<ACollectables>(GetWorld()->SpawnActor<ACollectables>(collectables, GetActorLocation() + FVector(collectablesdis, 0, 150)
					, GetActorRotation()));
				//pos += temp->walls_distance;
				pos += temp->wallsShapes.Num()*Rip *temp->walls_distance;

				
			}
			else
			{
				Rip = 1;
				temp->spawnWAlls(speed, Rip);
			    collectablesdis+= pos + distance / 2;
				tempcollectables = Cast<ACollectables>(GetWorld()->SpawnActor<ACollectables>(collectables, GetActorLocation() + FVector(collectablesdis, 0, 150)
					, GetActorRotation()));
				pos += temp->wallsShapes.Num()*Rip *temp->walls_distance;

			}
		}
		wavesnum--;

	}
}

void AMimicGameManager::spawnRandomSets()
{

	while (wavesnum > 0)
	{

		for (int32 i = 0; i < mimcEXsets.Num(); i++)
		{

			float x = FMath::RandRange(0, mimcEXsets.Num() - 1);
			temp = Cast<AMimicExSet>(GetWorld()->SpawnActor<AMimicExSet>(mimcEXsets[x],
				GetActorLocation() + FVector(pos, 0, 0), GetActorRotation()));
			temp->walls_distance = distance;
			temp->spawnWAlls(speed, temprepet);
			Spawnedwalles.Add(temp);
			pos += temp->wallsShapes.Num()*temprepet *temp->walls_distance;

		}
		wavesnum--;
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
	mimcEXsets.Swap(0, num);

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
	case RepeatEX::defval:
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
		return repeat;
}

void AMimicGameManager::selectExersice()
{
	temprepet = repeatEx(Exrepeat);
	switch (setselectionEx)
	{
	case SetSelection::NONe:
	case  SetSelection::Set01:

		starter = 0;
		spawnWAllsets();
		break;
	case SetSelection::set02:
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
		temprepet = 1;
		spawnRandomSets();
	}
}



FString AMimicGameManager::exerciseName(AWallActor * wall)
{
	FString ExerciseName;
	//UE_LOG(LogTemp, Error, TEXT("name : DSDFSDFSDF"));
	for (int32 i = 0;i < Spawnedwalles.Num();i++)
	{

		for (int32 j=0;j<Spawnedwalles[i]->wallsShapes.Num();j++)
		{
			FString walllsname = *Spawnedwalles[i]->wallsShapes[j]->GetFName().ToString();
			FString mwall = wall->GetFName().ToString();
			mwall.RemoveAt(13, 5);
			if (walllsname==mwall) {
				ExerciseName = Spawnedwalles[i]->GetFName().ToString();
			}
		}
	}
	UE_LOG(LogTemp, Error, TEXT("%s"), *ExerciseName);
	return ExerciseName;
}






