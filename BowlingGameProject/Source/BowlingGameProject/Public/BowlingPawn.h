// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "BowlingPawn.generated.h"

UCLASS()
class BOWLINGGAMEPROJECT_API ABowlingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABowlingPawn();

private:

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USphereComponent* BallCollsion;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* BowlingBallMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USpringArmComponent* CameraArm;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float MinForce = 10000.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float MaxForce = 1000000.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float CurrentForce = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float ForceIncrement = 50000.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool IsShootDisable = false;

	UFUNCTION(BlueprintCallable)
	void OnNextShoot();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
