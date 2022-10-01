/**

Ball bearing HUD for Metal in Motion.

Original author: Rob Baker.
Current maintainer: Rob Baker.

*********************************************************************************/

#pragma once

#include "DebugHUD.h"
#include "BallBearingHUD.generated.h"


/**
Ball bearing HUD for Metal in Motion.
*********************************************************************************/

UCLASS()
class METALINMOTION_API ABallBearingHUD : public ADebugHUD
{
	GENERATED_BODY()

protected:

	// Draw the HUD.
	virtual void DrawHUD() override;
};
