// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "BlockGrid.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyPawn::AMyPawn()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	FindBlockGridInScene();
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("ShiftBlocksLeft", EInputEvent::IE_Pressed, this, &AMyPawn::OnShiftBlockLeft);
	PlayerInputComponent->BindAction("ShiftBlocksRight", EInputEvent::IE_Pressed, this, &AMyPawn::OnShiftBlocksRight);
	PlayerInputComponent->BindAction("ShiftBlocksUp", EInputEvent::IE_Pressed, this, &AMyPawn::OnShiftBlocksUp);
	PlayerInputComponent->BindAction("ShiftBlocksDown", EInputEvent::IE_Pressed, this, &AMyPawn::OnShiftBlockDown);
}

void AMyPawn::OnShiftBlockLeft()
{
	BlockGrid->MoveGridBlocks(EBlockGridMoveDirection::Left);
}

void AMyPawn::OnShiftBlocksRight()
{
	BlockGrid->MoveGridBlocks(EBlockGridMoveDirection::Right);
}

void AMyPawn::OnShiftBlocksUp()
{
	BlockGrid->MoveGridBlocks(EBlockGridMoveDirection::Up);
}

void AMyPawn::OnShiftBlockDown()
{
	BlockGrid->MoveGridBlocks(EBlockGridMoveDirection::Down);
}

void AMyPawn::FindBlockGridInScene()
{
	TArray<AActor*> FoundBlockGrid;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlockGrid::StaticClass(), FoundBlockGrid);
	BlockGrid = Cast<ABlockGrid>(FoundBlockGrid.Pop());
}

