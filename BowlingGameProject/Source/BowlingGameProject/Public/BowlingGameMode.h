// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoundData.h"
#include "GameFramework/GameModeBase.h"
#include "BowlingGameMode.generated.h"

UCLASS()
class BOWLINGGAMEPROJECT_API ABowlingGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:

	UPROPERTY(EditDefaultsOnly, Category = "Bowling Scoring")
	int MaxRounds;

	UPROPERTY(VisibleAnywhere, Category = "Bowling Scoring")
	int CurrentRound;

	UPROPERTY(EditDefaultsOnly, Category = "Bowling Scoring|Rounds")
	TArray<FRoundData> Rounds;

public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Bowling Scoring")
	float PreviousRoundScore;

	UFUNCTION(BlueprintCallable)
	float EvaluateRoundScore();
	
};
