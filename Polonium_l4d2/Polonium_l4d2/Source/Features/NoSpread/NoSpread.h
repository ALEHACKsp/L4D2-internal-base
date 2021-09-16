#pragma once

#include "../../SDK/SDK.h"

class CNoSpread
{
public:
	void Run(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* cmd);

private:
	bool ShouldRun(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* cmd);
};

inline CNoSpread g_NoSpread;