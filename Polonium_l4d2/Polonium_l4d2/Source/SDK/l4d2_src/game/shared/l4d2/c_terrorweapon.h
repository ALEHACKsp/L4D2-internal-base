#pragma once

#include "../cstrike/weapon_csbase.h"
#include "../../client/c_baseplayer.h"

class IResponseRulesWeaponSource
{
public:
	//penis
};

class C_TerrorWeapon : public C_WeaponCSBase, public IResponseRulesWeaponSource
{
public:
	M_NETVAR(m_helpingHandSuppressionTimer, void*, "CTerrorWeapon", "m_helpingHandSuppressionTimer");
	M_NETVAR(m_duration, float, "CTerrorWeapon", "m_duration");
	M_NETVAR(m_timestamp, float, "CTerrorWeapon", "m_timestamp");
	M_NETVAR(m_helpingHandTimer, void*, "CTerrorWeapon", "m_helpingHandTimer");
	M_NETVAR(m_helpingHandTargetTimer, void*, "CTerrorWeapon", "m_helpingHandTargetTimer");
	M_NETVAR(m_helpingHandState, int, "CTerrorWeapon", "m_helpingHandState");
	M_NETVAR(m_helpingHandTarget, EHANDLE, "CTerrorWeapon", "m_helpingHandTarget");
	M_NETVAR(m_helpingHandExtendDuration, float, "CTerrorWeapon", "m_helpingHandExtendDuration");
	M_NETVAR(m_reloadQueuedStartTime, float, "CTerrorWeapon", "m_reloadQueuedStartTime");
	M_NETVAR(m_releasedAltFireButton, bool, "CTerrorWeapon", "m_releasedAltFireButton");
	M_NETVAR(m_releasedFireButton, bool, "CTerrorWeapon", "m_releasedFireButton");
	M_NETVAR(m_isHoldingAltFireButton, bool, "CTerrorWeapon", "m_isHoldingAltFireButton");
	M_NETVAR(m_isHoldingFireButton, bool, "CTerrorWeapon", "m_isHoldingFireButton");
	M_NETVAR(m_bPickedUpOnTransition, bool, "CTerrorWeapon", "m_bPickedUpOnTransition");
	M_NETVAR(m_DroppedByInfectedGender, bool, "CTerrorWeapon", "m_DroppedByInfectedGender");
	M_NETVAR(m_iBloodyWeaponLevel, int, "CTerrorWeapon", "m_iBloodyWeaponLevel");
	M_NETVAR(m_attackTimer, void*, "CTerrorWeapon", "m_attackTimer");
	M_NETVAR(m_swingTimer, void*, "CTerrorWeapon", "m_swingTimer");
	M_NETVAR(m_nUpgradedPrimaryAmmoLoaded, int, "CTerrorWeapon", "m_nUpgradedPrimaryAmmoLoaded");

public:
	inline float& GetBulletSpread() {
		return *reinterpret_cast<float*>(reinterpret_cast<unsigned long>(this) + 0xD0C);
	}

	inline bool CanPrimaryAttack(const int nTickBase) {
		return (m_flNextPrimaryAttack() <= (nTickBase * TICK_INTERVAL));
	}

	inline bool CanSecondaryAttack(const int nTickBase) {
		return (m_flNextSecondaryAttack() <= (nTickBase * TICK_INTERVAL));
	}
};

inline C_TerrorWeapon* ToTerrorWeapon(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_TerrorWeapon*>(pClientEntity);
#else
	return static_cast<C_TerrorWeapon*>(pClientEntity);
#endif
}

inline C_TerrorWeapon* ToTerrorWeapon(C_BaseEntity* pBaseEntity)
{
	if (!pBaseEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_TerrorWeapon*>(pBaseEntity);
#else
	return static_cast<C_TerrorWeapon*>(pBaseEntity);
#endif
}