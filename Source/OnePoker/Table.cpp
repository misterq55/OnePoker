// Fill out your copyright notice in the Description page of Project Settings.


#include "Table.h"
#include "Lamp.h"

// Sets default values
ATable::ATable(const FObjectInitializer& ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TableBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TABLE"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_TABLE(TEXT("/Game/OfficePack/StaticMesh/SM_Desk03.SM_Desk03"));

	RootComponent = TableBody;

	if (SM_TABLE.Succeeded()) {
		// TableBody->SetStaticMesh(SM_TABLE.Object);
	}

	UWorld* world = GetWorld();

	if (!UObject::IsTemplate(RF_Transient) && world) {
		for (int i = 0; i < 2; i++) {
			FString label;
			label += TEXT("Lamp");
			label.AppendInt(i);
			LampActors[i] = ObjectInitializer.CreateDefaultSubobject<UChildActorComponent>(this, *label);
			LampActors[i]->SetChildActorClass(ALamp::StaticClass());
			LampActors[i]->SetupAttachment(RootComponent);
			LampActors[i]->SetRelativeLocation(FVector(i * 20, 0, 0));
		}
	}
}

// Called when the game starts or when spawned
void ATable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATable::PostInitializeComponents()
{

}

void ATable::ControlLamp(int idx, bool turnOn)
{
	if (idx == 0 || idx == 1) {
		// Lamps[idx]->ControlLamp(turnOn);
		//LampActors[idx]->GetChildActorClass();
	}
}

