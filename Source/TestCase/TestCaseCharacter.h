// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BodyPartBase.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "TestCaseCharacter.generated.h"

UCLASS(config=Game)
class ATestCaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ATestCaseCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UBodyPartBase *> body_parts;

	UFUNCTION(BlueprintCallable)
	const TArray<UBodyPartBase *> & get_body_parts()
	{
		return body_parts;
	}

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (DisplayName = "ChooseBodyPart"))
	void choose_body_part(const TArray<UBodyPartBase *> & attacked_parts, UBodyPartBase * & AttackedPart, UBodyPartBase * & BlockedPart);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (DisplayName = "Reset"))
	void reset();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (DisplayName = "AttackBlocked"))
    void attack_blocked();

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

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

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

