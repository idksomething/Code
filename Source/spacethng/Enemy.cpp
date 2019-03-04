// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "spacethng.h"
#include "spacethngGameModeBase.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UShapeComponent* RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MyEnemy"));
	RootComponent = RootBox;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

//called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += (MoveDirection * Speed * DeltaTime);
	SetActorLocation(NewLocation);

	if (NewLocation.X < DestroyPlacement)
	{
		DeleteEnemy = true;

	}
}

	void AEnemy::EnemyHit()
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy hit! Im going down!"))
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		DeleteEnemy = true;
	}


