// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include "Bullet.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
ATPSPlayer::ATPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 1.���̷�Ż �޽� �����͸� �ҷ����� �ʹ�.
	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (TempMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(TempMesh.Object);
		// Mesh ������Ʈ ��ġ ����
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}

	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->SetupAttachment(RootComponent);
	springArmComp->SetRelativeLocation(FVector(0, 70, 90));
	springArmComp->TargetArmLength = 400;
	springArmComp->bUsePawnControlRotation = true;

	tpsCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
	tpsCamComp->SetupAttachment(springArmComp);
	tpsCamComp->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = true;
	
	// 4. �� ���̷�Ż�޽� ������Ʈ ���
	gunMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMeshComp"));
	// 4-1. �θ� ������Ʈ�� Mesh ������Ʈ�� ����
	gunMeshComp->SetupAttachment(GetMesh());
	// 4-2. ���̷�Ż �޽� ������ �ε�
	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempGunMesh(TEXT("SkeletalMesh'/Game/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	// 4-3 ������ �ε尡 �����ߴٸ�
	if (TempGunMesh.Succeeded())
	{
		// 4-4. ���̷�Ż �޽� ������ �Ҵ�
		gunMeshComp->SetSkeletalMesh(TempGunMesh.Object);
		// 4-5. ��ġ �����ϱ�
		gunMeshComp->SetRelativeLocation(FVector(-14, 52, 120));
	}

	// 5. �������۰� ������Ʈ ���
	sniperGunComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SniperGunComp"));
	// 5-1. �θ� ������Ʈ�� Mesh ������Ʈ�� ����
	sniperGunComp->SetupAttachment(GetMesh());
	// 5-2. ����ƽ�޽� ������ �ε�
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempSniperMesh(TEXT("StaticMesh'/Game/SniperGun/sniper1.sniper1'"));
	// 5-3. �����ͷε尡 �����ߴٸ�
	if (TempSniperMesh.Succeeded())
	{
		// 5-4. ����ƽ�޽� ������ �Ҵ�
		sniperGunComp->SetStaticMesh(TempSniperMesh.Object);
		// 5-5. ��ġ �����ϱ�
		sniperGunComp->SetRelativeLocation(FVector(-22, 55, 120));
		// 5-6. ũ�� �����ϱ�
		sniperGunComp->SetRelativeScale3D(FVector(0.15f));
	}
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();

	// �⺻���� �������۰��� ����ϵ��� ����
	ChangeToSniperGun();
}

// Called every frame
void ATPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move();
	
}

// Called to bind functionality to input
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATPSPlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATPSPlayer::LookUp);
	// �¿� �Է� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ATPSPlayer::InputHorizontal);
	// ���� �Է� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ATPSPlayer::InputVertical);
	// ���� �Է� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ATPSPlayer::InputJump);

	// �Ѿ� �߻� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATPSPlayer::InputFire);

	// �� ��ü �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAction(TEXT("GrenadeGun"), IE_Pressed, this, &ATPSPlayer::ChangeToGrenadeGun);
	PlayerInputComponent->BindAction(TEXT("SniperGun"), IE_Pressed, this, &ATPSPlayer::ChangeToSniperGun);
}

void ATPSPlayer::InputFire()
{
	// �Ѿ� �߻� ó��
	FTransform firePosition = gunMeshComp->GetSocketTransform(TEXT("FirePosition"));
	GetWorld()->SpawnActor<ABullet>(bulletFactory, firePosition);
}

void ATPSPlayer::Move()
{
	direction = FTransform(GetControlRotation()).TransformVector(direction);
	AddMovementInput(direction);
	direction = FVector::ZeroVector;
}
// ���� �Լ�
void ATPSPlayer::InputJump()
{
	Jump();
}


// �¿� �Է� �̺�Ʈ �Լ�
void ATPSPlayer::InputHorizontal(float value)
{
	direction.Y = value;
}
// ���� �Է� �̺�Ʈ �Լ�
void ATPSPlayer::InputVertical(float value)
{
	direction.X = value;
}

void ATPSPlayer::Turn(float value)
{
	AddControllerYawInput(value);
}

void ATPSPlayer::LookUp(float value)
{
	AddControllerPitchInput(value);
}

// ��ź������ ����
void ATPSPlayer::ChangeToGrenadeGun()
{
	// ��ź�� ��� ������ üũ
	bUsingGrenadeGun = true;
	sniperGunComp->SetVisibility(false);
	gunMeshComp->SetVisibility(true);
}

// �������۰����� ����
void ATPSPlayer::ChangeToSniperGun()
{
	bUsingGrenadeGun = false;
	sniperGunComp->SetVisibility(true);
	gunMeshComp->SetVisibility(false);
}

