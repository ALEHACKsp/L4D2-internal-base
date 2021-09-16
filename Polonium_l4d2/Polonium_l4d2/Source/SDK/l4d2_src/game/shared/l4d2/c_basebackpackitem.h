#pragma once

#include "c_terrorweapon.h"

class C_BaseBackpackItem : public C_TerrorWeapon
{
public:
	M_NETVAR(m_bPerformingAction, bool, "CBaseBackpackItem", "m_bPerformingAction");
};

inline C_BaseBackpackItem* ToBaseBackpackItem(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_BaseBackpackItem*>(pClientEntity);
#else
	return static_cast<C_BaseBackpackItem*>(pClientEntity);
#endif
}