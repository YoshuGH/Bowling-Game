// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingPinDeck.h"

// Sets default values
ABowlingPinDeck::ABowlingPinDeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Pin1 = CreateDefaultSubobject<ABowlingPin>(TEXT("Pin_1"));
	Pin1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ABowlingPinDeck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABowlingPinDeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

