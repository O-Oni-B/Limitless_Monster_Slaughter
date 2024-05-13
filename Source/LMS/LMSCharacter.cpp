// Copyright Epic Games, Inc. All Rights Reserved.

#include "LMSCharacter.h"
#include "AbilitySystemComponent.h"
#include "LMSAttributeSet.h"
//#include "Camera/CameraComponent.h"
//#include "Components/CapsuleComponent.h"
//#include "Components/InputComponent.h"
//#include "GameFramework/CharacterMovementComponent.h"
//#include "GameFramework/Controller.h"
//#include "GameFramework/SpringArmComponent.h"
//#include "EnhancedInputComponent.h"
//#include "EnhancedInputSubsystems.h"


//////////////////////////////////////////////////////////////////////////
// ALMSCharacter



ALMSCharacter::ALMSCharacter()
{
	// Initialize Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

UAbilitySystemComponent* ALMSCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALMSCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		AttributeSetComponent = AbilitySystemComponent->GetSet<ULMSAttributeSet>();

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetHealthAttribute()).AddUObject(this, &ALMSCharacter::OnHealthChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetStaminaAttribute()).AddUObject(this, &ALMSCharacter::OnStaminaChangedNative);
	}
}

void ALMSCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

	}
	InitializeAttributes();
	GiveDefaultAbilities();
}

void ALMSCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (AbilitySystemComponent)
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitializeAttributes();
}

void ALMSCharacter::InitializeAttributes()
{
	if (AbilitySystemComponent && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void ALMSCharacter::GiveDefaultAbilities()
{
	if (HasAuthority() && AbilitySystemComponent)
		for (TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities)
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility.GetDefaultObject(), 1, 0));
}

void ALMSCharacter::GetHealthValues(float& Health, float& Max_Health)
{
	Health = AttributeSetComponent->GetHealth();
	Max_Health = AttributeSetComponent->GetMax_Health();
}

void ALMSCharacter::GetStaminaValues(float& Stamina, float& Max_Stamina)
{
	Stamina = AttributeSetComponent->GetStamina();
	Max_Stamina = AttributeSetComponent->GetMax_Stamina();
}

void ALMSCharacter::OnHealthChangedNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ALMSCharacter::OnStaminaChangedNative(const FOnAttributeChangeData& Data)
{
	OnStaminaChanged(Data.OldValue, Data.NewValue);
}
