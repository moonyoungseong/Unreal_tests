// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingTestActor.generated.h"


// 헤더파일에서 변수,함수 선언하고 사용한다.
UCLASS()
class CPPTEST_API ACodingTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodingTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 정수형 int32로 int도 가능한데 나중에 사용하는 기능에 제약 생김 
	int32 number1 = 85;
	int32 number2 = 90;
};
