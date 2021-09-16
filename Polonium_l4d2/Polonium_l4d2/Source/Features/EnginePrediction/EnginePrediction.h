#pragma once

#include "../../SDK/SDK.h"

class CEnginePrediction
{
public:
	void Start(C_BasePlayer* pLocal, CUserCmd* cmd);
	void Finish(C_BasePlayer* pLocal, CUserCmd* cmd);

private:
	int GetTickBase(const int nCurrentTickBase, CUserCmd* cmd);

private:
	float m_flOldCurTime   = 0.0f;
	float m_flOldFrameTime = 0.0f;

	int m_nOldTickCount = 0;
	int m_nOldTickBase  = 0;
	int m_nOldFlags     = 0;
};

inline CEnginePrediction g_EnginePrediction;