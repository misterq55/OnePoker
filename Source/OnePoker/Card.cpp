// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CardBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CARD"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CARD(TEXT("/Game/HG_Playing_Cards/Meshes/SM_PlayingCard.SM_PlayingCard"));

	if (SM_CARD.Succeeded()) {
		CardBody->SetStaticMesh(SM_CARD.Object);
	}

	SetCardInfo(0, 0);
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACard::SetCardInfo(char number, char mark)
{
	Info.Number = number;
	Info.Mark = mark;

	UStaticMesh* mesh = CardBody->GetStaticMesh();
	if (mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> materialFinder(TEXT("/Game/HG_Playing_Cards/Materials/Card_Front"));
		//UMaterial *meterial = mesh->GetMaterial(0)->GetMaterial();
		UMaterial* meterial = materialFinder.Object;

		UMaterialInstanceDynamic *dynamicMeterial = UMaterialInstanceDynamic::Create(meterial, NULL);

		static ConstructorHelpers::FObjectFinder<UTexture> textureFinder(TEXT("/Game/HG_Playing_Cards/Textures/Set_1/4096/T_Set_01_002_4096.T_Set_01_002_4096"));
		UTexture* texture = textureFinder.Object;
		dynamicMeterial->SetTextureParameterValue(FName(TEXT("StaticTexture")), texture);

		mesh->SetMaterial(0, dynamicMeterial);
	}
}

