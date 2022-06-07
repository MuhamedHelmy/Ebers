// Fill out your copyright notice in the Description page of Project Settings.
#include "Drum.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADrum::ADrum()
{

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	//Mesh->OnComponentBeginOverlap.AddDynamic(this  , &ADrum::OnOverlap);
	
	 
	//UE_LOG(LogTemp, Error, TEXT("drum initiated !!! "));
	/*sceneCompanent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComapanent"));
	RootComponent = sceneCompanent;

	collider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	collider->SetupAttachment(RootComponent);
	collider->SetCollisionProfileName(TEXT("OverLapeOnly pawn"));

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh"));
	staticMesh->SetupAttachment(collider);
	staticMesh->SetCollisionProfileName(TEXT("OverLap only Pawn"));*/

}


// Called when the game starts or when spawned
void ADrum::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ADrum::OnCollision);

	//collider->OnComponentBeginOverlap.AddDynamic(this, &ADrum::OnOverlapBegin);


}


void ADrum::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Error, TEXT("Trail have hit  : %s ") , * OtherActor->GetFName().ToString());

	Destroy();
}





//
//void ADrum::OnOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//}






//void ADrum::SetMesh(UStaticMesh* mesh)
//{
//	if (mesh) {
//		UE_LOG(LogTemp, Error, TEXT("AAAAAAAAAAAAAAAAH : %s "), *mesh->GetName());
//	}
//	else {
//		UE_LOG(LogTemp, Error, TEXT("AAAAAAAAAAAAAAAAH :"));
//	}
//
//
//}
//void ADrum::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
//
//	if (overlapSound)
//	{
//		UGameplayStatics::PlaySoundAtLocation(GetWorld(), overlapSound, GetActorLocation());
//	}
//
//	if (OtherComp->GetFName().ToString() == "RightHandCollider") {
//
//		UE_LOG(LogTemp, Warning, TEXT("biiiiiii %s"), *OtherComp->GetFName().ToString());
//		//ChangePos();
//	}
//
//}

// Called every frame


