#pragma once

#include "IMaterial.h"

class IMaterialSystem
{
public:
	inline IMaterial* CreateMaterial(const char* pMaterialName, void* pVMTKeyValues) {
		return VFunc_Get<IMaterial* (__thiscall*)(void*, const char*, void*)>(this, 70u)(this, pMaterialName, pVMTKeyValues);
	}

	inline IMaterial* FindMaterial(char* const szName, const char* const szTextureGroup, const bool bComplain = true, const char* const szComplainPrefix = nullptr) {
		return VFunc_Get<IMaterial* (__thiscall*)(void*, char const*, const char*, bool, const char*)>(this, 71u)(this, szName, szTextureGroup, bComplain, szComplainPrefix);
	}
};

inline IMaterialSystem* g_pMaterialSystem = nullptr;