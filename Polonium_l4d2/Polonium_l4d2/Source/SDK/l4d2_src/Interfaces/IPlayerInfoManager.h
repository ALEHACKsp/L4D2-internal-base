#pragma once

#include "../../../Util/VFunc/VFunc.h"
#include "../public/globalvars_base.h"

class IPlayerInfoManager
{
public:
	inline CGlobalVarsBase* GetGlobalVars() {
		return VFunc_Get<CGlobalVarsBase* (__thiscall*)(void*)>(this, 1u)(this);
	}
};

//inline IPlayerInfoManager* g_pPlayerInfoManager = nullptr;