// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerData.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

#define DELAY(time, block)\
{\
FTimerHandle TimerHandle;\
GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()block, time, false);\
}

void UPlayerData::BeginPlay()
{
	Super::BeginPlay();

	//Start decreasing health every second
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UPlayerData::ReduceHealthEverySecond, 1.0f,true);
	
}


// Sets default values for this component's properties
UPlayerData::UPlayerData()
{
	PlayerScore = 0;
	HealthDecreaseRate = 1;
	PlayerHealth = 700;
	PlayerSpeed = 100;
	PlayerArmor = 100;
	DamagePower = 1;
	AttackSpeed = 1.0f;
	MagicPower = 1;
	ShotSpeed = 1.0f;
}

void UPlayerData::IncreaseScore(const int Score)
{
	PlayerScore += Score;
}

void UPlayerData::TakeDamage(const int Damage)
{
	PlayerHealth -= Damage;
	if (PlayerHealth <= 0)
	{
		PlayerHealth = 0;
		//Calls player death event, to be processed in blueprint on actor
		OnPlayerDeath.Broadcast();
	}
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("PlayerHealth: %i"), PlayerHealth));
}

void UPlayerData::ReduceHealthEverySecond()
{
	TakeDamage(HealthDecreaseRate);
}

