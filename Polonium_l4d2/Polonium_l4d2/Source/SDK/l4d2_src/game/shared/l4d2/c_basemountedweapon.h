#pragma once

#include "../../client/c_dynamicprop.h"

class C_BaseMountedWeapon : public C_DynamicProp
{
public:
	M_NETVAR(m_initialAngles, Vector, "CBaseMountedWeapon", "m_initialAngles");
	M_NETVAR(m_owner, EHANDLE, "CBaseMountedWeapon", "m_owner");
	M_NETVAR(m_maxYaw, float, "CBaseMountedWeapon", "m_maxYaw");
	M_NETVAR(m_maxPitch, float, "CBaseMountedWeapon", "m_maxPitch");
	M_NETVAR(m_minPitch, float, "CBaseMountedWeapon", "m_minPitch");
	M_NETVAR(m_firing, bool, "CBaseMountedWeapon", "m_firing");
	M_NETVAR(m_overheated, bool, "CBaseMountedWeapon", "m_overheated");
	M_NETVAR(m_heat, float, "CBaseMountedWeapon", "m_heat");
};

inline C_BaseMountedWeapon* ToBaseMountedWeapon(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_BaseMountedWeapon*>(pClientEntity);
#else
	return static_cast<C_BaseMountedWeapon*>(pClientEntity);
#endif
}