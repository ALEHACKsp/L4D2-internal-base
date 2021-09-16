#pragma once

#include "../../client/c_baseanimating.h"

class C_WeaponSpawn : public C_BaseAnimating
{
public:
	M_NETVAR(m_weaponID, int, "CWeaponSpawn", "m_weaponID");
	M_NETVAR(m_flGlowRange, float, "CWeaponSpawn", "m_flGlowRange");
};

inline C_WeaponSpawn* ToWeaponSpawn(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_WeaponSpawn*>(pClientEntity);
#else
	return static_cast<C_WeaponSpawn*>(pClientEntity);
#endif
}