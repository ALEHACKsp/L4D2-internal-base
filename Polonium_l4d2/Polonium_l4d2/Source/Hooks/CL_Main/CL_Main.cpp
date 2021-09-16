#include "CL_Main.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __cdecl CL_Main::CL_Move::Detour(float accumulated_extra_samples, bool bFinalTick)
{
	//Original
	Func.Original<FN>()(accumulated_extra_samples, bFinalTick);

	//Additional
	if (GetAsyncKeyState(VK_XBUTTON2))
	{
		for (int n = 0; n <= 5; n++)
			Func.Original<FN>()(accumulated_extra_samples, bFinalTick);
	}
}

void __fastcall CL_Main::CL_SendMove::Detour(void* ecx, void* edx)
{
	Func.Original<FN>()(ecx, edx);
}

void CL_Main::Initialize()
{
	//CL_Move
	{
		static const auto pCLMoveFn = reinterpret_cast<CL_Move::FN>(g_Offsets.m_dwCLMove);
		XASSERT(pCLMoveFn == nullptr);

		if (pCLMoveFn)
			XASSERT(CL_Move::Func.Initialize(pCLMoveFn, &CL_Move::Detour) == FAILED_TO_INITIALIZE);
	}

	//CL_SendMove
	{
		static const auto pCLSendMoveFn = reinterpret_cast<CL_SendMove::FN>(g_Offsets.m_dwCLSendMove);
		XASSERT(pCLSendMoveFn == nullptr);

		if (pCLSendMoveFn)
			XASSERT(CL_SendMove::Func.Initialize(pCLSendMoveFn, &CL_SendMove::Detour) == FAILED_TO_INITIALIZE);
	}
}