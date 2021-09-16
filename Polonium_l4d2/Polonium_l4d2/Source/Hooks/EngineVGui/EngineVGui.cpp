#include "EngineVGui.h"

#include "../../Features/ESP/ESP.h"

using namespace Hooks;

void __fastcall EngineVGui::Paint::Detour(void* ecx, void* edx, int mode)
{
	static const auto StartDrawing  = reinterpret_cast<void(__thiscall*)(void*)>(g_Offsets.m_dwStartDrawing);
	static const auto FinishDrawing = reinterpret_cast<void(__thiscall*)(void*)>(g_Offsets.m_dwFinishDrawing);

	Func.Original<FN>()(ecx, edx, mode);

	StartDrawing(g_pSurface);
	{
		g_Draw.String(EFont::DEBUG, 5, 5, COLOR_WHITE, TXT_DEFAULT, _(L"Left 4 Dead 2 Hooker"));

		if (g_Global.m_bInGame && !g_Global.m_bIsGameUIVisible)
		{
			g_ESP.Render();
		}
	}
	FinishDrawing(g_pSurface);
}

void EngineVGui::Initialize()
{
	XASSERT(Paint::Func.Initialize(VFunc_Get<Paint::FN>(g_pEngineVGui, Paint::Index), &Paint::Detour) == FAILED_TO_INITIALIZE);
}