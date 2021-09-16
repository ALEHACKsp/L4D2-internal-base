#include "Entry.h"

#include "../Features/Vars.h"

void CModuleEntry::Load()
{
	while (!GetModuleHandleW(_(L"serverbrowser.dll")))
		std::this_thread::sleep_for(std::chrono::seconds(1));

	g_Offsets.Initialize();
	{
		g_pClient = reinterpret_cast<IBaseClientDLL*>(g_Interface.Get(_(L"client.dll"), _("VClient016")));
		XASSERT(g_pClient == nullptr);

		g_pEntityList = reinterpret_cast<IClientEntityList*>(g_Interface.Get(_(L"client.dll"), _("VClientEntityList003")));
		XASSERT(g_pEntityList == nullptr);

		g_pGameMovement = reinterpret_cast<IGameMovement*>(g_Interface.Get(_(L"client.dll"), _("GameMovement001")));
		XASSERT(g_pGameMovement == nullptr);

		g_pPrediction = reinterpret_cast<IPrediction*>(g_Interface.Get(_(L"client.dll"), _("VClientPrediction001")));
		XASSERT(g_pPrediction == nullptr);

		g_pEngine = reinterpret_cast<IVEngineClient*>(g_Interface.Get(_(L"engine.dll"), _("VEngineClient013")));
		XASSERT(g_pEngine == nullptr);

		g_pModelInfo = reinterpret_cast<IVModelInfo*>(g_Interface.Get(_(L"engine.dll"), _("VModelInfoClient004")));
		XASSERT(g_pModelInfo == nullptr);

		g_pModelRender = reinterpret_cast<IVModelRender*>(g_Interface.Get(_(L"engine.dll"), _("VEngineModel016")));
		XASSERT(g_pModelRender == nullptr);

		g_pEngineTrace = reinterpret_cast<IEngineTrace*>(g_Interface.Get(_(L"engine.dll"), _("EngineTraceClient003")));
		XASSERT(g_pEngineTrace == nullptr);

		g_pDebugOverlay = reinterpret_cast<IVDebugOverlay*>(g_Interface.Get(_(L"engine.dll"), _("VDebugOverlay003")));
		XASSERT(g_pDebugOverlay == nullptr);

		g_pRenderView = reinterpret_cast<IVRenderView*>(g_Interface.Get(_(L"engine.dll"), _("VEngineRenderView013")));
		XASSERT(g_pRenderView == nullptr);

		g_pEngineVGui = reinterpret_cast<IEngineVGui*>(g_Interface.Get(_(L"engine.dll"), _("VEngineVGui001")));
		XASSERT(g_pEngineVGui == nullptr);

		g_pSurface = reinterpret_cast<ISurface*>(g_Interface.Get(_(L"vguimatsurface.dll"), _("VGUI_Surface031")));
		XASSERT(g_pSurface == nullptr);

		g_pMaterialSystem = reinterpret_cast<IMaterialSystem*>(g_Interface.Get(_(L"materialsystem.dll"), _("VMaterialSystem080")));
		XASSERT(g_pMaterialSystem == nullptr);

		g_pStudioRender = reinterpret_cast<IStudioRender*>(g_Interface.Get(_(L"studiorender.dll"), _("VStudioRender026")));
		XASSERT(g_pStudioRender == nullptr);

		g_pClientMode = **reinterpret_cast<void***>(g_Offsets.m_dwClientMode);
		XASSERT(g_pClientMode == nullptr);

		g_pGlobals = **reinterpret_cast<CGlobalVarsBase***>(g_Offsets.m_dwGlobalVars);
		XASSERT(g_pGlobals == nullptr);

		g_pMoveHelper = **reinterpret_cast<IMoveHelper***>(g_Offsets.m_dwMoveHelper);
		XASSERT(g_pMoveHelper == nullptr);
	}

	{
		Vars::Load();
		g_Draw.Initialize();

		//If injecting while in game, our levelinitpostentity hook wont update this
		if (g_pEngine->IsInGame())
			g_Global.m_nLocalIndex = g_pEngine->GetLocalPlayer();
	}

	XASSERT(MH_Initialize() != MH_STATUS::MH_OK);
	{
		Hooks::Initialize();
	}
	XASSERT(MH_EnableHook(MH_ALL_HOOKS) != MH_STATUS::MH_OK);
}

void CModuleEntry::Unload()
{
	XASSERT(MH_Uninitialize() != MH_STATUS::MH_OK);
	Hooks::WndProc::UnInitialize();

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

bool CModuleEntry::ShouldUnload()
{
	return GetAsyncKeyState(VK_F11);
}

//"Game-code" CBaseHandle implementation.
IHandleEntity* CBaseHandle::Get() const
{
	return reinterpret_cast<IHandleEntity*>(g_pEntityList->GetClientEntityFromHandle(*this));
}