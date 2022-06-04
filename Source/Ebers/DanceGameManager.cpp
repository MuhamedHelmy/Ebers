// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceGameManager.h"
#include "DanceEnemy.h"
#include "EbersPlayer.h"
#include "Math/UnrealMathUtility.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <Ebers/ArrowEnemyActor.h>

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
	CharacterRef = Cast<AEbersPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}
// Called every frame
void ADanceGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DoctorChoice.IsValidIndex(DoctorChoiceIndex)) 
	{

			if (DanceEnemies.IsValidIndex(EnemyIndex) && DanceEnemies[EnemyIndex])
			{

				DataForDoctor();
				CheckEnemyDestroyed(); //During each curve

			}
			else
			{
				EnemyIndex = 0;
				CurveNum++;
				if (CurveNum < 3&& DoctorChoice[DoctorChoiceIndex].NumOfRepeating>0)
				{
					
					CheckTypeOfExercise(); 
				
				}
				else
				{
					CurveNum = -1;

					if (DoctorChoice[DoctorChoiceIndex].NumOfRepeating > 1)
					{
						DoctorChoice[DoctorChoiceIndex].NumOfRepeating--;

					}
					else
					{
						if (!bDown)
						{
							DoctorChoiceIndex++;
						}
						else 
						{
							CheckTypeOfExercise();
							bUp = true;
						}
					}

				}

				if (DanceEnemies.IsValidIndex(EnemyIndex)&& DanceEnemies[EnemyIndex])
				{
					//SetEnemyMaterial(StartMaterial, EnemyIndex);
					DanceEnemies[EnemyIndex]->canAttack = true;
					DanceEnemies[EnemyIndex]->bLaserFearAnim = true;

				}

			}


	}
	else {
		if (Arrowtemp) Arrowtemp->Destroy();

	}

	if (Arrowtemp)
	{
		if (CharacterRef->IsInCurve)
		{
			if (Arrowtemp->Arrow->GetMaterial(0) != ArrowInCurveMaterial)
			{
				Arrowtemp->Arrow->SetMaterial(0, ArrowInCurveMaterial);
			}

		}
		else
		{
			if (Arrowtemp->Arrow->GetMaterial(0) != ArrowNotInCurveMaterial)
			{
				Arrowtemp->Arrow->SetMaterial(0, ArrowNotInCurveMaterial);

			}
		}
	}
}



void ADanceGameManager::SpawnDanceEnemy(ExerciseTypes::Type type,float maxAngle, bool direction)
{

	spanLife_i = 0;
	MaxAngle = maxAngle;
	if (direction)angleDirection = 1;
	else angleDirection = -1;

	//UE_LOG(LogTemp, Warning, TEXT("me%f"), angle);
	


	//Arrowtemp->SetActorHiddenInGame(false);
	//
	//AArrowEnemyActor* t = Cast<AArrowEnemyActor>(temp);


	if (MyDanceEnemy) {

		while (angle != (MaxAngle + stepAngle) * angleDirection)
		{
			////UE_LOG(LogTemp, Warning, TEXT("mmm%f"), angle);


			AActor* temp = world->SpawnActor<ADanceEnemy>(MyDanceEnemy, spawnLocation, spawnRotation, spawnParams);
			ADanceEnemy* t = Cast<ADanceEnemy>(temp);

			t->SetLifeSpan(startSpanTime + spanLife_i);
			spanLife_i = spanLife_i + stepSpanLife;
			DanceEnemies.Add(t);
			angle += stepAngle * angleDirection;

			//UE_LOG(LogTemp, Warning, TEXT("beforelllloc%f"), angle);

			if (type == ExerciseTypes::Type(0)) {
				spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
				spawnLocation.X = FarPlayer * cos(angle * PI / 180);
			}
			else if (type == ExerciseTypes::Type(1))
			{
				spawnLocation.Z = FarPlayer * sin(angle * PI / 180) + PlayerLenH;
				spawnLocation.X = FarPlayer * cos(angle * PI / 180);

			}
			else if (type == ExerciseTypes::Type(2))
			{
				spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
				spawnLocation.X = FarPlayer * cos(angle * PI / 180);
			}
			else if (type == ExerciseTypes::Type(3))
			{
				spawnLocation.Z = FarPlayer * cos(angle * PI / 180) + PlayerLenH - 100;
				spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
			}

			//UE_LOG(LogTemp, Warning, TEXT("llloccc%f"), spawnLocation.X);

		}
	}
	angle = MaxAngle * angleDirection;

	if (type == ExerciseTypes::Type(0)) {
		spawnLocation.Y = FarPlayer * sin(angle * PI / 180);

		spawnLocation.X = FarPlayer * cos(angle * PI / 180);


		SpawnArrowEnemy(ArrowHorizontalVector, ArrowHorizontalRot, HArrowMesh, HArrowCollisionMesh);
		
		if (direction) 
		{
		
			Arrowtemp->SetActorScale3D(FVector(1.0f, 1.0f, -1.0f));
		}
		else
		{
			Arrowtemp->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

		}

	}
	else if (type == ExerciseTypes::Type(1))
	{
		spawnLocation.Z = FarPlayer * sin(angle * PI / 180) + PlayerLenH;
		spawnLocation.X = FarPlayer * cos(angle * PI / 180);
		if (direction)
		{
			ArrowVerticalVector = FVector(-37.0f, -21.0f, 229.0f);

		}
		else
		{
			ArrowVerticalVector = FVector(-29.0f, 25.0f, 229.0f);

		}
		SpawnArrowEnemy(ArrowVerticalVector, ArrowVerticalRot, VArrowMesh, VArrowCollisionMesh);
		if (direction)
		{

			Arrowtemp->SetActorScale3D(FVector(1.0f, -1.0f, -1.0f));
		}
		else
		{
			Arrowtemp->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

		}
	}
	else if (type == ExerciseTypes::Type(2))
	{
		spawnLocation.Y = FarPlayer * sin(angle * PI / 180);
		spawnLocation.X = FarPlayer * cos(angle * PI / 180);
		SpawnArrowEnemy(ArrowHorizontalDownVector, ArrowHorizontalRot, HArrowMesh, HArrowCollisionMesh);
		if (direction)
		{

			Arrowtemp->SetActorScale3D(FVector(1.0f, 1.0f, -1.0f));
		}
		else
		{
			Arrowtemp->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

		}


	}
	else if (type == ExerciseTypes::Type(3))
	{
		spawnLocation.Z = FarPlayer * cos(angle * PI / 180) + PlayerLenH - 100;
		spawnLocation.Y = FarPlayer * sin(angle * PI / 180);

		SpawnArrowEnemy(ArrowTriangleVector, ArrowTriangleRot, TArrowMesh, TArrowCollisionMesh);
		if (direction)
		{

			Arrowtemp->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
		}
		else
		{
			Arrowtemp->SetActorScale3D(FVector(1.0f, -1.0f, 1.0f));

		}
	}

}

void ADanceGameManager::SpawnArrowEnemy(FVector ArrowVector, FRotator ArrowRot, UStaticMesh* ArrowMesh, UStaticMesh *ArrowCollisionMesh) {
	
	if(Arrowtemp) Arrowtemp->Destroy();
	Arrowtemp = world->SpawnActor<AArrowEnemyActor>(Arrow_EnemyActor, ArrowVector, ArrowRot, spawnParams);
	Arrowtemp->Arrow->SetStaticMesh(ArrowMesh);
	Arrowtemp->ArrowCollision->SetStaticMesh(ArrowCollisionMesh);
	Arrowtemp->Arrow->SetMaterial(0, opacity);
	Arrowtemp->ArrowCollision->SetMaterial(0, opacity);
	//Arrowtemp->SetLifeSpan(ArrowLifeSpan);

}

void ADanceGameManager::MoveFromCurveToAnotherHorizontal() {
	EnemyIndex = 0;
	DanceEnemies.Reset();
	switch (CurveNum)
	{
	case 0:
		spawnLocation.Z = PlayerLenH;
		spawnLocation.X = 100.0f;
		SpawnDanceEnemy(ExerciseTypes::Type(0),90, true);
		break;
	case 1:
		SpawnDanceEnemy(ExerciseTypes::Type(0),90, false);
		break;
	case 2:
		SpawnDanceEnemy(ExerciseTypes::Type(0),0, true);
		break;
	default:
		break;
	}
}




void ADanceGameManager::MoveFromCurveToAnotherVertical() {
	EnemyIndex = 0;
	DanceEnemies.Reset();
	switch (CurveNum)
	{
	case 0:
		spawnLocation.Z = PlayerLenH;
		spawnLocation.X = 100.0f;
		spawnLocation.Y = 0.0f;
		angle = 0;
		SpawnDanceEnemy(ExerciseTypes::Type(1),60, true);
		break;
	case 1:
		SpawnDanceEnemy(ExerciseTypes::Type(1),60, false);
		break;
	case 2:
		SpawnDanceEnemy(ExerciseTypes::Type(1),0, true);
		break;

	default:
		break;
	}
}

void ADanceGameManager::MoveFromCurveToAnotherHorizontalDown() {
	EnemyIndex = 0;
	DanceEnemies.Reset();

	switch (CurveNum)
	{
	case 0:
		spawnLocation.Z = 100; //Down
		spawnLocation.X = 100.0f;
		spawnLocation.Y = 0.0f;
		angle = 0;
		SpawnDanceEnemy(ExerciseTypes::Type(2), 90, true);
		break;
	case 1:
		SpawnDanceEnemy(ExerciseTypes::Type(2), 90, false);
		break;
	case 2:
		SpawnDanceEnemy(ExerciseTypes::Type(2), 0, true);
		break;

	default:
		break;
	}
}


void ADanceGameManager::MoveFromCurveToAnotherTriangle() {
	EnemyIndex = 0;
	DanceEnemies.Reset();
	switch (CurveNum)
	{
	case 0:
		spawnLocation.Z = PlayerLenH;
		spawnLocation.X = 100.0f;
		spawnLocation.Y = 0.0f;
		angle = 0;
		SpawnDanceEnemy(ExerciseTypes::Type(3), 90, true);
		break;
	case 1:
		SpawnDanceEnemy(ExerciseTypes::Type(3), 90, false);
		break;
	case 2:
		SpawnDanceEnemy(ExerciseTypes::Type(3), 0, true);
		break;
	default:
		break;
	}
}

void ADanceGameManager::FromStartToDown() {
	spawnLocation.Z = PlayerLenH;
	spawnLocation.X = 100.0f;
	spawnLocation.Y = 0.0f;
	SpawnDanceEnemy(ExerciseTypes::Type(1), 60, false);

}

void ADanceGameManager::FromDownToStart() {
	//Return from down to start
	spawnLocation.Z = 113.4;
	spawnLocation.X = 50.0f;
	spawnLocation.Y = 0.0f;
	angle = -60;
	SpawnDanceEnemy(ExerciseTypes::Type(1), 0, true);
}

void ADanceGameManager::SetEnemyMaterial(class UMaterial* mat, int EnemyNum) {
	EnemyDanceMesh = Cast <USkeletalMeshComponent>(DanceEnemies[EnemyNum]->GetRootComponent()->GetChildComponent(0));
	if (mat) {

		if (EnemyDanceMesh) {
			EnemyDanceMesh->SetMaterial(0, mat);

		}
	}
}


void  ADanceGameManager::DataForDoctor() {
	if (DanceEnemies[EnemyIndex]->GetLifeSpan() == 0)
	{
		HorizontalAngle = round((asin(DanceEnemies[EnemyIndex]->GetActorLocation().Y / FarPlayer)) * 180 / PI);
		VerticalAngle = round((asin((round(DanceEnemies[EnemyIndex]->GetActorLocation().Z - PlayerLenH)) / FarPlayer)) * 180 / PI);
		strInfoForDoctor = "HorizontalAngle: " + FString::SanitizeFloat(HorizontalAngle) + "  VerticalAngle: " + FString::SanitizeFloat(VerticalAngle);
		strArrInfoForDoctor.Add(strInfoForDoctor);
		UE_LOG(LogTemp, Warning, TEXT("----------------str---------------%s"), *strInfoForDoctor);
		EnemyDanceMesh = Cast <USkeletalMeshComponent>(DanceEnemies[EnemyIndex]->GetRootComponent()->GetChildComponent(0));
		//SetEnemyMaterial(StartMaterial, EnemyIndex);

	}

}


void  ADanceGameManager::CheckTypeOfExercise() {

	if (DoctorChoice[DoctorChoiceIndex].ExerciseType == ExerciseTypes::Type(0))
		MoveFromCurveToAnotherHorizontal();
	else if (DoctorChoice[DoctorChoiceIndex].ExerciseType == ExerciseTypes::Type(1))
		MoveFromCurveToAnotherVertical();
	else if (DoctorChoice[DoctorChoiceIndex].ExerciseType == ExerciseTypes::Type(2)) {
		if (DoctorChoice[DoctorChoiceIndex].NumOfRepeating == 1 && bDown&&bUp)
		{

			FromDownToStart();
			CurveNum = 3;
			bDown = false;
			bUp = false;


		}
		else if (!bDown)
		{

			DoctorChoice[DoctorChoiceIndex].NumOfRepeating+=1;
			FromStartToDown();
			bDown = true;
			CurveNum = 3;
		 }
		else
		{

		MoveFromCurveToAnotherHorizontalDown();
		
		}

	}
	else if (DoctorChoice[DoctorChoiceIndex].ExerciseType == ExerciseTypes::Type(3))
		MoveFromCurveToAnotherTriangle();

	//bUp = false;
	//bDown = false;
}

void  ADanceGameManager::CheckEnemyDestroyed() {
	if ((DanceEnemies[EnemyIndex] == nullptr || DanceEnemies[EnemyIndex]->DestroyedDone || DanceEnemies[EnemyIndex]->GetLifeSpan() == 0) && CharacterRef)
	{
		//UE_LOG(LogTemp, Warning, TEXT("----------------NOOOOOOOOOOOOOO--------------"));

		if (DanceEnemies.IsValidIndex(EnemyIndex + 1) && DanceEnemies[EnemyIndex + 1]) {
			EnemyIndex++;
			//UE_LOG(LogTemp, Warning, TEXT("----------------indeeeex---------------%d"), EnemyIndex);
			//SetEnemyMaterial(StartMaterial, EnemyIndex);
			DanceEnemies[EnemyIndex]->bLaserFearAnim = true;
			DanceEnemies[EnemyIndex]->canAttack = true;
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("----------------WHHHHHHHHHHHHHY---------------"));

			EnemyIndex++;
		}
	}

}
