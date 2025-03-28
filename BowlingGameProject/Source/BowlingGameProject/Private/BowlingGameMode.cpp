// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingGameMode.h"
#include "Kismet/GameplayStatics.h"

void ABowlingGameMode::OnPinFall()
{
	PinCounter++;
}

FRoundData ABowlingGameMode::NextRound()
{
	int SumScore = EvaluateRoundScore();

	// Strike
	if (SumScore == 10 && Rounds.Last().Shoots.Num() == 1)
	{
		return FRoundData();
	}
	else if (SumScore == 10 && Rounds.Last().Shoots.Num() == 2) // Spare
	{
		return FRoundData();
	}
	else
	{
		Rounds.Last().RoundScore = EvaluateRoundScore();
	}

	OnNextRound.Broadcast();

	FRoundData NextRound = FRoundData(true);
	Rounds.Add(NextRound);
	OnNextShoot.Broadcast();
	return NextRound;
}

FRoundData ABowlingGameMode::InitRound()
{
	// Create the First Round
	FRoundData FirstRound = FRoundData(true);
	Rounds.Add(FirstRound);
	return FirstRound;
}

void ABowlingGameMode::SetShoot(int ShootValue)
{
	//First Shoot
	if (GetLastShoot() == -1) { Rounds.Last().Shoots[Rounds.Last().Shoots.Num() - 1] = ShootValue; OnNextShoot.Broadcast();  return; }
	
	// Second Shoot of the Round
	if (Rounds.Last().Shoots.Num() == 1 && GetRound() != MaxRounds)
	{
		OnNextShoot.Broadcast();
		Rounds.Last().Shoots.Add(ShootValue);

		//OnNextShoot.Broadcast();
		//Set Next Round
		NextRound();
		return;
	}
	else if(Rounds.Last().Shoots.Num() == 2 && GetRound() == MaxRounds)
	{
		Rounds.Last().Shoots.Add(ShootValue);

		//Finish the game
	}
	else
	{
		Rounds.Last().Shoots.Add(ShootValue);
		OnNextShoot.Broadcast();
	}
}

int ABowlingGameMode::GetRound()
{
	return Rounds.Num();
}

void ABowlingGameMode::FindPinsInWorld()
{
	TArray<AActor*> ActorsToFind;

	if (UWorld* world = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABowlingPin::StaticClass(), ActorsToFind);
	}

	for (AActor* PinActor : ActorsToFind)
	{
		ABowlingPin* PinActorCast = Cast<ABowlingPin>(PinActor);

		if (PinActorCast)
		{
			Pins.Add(PinActorCast);

			PinActorCast->OnPinFall.AddDynamic(this, &ABowlingGameMode::OnPinFall);
		}
	}
}

FRoundData ABowlingGameMode::GetRoundData(int RoundToSearch)
{
	if(!Rounds.IsValidIndex(RoundToSearch)){ return FRoundData(); }

	if (Rounds[RoundToSearch].IsValid)
	{
		return Rounds[RoundToSearch];
	}
	else
	{
		return FRoundData();
	}
}

void ABowlingGameMode::BeginPlay()
{
	Super::BeginPlay();

	FindPinsInWorld();

	InitRound();
}

float ABowlingGameMode::EvaluateRoundScore()
{

	// Calculate Final Score
	int SumScore = 0;

	UE_LOG(LogTemp, Warning, TEXT(" %i"), Rounds[GetRound()-1].Shoots.Num());

	for (int i = 0; i < Rounds[GetRound() - 1].Shoots.Num(); i++)
	{
		SumScore += Rounds[GetRound() - 1].Shoots[i];
		//UE_LOG(LogTemp, Warning, TEXT(" si%i"), SumScore);
	}
	return SumScore;
}

int ABowlingGameMode::GetLastShoot()
{
	return Rounds.Last().Shoots.Last();
}

int ABowlingGameMode::GetShootNum()
{
	return Rounds.Last().Shoots.Num();
}

int ABowlingGameMode::GetRemainingPins()
{

	return 10 - ((EvaluateRoundScore() == -1) ? 0 : EvaluateRoundScore());
}

void ABowlingGameMode::RestartGame()
{
	UGameplayStatics::OpenLevel(this, GetWorld()->GetFName(), true);
}
