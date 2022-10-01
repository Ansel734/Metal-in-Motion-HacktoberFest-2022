/**

Goals for ball bearings in Metal in Motion.

Original author: Rob Baker.
Current maintainer: Rob Baker.

These are generally used as the parent actor for goals within the game.

*********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "BallBearing.h"
#include "BallBearingGoal.generated.h"


/**
A goal for ball bearings in Metal in Motion.
*********************************************************************************/

UCLASS()
class METALINMOTION_API ABallBearingGoal : public ATriggerSphere
{
	GENERATED_BODY()

public:

	// Constructor for a goal for ball bearings.
	ABallBearingGoal();

	// The power of the magnetism.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Goal)
		float Magnetism = 7500.0f;

	// Does this goal have a ball bearing resting in its center?
	bool HasBallBearing() const;

protected:

	// Hide the collision and sprite components in-game.
	virtual void PostInitializeComponents() override;

	// Add magnetism to the proximate ball bearings, drawing them towards our center.
	virtual void Tick(float deltaSeconds) override;

	// Add a ball bearing to the list of proximate bearings we're maintaining.
	virtual void NotifyActorBeginOverlap(AActor* otherActor) override;

	// Remove a ball bearing from the list of proximate bearings we're maintaining.
	virtual void NotifyActorEndOverlap(AActor* otherActor) override;

private:

	// A list of proximate ball bearings.
	UPROPERTY(Transient)
		TArray<ABallBearing*> BallBearings;
};
