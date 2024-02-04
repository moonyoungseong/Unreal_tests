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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 number1 = 85;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly) // ��� ����Ʈâ���� ����
	int number2 = 33;

	UPROPERTY(EditInstanceOnly)
	FString name = "Moon0sung";	// ���ڿ� ������ �� �ٸ���. ���߿� ����

	UPROPERTY(Editanywhere)
	bool isReady = true;
	bool isFinished = false;

	// ���ϱ� �Լ� ����
	UFUNCTION(BlueprintCallable)
	int32 Add(int32 num1, int32 num2);
};
