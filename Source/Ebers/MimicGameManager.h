#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallActor.h"
#include "MimicGameManager.generated.h"

UCLASS()
class EBERS_API AMimicGameManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMimicGameManager();
	UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<AWallActor>> SpawnActors;
	UPROPERTY(EditAnywhere)
		float wavesnum = 5;
	UPROPERTY(EditAnywhere)
		FVector Spawnpos;
	UPROPERTY(EditAnywhere)
		FRotator Spawnrotation;
	UPROPERTY(EditAnywhere)
		float speed = 5;
	UPROPERTY(EditAnywhere)
		float distance = 100;

	UPROPERTY(EditAnywhere)
		bool randomGeneration;
	UPROPERTY(EditAnywhere)
		float timebetweenSpawning = 5;

private:
	float pos = 0;
	float iterations;
	AWallActor* temp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void spawnWAlls();
	void returnJason();

};