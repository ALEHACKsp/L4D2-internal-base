#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace StudioRender
	{
		namespace DrawModel
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*, void*, DrawModelInfo_t&, matrix3x4_t*, float*, float*, const Vector&, int);
			constexpr unsigned int Index = 25u;

			void __fastcall Detour(void* ecx, void* edx, void* pResults, DrawModelInfo_t& info, matrix3x4_t* pBoneToWorld, float* pFlexWeights, float* pFlexDelayedWeights, const Vector& modelOrigin, int flags);
		}

		void Initialize();
	}
}