#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MimicExSet.h"
#include "WallActor.h"
#include "MimicGameManager.generated.h"
UENUM()
enum SetSelection {

	NONe UMETA(DisplayName = "NO Filter"),
	Set01 UMETA(DisplayName = "Lateral Deltoid Raises"),
	set02 UMETA(DisplayName = "Shoulder with Rotations"),
	set03 UMETA(DisplayName = "Standing Shoulder with Rotations"),
	set04 UMETA(DisplayName = "Overhead Press"),
	set05 UMETA(DisplayName = "Horizontal Abduction"),
	randomsel  UMETA(DisplayName = "Random"),
};
UENUM()
enum RepeatEX {

	defval UMETA(DisplayName = "NO Repeat"),
	ReSet01 UMETA(DisplayName = "Reapeat Lateral Deltoid Raises"),
	Reset02 UMETA(DisplayName = "Repeat Shoulder with Rotations"),
	Reset03 UMETA(DisplayName = "Repeat Standing Shoulder with Rotations"),
	Reset04 UMETA(DisplayName = "Repeat Overhead Press"),
	Reset05 UMETA(DisplayName = "Repeat Horizontal Abduction"),
};




UCLASS()
class EBERS_API AMimicGameManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMimicGameManager();

#pragma  region Enums

	//Enums for Exercise to start with
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exercise Selection")
		TEnumAsByte <SetSelection>setselectionEx;

	//Enums for Exercise to repeat  the started Exercise
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exercise Repeat")
		TEnumAsByte <RepeatEX>_repeatEx;

#pragma  endregion Enums

#pragma region  Tsubclass
	//array of actors to spawn set of exercise

	UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<AMimicExSet>> mimcEXsets;
#pragma  endregion Tsubclass

#pragma region UPROPERTIES

	UPROPERTY(EditAnywhere)
		float wavesnum = 5;				//waves number spawning
	UPROPERTY(EditAnywhere)
		FVector Spawnpos;				//spawning position for exercise  sets
	UPROPERTY(EditAnywhere)
		FRotator Spawnrotation;			//spawning rotation for exercise sets
	UPROPERTY(EditAnywhere)
		float speed = 5;                //movement speed for walls
	UPROPERTY(EditAnywhere)
		float distance = 100;          //distance between walls 
	UPROPERTY(EditAnywhere)
		float Exrepeat;
	UPROPERTY(EditAnywhere)
	bool _isGameStarted;
	//repeat exercise 
	
#pragma endregion UPROPERTIES


#pragma region privateVariables
private:
	float pos = 0;
	AMimicExSet* temp;
	//float iterations=5;
	int32 starter;
	int32 repeat;
	int32 temprepet;
	int32 repeatedIndex = -1;
	int32 selector;
	TArray<AMimicExSet *>Spawnedwalles;

#pragma endregion privateVariables

protected:
#pragma region Functions 
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void spawnWAllsets();
	void spawnRandomSets();
	void returnJason();
	void swapSetOfExersices(int32 num);
	int32 repeatEx(int32 num);
	void selectExersice();
public:
	FString exerciseName(AWallActor * wall);
#pragma endregion Functions
};