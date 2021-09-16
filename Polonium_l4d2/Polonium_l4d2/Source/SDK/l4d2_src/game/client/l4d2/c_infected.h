#pragma once

#include "c_terrorplayer.h"
#include "../c_basecombatcharacter.h"

class C_Infected : public C_NextBotCombatCharacter
{
public:
	M_NETVAR(m_flStartTime, float, "Infected", "m_flStartTime");
	M_NETVAR(m_bLooping, bool, "Infected", "m_bLooping");
	M_NETVAR(m_fFlags, int, "Infected", "m_fFlags");
	M_NETVAR(m_nWaterLevel, int, "Infected", "m_nWaterLevel");
	M_NETVAR(m_sequenceStartTime, float, "Infected", "m_sequenceStartTime");
	M_NETVAR(m_clientLookatTarget, EHANDLE, "Infected", "m_clientLookatTarget");
	M_NETVAR(m_clientLeanYaw, float, "Infected", "m_clientLeanYaw");
	M_NETVAR(m_gibbedLimbForce, Vector, "Infected", "m_gibbedLimbForce");
	M_NETVAR(m_originalBody, int, "Infected", "m_originalBody");
	M_NETVAR(m_mobRush, bool, "Infected", "m_mobRush");
	M_NETVAR(m_bIsBurning, bool, "Infected", "m_bIsBurning");
	M_NETVAR(m_nFallenFlags, int, "Infected", "m_nFallenFlags");
};

class C_SurvivorBot : public C_TerrorPlayer
{
public:
	M_NETVAR(m_humanSpectatorUserID, int, "SurvivorBot", "m_humanSpectatorUserID");
	M_NETVAR(m_humanSpectatorEntIndex, int, "SurvivorBot", "m_humanSpectatorEntIndex");
};

class C_Tank : public C_TerrorPlayer
{
public:

};

class C_Witch : public C_Infected
{
public:
	M_NETVAR(m_rage, float, "Witch", "m_rage");
	M_NETVAR(m_wanderRage, float, "Witch", "m_wanderRage");
};

inline C_Infected* ToInfected(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_Infected*>(pClientEntity);
#else
	return static_cast<C_Infected*>(pClientEntity);
#endif
}

inline C_SurvivorBot* ToSurvivorBot(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_SurvivorBot*>(pClientEntity);
#else
	return static_cast<C_SurvivorBot*>(pClientEntity);
#endif
}

inline C_Tank* ToTank(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_Tank*>(pClientEntity);
#else
	return static_cast<C_Tank*>(pClientEntity);
#endif
}

inline C_Witch* ToWitch(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_Witch*>(pClientEntity);
#else
	return static_cast<C_Witch*>(pClientEntity);
#endif
}