// Fill out your copyright notice in the Description page of Project Settings.


#include "LMSWeapon.h"
#include "AbilitySystemComponent.h"
#include "LMS_Weapon_AttributeSet.h"

// Sets default values
ALMSWeapon::ALMSWeapon()
{
	// Initialize Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


UAbilitySystemComponent* ALMSWeapon::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


// Called when the game starts or when spawned
void ALMSWeapon::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystemComponent)
	{
		AttributeSetComponent = AbilitySystemComponent->GetSet<ULMS_Weapon_AttributeSet>();

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnRangeChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnSpreadChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnFire_RateChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnReload_RateChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnController_RecoilChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnMax_DamageChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnMin_DamageChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnMax_Damage_DistanceChanagedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetComponent->GetRangeAttribute()).AddUObject(this, &ALMSWeapon::OnMin_Damage_DistanceChangedNative);

		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
	GiveDefaultAbilities();
	
}

void ALMSWeapon::InitializeAttributes()
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

void ALMSWeapon::GiveDefaultAbilities()
{
	if ( AbilitySystemComponent)
		for (TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities)
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility.GetDefaultObject(), 1, 0));
}

// Called every frame
void ALMSWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//////////////////////////Getting Attribute Values ///////////////////////////////

void ALMSWeapon::GetRangeValue(float& Range)
{
	Range = AttributeSetComponent->GetRange();
}

void ALMSWeapon::GetSpreadValue(float& Spread)
{
	Spread = AttributeSetComponent->GetSpread();
}

void ALMSWeapon::GetFire_RateValue(float& Fire_Rate)
{
	Fire_Rate = AttributeSetComponent->GetFire_Rate();
}

void ALMSWeapon::GetReload_RateValue(float& Reload_Rate)
{
	Reload_Rate = AttributeSetComponent->GetReload_Rate();
}

void ALMSWeapon::GetController_RecoilValue(float& Controller_Recoil)
{
	Controller_Recoil = AttributeSetComponent->GetController_Recoil();
}

void ALMSWeapon::GetDamageValues(float& Max_Damage, float& Min_Damage)
{
	Max_Damage = AttributeSetComponent->GetMax_Damage();
	Min_Damage = AttributeSetComponent->GetMin_Damage();
}

void ALMSWeapon::GetDamage_DistanceValues(float& Max_Damage_Distance, float& Min_Damage_Distance)
{
	Max_Damage_Distance = AttributeSetComponent->GetMax_Damage_Distance();
	Min_Damage_Distance = AttributeSetComponent->GetMin_Damage_Distance();
}

/////////////////////////////Getting On Attribute Value Changed///////////////////////////////

void ALMSWeapon::OnRangeChangedNative(const FOnAttributeChangeData& Data)
{
	OnRangeChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnSpreadChangedNative(const FOnAttributeChangeData& Data)
{
	OnSpreadChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnFire_RateChangedNative(const FOnAttributeChangeData& Data)
{
	OnFire_RateChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnReload_RateChangedNative(const FOnAttributeChangeData& Data)
{
	OnReload_RateChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnController_RecoilChangedNative(const FOnAttributeChangeData& Data)
{
	OnController_RecoilChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnMax_DamageChangedNative(const FOnAttributeChangeData& Data)
{
	OnMax_DamageChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnMin_DamageChangedNative(const FOnAttributeChangeData& Data)
{
	OnMin_DamageChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnMax_Damage_DistanceChanagedNative(const FOnAttributeChangeData& Data)
{
	OnMax_Damage_DistanceChanged(Data.OldValue, Data.NewValue);
}

void ALMSWeapon::OnMin_Damage_DistanceChangedNative(const FOnAttributeChangeData& Data)
{
	OnMin_Damage_DistanceChanged(Data.OldValue, Data.NewValue);
}


