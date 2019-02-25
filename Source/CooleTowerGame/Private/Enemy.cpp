// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Assign Mesh as Subobject
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector selfLoc = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("heyy"));
	//UE_LOG(LogTemp, Warning, TEXT("selfLoc: %s"), *FString::Printf(TEXT("%f"), selfLoc);
	FVector targetLoc = tower->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("targetLoc: %f %f %f"), targetLoc.X, targetLoc.Y, targetLoc.Z);
	FVector newLoc = FMath::Lerp(selfLoc, targetLoc, moveSpeed/DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("newLoc after Lerp"), newLoc);
	SetActorLocation(newLoc);
	//UE_LOG(LogTemp, Warning, TEXT("newLoc after SetLocation"), newLoc);
}

void Move(FVector currentPos, FVector ) {
	//FVector newPos = FVector(2, 2, 2);
	//FVector direction = FVector.dist(currentPos, newPos);
}