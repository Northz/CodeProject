// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "CodeProjectCharacter.generated.h"

UCLASS(config=Game)
class ACodeProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class UCameraComponent* FollowCamera;

public:
	ACodeProjectCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera )
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera )
	float BaseLookUpRate;

	/** The default camera distance */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera )
	float CameraDistance;

	/** The max rate of which the camera can readjustment itself */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera )
	float CameraMaxAdjustRate;

	UFUNCTION()
	void SetbCanAutoAdjust();

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** Called via input to change the camera yaw value */
	void Turn( float Value );

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Called via input to zoom in the camera*/
	void ZoomIn();

	/** Called via input to zoom out the camera*/
	void ZoomOut();

	/** Called via right and left input */
	void AutoAdjustCamera( float Value );

	/** Called for yaw rotation input */
	void RotateYaw( float Value );

private:
	FTimerHandle _TimerHandle;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera )
	bool bCanAutoAdjust;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Camera )
	float MaxCameraDistance = 1000.0f;

	/** Current health of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float CurrentHealth;

	/** Max health of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float MaxHealth;

	/** Current stamina of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float CurrentStamina;

	/** Max stamina of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float MaxStamina;

	/** Current mana of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float CurrentMana;

	/** Max mana of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float MaxMana;

	/** Health regen of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float HealthRegen;

	/** Stamina regen of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float StaminaRegen;

	/** Mana regen of the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	float ManaRegen;
};

