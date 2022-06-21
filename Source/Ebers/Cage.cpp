// Fill out your copyright notice in the Description page of Project Settings.



#include "Cage.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>

// Sets default values
ACage::ACage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*Root = CreateDefaultSubobject<UBoxComponent>("Root");
	RootComponent = Root;*/

	/*CageBodyComponent = CreateDefaultSubobject<UStaticMeshComponent>("Cage");
	CageBodyComponent->AttachTo(RootComponent);*/

	CageDoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("CageDoor");
	RootComponent = CageDoorMeshComponent;
	

}

// Called when the game starts or when spawned
void ACage::BeginPlay()
{
	Super::BeginPlay();



	CageDoorMaterial = CageDoorMeshComponent->GetMaterial(0);

	//UE_LOG(LogTemp, Error, TEXT("Door Material : %s"), *CageDoorMaterial->GetFName().ToString());

	CageDoorDynamicMat = UMaterialInstanceDynamic::Create(CageDoorMaterial , this);

	CageDoorMeshComponent->SetMaterial(0,CageDoorDynamicMat );
	

	//setDisolveValue(-1.f );
}

// Called every frame
void ACage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (startdesolve) {
		FHashedMaterialParameterInfo test;
		//CageDoorDynamicMat->SetScalarParameterValue("Disolve" , DisolveVal);
		//CageDoorDynamicMat->SetScalarParameterValue("Disolve", FMath::Lerp(OldDisolveValue , DisolveValue , 0.001f * DeltaTime));
		
		/*if (xx) {

		}*/
		startdesolve = false;
	}
}

void ACage::setDisolveValue(float newDis,float  oldDis)
{
	//startdesolve = true;
	this->DisolveValue = newDis;
	this->OldDisolveValue = oldDis;
}

void ACage::OpenDoor(int32 NPCNum)
{
	float  disolveStep =  (FullyVisableValue - FullyDisovedValue) / NPCNum;
	//UE_LOG(LogTemp, Error, TEXT("pppppppppppppppppppppppppppp : %f"), disolveStep);
	DisolveVal -= disolveStep;
	//UE_LOG(LogTemp, Error, TEXT("ooooooooooooooooooooooooooooooooooooooo : %f"), DisolveVal);
	CageDoorDynamicMat->SetScalarParameterValue("Disolve", DisolveVal);
	
}



