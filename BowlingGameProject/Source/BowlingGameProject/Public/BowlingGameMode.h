// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoundData.h"
#include "BowlingPin.h"
#include "Delegates/Delegate.h"
#include "GameFramework/GameModeBase.h"
#include "BowlingGameMode.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNextShootSignature);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNextRoundSignature);

UCLASS()
class BOWLINGGAMEPROJECT_API ABowlingGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:

	UPROPERTY(EditDefaultsOnly, Category = "Bowling Scoring")
	int MaxRounds = 10;

	UPROPERTY(VisibleAnywhere, Category = "Bowling Scoring")
	int CurrentRound;

	UPROPERTY(VisibleAnywhere, Category = "Bowling Scoring")
	int PinCounter;

	UPROPERTY(VisibleAnywhere, Category = "Bowling Scoring|Rounds")
	TArray<FRoundData> Rounds;

	UPROPERTY(VisibleAnywhere, Category = "Pins")
	TArray<ABowlingPin*> Pins;

	UFUNCTION(BlueprintCallable)
	void FindPinsInWorld();

	UFUNCTION(BlueprintCallable)
	FRoundData GetRoundData(int RoundToSearch);

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPinFall();

	UFUNCTION(BlueprintCallable)
	FRoundData NextRound();

	UFUNCTION(BlueprintCallable)
	FRoundData InitRound();

	UFUNCTION(BlueprintCallable)
	void SetShoot(int ShootValue);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetRound();

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	FOnNextShootSignature OnNextShoot;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	FOnNextRoundSignature OnNextRound;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Bowling Scoring")
	float PreviousRoundScore;

	UFUNCTION(BlueprintCallable)
	float EvaluateRoundScore();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetLastShoot();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetShootNum();

	UFUNCTION(BlueprintCallable)
	int GetRemainingPins();

	UFUNCTION(BlueprintCallable)
	void RestartGame();
	
};
