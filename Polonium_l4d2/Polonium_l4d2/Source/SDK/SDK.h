#pragma once

#include "EntityCache/EntityCache.h"

#define FAILED_TO_HOOK false
#define FAILED_TO_INITIALIZE false

class CUtil
{
public:
	void FixMovement(const Vector vAngle, CUserCmd* cmd);
	void Trace(const Vector& start, const Vector& end, unsigned int mask, ITraceFilter* filter, trace_t* trace);

	bool W2S(const Vector vWorld, Vector& vScreen);
	bool IsVisible(const Vector& from, const Vector& to);

	const char* GetWeaponAlias(const int nWeaponID);

	std::wstring Utf8ToWide(const std::string_view& str);

	Color_t GetHealthColor(const int nHealth, const int nMaxHealth);
};

inline CUtil g_Util;