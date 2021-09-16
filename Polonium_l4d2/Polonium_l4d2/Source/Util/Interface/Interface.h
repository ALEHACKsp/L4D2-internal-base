#pragma once

#include <Windows.h>
#include <thread>

typedef void* (*CreateInterfaceFn)(const char*, int*);

class CInterface
{
public:
	void* Get(const wchar_t* const szModule, const char* const szObject);
};

inline CInterface g_Interface;