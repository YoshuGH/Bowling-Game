// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BowlingPin.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPinFallSignature , AActor*, PinThatFall);

UCLASS()
class BOWLINGGAMEPROJECT_API ABowlingPin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABowlingPin();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UStaticMeshComponent* PinMesh;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	FOnPinFallSignature OnPinFall;

private:

	float FallAngleThreshold = 35.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
