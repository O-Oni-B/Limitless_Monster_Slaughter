// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LMSAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) 

UCLASS()
class LMS_API ULMSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	

public:
    ULMSAttributeSet();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

    // ************Adding Health Attribute************ //
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(ULMSAttributeSet, Health);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Max_Health;
    ATTRIBUTE_ACCESSORS(ULMSAttributeSet, Max_Health);

    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

    // ************Adding Stamina Attribute************ //
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(ULMSAttributeSet, Stamina);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Max_Stamina;
    ATTRIBUTE_ACCESSORS(ULMSAttributeSet, Max_Stamina);

    UFUNCTION()
    virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

   
};
