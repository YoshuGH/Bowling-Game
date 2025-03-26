// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoundData.generated.h"

USTRUCT(BlueprintType)
struct BOWLINGGAMEPROJECT_API FRoundData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<float> Shoots;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float RoundScore;
};
