// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMovement.h"




// Sets default values for this component's properties
UEnemyMovement::UEnemyMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	AActor* OwningActor = GetOwner();

	if (OwningActor) {

		UEnemyStats* StatsComp = OwningActor->FindComponentByClass<UEnemyStats>();

		if (StatsComp) {
			Speed = StatsComp->Speed;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("EnemySpeed: %f"), Speed));

			AttackType = StatsComp->AttackType;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("EnemyAttackType: %s"), *UEnum::GetValueAsString(AttackType)));
		}
	}
}


// Called when the game starts
void UEnemyMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...

	
	
}


// Called every frame
void UEnemyMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

