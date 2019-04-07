// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePathManager.h"

// Sets default values
ABasePathManager::ABasePathManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePathManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePathManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector> ABasePathManager::GetPath()
{
	TArray<FVector> vectorPath;

	for (int i = 0; i < pathNodes.Num(); i++) {
		vectorPath.Add(pathNodes[i]->GetActorLocation());
	}

	return vectorPath;
}

