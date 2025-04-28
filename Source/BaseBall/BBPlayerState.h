// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BBPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALL_API ABBPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	FORCEINLINE FString& GetPlayerUniaueID() { return PlayerUniqueID; }

	UFUNCTION()
	FORCEINLINE void SetPlayerUniaueID(const FString& ID) { PlayerUniqueID = ID; }
	
private:
	UPROPERTY(VisibleAnywhere, Replicated)
	FString PlayerUniqueID;

	UPROPERTY(VisibleAnywhere, Replicated)
	int32 PlayerCount = 3;

	UPROPERTY(VisibleAnywhere, Replicated)
	bool bMyturn = false;


};
