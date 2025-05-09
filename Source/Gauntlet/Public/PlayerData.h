/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 4/26/2025
 * Handles player taking damage, broadcasting death event, taking damage every second, and holds player stats/data.
 * Shows how to declare an event, declare variables, allow event to be called in BP,declare functions, and put categories on variables.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerData.generated.h"

//Declares an event
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAUNTLET_API UPlayerData : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerData();
	//UProperties

	//Score
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerData)
	int PlayerScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	int HealthDecreaseRate;
	
	//Player Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerArmor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int DamagePower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float MagicPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float ShotSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float ShotSize;

	//Allows event to be called/processed in blueprint
	UPROPERTY(BlueprintAssignable)
	FOnPlayerDeath OnPlayerDeath;

	//Functions
	UFUNCTION(BlueprintCallable)
	void TakeDamage(int Damage);

	UFUNCTION(BlueprintCallable)
	void IncreaseScore(int Score);

	UFUNCTION()
	void ReduceHealthEverySecond();

protected:
	virtual void BeginPlay() override;
};
