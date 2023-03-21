// Copyright Epic Games, Inc. All Rights Reserved.


#include "G2048GameModeBase.h"
#include "MyPlayerController.h"
#include "MyPawn.h"

AG2048GameModeBase::AG2048GameModeBase()
{
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

