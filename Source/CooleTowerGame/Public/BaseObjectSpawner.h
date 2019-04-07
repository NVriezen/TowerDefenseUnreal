// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseTower.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseObjectSpawner.generated.h"

UCLASS()
class COOLETOWERGAME_API ABaseObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseObjectSpawner();

	APlayerController* MyController;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseTower> YourActorBP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	FHitResult RaycastScreen();

	void SpawnObject();
};
