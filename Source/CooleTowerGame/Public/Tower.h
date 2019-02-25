// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class COOLETOWERGAME_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

	//The time between projectiles shooting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tower)
	int timeBetween;
	//Speed of the projectiles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tower)
	int projectSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
