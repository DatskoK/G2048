// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

/** Block that the player moves around the playfield */
UCLASS(minimalapi)
class ABlock : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** Text component for the score */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* BlockValueLabel;

public:
	ABlock();

	int32 GetBlockValue() const;

	/** Doubles the value of the Block and updates its label */
	void DoubleBlockValue();
	
	int32 SpawnBlockWithChanceOfFour() const;
	
	int32 BlockValue;
	
	/** Smoothly translates the Block to the given EndPosition */
	UFUNCTION(BlueprintImplementableEvent, Category = "Movement")
	void MoveBlockToPosition(FVector EndPosition);

	/** Plays animation before destroying the Block */
	UFUNCTION(BlueprintImplementableEvent, Category = "Destruction")
	void DestroyBlock();

	/** Returns true if two ABlocks have the same BlockValue  */
	FORCEINLINE bool operator==(const ABlock& OtherBlock) const
	{
		return BlockValue == OtherBlock.BlockValue;
	}

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }

	/** Static pointer to the scoreboard */
	static class AScoreboard* Scoreboard;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SpawnBlockWithChanceOfFour2();
	/** Used to clean up static variables in the editor upon exiting the game */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


};