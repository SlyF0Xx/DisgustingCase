#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class TESTCASE_API IBodyPart
{
public:
	virtual ~IBodyPart() = default;
	
	virtual bool damage(float base_damage, AController* event_instigator, AActor* damage_causer) = 0;
	virtual void block() = 0;
	virtual void reset() = 0;
};

