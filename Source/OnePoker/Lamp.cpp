// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Lamp.h"


// Sets default values
ALamp::ALamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LampBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LAMP_BODY"));
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("POINT_LIGHT"));
	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SPOT_LIGHT"));

	TurnOn = false;

	TurnedOnPoint = 15.f;
	TurnedOnSpot = 200.f;

	RootComponent = LampBody;
	PointLight->SetupAttachment(LampBody);
	SpotLight->SetupAttachment(LampBody);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_LAMP_BODY(TEXT("/Game/OfficePack/StaticMesh/SM_Lamp07.SM_Lamp07"));

	if (SM_LAMP_BODY.Succeeded()) {
		LampBody->SetStaticMesh(SM_LAMP_BODY.Object);
	}

	PointLight->SetRelativeLocation(FVector(0.0f, 8.5f, 23.f));
	PointLight->SetRelativeRotation_Direct(FRotator(-25.f, 90.f, 0.f));
	PointLight->SetIntensity(0.f);
	PointLight->SetAttenuationRadius(30.f);
	PointLight->SetIndirectLightingIntensity(1.f);
	PointLight->SetVolumetricScatteringIntensity(1.f);

	SpotLight->SetRelativeLocation(FVector(0.0f, 8.5f, 23.f));
	SpotLight->SetRelativeRotation_Direct(FRotator(-25.f, 90.f, 0.f));
	SpotLight->SetIntensity(0.f);
	SpotLight->SetAttenuationRadius(1000.f);
	SpotLight->SetInnerConeAngle(25.828571f);
	SpotLight->SetOuterConeAngle(44.f);
	SpotLight->SetIndirectLightingIntensity(1.f);
	SpotLight->SetVolumetricScatteringIntensity(1.f);

	ControlLamp(false);
}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALamp::ControlLamp(bool turnOn)
{
	if (TurnOn == turnOn) {
		return;
	}

	TurnOn = turnOn;

	if (TurnOn) {
		PointLight->SetIntensity(TurnedOnPoint);
		SpotLight->SetIntensity(TurnedOnSpot);
	}
	else {
		PointLight->SetIntensity(0.f);
		SpotLight->SetIntensity(0.f);
	}
}

