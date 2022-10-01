/**

Ball bearing HUD for Metal in Motion.

Original author: Rob Baker.
Current maintainer: Rob Baker.

*********************************************************************************/

#include "BallBearingHUD.h"
#include "PlayerBallBearing.h"


/**
Draw the HUD.
*********************************************************************************/

void ABallBearingHUD::DrawHUD()
{
	Super::DrawHUD();

	APlayerBallBearing* ballBearing = Cast<APlayerBallBearing>(GetOwningPawn());

	if (ballBearing != nullptr)
	{
		AddBool(L"In contact", ballBearing->InContact);
		AddFloat(L"Speed", ballBearing->GetVelocity().Size() / 100.0f);
		AddFloat(L"Dash timer", ballBearing->DashTimer);
		AddFloat(L"Input latitude", ballBearing->InputLatitude);
		AddFloat(L"Input longitude", ballBearing->InputLongitude);
	}
}
