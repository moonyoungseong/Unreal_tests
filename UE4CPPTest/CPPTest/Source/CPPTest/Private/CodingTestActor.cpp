﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingTestActor.h"

// Sets default values
ACodingTestActor::ACodingTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodingTestActor::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Hello World")); 
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	//UE_LOG(LogTemp, Warning, TEXT("%.2f"), number2);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *name);

	//int32 result = Add(number1, number2);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), result);
	/*
	if (number1 > 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10보다 크다."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10보다 작다!!!!!!!!!!!!!."));
	}

	if (isReady)
	{
		int32 result = Add(number1, number2);
		UE_LOG(LogTemp, Warning, TEXT("%d"), result);
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("아직 준비가 안됐습니다. 기다리세요"));
	}

	for (int32 i = 0; i < 100; i++)
	{
		number1++;
		UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	}*/
}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACodingTestActor::Add(int32 num1, int32 num2)
{
	int32 result = num1 + num2;
	return result;
}

