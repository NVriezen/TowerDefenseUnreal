// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.h"
#include "Enemy.generated.h"

UCLASS()
class COOLETOWERGAME_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	//The movement speed of the Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	float moveSpeed;
	//Attacking Speed; How many seconds are in between attacks
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	float attackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	ATower* tower;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move();

};
