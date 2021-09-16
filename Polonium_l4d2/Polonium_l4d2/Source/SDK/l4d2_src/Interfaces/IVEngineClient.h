#pragma once

#include "../../../Util/VFunc/VFunc.h"
#include "../../../Util/Math/Vector/Vector.h"
#include "../public/const.h"

struct player_info_t
{
private:
	char __pad00[0x8];

public:
	char name[MAX_PLAYER_NAME_LENGTH];
	int  userid;

private:
	char __pad01[0x150];
};

class INetChannel
{
public:
	inline float GetLatency(const int nFlow) {
		return VFunc_Get<float(__thiscall*)(void*, int)>(this, 9u)(this, nFlow);
	}
};

class IVEngineClient
{
public:
	inline void GetScreenSize(int& w, int& h) {
		VFunc_Get<void(__thiscall*)(void*, int&, int&)>(this, 5u)(this, w, h);
	}

	inline bool GetPlayerInfo(const int nIndex, player_info_t* pi) {
		return VFunc_Get<bool(__thiscall*)(void*, int, player_info_t*)>(this, 8u)(this, nIndex, pi);
	}

	inline int GetLocalPlayer() {
		return VFunc_Get<int(__thiscall*)(void*)>(this, 12u)(this);
	}

	inline float Time() {
		return VFunc_Get<float(__thiscall*)(void*)>(this, 14u)(this);
	}

	inline void GetViewAngles(Vector& va) {
		VFunc_Get<void(__thiscall*)(void*, Vector&)>(this, 19u)(this, va);
	}

	inline const Vector GetViewAngles() {
		Vector va; GetViewAngles(va); return va;
	}

	inline void SetViewAngles(Vector& va) {
		VFunc_Get<void(__thiscall*)(void*, Vector&)>(this, 20u)(this, va);
	}

	inline int GetMaxClients() {
		return VFunc_Get<int(__thiscall*)(void*)>(this, 21u)(this);
	}

	inline bool IsInGame() {
		return VFunc_Get<bool(__thiscall*)(void*)>(this, 26u)(this);
	}

	inline INetChannel* GetNetChannelInfo() {
		return VFunc_Get<INetChannel* (__thiscall*)(void*)>(this, 74u)(this);
	}

	inline void ClientCmd_Unrestricted(const char* const szCommand) {
		VFunc_Get<void(__thiscall*)(void*, const char*)>(this, 108u)(this, szCommand);
	}
};

inline IVEngineClient* g_pEngine = nullptr;