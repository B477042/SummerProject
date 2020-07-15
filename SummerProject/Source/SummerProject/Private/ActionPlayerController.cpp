// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlayerController.h"

AActionPlayerController::AActionPlayerController()
{

	//FInputModeGameOnly InputMode;
	//SetInputMode(InputMode);
	
}

void AActionPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AActionPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void AActionPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

void AActionPlayerController::OnPossess(APawn * aPawn)
{
	Super::OnPossess(aPawn);
}
