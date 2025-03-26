// Copyright Epic Games, Inc. All Rights Reserved.

#include "BowlingGameProjectGameMode.h"
#include "BowlingGameProjectPlayerController.h"
#include "BowlingGameProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABowlingGameProjectGameMode::ABowlingGameProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABowlingGameProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}