// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoundData.generated.h"

USTRUCT(BlueprintType)
struct BOWLINGGAMEPROJECT_API FRoundData
{
	GENERATED_BODY()

public:

	FRoundData();
	FRoundData(bool IsValided);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsValid = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> Shoots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RoundScore = -1;
};
