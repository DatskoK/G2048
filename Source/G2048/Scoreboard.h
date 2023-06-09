// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scoreboard.generated.h"

UCLASS()
class G2048_API AScoreboard : public AActor
{
	GENERATED_BODY()
	
	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** Text component for the score */
	UPROPERTY(Category = "Score", VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* ScoreboardLabel;

public:	
	// Sets default values for this actor's properties
	AScoreboard();

	// TODO: May need to remove/change
	void AddToScore(int32 ValueToAdd);

private:
	/** The player's current score. Defaults to 0 **/
	int32 Score = 0;
};
