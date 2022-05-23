// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceGameManager.h"
#include "DanceEnemy.h"
#include "EbersPlayer.h"
#include "Math/UnrealMathUtility.h"

#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
//#include "../../../../Epic Games/UE_4.27/Engine/Plugins/FX/Niagara/Source/Niagara/Classes/NiagaraDataInterface.h"
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

	spawnLocation.Z = PlayerLenH;
	spawnLocation.X = 100.0f;
	MyEnemyMaterial = EnemyMaterial;



	//UE_LOG(LogTemp, Warning, TEXT("----------------BeginPlayGameDance---------------"));
	CharacterRef = Cast<AEbersPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//UE_LOG(LogTemp, Warning, TEXT("hiiiiii : %f"), getplayerpawn);
	//if(GetWorld()->GetFirstPlayerController()->GetActorLocation())
	//if (CharacterRef) {
	//	UE_LOG(LogTemp, Warning, TEXT("----------------MyCharacter---------------"));

	//	spawnLocation.X = CharacterRef->mycamera->GetComponentLocation().X + 100;
	//	spawnLocation.Y = 0;
	//	spawnLocation.Z = CharacterRef->mycamera->GetComponentLocation().Z + 100;

	//}

	//DanceEnemies[EnemyIndex]->canAttack = true;

}
// Called every frame
void ADanceGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (CharacterRef) {

	//	spawnLocation.Z = CharacterRef->mycamera->GetComponentLocation().Z + 100;
	//	UE_LOG(LogTemp, Warning, TEXT("----------------caaaam---------------"));

	//}
	//if (GetWorld()->GetFirstPlayerController()->GetCharacter()) {
	//	 tempchar = GetWorld()->GetFirstPlayerController()->GetCharacter();
	//	 tchar = Cast<AEbersPlayer>(tempchar);
	//	if (tchar) {
	//		//MyEbersPlayer = Cast<TSubclassOf<class AEbersPlayer>>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	//		if (tchar->mycamera) {
	//			UE_LOG(LogTemp, Warning, TEXT("----------------MyyyyyyPlayer---------------%f"), tchar->mycamera->GetComponentLocation().Z);
	//			PlayerLen = tchar->mycamera->GetComponentLocation().Z;
	//		}
	//	}
	//}
	// 
	// 

	//SpawnDanceEnemyHorizontal(90, true);
	//spawnLocation.Z = PlayerLenH;
	//spawnLocation.X = 100.0f;
	//spawnLocation.Y = 0.0f;
	//angle = 0;

	//SpawnDanceEnemyVertical(60, true);
	//SpawnDanceEnemyVertical(60, false);
	//SpawnDanceEnemyVertical(60, true);

	//spawnLocation.Z = 100; //Down
	//spawnLocation.X = 100.0f;
	//spawnLocation.Y = 0.0f;
	//angle = 0;

	//SpawnDanceEnemyHorizontal(90, true);
	//SpawnDanceEnemyHorizontal(90, false);
	//SpawnDanceEnemyHorizontal(90, true);

	//spawnLocation.Z = PlayerLenH;
	//spawnLocation.X = 100.0f;
	//spawnLocation.Y = 0.0f;
	//angle = 0;



	//SpawnDanceEnemyTriangle(90, true);
	//SpawnDanceEnemyTriangle(90, false);
	//SpawnDanceEnemyTriangle(90, true);


	//if (DanceEnemies.IsValidIndex(EnemyIndex))

	if (CurveNum <= 12) {


		if (DanceEnemies.IsValidIndex(EnemyIndex))
		{
			//if (DanceEnemies[EnemyIndex]){
			//		if (DanceEnemies[EnemyIndex]->MatChanged == CharacterRef->LaserChanged)
			//		{
			//			//	UE_LOG(LogTemp, Warning, TEXT("----------------indeeeex---------------%d"), EnemyIndex);
			//			DanceEnemies[EnemyIndex]->canAttack = true;
			//			//EnemyDanceMesh = Cast <UStaticMeshComponent>(DanceEnemies[EnemyIndex]->GetRootComponent());
			//			//if (StartMaterial) {
			//			//	if (EnemyDanceMesh) {
			//			//		EnemyDanceMesh->SetMaterial(0, StartMaterial);
			//			//	}
			//		}
			//		else
			//			DanceEnemies[EnemyIndex]->canAttack = false;
			//}

			if (DanceEnemies[EnemyIndex]) {

				DanceEnemies[EnemyIndex]->canAttack = true;

				if (DanceEnemies[EnemyIndex]->GetLifeSpan() == 0)
				{
					HorizontalAngle = round((asin(DanceEnemies[EnemyIndex]->GetActorLocation().Y / FarPlayer)) * 180 / PI);
					VerticalAngle = round((asin((round(DanceEnemies[EnemyIndex]->GetActorLocation().Z - PlayerLenH)) / FarPlayer)) * 180 / PI);
					strInfoForDoctor = "HorizontalAngle: " + FString::SanitizeFloat(HorizontalAngle) + "  VerticalAngle: " + FString::SanitizeFloat(VerticalAngle);
					strArrInfoForDoctor.Add(strInfoForDoctor);
					UE_LOG(LogTemp, Warning, TEXT("----------------str---------------%s"), *strInfoForDoctor);
					EnemyDanceMesh = Cast <UStaticMeshComponent>(DanceEnemies[EnemyIndex]->GetRootComponent());
					if (StartMaterial) {
						if (EnemyDanceMesh) {
							EnemyDanceMesh->SetMaterial(0, StartMaterial);
						}
					}
					//str_i_ForDoctor++;
				}

			}

			if (DanceEnemies[EnemyIndex] == nullptr || DanceEnemies[EnemyIndex]->DestroyedDone || DanceEnemies[EnemyIndex]->GetLifeSpan() == 0)
			{

				if (CharacterRef)
				{
					if (DanceEnemies.IsValidIndex(EnemyIndex + 1))
					{
						if (DanceEnemies[EnemyIndex + 1])
						{
							EnemyIndex += 1;
							UE_LOG(LogTemp, Warning, TEXT("----------------indeeeex---------------%d"), EnemyIndex);
							//	DanceEnemies[EnemyIndex]->canAttack = true;
							EnemyDanceMesh = Cast <UStaticMeshComponent>(DanceEnemies[EnemyIndex]->GetRootComponent());
							if (StartMaterial) {
								if (EnemyDanceMesh) {
									EnemyDanceMesh->SetMaterial(0, StartMaterial);
								}
							}
						}
					}
					else {
						EnemyIndex += 1;
					}
				}
			}

		}

		else {
			EnemyIndex = 0;

			//SpawnDanceEnemyHorizontal(90, false);
			MoveFromCurveToAnother();
			if (DanceEnemies.IsValidIndex(EnemyIndex))
				SetEnemyMaterial(StartMaterial, EnemyIndex);
			if (DanceEnemies.IsValidIndex(EnemyIndex)) {

				DanceEnemies[EnemyIndex]->canAttack = true;
				CurveNum++;
			}
			else
				UE_LOG(LogTemp, Warning, TEXT("----------------win---------------"));

		}

	}

}



void ADanceGameManager::SpawnDanceEnemyHorizontal(float maxAngle, bool direction)
{
	//if (direction) MyEnemydirection = 1;
	//else MyEnemydirection = 2;

	PlayerLenH = 200;
	spanLife_i = 0;
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

			t->SetLifeSpan(10 + spanLife_i);
			spanLife_i = spanLife_i + 2;
			//t->Enemydirection = MyEnemydirection;
			DanceEnemies.Add(t);
			angle += 30 * angleDirection;

			spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
			spawnLocation.X = FarPlayer * cos(angle * PI / 180);
			//if (DanceEnemies.Num() - 1 > 0) {
			//	RandMaterial(FMath::RandRange(0, 1), DanceEnemies.Num() - 1);
			//}


		}
	}
	angle = MaxAngle * angleDirection;
	spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
	spawnLocation.X = FarPlayer * cos(angle * PI / 180);
}

void ADanceGameManager::SpawnDanceEnemyVertical(float maxAngle, bool direction)
{
	//if (direction) MyEnemydirection = 3;
	//else MyEnemydirection = 4;

	PlayerLenH = 200;
	//spawnLocation.Z = 20;
	spanLife_i = 0;
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

			t->SetLifeSpan(10 + spanLife_i);
			spanLife_i = spanLife_i + 2;
			//t->Enemydirection = MyEnemydirection;

			DanceEnemies.Add(t);
			angle += 30 * angleDirection;

			spawnLocation.Z = FarPlayer * sin(angle * PI / 180) + PlayerLenH;
			spawnLocation.X = FarPlayer * cos(angle * PI / 180);
			//if (DanceEnemies.Num() - 1 > 0) {
			//	RandMaterial(FMath::RandRange(0, 1), DanceEnemies.Num() - 1);
			//}

		}
	}
	angle = MaxAngle * angleDirection;
	spawnLocation.Z = FarPlayer * sin(angle * PI / 180) + PlayerLenH;
	spawnLocation.X = FarPlayer * cos(angle * PI / 180);
}

void ADanceGameManager::SpawnDanceEnemyTriangle(float maxAngle, bool direction)
{
	//if (direction) MyEnemydirection = 3;
	//else MyEnemydirection = 4;


	//PlayerLenH = 100;
	//bTringle = true;
	spanLife_i = 0;
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

			t->SetLifeSpan(10 + spanLife_i);
			spanLife_i = spanLife_i + 2;
			//t->Enemydirection = MyEnemydirection;

			DanceEnemies.Add(t);
			angle += 30 * angleDirection;

			spawnLocation.Z = FarPlayer * cos(angle * PI / 180) + PlayerLenH - 100;
			spawnLocation.Y = FarPlayer * sin(angle * PI / 180);

			UE_LOG(LogTemp, Warning, TEXT("----------------tttttttttttttttttttttttttttt---------------"));
			//if (DanceEnemies.Num() - 1 > 0) {
			//	RandMaterial(FMath::RandRange(0, 1), DanceEnemies.Num() - 1);
			//}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("----------------tttttttttttttttttttttttttttt---------------"));

	angle = MaxAngle * angleDirection;
	spawnLocation.Z = FarPlayer * cos(angle * PI / 180) + PlayerLenH - 100;
	spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
}
void ADanceGameManager::MoveFromCurveToAnother() {
	EnemyIndex = 0;
	DanceEnemies.Reset();

	switch (CurveNum)
	{
	case 0:
		SpawnDanceEnemyHorizontal(90, true);

		break;
	case 1:
		SpawnDanceEnemyHorizontal(90, false);
		break;
	case 2:
		SpawnDanceEnemyHorizontal(90, true);
		break;
	case 3:
		spawnLocation.Z = PlayerLenH;
		spawnLocation.X = 100.0f;
		spawnLocation.Y = 0.0f;
		angle = 0;
		SpawnDanceEnemyVertical(60, true);
		break;
	case 4:
		SpawnDanceEnemyVertical(60, false);
		break;
	case 5:
		SpawnDanceEnemyVertical(60, true);
		break;
	case 6:
		spawnLocation.Z = 100; //Down
		spawnLocation.X = 100.0f;
		spawnLocation.Y = 0.0f;
		angle = 0;
		SpawnDanceEnemyHorizontal(90, true);
		break;
	case 7:
		SpawnDanceEnemyHorizontal(90, false);
		break;
	case 8:
		SpawnDanceEnemyHorizontal(90, true);
		break;
	case 9:
		spawnLocation.Z = PlayerLenH;
		spawnLocation.X = 100.0f;
		spawnLocation.Y = 0.0f;
		angle = 0;
		SpawnDanceEnemyTriangle(90, true);
		break;
	case 10:
		SpawnDanceEnemyTriangle(90, false);
		break;
	case 11:
		SpawnDanceEnemyTriangle(90, true);
		break;
		//case 12:
		//	break;
		//case 13:
		//	break;
		//case 14:
		//	break;
		//case 15:
		//	break;
		//case 16:
		//	break;
		//case 17:
		//	break;
	default:
		break;
	}

}
void ADanceGameManager::SetEnemyMaterial(class UMaterial* mat, int EnemyNum) {
	EnemyDanceMesh = Cast <UStaticMeshComponent>(DanceEnemies[EnemyNum]->GetRootComponent());
	if (mat) {

		if (EnemyDanceMesh) {
			EnemyDanceMesh->SetMaterial(0, mat);

		}
	}
}
void  ADanceGameManager::RandMaterial(int randNum, int EnemyNum) {
	if (randNum == 1) {
		SetEnemyMaterial(EnemyMaterial_2, EnemyNum);
		DanceEnemies[EnemyNum]->MatChanged = true;
	}
	else {
		SetEnemyMaterial(EnemyMaterial, EnemyNum);
		DanceEnemies[EnemyNum]->MatChanged = false;

	}
}