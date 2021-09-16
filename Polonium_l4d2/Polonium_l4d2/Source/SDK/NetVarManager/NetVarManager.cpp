#pragma once

#include "NetVarManager.h"

#include "../l4d2_src/Interfaces/IBaseClientDLL.h"
#include "../l4d2_src/public/dt_recv.h"
#include "../l4d2_src/public/client_class.h"

#include <Windows.h>

int GetOffset(RecvTable* pTable, const char* const szVar)
{
	int n; const int nMax = pTable->m_nProps;
	for (n = 0; n < nMax; n++)
	{
		const auto Prop = pTable->m_pProps[n];

		if (strcmp(szVar, Prop.m_pVarName) == 0)
			return Prop.GetOffset();

		if (const auto pDataTable = Prop.GetDataTable())
		{
			if (const auto nOffset = GetOffset(pDataTable, szVar))
				return nOffset + Prop.GetOffset();
		}
	}

	return 0;
}

int GetNetVar(const char* const szClass, const char* const szVar)
{
	ClientClass* pCC = g_pClient->GetAllClasses();

	while (pCC)
	{
		if (strcmp(szClass, pCC->GetName()) == 0)
			return GetOffset(pCC->GetRecvTable(), szVar);

		pCC = pCC->GetNext();
	}

	return 0;
}