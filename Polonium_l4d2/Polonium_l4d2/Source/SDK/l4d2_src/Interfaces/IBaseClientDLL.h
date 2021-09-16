#pragma once

#include "../../../Util/VFunc/VFunc.h"

class ClientClass;
class IBaseClientDLL
{
public:
	inline ClientClass* GetAllClasses() {
		return VFunc_Get<ClientClass* (__thiscall*)(void*)>(this, 7u)(this);
	}
};

inline IBaseClientDLL* g_pClient = nullptr;