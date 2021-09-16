#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace RenderView
	{
		namespace SceneEnd
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*);
			constexpr unsigned int Index = 9u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		void Initialize();
	}
}