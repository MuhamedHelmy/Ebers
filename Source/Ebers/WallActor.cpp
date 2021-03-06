#include "WallActor.h"
#include "Components/BoxComponent.h"
#include "MimicGameManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
AWallActor::AWallActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	Mesh->SetupAttachment(Root);

	rightHand = CreateDefaultSubobject<UBoxComponent>(TEXT("RightHandCollider"));
	rightHand->SetupAttachment(Root);

	leftHand = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftHandCollider"));
	leftHand->SetupAttachment(Root);
	acdata = FAccuracyData();
}

void AWallActor::BeginPlay()
{
	Super::BeginPlay();
	rightHand->OnComponentBeginOverlap.AddDynamic(this, &AWallActor::leftHandOnOverlapBegin);
	leftHand->OnComponentBeginOverlap.AddDynamic(this, &AWallActor::leftHandOnOverlapBegin);
	TArray<AActor *> player;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", player);
	if (player.Num() > 0) {
		mypalyer = Cast<AEbersPlayer>(player[0]);
		
	}

	TArray<AActor*> redlight;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "redlight", redlight);
	if (redlight.Num() > 0) {
		light = Cast<ALightTrigger>(redlight[0]);
		UE_LOG(LogTemp, Error, TEXT("bhgfhfh"));
	}


	
}

void AWallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateposition(DeltaTime);
	float dist = (GetActorLocation().Y - mypalyer->GetActorLocation().Y);
	UE_LOG(LogTemp , Error  , TEXT ("Player dist ===>> %f "), (GetActorLocation().Y - mypalyer->GetActorLocation().Y));
	if (dist <=-1) {
		if (!righthandcollision || !lefthandcolllision) {
			mypalyer->MimicScore = 0;
			
			TArray<AActor *> manger;
			UGameplayStatics::GetAllActorsWithTag(GetWorld(), "manger", manger);
			if (manger.Num() > 0) {
				temp11 = Cast<AMimicGameManager>(manger[0]);
		       temp11->exerciseName(this);

			}
			light->lighttriggeron();


		}
	}
	if ((dist <-1))
	{
		Destroy();
	}
}

void AWallActor::updateposition(float time)
{
	FVector newlocation = this->GetActorLocation();
	newlocation.Y = newlocation.Y - WallMovementSpeed;
	SetActorLocation(newlocation);
}
void AWallActor::leftHandOnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OverlappedComp->GetFName().ToString() == "LeftHandCollider") {
		if (OtherComp->GetFName().ToString() == "RightHand") {
			righthandcollision = true;
			rightHandscored = true;
			acdata.rightHandeCollision = righthandcollision;
		}
	}
	if (OverlappedComp->GetFName().ToString() == "RightHandCollider") {

		if (OtherComp->GetFName().ToString() == "LeftHand") {
			lefthandcolllision = true;
			leftHandScored = true;
			acdata.leftHandeCollision = lefthandcolllision;

		}
	}
	if (rightHandscored&&leftHandScored)
	{

		mypalyer->MimicScore += 10;
		rightHandscored=false;
	}
	data.Add(acdata);
} 

void AWallActor::lefthandendoverlape(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}

