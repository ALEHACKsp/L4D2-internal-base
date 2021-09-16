#include "Interface.h"

#include "../XorString/XorString.h"

void* CInterface::Get(const wchar_t* szModule, const char* const szObject)
{
	if (const auto hMod = GetModuleHandleW(szModule))
	{
		if (const auto CreateFn = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(hMod, _("CreateInterface"))))
			return CreateFn(szObject, nullptr);
	}

	return nullptr;
}