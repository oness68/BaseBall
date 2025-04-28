// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BBUserWidget.h"
#include "BBPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALL_API ABBPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	ABBPlayerController();

	UFUNCTION()
	void MakeMessagetoSend(const FString& Message);

	UFUNCTION(Server, Reliable)
	void ServerSendMessage(const FString& FullMessage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<UBBUserWidget> MainWidgetClass;

private:
	void AddWidget();

	UFUNCTION()
	void ShowMouseAndFocusUI();

protected:
	virtual void BeginPlay() override;

public:
	UBBUserWidget* UserWidget;

private:
	UPROPERTY()
	UBBUserWidget* MainWidget;
	

	UPROPERTY()
	FString Name;
};
