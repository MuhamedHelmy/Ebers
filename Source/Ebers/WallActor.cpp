#include "WallActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
// Sets default values
AWallActor::AWallActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	Mesh->SetupAttachment(Root);



	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AWallActor::OnOverlapBegin);


	//MeshComponent = Cast<UStaticMeshComponent>(Root->GetChildComponent(0));

	//UE_LOG(LogTemp, Error, TEXT("hhhhhhhhhhhh %f" , x));

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

}
void AWallActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, "Overlap working !!!");

	//Destroy();

	//UE_LOG();

}
void AWallActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
//
//void AWallActor::setMeshTest(UStaticMesh* mesh)
//{
//	UE_LOG(LogTemp, Error, TEXT("setMesh"));
//
//	MeshComponent->SetStaticMesh(mesh);
//}