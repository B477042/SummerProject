// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ActionPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SUMMERPROJECT_API AActionPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AActionPlayerController();
	virtual void BeginPlay();
	virtual void SetupInputComponent()override;
	virtual void PostInitializeComponents()override;
	virtual void OnPossess(APawn* aPawn)override;

	

};
