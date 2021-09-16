#pragma once

#include "../../../Util/VFunc/VFunc.h"

class IVRenderView
{
public:
	inline void SetBlend(const float blend) {
		VFunc_Get<void(__thiscall*)(void*, float)>(this, 4u)(this, blend);
	}

	inline void SetColorModulation(float const* blend) {
		VFunc_Get<void(__thiscall*)(void*, float const*)>(this, 6u)(this, blend);
	}
};

inline IVRenderView* g_pRenderView = nullptr;