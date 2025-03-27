// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingPinDeck.h"

// Sets default values
ABowlingPinDeck::ABowlingPinDeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Pin1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pin_1"));
	Pin1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pin_2"));
	Pin2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh2"));
	Pin3->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh3"));
	Pin4->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh4"));
	Pin5->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh5"));
	Pin6->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh6"));
	Pin7->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh7"));
	Pin8->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin9 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh8"));
	Pin9->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Pin10 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh9"));
	Pin10->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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

