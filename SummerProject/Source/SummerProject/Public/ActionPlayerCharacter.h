// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
//#include""
#include "Camera/CameraComponent.h"
#include "ActionPlayerAnimInstance.h"
#include "ActionPlayerCharacter.generated.h"


/*
	Player Character for Action Game.
	

*/
UCLASS()
class SUMMERPROJECT_API AActionPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActionPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents()override;

private:
	void Turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
	//Move Left or Right 
	void MoveLeft(float NewAxisValue);
	//Move Forward or Backward
	void MoveForward(float NewAxisValue);

	void setMoveDirection(float DeltaTime);
	void setupSpringarm();
private:
	void initializeAssets();
	
	UPROPERTY(VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Speed")
		FVector MoveDirection;

};
