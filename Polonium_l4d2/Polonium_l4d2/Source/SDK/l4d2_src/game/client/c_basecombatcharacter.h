#pragma once

#include "c_baseanimating.h"
#include "c_basecombatweapon.h"

class C_BaseCombatCharacter : public C_BaseFlex
{
public:
	M_NETVAR(m_flNextAttack, float, "CBaseCombatCharacter", "m_flNextAttack");
	M_NETVAR(m_hActiveWeapon, EHANDLE, "CBaseCombatCharacter", "m_hActiveWeapon");
	M_NETVAR(m_hMyWeapons, EHANDLE*, "CBaseCombatCharacter", "m_hMyWeapons");

public:
	inline bool CanAttack(const int nTickBase)
	{
		bool bResult = false;

		if (nTickBase)
			bResult = (m_flNextAttack() <= TICKS_TO_TIME(nTickBase));

		return bResult;
	}
};

class C_NextBotCombatCharacter : public C_BaseCombatCharacter
{
public:

};