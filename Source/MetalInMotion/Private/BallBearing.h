/**

Main ball bearing implementation.

Original author: Rob Baker.
Current maintainer: Rob Baker.

*********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "BallBearing.generated.h"


/**
Main ball bearing class, derived from pawn but with no input and no camera.
*********************************************************************************/

UCLASS()
class METALINMOTION_API ABallBearing : public APawn
{
	GENERATED_BODY()

public:
	
	// Create a static mesh for this ball bearing on object construction.
	ABallBearing();

	// The static mesh that represents the ball bearing.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BallBearing)
		UStaticMeshComponent* BallMesh = nullptr;

	// Is the ball bearing attractive to magnets?
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BallBearing)
		bool Magnetized = true;
		
	// Reset the location of the ball bearing to its initial location when spawned.
	UFUNCTION(BlueprintCallable, Category="Ball Bearing")
		void ResetLocation() const
	{
		BallMesh->SetWorldLocation(InitialLocation + FVector(0.0f, 0.0f, 150.0f));
		BallMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
		BallMesh->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
	}

protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Control the movement of the ball bearing, called every frame.
	virtual void Tick(float deltaSeconds) override;

	// Receive notification of a collision contact and record that we're in contact with something.
	virtual void NotifyHit(UPrimitiveComponent* myComponent, AActor* other, UPrimitiveComponent* otherComp, bool selfMoved, FVector hitLocation, FVector hitNormal, FVector normalImpulse, const FHitResult& hitResult) override
	{
		Super::NotifyHit(myComponent, other, otherComp, selfMoved, hitLocation, hitNormal, normalImpulse, hitResult);

		InContact = true;
	}

	// Is the ball bearing in contact with any other geometry?
	bool InContact = false;

private:

	// The initial location of the ball bearing at game start.
	FVector InitialLocation = FVector::ZeroVector;

	// Allow the ball bearing HUD unfettered access to this class.
	friend class ABallBearingHUD;
};
