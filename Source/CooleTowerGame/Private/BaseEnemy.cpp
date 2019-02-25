// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>("EnemyMesh");
	Collider = CreateDefaultSubobject<UCapsuleComponent>("Collider");

	RootComponent = EnemyMesh;
	Collider->SetupAttachment(EnemyMesh);
	//SetActorLocation(FVector(0, 0, 0), false, NULL, ETeleportType::TeleportPhysics);
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation.X -= (DeltaTime * moveSpeed);
	SetActorLocation(NewLocation, false, NULL, ETeleportType::TeleportPhysics);

}
