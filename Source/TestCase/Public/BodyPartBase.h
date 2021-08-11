// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IBodyPart.h"

#include "CoreMinimal.h"

#include "BodyPartBase.generated.h"

class ATestCaseCharacter;

/**
 * 
 */
UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTCASE_API UBodyPartBase : /*public IBodyPart,*/ public UActorComponent
{
	GENERATED_BODY()
public:
	UBodyPartBase();
	virtual ~UBodyPartBase();

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual bool damage(float base_damage, AController* event_instigator, AActor* damage_causer) /*override*/;
	
	UFUNCTION(BlueprintCallable)
	virtual void block() /*override*/;
	
	UFUNCTION(BlueprintCallable)
	virtual void reset() /*override*/;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	float damage_multiplier = 0.0f;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FText get_name();

	ATestCaseCharacter* owner;
	bool is_blocked = false;
};
