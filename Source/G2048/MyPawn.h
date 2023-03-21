// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class ABlockGrid;

UCLASS()
class G2048_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
protected:
	// Input
	void OnShiftBlockLeft();
	void OnShiftBlocksRight();
	void OnShiftBlocksUp();
	void OnShiftBlockDown();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)

	ABlockGrid* BlockGrid = nullptr;
	
private:	
	void FindBlockGridInScene();
};
