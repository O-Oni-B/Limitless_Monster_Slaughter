
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "LMS_Weapon_AttributeSet.h"
#include "LMSWeapon.generated.h"

class ULMS_Weapon_AttributeSet;

UCLASS()
class LMS_API ALMSWeapon : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	/** Ability System Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	/*** Attribute System ***/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	const class ULMS_Weapon_AttributeSet* AttributeSetComponent;


	/*** Getting Attribute Values ***/
	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetRangeValue(float& Range);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetSpreadValue(float& Spread);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetFire_RateValue(float& Fire_Rate);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetReload_RateValue(float& Reload_Rate);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetController_RecoilValue(float& Controller_Recoil);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetDamageValues(float& Max_Damage, float& Min_Damage);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	void GetDamage_DistanceValues(float& Max_Damage_Distance, float& Min_Damage_Distance);
	/*************************************/

    //**** On Attribute Changed Native ****//
	void OnRangeChangedNative(const FOnAttributeChangeData& Data);
	void OnSpreadChangedNative(const FOnAttributeChangeData& Data);
	void OnFire_RateChangedNative(const FOnAttributeChangeData& Data);
	void OnReload_RateChangedNative(const FOnAttributeChangeData& Data);
	void OnController_RecoilChangedNative(const FOnAttributeChangeData& Data);
	void OnMax_DamageChangedNative(const FOnAttributeChangeData& Data);
	void OnMin_DamageChangedNative(const FOnAttributeChangeData& Data);
	void OnMax_Damage_DistanceChanagedNative(const FOnAttributeChangeData& Data);
	void OnMin_Damage_DistanceChangedNative(const FOnAttributeChangeData& Data);
	//***********************************//



public:	
	// Sets default values for this actor's properties
	ALMSWeapon();
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnRangeChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnSpreadChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnFire_RateChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnReload_RateChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnController_RecoilChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnMax_DamageChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnMin_DamageChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnMax_Damage_DistanceChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
	void OnMin_Damage_DistanceChanged(float OldValue, float NewValue);





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilities();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
