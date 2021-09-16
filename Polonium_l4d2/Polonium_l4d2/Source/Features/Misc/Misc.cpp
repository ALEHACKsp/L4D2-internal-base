#include "Misc.h"

#include "../Vars.h"

void CMisc::Run(C_TerrorPlayer* pLocal, CUserCmd* cmd)
{
	if (Vars::Misc::Bunnyhop && (cmd->buttons & IN_JUMP) && !(pLocal->m_fFlags() & FL_ONGROUND))
		cmd->buttons &= ~IN_JUMP;

	if (Vars::Misc::AutoJockeyTeleport && (g_Global.m_nLocalTeam == 3) && pLocal->m_jockeyVictim().Get() && !pLocal->GetAbsOrigin().IsZero(1.0f))
		cmd->forwardmove = NAN;
}