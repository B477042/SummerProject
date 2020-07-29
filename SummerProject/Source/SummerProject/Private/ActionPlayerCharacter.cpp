// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlayerCharacter.h"


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
	setupSpringarm();
	//SpringArm->TargetArmLength = 300.0f;

	initializeAssets();

	MoveDirection = FVector::ZeroVector;
	GetCharacterMovement()->MaxWalkSpeed = 560.0f;
	
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

	setMoveDirection(DeltaTime);
}

// Called to bind functionality to input
void AActionPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Axis inputs
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this, &AActionPlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AActionPlayerCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("MoveLeft"), this, &AActionPlayerCharacter::MoveLeft);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AActionPlayerCharacter::MoveForward);


	//Action Inputs


}

void AActionPlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AActionPlayerCharacter::Turn(float NewAxisValue)
{
	if (NewAxisValue == 0.0f)return;

	AddControllerYawInput(NewAxisValue);
}

void AActionPlayerCharacter::LookUp(float NewAxisValue)
{
	if (NewAxisValue == 0.0f)return;
	AddControllerPitchInput(NewAxisValue);
}

void AActionPlayerCharacter::MoveLeft(float NewAxisValue)
{

	if (NewAxisValue == 0.0f)return;

	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	Direction.Z = 0.0f;
	Direction.Normalize();
	//MoveDirection += Direction * FMath::Clamp(Value, -1.0f, 1.0f);
	AddMovementInput(Direction, NewAxisValue);
}

void AActionPlayerCharacter::MoveForward(float NewAxisValue)
{
	if (NewAxisValue == 0.0f)return;

	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	Direction.Z = 0.0f;
	Direction.Normalize();
	//MoveDirection += Direction * FMath::Clamp(Value, -1.0f, 1.0f);
	AddMovementInput(Direction, NewAxisValue);

}

void AActionPlayerCharacter::setMoveDirection(float DeltaTime)
{
	if (MoveDirection.IsZero()) {
		return;
	}

	MoveDirection.Normalize();
	
	AddMovementInput(MoveDirection,/* CurrentVelocity **/ DeltaTime);
	MoveDirection.Set(0.0f, 0.0f, 0.0f);
}

void AActionPlayerCharacter::setupSpringarm()
{
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bDoCollisionTest = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

void AActionPlayerCharacter::initializeAssets()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SM_BODY(TEXT("SkeletalMesh'/Game/MyFolder/ModelAsset/marie/marierose.marierose'"));
	if (SM_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f,0.0f,-70.0f), FRotator(0.0f, -90.0f, 0.0f));
		
	
	}
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance>ANIM(TEXT("Blueprint'/Game/MyFolder/Blueprint/Anim/BP_ActionPlayerAnimInstance.BP_ActionPlayerAnimInstance_C'"));
	if (ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ANIM.Class);
	}

	
	

}

