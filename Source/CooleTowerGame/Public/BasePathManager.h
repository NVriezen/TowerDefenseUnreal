// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Array>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePathManager.generated.h"

UCLASS()
class COOLETOWERGAME_API ABasePathManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePathManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> pathNodes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<FVector> GetPath();

};
