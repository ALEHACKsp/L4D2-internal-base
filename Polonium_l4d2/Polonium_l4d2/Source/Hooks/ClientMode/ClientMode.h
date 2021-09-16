#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace ClientMode
	{
		inline Hook::CTable Table;

		namespace OverrideView
		{
			using FN = void(__fastcall*)(void*, void*, CViewSetup*);
			constexpr unsigned int Index = 19u;

			void __fastcall Detour(void* ecx, void* edx, CViewSetup* pSetup);
		}

		namespace CreateMove
		{
			using FN = bool(__fastcall*)(void*, void*, float, CUserCmd*);
			constexpr unsigned int Index = 27u;

			bool __fastcall Detour(void* ecx, void* edx, float flInputSampleTime, CUserCmd* cmd);
		}

		void Initialize();
	}
}