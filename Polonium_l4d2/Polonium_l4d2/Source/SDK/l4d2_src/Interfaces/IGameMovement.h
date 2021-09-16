#pragma once

#include "../../../Util/VFunc/VFunc.h"
#include "../../../Util/Math/Vector/Vector.h"

class C_BasePlayer;

//l4d2hook
class CMoveData
{
public:
	bool			m_bFirstRunOfFunctions : 1;
	bool			m_bGameCodeMovedPlayer : 1;
	bool			m_bNoAirControl : 1;

	unsigned long	m_nPlayerHandle;
	int				m_nImpulseCommand;
	Vector			m_vecViewAngles;
	Vector			m_vecAbsViewAngles;
	int				m_nButtons;
	int				m_nOldButtons;
	float			m_flForwardMove;
	float			m_flSideMove;
	float			m_flUpMove;

	float			m_flMaxSpeed;
	float			m_flClientMaxSpeed;

	Vector			m_vecVelocity;
	Vector			m_vecOldVelocity;
	float			somefloat;
	Vector			m_vecAngles;
	Vector			m_vecOldAngles;

	float			m_outStepHeight;
	Vector			m_outWishVel;
	Vector			m_outJumpVel;

	Vector			m_vecConstraintCenter;
	float			m_flConstraintRadius;
	float			m_flConstraintWidth;
	float			m_flConstraintSpeedFactor;
	bool			m_bConstraintPastRadius;

	Vector			m_vecAbsOrigin; //edict::origin
};

class IGameMovement
{
public:
	inline void ProcessMovement(C_BasePlayer* pPlayer, CMoveData* pMove) {
		VFunc_Get<void(__thiscall*)(void*, C_BasePlayer*, CMoveData*)>(this, 1u)(this, pPlayer, pMove);
	}
};

inline IGameMovement* g_pGameMovement = nullptr;