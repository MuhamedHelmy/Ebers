// Fill out your copyright notice in the Description page of Project Settings.



#include "Cage.h"

// Sets default values
ACage::ACage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CageDoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("CageDoor");
	RootComponent = CageDoorMeshComponent;


}

// Called when the game starts or when spawned
void ACage::BeginPlay()
{
	Super::BeginPlay();
	CageDoorMaterial = CageDoorMeshComponent->GetMaterial(0);

	UE_LOG(LogTemp, Error, TEXT("Door Material : %s"), *CageDoorMaterial->GetFName().ToString());

	CageDoorDynamicMat = UMaterialInstanceDynamic::Create(CageDoorMaterial , this);

	CageDoorMeshComponent->SetMaterial(0,CageDoorDynamicMat );
	
}

// Called every frame
void ACage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ACage::setDisolveValue(float DisolveValue)
{
	CageDoorDynamicMat->SetScalarParameterValue("Disolve", DisolveValue);
}

