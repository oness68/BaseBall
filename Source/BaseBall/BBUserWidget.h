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
    
    // �������� �Է� �޴� �ؽ�Ʈ�ڽ�
    UPROPERTY(meta = (BindWidget))
    UEditableTextBox* InputBox;

};
