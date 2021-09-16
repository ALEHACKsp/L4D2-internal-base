#pragma once

#include "../../../Util/VFunc/VFunc.h"

class C_BasePlayer;
class IMoveHelper;
class CMoveData;
class CUserCmd;

class IPrediction
{
public:
	inline void SetupMove(C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* pHelper, CMoveData* move) {
		VFunc_Get<void(__thiscall*)(void*, C_BasePlayer*, CUserCmd*, IMoveHelper*, CMoveData*)>(this, 19u)(this, player, ucmd, pHelper, move);
	}

	inline void FinishMove(C_BasePlayer* player, CUserCmd* ucmd, CMoveData* move) {
		VFunc_Get<void(__thiscall*)(void*, C_BasePlayer*, CUserCmd*, CMoveData*)>(this, 20u)(this, player, ucmd, move);
	}
};

inline IPrediction* g_pPrediction = nullptr;