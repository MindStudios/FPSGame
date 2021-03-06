// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameGameMode.h"
#include "FPSGameHUD.h"
#include "FPSGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSGameGameMode::AFPSGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSGameHUD::StaticClass();
}
