/**

Main ball bearing implementation.

Original author: Rob Baker.
Current maintainer: Rob Baker.

*********************************************************************************/

#include "BallBearing.h"


/**
Create a static mesh for this ball bearing on object construction.
*********************************************************************************/

ABallBearing::ABallBearing()
{
 	// Set this pawn to call Tick() every frame.

	PrimaryActorTick.bCanEverTick = true;

	// Create the ball mesh, turn on its physics and set it as the root component.

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	
	BallMesh->SetSimulatePhysics(true);

	SetRootComponent(BallMesh);
}


/**
Called when the game starts or when spawned.
*********************************************************************************/

void ABallBearing::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = BallMesh->GetComponentLocation();

	BallMesh->SetLinearDamping(0.5f);
	BallMesh->SetAngularDamping(0.5f);
}


/**
Control the movement of the ball bearing, called every frame.
*********************************************************************************/

void ABallBearing::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	InContact = false;
}
