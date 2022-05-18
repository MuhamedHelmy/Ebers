#include "WallActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
AWallActor::AWallActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AWallActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateposition(DeltaTime);

}
void AWallActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
void AWallActor::updateposition(float time)
{
	FVector newlocation = this->GetActorLocation();

	newlocation.Y = newlocation.Y + WallMovementSpeed;
	SetActorLocation(newlocation);
}
