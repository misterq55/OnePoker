// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Table.generated.h"

class ALamp;

UCLASS()
class ONEPOKER_API ATable : public AActor
{
	GENERATED_UCLASS_BODY()
	//GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	//ATable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;

private:
	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* TableBody;

	// ALamp *Lamps[2];
	UPROPERTY(VisibleAnyWhere)
	UChildActorComponent* LampActors[2];

public:
	void ControlLamp(int idx, bool turnOn);
};
