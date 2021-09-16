#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace WndProc
	{
		inline WNDPROC WndProc = nullptr;
		inline HWND    hwWindow = nullptr;

		LONG WINAPI Detour(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		void Initialize();
		void UnInitialize();
	}
}