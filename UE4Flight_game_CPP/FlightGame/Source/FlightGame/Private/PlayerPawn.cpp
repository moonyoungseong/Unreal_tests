// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 박스 콜라이더 컴포넌트를 생성한다.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));

	// 생성한 박스 콜라이더 컴포넌트를 최상단 컴포넌트로 설정
	SetRootComponent(boxComp);

	// 스태틱 메시 컴포넌트를 생성한다.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));

	// 박스 콜라이더 컴포넌트의 자식 컴포넌트로 설정
	meshComp->SetupAttachment(boxComp);

	// 박스 콜라이더의 크기를 50으로 수정
	FVector boxSize = FVector(50.0f, 50.0f, 50.0f);
	boxComp->SetBoxExtent(boxSize);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

