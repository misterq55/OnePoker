// Fill out your copyright notice in the Description page of Project Settings.


#include "Table.h"
#include "Lamp.h"

// Sets default values
ATable::ATable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TableBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TABLE"));

	RootComponent = TableBody;

	UWorld* world = GetWorld();

	if (!UObject::IsTemplate(RF_Transient) && world) {
		for (int i = 0; i < 2; i++) {
			FString label;
			label += TEXT("Lamp");
			label.AppendInt(i);

			/*Lamps[i] = (ALamp*)world->SpawnActor(ALamp::StaticClass());
			Lamps[i]->SetActorLabel(*label);
			Lamps[i]->GetRootComponent()->SetupAttachment(TableBody);
			Lamps[i]->SetActorRelativeLocation(FVector(-10, i * 20 - 50, 60));
			Lamps[i]->SetActorRelativeRotation(FRotator(0, -90.f, 0));*/

			LampActors[i] = CreateDefaultSubobject<UChildActorComponent>(*label);
			LampActors[i]->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			//LampActors[i]->SetupAttachment(RootComponent);
			LampActors[i]->SetChildActorClass(ALamp::StaticClass());
			//LampActors[i]->RegisterComponent();
			LampActors[i]->CreateChildActor();
			LampActors[i]->SetRelativeLocation(FVector(-10, i * 20 - 50, 60));
			LampActors[i]->SetRelativeRotation(FRotator(0, -90.f, 0));
		}
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_TABLE(TEXT("/Game/OfficePack/StaticMesh/SM_Desk03.SM_Desk03"));

	if (SM_TABLE.Succeeded()) {
		TableBody->SetStaticMesh(SM_TABLE.Object);
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

