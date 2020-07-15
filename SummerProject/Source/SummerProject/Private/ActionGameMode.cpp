// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionGameMode.h"
#include "ActionPlayerCharacter.h"
#include "ActionPlayerController.h"
#include "ActionGameState.h"

AActionGameMode::AActionGameMode()
{
	DefaultPawnClass = AActionPlayerCharacter::StaticClass();

	PlayerControllerClass = AActionPlayerController::StaticClass();
	GameStateClass = AActionGameState::StaticClass();
}

void AActionGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
