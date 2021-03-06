// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

UCLASS()
class SPACETHNG_API AAvatar : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AAvatar> MyBullet_BP;
public:
	// Sets default values for this character's properties
	AAvatar();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> ToSpawn;

	UFUNCTION(BlueprintCallable)

	void shoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void forward(float amount);

	void side(float amount);
};
