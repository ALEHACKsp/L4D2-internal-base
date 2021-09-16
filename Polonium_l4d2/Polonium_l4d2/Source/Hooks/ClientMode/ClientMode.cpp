#include "ClientMode.h"

#include "../../Features/Misc/Misc.h"
#include "../../Features/NoSpread/NoSpread.h"
#include "../../Features/EnginePrediction/EnginePrediction.h"

using namespace Hooks;

void __fastcall ClientMode::OverrideView::Detour(void* ecx, void* edx, CViewSetup* pSetup)
{
	Table.Original<FN>(Index)(ecx, edx, pSetup);

	pSetup->fov = 125.0f;
}

bool __fastcall ClientMode::CreateMove::Detour(void* ecx, void* edx, float flInputSampleTime, CUserCmd* cmd)
{
	if (!cmd || !cmd->command_number)
		return Table.Original<FN>(Index)(ecx, edx, flInputSampleTime, cmd);

	const auto& pLocal  = g_EntityCache.GetLocal();
	const auto& pWeapon = g_EntityCache.GetWeapon();

	if (g_Global.m_bInGame && pLocal && pWeapon && pLocal->IsAlive())
	{
		g_Misc.Run(pLocal, cmd);

		g_EnginePrediction.Start(pLocal, cmd);
		{
			g_NoSpread.Run(pLocal, pWeapon, cmd);
		}
		g_EnginePrediction.Finish(pLocal, cmd);
	}

	return false;
}

void ClientMode::Initialize()
{
	XASSERT(Table.Initialize(g_pClientMode) == FAILED_TO_INITIALIZE);
	XASSERT(Table.Hook(&OverrideView::Detour, OverrideView::Index) == FAILED_TO_HOOK);
	XASSERT(Table.Hook(&CreateMove::Detour, CreateMove::Index) == FAILED_TO_HOOK);
}