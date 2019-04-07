// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGun.h"
#include "BaseEnemy.h"
#include "DrawDebugHelpers.h"

// Sets default values
ABaseGun::ABaseGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>("GunMesh");
	Collider = CreateDefaultSubobject<UCapsuleComponent>("Collider");
	RootComponent = GunMesh;
	Collider->SetupAttachment(GunMesh);
}

// Called when the game starts or when spawned
void ABaseGun::BeginPlay()
{
	Super::BeginPlay();

	TurningSpeed = 10;
	TargetInRange = false;

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABaseGun::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &ABaseGun::OnOverlapEnd);

	//OnActorBeginOverlap.AddDynamic(this, &ABaseGun::OnOverlap);
}

// Called every frame
void ABaseGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugCapsule(GetWorld(), GetActorLocation(), 44, 22, FQuat(GetActorRotation()), FColor::Red);

	if (TargetInRange && Target != nullptr) {
		FollowTarget(this, Target);
	}
}

void ABaseGun::FollowTarget(AActor* OverlappedActor, AActor* OtherActor)
{
	FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(OverlappedActor->GetActorLocation(), OtherActor->GetActorLocation());
	FQuat QuatRotation = FQuat(lookRotation);
	AddActorLocalRotation(QuatRotation);
}

//void ABaseGun::OnOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor) {
//	if ((Cast<ABaseEnemy>(OtherActor) != nullptr) && (Target != nullptr) && (OtherActor != this) && (TargetInRange == false)) {
//		//start firing and turn gun
//		//Destroy();
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Oh no, an Enemy is in range! Shoot it!");
//		UE_LOG(LogClass, Log, TEXT("Oh no, an Enemy is in range! Shoot it!"));
//
//		Target = OtherActor;
//		TargetInRange = true;
//	}
//}
//
//void ABaseGun::OnOverlapEnd_Implementation(AActor* OverlappedActor, AActor* OtherActor) {
//	if ((Cast<ABaseEnemy>(OtherActor) != nullptr) && (Target == OtherActor) && (OtherActor != this) && (TargetInRange == true)) {
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "It Got Through!!!");
//		UE_LOG(LogClass, Log, TEXT("It Got Through!!!"));
//
//		TargetInRange = false;
//	}
//}

void ABaseGun::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (Cast<ABaseEnemy>(OtherActor) != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		//start firing and turn gun
		//Destroy();
		if (!TargetInRange) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Oh no, an Enemy is in range! Shoot it!");
			UE_LOG(LogClass, Log, TEXT("Oh no, an Enemy is in range! Shoot it!"));

			Target = OtherActor;
			TargetInRange = true;
		}
	}
}

void ABaseGun::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if ((OtherActor != nullptr) && (Cast<ABaseEnemy>(OtherActor) != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "It Got Through!!!");
		UE_LOG(LogClass, Log, TEXT("It Got Through!!!"));
		TargetInRange = false;
	}
}

