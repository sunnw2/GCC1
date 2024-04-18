// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():isMoveRight(true), LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Scene : �����ؼ� ���� ����
	// = : ���� ������(�����ʿ� �ִ� ���� ���ʿ� �ִ´�.)
	// CreateDefaultSubobject : ���� ����
	// USceneComponent : ������ Ŭ���� ����
	// TEXT("Scene") : �������Ʈ���� ������ �̸�

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SetRootComponent(Scene); //Scene�� RootComponent�� �����(SetRootComponent �޼���)

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform); //StaticMesg�� ��� ��ǥ�� �������� Scen(RootComponent)�� ����
	StaticMesh->SetRelativeTransform(FTransform::Identity);//StaticMesh�� Transform�� �ʱⰪ���� ����

}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	if (isMoveRight) 
	{
		//True
		LocX += 1;

		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));

		if (StaticMesh->GetRelativeLocation().X > 200) {
			isMoveRight = false;
			
		}
	}
	else 
	{
		//False
		LocX -= 1;

		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));

		if (StaticMesh->GetRelativeLocation().X < 0) {
			isMoveRight = true;
		}
	}
}

