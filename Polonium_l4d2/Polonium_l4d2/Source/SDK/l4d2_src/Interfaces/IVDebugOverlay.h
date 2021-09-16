#pragma once

#include "../../../Util/Math/Vector/Vector.h"
#include "../../../Util/VFunc/VFunc.h"

class IVDebugOverlay
{
public:


	inline bool ScreenPosition(const Vector& vIn, Vector& vOut) {
		return VFunc_Get<bool(__thiscall*)(void*, const Vector&, Vector&)>(this, 12u)(this, vIn, vOut);
	}
};

inline IVDebugOverlay* g_pDebugOverlay = nullptr;