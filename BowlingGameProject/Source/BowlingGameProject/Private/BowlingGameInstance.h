// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BowlingGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UBowlingGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Scoring")
	float TotalScore;
};
