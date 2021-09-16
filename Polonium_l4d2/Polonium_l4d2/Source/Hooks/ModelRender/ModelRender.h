#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace ModelRender
	{
		inline Hook::CTable Table;

		namespace ForcedMaterialOverride
		{
			using FN = void(__fastcall*)(void*, void*, IMaterial*, OverrideType_t);
			constexpr unsigned int Index = 1u;

			void __fastcall Detour(void* ecx, void* edx, IMaterial* newMaterial, OverrideType_t nOverrideType);
		}

		namespace DrawModelExecute
		{
			using FN = void(__fastcall*)(void*, void*, const DrawModelState_t&, const ModelRenderInfo_t&, matrix3x4_t*);
			constexpr unsigned int Index = 19u;

			void __fastcall Detour(void* ecx, void* edx, const DrawModelState_t& pState, const ModelRenderInfo_t& pInfo, matrix3x4_t* pBoneToWorld);
		}

		void Initialize();
	}
}