// Fill out your copyright notice in the Description page of Project Settings.


#include "LMS_Weapon_AttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


ULMS_Weapon_AttributeSet::ULMS_Weapon_AttributeSet()
{
}

void ULMS_Weapon_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Range, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Spread, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Fire_Rate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Reload_Rate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Controller_Recoil, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Max_Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Min_Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Max_Damage_Distance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULMS_Weapon_AttributeSet, Min_Damage_Distance, COND_None, REPNOTIFY_Always);

}

void ULMS_Weapon_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}

void ULMS_Weapon_AttributeSet::OnRep_Range(const FGameplayAttributeData& OldRange)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Range, OldRange);
}

void ULMS_Weapon_AttributeSet::OnRep_Spread(const FGameplayAttributeData& OldSpread)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Spread, OldSpread);
}

void ULMS_Weapon_AttributeSet::OnRep_Fire_Rate(const FGameplayAttributeData& OldFire_Rate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Fire_Rate, OldFire_Rate);
}

void ULMS_Weapon_AttributeSet::OnRep_Reload_Rate(const FGameplayAttributeData& OldReload_Rate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Reload_Rate, OldReload_Rate);
}

void ULMS_Weapon_AttributeSet::OnRep_Controller_Recoil(const FGameplayAttributeData& OldController_Recoil)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Controller_Recoil, OldController_Recoil);
}

void ULMS_Weapon_AttributeSet::OnRep_Max_Damage(const FGameplayAttributeData& OldMax_Damage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Max_Damage, OldMax_Damage);
}

void ULMS_Weapon_AttributeSet::OnRep_Min_Damage(const FGameplayAttributeData& OldMin_Damage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Min_Damage, OldMin_Damage);
}

void ULMS_Weapon_AttributeSet::OnRep_Max_Damage_Distance(const FGameplayAttributeData& OldMax_Damage_Distance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Max_Damage_Distance, OldMax_Damage_Distance);
}

void ULMS_Weapon_AttributeSet::OnRep_Min_Damage_Distance(const FGameplayAttributeData& OldMin_Damage_Distance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULMS_Weapon_AttributeSet, Min_Damage_Distance, OldMin_Damage_Distance);
}


