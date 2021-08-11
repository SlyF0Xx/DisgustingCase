// Fill out your copyright notice in the Description page of Project Settings.


#include "BodyPartBase.h"
#include "../TestCaseCharacter.h"

#include "Kismet/GameplayStatics.h"

UBodyPartBase::UBodyPartBase()
{
	PrimaryComponentTick.bCanEverTick = true;
}

UBodyPartBase::~UBodyPartBase()
{
}

void UBodyPartBase::BeginPlay()
{
	UActorComponent::BeginPlay();
	owner = Cast<ATestCaseCharacter>(GetOwner());
	owner->body_parts.Add(this);
}

bool UBodyPartBase::damage(float base_damage, AController* event_instigator, AActor* damage_causer)
{
	if (is_blocked)
	{
		return false;
	}

	UGameplayStatics::ApplyDamage(GetOwner(), base_damage * damage_multiplier, event_instigator, damage_causer, UDamageType::StaticClass());
	return true;
}

void UBodyPartBase::block()
{
	is_blocked = true;
}

void UBodyPartBase::reset()
{
	is_blocked = false;
}
