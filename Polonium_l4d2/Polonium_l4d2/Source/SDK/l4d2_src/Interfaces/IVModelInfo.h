#pragma once

#include "../../../Util/VFunc/VFunc.h"
#include "../../../Util/Math/Vector/Vector.h"

#define HITGROUP_GENERIC 0
#define HITGROUP_HEAD 1
#define HITGROUP_CHEST 2
#define HITGROUP_STOMACH 3
#define HITGROUP_LEFTARM 4
#define HITGROUP_RIGHTARM 5
#define HITGROUP_LEFTLEG 6
#define HITGROUP_RIGHTLEG 7
#define HITGROUP_GEAR 10

struct mstudiobbox
{
	int         bone;
	int         group;
	Vector		bbmin;
	Vector		bbmax;
	int         szhitboxnameindex;
	int         _pad00[8];
};

struct mstudiohitboxset
{
	int                   sznameindex;
	inline char* const    pszName(void) const { return ((char*)this) + sznameindex; }
	int                   numhitboxes;
	int                   hitboxindex;
	inline mstudiobbox*   pHitbox(int i) const { return (mstudiobbox*)(((unsigned char*)this) + hitboxindex) + i; };
};

struct studiohdr_t
{
	unsigned char     _pad00[0xAC];
	int               numhitboxsets;
	int               hitboxsetindex;

	inline mstudiohitboxset* pHitboxSet(const int n) const
	{
		return (mstudiohitboxset*)(((unsigned char*)this) + hitboxsetindex) + n;
	};
};

class IVModelInfo
{
public:
	inline int GetModelIndex(const char* const szModelName) {
		return VFunc_Get<int(__thiscall*)(void*, const char*)>(this, 2u)(this, szModelName);
	}

	inline const char* GetModelName(const void* pModel) {
		return VFunc_Get<const char* (__thiscall*)(void*, const void*)>(this, 3u)(this, pModel);
	}

	inline studiohdr_t* GetStudioModel(const void* pModel) {
		return VFunc_Get<studiohdr_t* (__thiscall*)(void*, const void*)>(this, 30u)(this, pModel);
	}
};

inline IVModelInfo* g_pModelInfo = nullptr;