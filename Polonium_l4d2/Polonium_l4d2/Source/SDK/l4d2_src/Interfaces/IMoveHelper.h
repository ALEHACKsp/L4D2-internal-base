#pragma once

#include "../../../Util/VFunc/VFunc.h"

class C_BasePlayer;

class IMoveHelper
{
public:
	inline void SetHost(C_BasePlayer* player) {
		VFunc_Get<void(__thiscall*)(void*, C_BasePlayer*)>(this, 1u)(this, player);
	}
};

inline IMoveHelper* g_pMoveHelper = nullptr;