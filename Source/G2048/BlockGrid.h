#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockGrid.generated.h"

UENUM()
enum class EBlockGridMoveDirection : uint8
{
	Left,
	Right,
	Up,
	Down
};

UCLASS(minimalapi)
class ABlockGrid : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

public:
	ABlockGrid();

	/** Attempts to move all blocks in given direction. Meant to be used by PlayerController */
	void MoveGridBlocks(EBlockGridMoveDirection EDirection);

	/** Number of blocks along each side of grid */
	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	int32 Size;

	/** Spacing of blocks */
	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	float BlockSpacing;

	/** Time to wait in seconds for next Block spawn */
	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	float BlockSpawnDelay;

	/** Slots used to represent the playfield grid */
	UPROPERTY(Category=Grid, EditAnywhere)
	TSubclassOf<class ASlot> Slot;

	/** Blocks used to populate the playfield */
	UPROPERTY(Category=Grid, EditAnywhere)
	TSubclassOf<class ABlock> Block;

	UPROPERTY(Category=Grid, EditAnywhere,BlueprintReadWrite)
	bool IsGameOver;
	
	/** Returns DummyRoot subobject */
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }

protected:
	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

private:
	/** Spawn block on to the Grid */
	void SpawnBlockAtRandomLocation();

	/** Populate playfield with slots to visually form a grid */
	void SpawnAllGridSlots();

	/** Shift all blocks to one side of the playfield */
	void ShiftBlocksLeft();
	void ShiftBlocksRight();
	void ShiftBlocksUp();
	void ShiftBlocksDown();

	/** Updates the position of all Blocks to match the Grid TArray */
	void UpdateAllBlockPositions();

	/** Sets the PreviousGrid to be equal to the current Grid */
	void SetPreviousGridEqualToGrid();

	/**
	 * Returns true if the Grid is not equal to the PreviousGrid. Used for determining if
	 * a valid move was made.
	 */
	bool bGridHasChanged();

	/** Returns an FVector with the world location of grid coordinate at specified index */
	FVector GetGridLocationAtIndex(int32 Index);

	/** Returns true if Grid TArray is full */
	bool bGridIsFull();

	/** Attempts to spawn a new Block. If it can't, gameover. */
	void AttemptToSpawnBlock();

	/** Destroy all Blocks marked for Deletion */
	void DestroyBlocksMarkedForDeletion();

	/**
	 * Transposes the Grid as you would a matrix. Used in conjunction with the ShiftBlocksUp() and
	 * ShiftBlocksDown() methods for shifting the Blocks left and right. See ShiftBlocksLeft() and
	 * ShiftBlocksRight() for how this is implmented.
	 */
	void TransposeGrid();

	/** The grid we are playing on */
	TArray<class ABlock*> Grid;

	/** Used for checking if the Grid has changed */
	TArray<class ABlock*> PreviousGrid;

	/** Blocks marked for deletion */
	TArray<class ABlock*> BlocksMarkedForDeletion;

	/** FTimerHandle used to delay the next Block spawn */
	FTimerHandle BlockSpawnDelayTimerHandle;

	/** If no more moves can be made, game over! */
};