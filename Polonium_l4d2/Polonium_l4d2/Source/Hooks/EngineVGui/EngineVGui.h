#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace EngineVGui
	{
		namespace Paint
		{
			inline Hook::CFunction Func;

			using FN = void(__fastcall*)(void*, void*, int);
			constexpr unsigned int Index = 14u;

			void __fastcall Detour(void* ecx, void* edx, int mode);
		}

		void Initialize();
	}
}