// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingPin.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABowlingPin::ABowlingPin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Pin"));
	PinMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void ABowlingPin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector WorldLocation = PinMesh->GetComponentLocation();
	FVector UpVector = Cast<USceneComponent>(PinMesh)->GetUpVector();
	FRotator PinRotation = UKismetMathLibrary::FindLookAtRotation(WorldLocation, WorldLocation+(UpVector+50));

	if (!bisFallen && (PinRotation.Pitch < FallAngleThreshold))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fall"));
		OnPinFall.Broadcast();
		bisFallen = true;
	}
}
