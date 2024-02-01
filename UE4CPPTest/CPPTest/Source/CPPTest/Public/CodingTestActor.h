// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingTestActor.generated.h"


// ������Ͽ��� ����,�Լ� �����ϰ� ����Ѵ�.
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

	// ������ int32�� int�� �����ѵ� ���߿� ����ϴ� ��ɿ� ���� ���� 
	int32 number1 = 85;
	int32 number2 = 90;
};
