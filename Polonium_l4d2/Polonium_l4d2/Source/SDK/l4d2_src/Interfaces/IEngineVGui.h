#pragma once

#include "../../../Util/VFunc/VFunc.h"

enum class VGuiPanel_t
{
	PANEL_ROOT = 0,
	PANEL_GAMEUIDLL,
	PANEL_CLIENTDLL,
	PANEL_TOOLS,
	PANEL_INGAMESCREENS,
	PANEL_GAMEDLL,
	PANEL_CLIENTDLL_TOOLS
};

enum class PaintMode_t
{
	PAINT_UIPANELS = (1 << 0),
	PAINT_INGAMEPANELS = (1 << 1),
	PAINT_CURSOR = (1 << 2), // software cursor, if appropriate
};

class IEngineVGui
{
public:
	inline bool IsGameUIVisible() {
		return VFunc_Get<bool(__thiscall*)(void*)>(this, 2u)(this);
	}
};

inline IEngineVGui* g_pEngineVGui = nullptr;