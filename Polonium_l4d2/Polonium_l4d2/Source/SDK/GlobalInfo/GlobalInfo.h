#pragma once

class CGlobalInfo
{
public:
	int m_nLocalIndex = -1;
	int m_nLocalTeam = 0;
	int m_nMaxClients = 0;
	int m_nMaxEntities = 0;

	bool m_bInGame = false;
	bool m_bIsGameUIVisible = false;
};

inline CGlobalInfo g_Global;