// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "LMSAttributeSet.h"
#include "InputActionValue.h"
#include "LMSCharacter.generated.h"

class ULMSAttributeSet;

UCLASS(config = Game)
class ALMSCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Ability System Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	/*** Attribute System ***/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	const class ULMSAttributeSet* AttributeSetComponent;

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetHealthValues(float& Health, float& Max_Health);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetStaminaValues(float& Stamina, float& Max_Stamina);


	void OnHealthChangedNative(const FOnAttributeChangeData& Data);
	void OnStaminaChangedNative(const FOnAttributeChangeData& Data);

public:
	ALMSCharacter();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnHealthChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnStaminaChanged(float OldValue, float NewValue);


protected:

	virtual void BeginPlay();

public:

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilities();


	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

};

