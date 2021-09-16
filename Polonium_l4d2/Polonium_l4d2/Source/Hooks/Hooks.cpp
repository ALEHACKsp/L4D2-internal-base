#include "Hooks.h"

void Hooks::Initialize()
{
	CL_Main::Initialize();
	Client::Initialize();
	ClientMode::Initialize();
	EngineVGui::Initialize();
	ModelRender::Initialize();
	RenderView::Initialize();
	StudioRender::Initialize();
	WndProc::Initialize();
}