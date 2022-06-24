#include "Collectables.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACollectables::ACollectables()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sceneCompanent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComapanent"));
	RootComponent = sceneCompanent;

	rightmeshcollider = CreateDefaultSubobject<USphereComponent>(TEXT("rightCollider"));
	rightmeshcollider->SetupAttachment(RootComponent);
	rightmeshcollider->SetCollisionProfileName(TEXT("OverLapeOnly pawn"));

	rightmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right static mesh"));
	rightmesh->SetupAttachment(rightmeshcollider);
	rightmesh->SetCollisionProfileName(TEXT("OverLap only Pawn"));



	leftmeshcollider = CreateDefaultSubobject<USphereComponent>(TEXT("leftCollider"));
	leftmeshcollider->SetupAttachment(RootComponent);
	leftmeshcollider->SetCollisionProfileName(TEXT("OverLapeOnly pawn"));

	leftmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left static mesh"));
	leftmesh->SetupAttachment(leftmeshcollider);
	leftmesh->SetCollisionProfileName(TEXT("OverLap only Pawn"));


	
}

void ACollectables::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor *> player;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", player);
	if (player.Num() > 0) {
		mypalyer = Cast<AEbersPlayer>(player[0]);
	}
	rightmeshcollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectables::OnOverlapBegin);
	leftmeshcollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectables::OnOverlapBegin);
}

// Called every frame
void ACollectables::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateposition(DeltaTime);
}

void ACollectables::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OverlappedComp->GetFName().ToString() == "rightCollider") {
		if (OtherComp->GetFName().ToString() == "RightHand") {
			UE_LOG(LogTemp, Warning, TEXT(" %s"), *OtherComp->GetFName().ToString());
			mypalyer->coins += 50;
			Destroy();
		}
	}
	if (OverlappedComp->GetFName().ToString() == "leftCollider") {
		if (OtherComp->GetFName().ToString() == "LeftHand") {
			UE_LOG(LogTemp, Warning, TEXT(" %s"), *OtherComp->GetFName().ToString());
			mypalyer->coins += 50;
			Destroy();
		}
	}
}

void ACollectables::updateposition(float time)
{
	
		FVector newlocation = this->GetActorLocation();
		newlocation.X = newlocation.X -_speed ;
		SetActorLocation(newlocation);
	
}

