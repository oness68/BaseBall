// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableTextBox.h"
#include "Blueprint/UserWidget.h"
#include "BBUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALL_API UBBUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;


    UFUNCTION()
    void OnMessageCommitted(const FText& Text, ETextCommit::Type CommitMethod);
    
    // 위젯에서 입력 받는 텍스트박스
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox* InputBox;

};
