// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"EbersPlayer.h"
#include "DanceGameManager.generated.h"

UENUM()
namespace ExerciseTypes {
	enum Type {
		Horizontal				UMETA(DisplayName = "Horizontal"),
		Vertical				UMETA(DisplayName = "Vertical"),
		HorizontalDown			UMETA(DisplayName = "HorizontalDown"),
		Triangle				UMETA(DisplayName = "Triangle")
	};
}



USTRUCT()
struct FDoctorChoice
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere)
public:

	UPROPERTY(EditAnywhere)
	TEnumAsByte<ExerciseTypes::Type> ExerciseType;
	UPROPERTY(EditAnywhere)
		int NumOfRepeating;
}; 

UCLASS()
class EBERS_API ADanceGameManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADanceGameManager();
	UWorld* world;
	UPROPERTY(EditAnywhere)
		class UMaterial* StartMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* EnemyMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* EnemyMaterial_2;

		class UMaterial* MyEnemyMaterial;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADanceEnemy> MyDanceEnemy;



	UPROPERTY(EditAnywhere)
		TSubclassOf<class AArrowEnemyActor> Arrow_EnemyActor;


	UPROPERTY(EditAnywhere)
		FVector spawnLocation;

	UPROPERTY(EditAnywhere)
		UStaticMesh* HArrowMesh;
	UPROPERTY(EditAnywhere)
		UStaticMesh* HArrowCollisionMesh;
	UPROPERTY(EditAnywhere)
		UStaticMesh* VArrowMesh;
	UPROPERTY(EditAnywhere)
		UStaticMesh* VArrowCollisionMesh;
	UPROPERTY(EditAnywhere)
		UStaticMesh* TArrowMesh;
	UPROPERTY(EditAnywhere)
		UStaticMesh* TArrowCollisionMesh;
	UPROPERTY(EditAnywhere)
		class UMaterial* opacity;


	FVector ArrowVerticalVector = FVector(-29.0f, 25.0f, 229.0f);
	FVector ArrowHorizontalVector = FVector(-41.0f, 23.0f, 226.0f);
	FVector ArrowTriangleVector = FVector(41.0f, 0.0f, 93.0f);
	FVector ArrowHorizontalDownVector = FVector(-48.000000, 18.000000, 129.000000);

	FRotator ArrowHorizontalRot = FRotator(0.0f, 180.0f, 90.0f);
	FRotator ArrowVerticalRot = FRotator( 0.0f,  180.0f, 90.0f);
	FRotator ArrowTriangleRot = FRotator(0.0f, 0.0f, 0.0f);


	//UStaticMeshComponent* EnemyDanceMesh;
	USkeletalMeshComponent* EnemyDanceMesh;
	float MaxAngle = 70;

	float angle = 0;
	float angleDirection = 1;
	int CurveNum = -1;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEbersPlayer> MyEbersPlayer;


	AEbersPlayer* CharacterRef;
	UPROPERTY(EditAnywhere)

		ACharacter* MyPlayer;

	UPROPERTY(BlueprintReadWrite)
		FRotator spawnRotation;

	ACharacter* tempchar;
	AEbersPlayer* tchar;
	AEbersPlayer* player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ADanceEnemy*> DanceEnemies;

	float PlayerLen = 300;
	float PlayerLenH = 200;
	float FarPlayer = 100;
	int EnemyIndex;

	float HorizontalAngle;
	int VerticalAngle;
	FString strInfoForDoctor;
	int str_i_ForDoctor;

	int stepAngle = 30;
	int startSpanTime = 2;
	int spanLife_i;
	int stepSpanLife = 2;

	int NumofExcHorizontal = 2;
	int NumofExcVertical = 2;
	int NumofExcHorizontalDown = 2;
	int NumofExcTriangle = 2;
	bool finishCurves = false;

	TArray<FString> strArrInfoForDoctor;

	// Unreal 5.0 onwards supports FText-like formatting
	UPROPERTY(EditAnywhere)
		TArray<FDoctorChoice> DoctorChoice;

	int NumOfExercise;
	int DoctorChoiceIndex;
	bool bDown;
	bool bUp;

//	UPROPERTY(EditAnywhere)
	FActorSpawnParameters spawnParams;

//	AActor ArrowVertical;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//void SpawnDanceEnemyHorizontal(float maxAngle, bool direction);
	//void SpawnDanceEnemyVertical(float maxAngle, bool direction);
	//void SpawnDanceEnemyTriangle(float maxAngle, bool direction);
	void SpawnDanceEnemy(ExerciseTypes::Type type,float maxAngle, bool direction);

	//void MoveFromCurveToAnother();
	void MoveFromCurveToAnotherHorizontal();
	void MoveFromCurveToAnotherVertical();
	void MoveFromCurveToAnotherHorizontalDown();
	void MoveFromCurveToAnotherTriangle();
	void FromStartToDown();
	void FromDownToStart();
	void DataForDoctor();
	void CheckTypeOfExercise();
	void CheckEnemyDestroyed();
	void SetEnemyMaterial(class UMaterial* mat, int EnemyNum);
	void RandMaterial(int randNum, int EnemyNum);
	void SpawnArrowEnemy(FVector ArrowVector,FRotator ArrowRot,UStaticMesh* ArrowMesh,UStaticMesh* ArrowCollisionMesh);

};
