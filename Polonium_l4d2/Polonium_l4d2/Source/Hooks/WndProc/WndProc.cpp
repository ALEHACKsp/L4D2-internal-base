#include "WndProc.h"

using namespace Hooks;

LONG WINAPI WndProc::Detour(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return CallWindowProcW(WndProc, hWnd, uMsg, wParam, lParam);
}

void WndProc::Initialize()
{
	while (!hwWindow) 
	{
		hwWindow = FindWindowW(_(L"Valve001"), 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	WndProc = reinterpret_cast<WNDPROC>(SetWindowLongW(hwWindow, GWL_WNDPROC, reinterpret_cast<LONG_PTR>(Detour)));
}

void WndProc::UnInitialize()
{
	SetWindowLongW(hwWindow, GWL_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc));
}