/**

The base game mode for Metal in Motion.

Original author: Rob Baker.
Current maintainer: Rob Baker.

*********************************************************************************/

#include "MetalInMotionGameModeBase.h"
#include "BallBearingHUD.h"
#include "BallBearingGoal.h"
#include "Kismet/GamePlayStatics.h"


/**
Construct the game mode, assigning a debugging HUD class.
*********************************************************************************/

AMetalInMotionGameModeBase::AMetalInMotionGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	HUDClass = ABallBearingHUD::StaticClass();
}


/**
Play the background music at the beginning of the game.
*********************************************************************************/

void AMetalInMotionGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::PlaySound2D(AActor::GetWorld(), BackgroundMusic);
}


/**
Manage the game mode, mostly detecting and implementing the end-game state.
*********************************************************************************/

void AMetalInMotionGameModeBase::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	// Determine if all the goals have ball bearings at their center.
	
	int32 numGoals = 0;
	bool finished = true;
	TArray<AActor*> actors;
	
	// Note, GetAllActorsOfClass is generally not great for performance, but OK right here.

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABallBearingGoal::StaticClass(), actors);

	for (const AActor* goal : actors)
	{
		numGoals++;

		if ((Cast<ABallBearingGoal>(goal))->HasBallBearing() == false)
		{
			finished = false;
			break;
		}
	}

	// If all goals are filled, then record how long that has been the case.
	
	if (numGoals > 0 &&
		finished == true)
	{
		FinishedTime += deltaSeconds;
	}
	else
	{
		FinishedTime = 0.0f;
	}

	// If all goals have been filled for at least one second, then handle the finishing of the game.
	// The delay is to avoid ball bearings passing through the goals without stopping.
	
	if (FinishedTime > 1.0f)
	{
		// Play the finished audio cue if not already done.
		
		if (FinishedSoundPlayed == false)
		{
			FinishedSoundPlayed = true;

			UGameplayStatics::PlaySound2D(GetWorld(), FinishedSound);
		}

		// If the game has been finished for at least 10 seconds then reset the game ready to go around again.
		
		if (FinishedTime > 10.0f)
		{
			Super::RestartGame();
		}
	}
}
