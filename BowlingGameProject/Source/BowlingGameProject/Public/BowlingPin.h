// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "GameFramework/Actor.h"
#include "BowlingPin.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPinFallSignature);

UCLASS()
class BOWLINGGAMEPROJECT_API ABowlingPin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABowlingPin();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	FOnPinFallSignature OnPinFall;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UStaticMeshComponent* PinMesh;

private:
	
	// Max angle to count as fallen (Relative to the Z axis) 
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float FallAngleThreshold = 35.0f;
	bool bisFallen = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
