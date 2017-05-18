// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CodeProject.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "CodeProjectCharacter.h"

//////////////////////////////////////////////////////////////////////////
// ACodeProjectCharacter

ACodeProjectCharacter::ACodeProjectCharacter()
{
	// Set size for collision capsule, UE4 default (42.f, 96.0f);
	GetCapsuleComponent()->InitCapsuleSize(40.f, 96.0f);

	// set default values
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	CameraDistance = 300.f;
	CameraMaxAdjustRate = 1.0f;

	// Don't rotate when the controller rotates, only affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = CameraDistance; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACodeProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Camera controls
	PlayerInputComponent->BindAction( "ZoomIn", IE_Pressed, this, &ACodeProjectCharacter::ZoomIn );
	PlayerInputComponent->BindAction( "ZoomOut", IE_Pressed, this, &ACodeProjectCharacter::ZoomOut );

	PlayerInputComponent->BindAxis("MoveForward", this, &ACodeProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACodeProjectCharacter::MoveRight);
	PlayerInputComponent->BindAxis( "RotateYaw", this, &ACodeProjectCharacter::RotateYaw );


	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ACodeProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ACodeProjectCharacter::LookUpAtRate);

}

void ACodeProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACodeProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACodeProjectCharacter::ZoomIn()
{
	if( CameraDistance >= 0.0f )
	{
		CameraDistance -= 100;
		CameraBoom->TargetArmLength = CameraDistance;
	}
}

void ACodeProjectCharacter::ZoomOut()
{
	if( CameraDistance < MaxCameraDistance )
	{
		CameraDistance += 100;
		CameraBoom->TargetArmLength = CameraDistance;
	}
}

void ACodeProjectCharacter::AutoAdjustCamera( float Value )
{
	// Get camera 360 yaw rotation
	const FRotator CameraRotation = Controller->GetControlRotation();
	const FRotator CameraYawRotation( 0, CameraRotation.Yaw, 0 );

	// Get the forward and right vector relative to the current camera view
	FVector ForwardVector = UKismetMathLibrary::GetForwardVector( CameraYawRotation );
	FVector RightVector = UKismetMathLibrary::GetRightVector( CameraYawRotation );

	// Get the MoveForward() axis value
	float ForwardAxisValue = InputComponent->GetAxisValue( "MoveForward" );

	// Multiply the respective vectors with an axis value
	ForwardVector = UKismetMathLibrary::Multiply_VectorFloat( ForwardVector, ForwardAxisValue );
	RightVector = UKismetMathLibrary::Multiply_VectorFloat( RightVector, Value );

	// Use forward and Right vector to create a normalized directional rotator in world space
	FVector DirectionalVector = UKismetMathLibrary::Add_VectorVector( ForwardVector, RightVector );
	DirectionalVector = UKismetMathLibrary::Normal( DirectionalVector );
	FRotator DirectionalRotator = UKismetMathLibrary::Conv_VectorToRotator( DirectionalVector );

	// Get a vector that points the camera towards the characters forward vector
	FRotator DeltaRotation = UKismetMathLibrary::NormalizedDeltaRotator( DirectionalRotator, CameraYawRotation );

	// Magic
	AddControllerYawInput( UKismetMathLibrary::FClamp( DeltaRotation.Yaw * GetWorld()->GetDeltaSeconds(), -CameraMaxAdjustRate, CameraMaxAdjustRate ) );
}

void ACodeProjectCharacter::RotateYaw( float Value )
{
	if( (Controller != NULL) && (Value != 0.0f) )
	{
		AddControllerYawInput( Value * BaseTurnRate * GetWorld()->GetDeltaSeconds() );
	}
}

void ACodeProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACodeProjectCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
		AutoAdjustCamera( Value );
	}
}
