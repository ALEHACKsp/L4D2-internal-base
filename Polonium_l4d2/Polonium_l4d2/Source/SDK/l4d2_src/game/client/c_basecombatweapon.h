#pragma once

#include "c_baseanimating.h"

class C_BaseCombatWeapon : public C_BaseAnimating
{
public:
	M_NETVAR(m_iPrimaryAmmoType, int, "CBaseCombatWeapon", "m_iPrimaryAmmoType");
	M_NETVAR(m_iSecondaryAmmoType, int, "CBaseCombatWeapon", "m_iSecondaryAmmoType");
	M_NETVAR(m_nViewModelIndex, int, "CBaseCombatWeapon", "m_nViewModelIndex");
	M_NETVAR(m_flNextPrimaryAttack, float, "CBaseCombatWeapon", "m_flNextPrimaryAttack");
	M_NETVAR(m_flNextSecondaryAttack, float, "CBaseCombatWeapon", "m_flNextSecondaryAttack");
	M_NETVAR(m_nNextThinkTick, int, "CBaseCombatWeapon", "m_nNextThinkTick");
	M_NETVAR(m_flTimeWeaponIdle, float, "CBaseCombatWeapon", "m_flTimeWeaponIdle");
	M_NETVAR(m_nQueuedAttack, int, "CBaseCombatWeapon", "m_nQueuedAttack");
	M_NETVAR(m_flTimeAttackQueued, float, "CBaseCombatWeapon", "m_flTimeAttackQueued");
	M_NETVAR(m_bOnlyPump, bool, "CBaseCombatWeapon", "m_bOnlyPump");
	M_NETVAR(m_iViewModelIndex, int, "CBaseCombatWeapon", "m_iViewModelIndex");
	M_NETVAR(m_iWorldModelIndex, int, "CBaseCombatWeapon", "m_iWorldModelIndex");
	M_NETVAR(m_iState, int, "CBaseCombatWeapon", "m_iState");
	M_NETVAR(m_hOwner, int, "CBaseCombatWeapon", "m_hOwner");
	M_NETVAR(m_bInReload, bool, "CBaseCombatWeapon", "m_bInReload");
};

inline C_BaseCombatWeapon* ToBaseCombatWeapon(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_BaseCombatWeapon*>(pClientEntity);
#else
	return static_cast<C_BaseCombatWeapon*>(pClientEntity);
#endif
}