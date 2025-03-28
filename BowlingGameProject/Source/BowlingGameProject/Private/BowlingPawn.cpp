// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingPawn.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BowlingGameMode.h"
#include <EnhancedInputSubsystems.h>

ABowlingPawn::ABowlingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BowlingBallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_BowlingBall"));
	RootComponent = BowlingBallMesh;

	BallCollsion = CreateDefaultSubobject<USphereComponent>(TEXT("Collsion"));
	BallCollsion->AttachToComponent(BowlingBallMesh, FAttachmentTransformRules::KeepRelativeTransform);

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachToComponent(CameraArm, FAttachmentTransformRules::KeepRelativeTransform);

	
}

// Called when the game starts or when spawned
void ABowlingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABowlingPawn::OnNextShoot()
{
}

// Called every frame
void ABowlingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (BowlingBallMesh->GetComponentVelocity().Length() < 0.1f && IsShootDisable)
	{
		Cast<ABowlingGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->RestartGame();
	}

}

