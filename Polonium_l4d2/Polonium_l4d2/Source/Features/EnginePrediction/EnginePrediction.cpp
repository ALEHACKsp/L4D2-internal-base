#include "EnginePrediction.h"

void CEnginePrediction::Start(C_BasePlayer* pLocal, CUserCmd* cmd)
{
	CMoveData MoveData;
	memset(&MoveData, 0, sizeof(CMoveData));

	g_pMoveHelper->SetHost(pLocal);

	m_flOldCurTime   = g_pGlobals->curtime;
	m_flOldFrameTime = g_pGlobals->frametime;
	m_nOldTickCount  = g_pGlobals->tickcount;

	m_nOldTickBase = pLocal->m_nTickBase();
	m_nOldFlags    = pLocal->m_fFlags();

	const int nTickBase = GetTickBase(m_nOldTickBase, cmd);

	g_pGlobals->curtime   = TICKS_TO_TIME(nTickBase);
	g_pGlobals->frametime = TICK_INTERVAL;
	g_pGlobals->tickcount = nTickBase;

	g_pPrediction->SetupMove(pLocal, cmd, g_pMoveHelper, &MoveData);
	g_pGameMovement->ProcessMovement(pLocal, &MoveData);
	g_pPrediction->FinishMove(pLocal, cmd, &MoveData);
}

void CEnginePrediction::Finish(C_BasePlayer* pLocal, CUserCmd* cmd)
{
	pLocal->m_nTickBase() = m_nOldTickBase;
	pLocal->m_fFlags()    = m_nOldFlags;

	g_pMoveHelper->SetHost(nullptr);

	g_pGlobals->curtime   = m_flOldCurTime;
	g_pGlobals->frametime = m_flOldFrameTime;
	g_pGlobals->tickcount = m_nOldTickCount;
}

int CEnginePrediction::GetTickBase(const int nCurrentTickBase, CUserCmd* cmd)
{
	static int nTick = 0;
	static CUserCmd* pLastCmd = nullptr;

	if (cmd)
	{
		if (!pLastCmd || pLastCmd->hasbeenpredicted)
			nTick = nCurrentTickBase;
		else 
			nTick++;

		pLastCmd = cmd;
	}

	return nTick;
}