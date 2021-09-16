#include "ModelRender.h"

using namespace Hooks;

void __fastcall ModelRender::ForcedMaterialOverride::Detour(void* ecx, void* edx, IMaterial* newMaterial, OverrideType_t nOverrideType)
{
	Table.Original<FN>(Index)(ecx, edx, newMaterial, nOverrideType);
}

void __fastcall ModelRender::DrawModelExecute::Detour(void* ecx, void* edx, const DrawModelState_t& pState, const ModelRenderInfo_t& pInfo, matrix3x4_t* pBoneToWorld)
{
	Table.Original<FN>(Index)(ecx, edx, pState, pInfo, pBoneToWorld);
}

void ModelRender::Initialize()
{
	XASSERT(Table.Initialize(g_pModelRender) == FAILED_TO_INITIALIZE);
	XASSERT(Table.Hook(&ForcedMaterialOverride::Detour, ForcedMaterialOverride::Index) == FAILED_TO_HOOK);
	XASSERT(Table.Hook(&DrawModelExecute::Detour, DrawModelExecute::Index) == FAILED_TO_HOOK);
}