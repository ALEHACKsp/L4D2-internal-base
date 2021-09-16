#include "SDK.h"

void CUtil::FixMovement(const Vector vAngle, CUserCmd* cmd)
{
	Vector vMove = { cmd->forwardmove, cmd->sidemove, cmd->upmove }, vMoveAng;
	g_Math.VectorAngles(vMove, vMoveAng);

	const float flSpeed = sqrt(vMove.x * vMove.x + vMove.y * vMove.y);
	const float flYaw   = DEG2RAD(vAngle.y - cmd->viewangles.y + vMoveAng.y);

	cmd->forwardmove = (cos(flYaw) * flSpeed);
	cmd->sidemove    = (sin(flYaw) * flSpeed);
}

void CUtil::Trace(const Vector& start, const Vector& end, unsigned int mask, ITraceFilter* filter, trace_t* trace)
{
	Ray_t ray = { start, end };
	g_pEngineTrace->TraceRay(ray, mask, filter, trace);
}

bool CUtil::W2S(const Vector vWorld, Vector& vScreen)
{
	return !(g_pDebugOverlay->ScreenPosition(vWorld, vScreen));
}

bool CUtil::IsVisible(const Vector& from, const Vector& to)
{
	trace_t trace = { };
	CTraceFilterWorldAndPropsOnly filter = { };
	Trace(from, to, (MASK_SHOT | CONTENTS_GRATE), &filter, &trace);
	return (trace.fraction > 0.99f);
}

const char* CUtil::GetWeaponAlias(const int nWeaponID)
{
	static const auto GetWeaponAliasFn = reinterpret_cast<char* (*)(int)>(g_Offsets.m_dwWeaponAlias);

	return GetWeaponAliasFn(nWeaponID);
}

std::wstring CUtil::Utf8ToWide(const std::string_view& str)
{
	const size_t len = str.length();
	const int count = MultiByteToWideChar(CP_UTF8, 0, str.data(), len, NULL, 0);
	std::wstring wstr(count, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.data(), len, &wstr[0], count);
	return wstr;
}

Color_t CUtil::GetHealthColor(const int nHealth, const int nMaxHealth)
{
	const int nHP = g_Math.Max<int>(0, g_Math.Min<int>(nHealth, nMaxHealth));
	const int nR  = g_Math.Min<int>((510 * (nMaxHealth - nHP)) / nMaxHealth, 200);
	const int nG  = g_Math.Min<int>((510 * nHP) / nMaxHealth, 200);

	return Color_t(nR, nG, 0, 255);
}