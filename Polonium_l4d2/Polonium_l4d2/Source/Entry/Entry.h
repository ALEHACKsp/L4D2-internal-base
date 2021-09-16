#pragma once

#include "../Hooks/Hooks.h"

class CModuleEntry
{
public:
	void Load();
	void Unload();

public:
	bool ShouldUnload();
};

inline CModuleEntry g_ModuleEntry;