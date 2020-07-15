// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lamp.generated.h"

class UPointLightComponent;
class USpotLightComponent;

UCLASS()
class ONEPOKER_API ALamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALamp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 멤버 변수 및 함수
private:
	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* LampBody;

	UPROPERTY(VisibleAnyWhere)
	UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnyWhere)
	USpotLightComponent* SpotLight;

	bool TurnOn;

	float TurnedOnPoint;
	float TurnedOnSpot;

public:
	void ControlLamp(bool turnOn);
};
