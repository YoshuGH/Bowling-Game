// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BowlingPin.h"
#include "GameFramework/Actor.h"
#include "BowlingPinDeck.generated.h"

UCLASS(Blueprintable)
class BOWLINGGAMEPROJECT_API ABowlingPinDeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABowlingPinDeck();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	ABowlingPin* Pin1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
