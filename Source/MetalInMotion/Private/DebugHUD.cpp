/**

Debugging HUD for Metal in Motion.

Original author: Rob Baker.
Current maintainer: Rob Baker.

*********************************************************************************/

#include "DebugHUD.h"
#include "UObject/ConstructorHelpers.h"


/**
Construct the debugging HUD, mainly establishing a font to use for display.
*********************************************************************************/

ADebugHUD::ADebugHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Engine/EngineFonts/Roboto"));

	MainFont = Font.Object;
}
