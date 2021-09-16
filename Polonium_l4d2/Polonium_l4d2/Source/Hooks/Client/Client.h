#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace Client
	{
		inline Hook::CTable Table;

		namespace LevelInitPostEntity
		{
			using FN = void(__fastcall*)(void*, void*);
			constexpr unsigned int Index = 5u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		namespace LevelShutdown
		{
			using FN = void(__fastcall*)(void*, void*);
			constexpr unsigned int Index = 6u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		namespace FrameStageNotify
		{
			using FN = void(__fastcall*)(void*, void*, ClientFrameStage_t);
			constexpr unsigned int Index = 34u;

			void __fastcall Detour(void* ecx, void* edx, ClientFrameStage_t curStage);
		}

		void Initialize();
	}
}