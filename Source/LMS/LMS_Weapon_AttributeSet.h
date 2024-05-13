// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LMS_Weapon_AttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) 

UCLASS()
class LMS_API ULMS_Weapon_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	ULMS_Weapon_AttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	// ************Adding Range Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Range;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Range);

	UFUNCTION()
	virtual void OnRep_Range(const FGameplayAttributeData& OldRange);

	// ************Adding Spread Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Spread;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Spread);

	UFUNCTION()
	virtual void OnRep_Spread(const FGameplayAttributeData& OldSpread);

	// ************Adding Fire Rate Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Fire_Rate;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Fire_Rate);

	UFUNCTION()
	virtual void OnRep_Fire_Rate(const FGameplayAttributeData& OldFire_Rate);

	// ************Adding Reload Rate Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Reload_Rate;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Reload_Rate);

	UFUNCTION()
	virtual void OnRep_Reload_Rate(const FGameplayAttributeData& OldReload_Rate);

	// ************Adding Controller_Recoil Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Controller_Recoil;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Controller_Recoil);

	UFUNCTION()
	virtual void OnRep_Controller_Recoil(const FGameplayAttributeData& OldController_Recoil);

	// ************Adding Max_Damage Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Max_Damage;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Max_Damage);

	UFUNCTION()
	virtual void OnRep_Max_Damage(const FGameplayAttributeData& OldMax_Damage);

	// ************Adding Min_Damage Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Min_Damage;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Min_Damage);

	UFUNCTION()
	virtual void OnRep_Min_Damage(const FGameplayAttributeData& OldMin_Damage);

	// ************Adding Max_Damage_Distance Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Max_Damage_Distance;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Max_Damage_Distance);

	UFUNCTION()
	virtual void OnRep_Max_Damage_Distance(const FGameplayAttributeData& OldMax_Damage_Distance);

	// ************Adding Min_Damage_Distance Attribute************ //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Min_Damage_Distance;
	ATTRIBUTE_ACCESSORS(ULMS_Weapon_AttributeSet, Min_Damage_Distance);

	UFUNCTION()
	virtual void OnRep_Min_Damage_Distance(const FGameplayAttributeData& OldMin_Damage_Distance);
};
