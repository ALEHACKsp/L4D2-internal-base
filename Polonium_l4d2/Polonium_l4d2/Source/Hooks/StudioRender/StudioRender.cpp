#include "StudioRender.h"

using namespace Hooks;

void __fastcall StudioRender::DrawModel::Detour(void* ecx, void* edx, void* pResults, DrawModelInfo_t& info, matrix3x4_t* pBoneToWorld, float* pFlexWeights, float* pFlexDelayedWeights, const Vector& modelOrigin, int flags)
{
	Func.Original<FN>()(ecx, edx, pResults, info, pBoneToWorld, pFlexWeights, pFlexDelayedWeights, modelOrigin, flags);
}

void StudioRender::Initialize()
{
	XASSERT(DrawModel::Func.Initialize(VFunc_Get<DrawModel::FN>(g_pStudioRender, DrawModel::Index), &DrawModel::Detour) == FAILED_TO_INITIALIZE);
}