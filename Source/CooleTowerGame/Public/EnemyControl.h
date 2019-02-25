// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyControl.generated.h"

UCLASS()
class COOLETOWERGAME_API AEnemyControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyControl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int wave;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<class AEnemy*, int> enemies;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
