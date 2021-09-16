#pragma once

#include "../Interface/Interface.h"

class CPattern
{
public:
	DWORD Find(const wchar_t* const szModule, const wchar_t* const szPattern);

private:
	DWORD FindPattern(const DWORD dwAddress, const DWORD dwLen, const wchar_t* const szPattern);
};

inline CPattern g_Pattern;