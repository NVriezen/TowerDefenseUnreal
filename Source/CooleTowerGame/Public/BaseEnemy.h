// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BasePathManager.h"
#include <Array>
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEnemy.generated.h"

UCLASS()
class COOLETOWERGAME_API ABaseEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* EnemyMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCapsuleComponent* Collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float moveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> pathNodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABasePathManager* pathManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float distanceMargin;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
