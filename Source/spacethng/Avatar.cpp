// Fill out your copyright notice in the Description page of Project Settings.

#include "Avatar.h"
#include "Components/InputComponent.h"
#include "Engine.h"
#include "Bullet.h"
#include "Components/SceneComponent.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AAvatar::shoot()
{ 
		UWorld* world = GetWorld();
		if (world)
		{
			FVector Location = GetActorLocation();
			world->SpawnActor<ABullet>(MyBullet_BP, Location + FVector(0.4f, 0.f, 0.f), GetActorRotation());
		}
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("forward", this, &AAvatar::forward);
	InputComponent->BindAxis("side", this, &AAvatar::side);
	InputComponent->BindAction("shoot", IE_Pressed, this, &AAvatar::shoot);
}

void AAvatar::forward(float amount)
{
	if (Controller && amount)
	{
		AddMovementInput(GetActorForwardVector(), amount);
	}
}

void AAvatar::side(float amount)
{
	if (Controller && amount)
	{
		AddMovementInput(GetActorRightVector(), amount);
	}
}

