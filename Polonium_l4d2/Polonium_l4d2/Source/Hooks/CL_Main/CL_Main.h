#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace CL_Main
	{
		namespace CL_Move
		{
			inline Hook::CFunction Func;
			using FN = void(__cdecl*)(float, bool);

			void __cdecl Detour(float accumulated_extra_samples, bool bFinalTick);
		}

		namespace CL_SendMove
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*);

			void __fastcall Detour(void* ecx, void* edx);
		}

		void Initialize();
	}
}