// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <vector>
#include "ObjectSpecifics.generated.h"
//#include <Ftext>
//#include <vector>


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COOLETOWERGAME_API UObjectSpecifics : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectSpecifics();

	//Name of the Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=General)
	FString name;

	//appearance via three 3d models combined?

	//Amount of total Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	int health;
	//Base Defense value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	int defense;
	//Base Attack Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	int attack;

	//The range of the attacks fired by the Actor in meters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	float attackRange;

	//Types for attacks the Actor can use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	TMap<FString, bool> attackTypes; // = { "Melee", "Projectile", "Hit-scan" };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
