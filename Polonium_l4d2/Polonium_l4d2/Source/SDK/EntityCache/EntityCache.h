#pragma once

#include "../Draw/Draw.h"

enum class EGroup
{
	PLAYER_ALL,
	PLAYER_INFECTED,
	PLAYER_SURVIVOR,
	INFECTED,
	SPECIAL_INFECTED,
	TANK,
	WITCH,
	WITCH_RAGE,
	WEAPON_SPAWN,
	AMMO_SPAWN
};

class CEntityCache
{
public:
	void Update();
	void Clear();

public:
	const std::vector<IClientEntity*>& GetGroup(EGroup Group);

	C_TerrorPlayer* GetLocal() const;
	C_TerrorWeapon* GetWeapon() const;

private:
	C_TerrorPlayer* m_pLocal = nullptr;
	C_TerrorWeapon* m_pWeapon = nullptr;

	std::map<EGroup, std::vector<IClientEntity*>> m_mapEntities = { };
};

inline CEntityCache g_EntityCache;
