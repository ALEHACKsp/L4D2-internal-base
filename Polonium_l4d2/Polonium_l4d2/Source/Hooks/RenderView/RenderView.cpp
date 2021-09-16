#include "RenderView.h"

using namespace Hooks;

void __fastcall RenderView::SceneEnd::Detour(void* ecx, void* edx)
{
	Func.Original<FN>()(ecx, edx);
}

void RenderView::Initialize()
{
	XASSERT(SceneEnd::Func.Initialize(VFunc_Get<SceneEnd::FN>(g_pRenderView, SceneEnd::Index), &SceneEnd::Detour) == FAILED_TO_INITIALIZE);
}