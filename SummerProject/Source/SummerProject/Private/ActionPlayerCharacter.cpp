// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlayerCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AActionPlayerCharacter::AActionPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->SetCapsuleHalfHeight(72.5f);
	GetCapsuleComponent()->SetCapsuleRadius(22.0f);
	Camera = CreateDefaultSubobject <UCameraComponent>(TEXT("CAMERA"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));

	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);

	//SpringArm->TargetArmLength = 300.0f;

	initializeAssets();
}

// Called when the game starts or when spawned
void AActionPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActionPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AActionPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AActionPlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AActionPlayerCharacter::initializeAssets()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SM_BODY(TEXT("SkeletalMesh'/Game/MyFolder/ModelAsset/marie/marierose.marierose'"));
	if (SM_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f,0.0f,-70.0f), FRotator(0.0f, -90.0f, 0.0f));
		
	
	}
}

