// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �ڽ� �ݶ��̴� ������Ʈ�� �����Ѵ�.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));

	// ������ �ڽ� �ݶ��̴� ������Ʈ�� �ֻ�� ������Ʈ�� ����
	SetRootComponent(boxComp);

	// ����ƽ �޽� ������Ʈ�� �����Ѵ�.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));

	// �ڽ� �ݶ��̴� ������Ʈ�� �ڽ� ������Ʈ�� ����
	meshComp->SetupAttachment(boxComp);

	// �ڽ� �ݶ��̴��� ũ�⸦ 50���� ����
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

	// 1. ���� �Է� ���� �¿� �Է� ���� �̿��ؼ� ���� ���͸� �����.
	FVector dir = FVector(0, h, v);

	// 2. ���� ������ ���̰� 1�� �ǵ��� ���͸� ����ȭ �Ѵ�.
	dir.Normalize();

	// 3. �̵��� ��ġ ��ǥ�� ���Ѵ�.
	FVector newLocation = GetActorLocation() + dir * moveSpeed * DeltaTime;

	// 4. ���� ������ ��ġ��ǥ�� ����ǥ�� ����
	SetActorLocation(newLocation);
}

// ����� �Է¿� �����ϱ� ���� ȣ���
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis ���ε� �� �� �Լ��� ����
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawn::MoveVertical);
}

void APlayerPawn::MoveHorizontal(float value)
{
	h = value;
}

void APlayerPawn::MoveVertical(float value)
{
	v = value;
}

