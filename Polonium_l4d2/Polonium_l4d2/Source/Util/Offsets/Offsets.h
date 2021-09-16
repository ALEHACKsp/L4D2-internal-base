#pragma once

#include "../Pattern/Pattern.h"

#define XASSERT(x) if (x) MessageBoxW(0, _(L#x), _(L"Polonium - FATAL ERROR"), MB_ICONERROR)

class COffsets
{
public:
	void Initialize();

public:
	DWORD m_dwSharedRandomFloat = 0x0;
	DWORD m_dwRandomSeed = 0x0;
	DWORD m_dwClientMode = 0x0;
	DWORD m_dwGlobalVars = 0x0;
	DWORD m_dwUpdateWeaponSpread = 0x0;
	DWORD m_dwMoveHelper = 0x0;
	DWORD m_dwGetWeaponData = 0x0;
	DWORD m_dwWeaponAlias = 0x0;
	DWORD m_dwCLMove = 0x0;
	DWORD m_dwCLSendMove = 0x0;
	DWORD m_dwStartDrawing = 0x0;
	DWORD m_dwFinishDrawing = 0x0;
};

inline COffsets g_Offsets;