// Fill out your copyright notice in the Description page of Project Settings.
#include "AccessTest.h"
#include "CodingTestActor.h"

// Sets default values
AAccessTest::AAccessTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAccessTest::BeginPlay()
{
	Super::BeginPlay();
	
	number = 200;
	numPointer = &number;

	UE_LOG(LogTemp, Warning, TEXT("변수의 값: %d"), number);
	UE_LOG(LogTemp, Warning, TEXT("포인터의 값: %d"), *numPointer);
}

// Called every frame
void AAccessTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

