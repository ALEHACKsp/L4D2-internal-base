#pragma once

#include "IBaseClientDLL.h"
#include "../public/basehandle.h"

class IClientEntity;
class IClientEntityList
{
public:
	inline IClientEntity* GetClientEntity(const int nIndex) {
		return VFunc_Get<IClientEntity* (__thiscall*)(void*, int)>(this, 3u)(this, nIndex);
	}

	inline IClientEntity* GetClientEntityFromHandle(CBaseHandle hEntity) {
		return VFunc_Get<IClientEntity* (__thiscall*)(void*, CBaseHandle)>(this, 4u)(this, hEntity);
	}

	inline int GetMaxEntities() {
		return VFunc_Get<int(__thiscall*)(void*)>(this, 8u)(this);
	}
};

inline IClientEntityList* g_pEntityList = nullptr;