// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseObjectSpawner.h"
#include "DrawDebugHelpers.h"

//#include "Engine/World.h"
//#include "GameFramework/PlayerController.h"

// Sets default values
ABaseObjectSpawner::ABaseObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

	MyController = GEngine->GetFirstLocalPlayerController(GetWorld());
	if (MyController) {
		MyController->bEnableClickEvents = true;
		MyController->bShowMouseCursor = true;
		GEngine->GetFirstLocalPlayerController(GetWorld())->InputComponent->BindAction("ScreenClick", IE_Pressed, this, &ABaseObjectSpawner::SpawnObject);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Mouse enabled");
		UE_LOG(LogClass, Log, TEXT("Mouse Enabled"));
	}

	
	//InputComponent->BindAction("ScreenClick", IE_Pressed, this, &ABaseObjectSpawner::SpawnObject);
}

//// Called to bind functionality to input
//void ABaseObjectSpawner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//	// Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
//	GEngine->GetFirstLocalPlayerController(GetWorld())->InputComponent->BindAction("ScreenClick", IE_Pressed, this, &ABaseObjectSpawner::SpawnObject);
//}

// Called every frame
void ABaseObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FHitResult ABaseObjectSpawner::RaycastScreen() {
	//Hit contains information about what the raycast hit.
	FHitResult Hit;

	//The length of the ray in units.
	//For more flexibility you can expose a public variable in the editor
	float RayLength = 200;

	//The Origin of the raycast
	FVector StartLocation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->PCOwner->GetFocalLocation();

	//The EndLocation of the raycast
	FVector EndLocation = StartLocation + (GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->PCOwner->GetControlRotation().Vector() * RayLength);

	//Collision parameters. The following syntax means that we don't want the trace to be complex
	FCollisionQueryParams CollisionParameters;

	//Perform the line trace
//The ECollisionChannel parameter is used in order to determine what we are looking for when performing the raycast
	ActorLineTraceSingle(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_WorldDynamic, CollisionParameters);

	//DrawDebugLine is used in order to see the raycast we performed
	//The boolean parameter used here means that we want the lines to be persistent so we can see the actual raycast
	//The last parameter is the width of the lines.
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1, 0, 1.f);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Raycast Done");
	UE_LOG(LogClass, Log, TEXT("RaycastDone"));

	return Hit;
}

void ABaseObjectSpawner::SpawnObject()
{
	FHitResult hitInfo = RaycastScreen();

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	if (GetWorld()) {
		ABaseTower* TowerSpawned = GetWorld()->SpawnActor<ABaseTower>(YourActorBP, Location, Rotation);

		if (TowerSpawned) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Object spawned");
		}
	}

	//Spawning Actor...
	//ABaseTower* TowerSpawned = GetWorld()->SpawnActor<ABaseTower>(YourActorBP, GetTransform(), SpawnParams);
	//TowerSpawned->SetActorLocation(hitInfo.Location);

}