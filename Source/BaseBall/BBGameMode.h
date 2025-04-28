// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BBPlayerController.h"
#include "BBGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALL_API ABBGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ABBGameMode();

public:
	void BroadcastChatMessage(const FString& Message);


protected:

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void BeginPlay() override;

	UFUNCTION(NetMulticast, Reliable)
	void MulticastChatMessage(const FString& Message);
	
	UPROPERTY(VisibleAnywhere)
	TArray<ABBPlayerController*> ConnectedControllers;
private:

	void GrantUserID(ABBPlayerController* NewPlayer);

	


};
