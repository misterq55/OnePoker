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

	BasePath += "/Game/HG_Playing_Cards/Materials/";
	const TCHAR* temp = *BasePath;

	SetCardInfo('H', 'K');
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

void ACard::SetCardInfo(char mark, char number)
{
	Info.Number = number;
	Info.Mark = mark;

	int numberType = 0;
	int markType = 0;

	switch (Info.Number)
	{
	case 'A':
	case 'a':
		numberType = 1;
		break;

	case 2:
	case '2':
		numberType = 2;
		break;

	case 3:
	case '3':
		numberType = 3;
		break;

	case 4:
	case '4':
		numberType = 4;
		break;

	case 5:
	case '5':
		numberType = 5;
		break;

	case 6:
	case '6':
		numberType = 6;
		break;

	case 7:
	case '7':
		numberType = 7;
		break;

	case 8:
	case '8':
		numberType = 8;
		break;

	case 9:
	case '9':
		numberType = 9;
		break;

	case 10:
	case '0':
		numberType = 10;
		break;

	case 'J':
	case 'j':
		numberType = 11;
		break;

	case 'Q':
	case 'q':
		numberType = 12;
		break;

	case 'K':
	case 'k':
		numberType = 13;
		break;
	default:
		break;
	}

	switch (Info.Mark)
	{
	case 'D':
	case 'd':
		markType = 0;
		break;

	case 'C':
	case 'c':
		markType = 1;
		break;

	case 'H':
	case 'h':
		markType = 2;
		break;

	case 'S':
	case 's':
		markType = 3;
		break;
	default:
		break;
	}

	// BasePath += "/Game/HG_Playing_Cards/Materials/Set_1/M_Set_1_007";

	UStaticMesh* mesh = CardBody->GetStaticMesh();
	if (mesh) {
		FString tempPath = BasePath + TEXT("Set_1/M_Set_1_");
		int tempNumber = markType * 13 + numberType;
		if (tempNumber < 10) {
			tempPath += "00";
		}
		else {
			tempPath += "0";
		}

		tempPath.AppendInt(markType * 13 + numberType);
		const TCHAR* temp = *tempPath;
		static ConstructorHelpers::FObjectFinder<UMaterialInstance> materialFinder(temp);
		// static ConstructorHelpers::FObjectFinder<UMaterialInstance> materialFinder(TEXT("/Game/HG_Playing_Cards/Materials/Set_1/M_Set_1_007"));
		
		UMaterialInstance* materialInst = materialFinder.Object;

		mesh->SetMaterial(0, materialInst);
	}
}

