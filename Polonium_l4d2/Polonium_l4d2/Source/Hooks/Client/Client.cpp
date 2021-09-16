#include "Client.h"

using namespace Hooks;

void __fastcall Client::LevelInitPostEntity::Detour(void* ecx, void* edx)
{
	Table.Original<FN>(Index)(ecx, edx);

	g_Global.m_nLocalIndex = g_pEngine->GetLocalPlayer();
}

void __fastcall Client::LevelShutdown::Detour(void* ecx, void* edx)
{
	g_EntityCache.Clear();

	g_Global.m_nLocalIndex = -1;
	g_Global.m_bInGame     = false;

	Table.Original<FN>(Index)(ecx, edx);
}

void __fastcall Client::FrameStageNotify::Detour(void* ecx, void* edx, ClientFrameStage_t curStage)
{
	Table.Original<FN>(Index)(ecx, edx, curStage);

	switch (curStage)
	{
		case ClientFrameStage_t::FRAME_NET_UPDATE_START:
		{
			g_EntityCache.Clear();
			break;
		}
		case ClientFrameStage_t::FRAME_NET_UPDATE_END:
		{
			g_EntityCache.Update();
			break;
		}
		default:
			break;
	}
}

void Client::Initialize()
{
	XASSERT(Table.Initialize(g_pClient) == FAILED_TO_INITIALIZE);
	XASSERT(Table.Hook(&LevelInitPostEntity::Detour, LevelInitPostEntity::Index) == FAILED_TO_HOOK);
	XASSERT(Table.Hook(&LevelShutdown::Detour, LevelShutdown::Index) == FAILED_TO_HOOK);
	XASSERT(Table.Hook(&FrameStageNotify::Detour, FrameStageNotify::Index) == FAILED_TO_HOOK);
}