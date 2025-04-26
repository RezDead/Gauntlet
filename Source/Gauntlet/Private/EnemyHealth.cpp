// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealth.h"

// Sets default values for this component's properties
UEnemyHealth::UEnemyHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyHealth::BeginPlay()
{
	Super::BeginPlay();

	// ...

	EnemyCurrentHealth = EnemyMaxHealth;
}


// Called every frame
void UEnemyHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemyHealth::TakeDamage(int DamageTaken) {

	EnemyCurrentHealth -= DamageTaken;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("EnemyHealth: %i"), EnemyCurrentHealth));
	if (EnemyCurrentHealth <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("PointsWorth: %i"), Death()));
	}
}


int UEnemyHealth::Death() {

	AActor* OwningActor = GetOwner();
	OwningActor->Destroy();
	return PointsWorth;
}