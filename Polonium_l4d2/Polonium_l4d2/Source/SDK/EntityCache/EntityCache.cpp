#include "EntityCache.h"

void CEntityCache::Update()
{
	g_Global.m_bInGame          = g_pEngine->IsInGame();
	g_Global.m_bIsGameUIVisible = g_pEngineVGui->IsGameUIVisible();

	if (g_Global.m_bInGame)
	{
		if (m_pLocal = ToTerrorPlayer(g_pEntityList->GetClientEntity(g_Global.m_nLocalIndex)))
		{
			m_pWeapon = ToTerrorWeapon(m_pLocal->m_hActiveWeapon().Get());

			g_Global.m_nLocalTeam   = m_pLocal->m_iTeamNum();
			g_Global.m_nMaxClients  = g_pEngine->GetMaxClients();
			g_Global.m_nMaxEntities = g_pEntityList->GetMaxEntities();

			int n;
			for (n = 1; n <= g_Global.m_nMaxEntities; n++)
			{
				if (n == g_Global.m_nLocalIndex)
					continue;

				if (const auto& pEntity = g_pEntityList->GetClientEntity(n))
				{
					if (!pEntity->IsDormant())
					{
						if (const auto pCC = pEntity->GetClientClass())
						{
							switch (pCC->GetClassID())
							{
								case EClientClass::CTerrorPlayer:
								case EClientClass::SurvivorBot:
								{
									if (const auto& pPlayer = ToTerrorPlayer(pEntity))
									{
										if (pPlayer->IsAlive())
										{
											const int nTeam = pPlayer->m_iTeamNum();

											if (nTeam == 2)
												m_mapEntities[EGroup::PLAYER_SURVIVOR].push_back(pEntity);
											else if (nTeam == 3)
												m_mapEntities[EGroup::PLAYER_INFECTED].push_back(pEntity);

											m_mapEntities[EGroup::PLAYER_ALL].push_back(pEntity);
										}
									}

									break;
								}
								case EClientClass::Tank:
								{
									if (const auto& pTank = ToTank(pEntity))
									{
										if (pTank->IsAlive() && (pTank->m_iHealth() <= pTank->m_iMaxHealth()))
											m_mapEntities[EGroup::TANK].push_back(pEntity);
									}

									break;
								}
								case EClientClass::Witch:
								{
									if (const auto& pWitch = ToWitch(pEntity))
									{
										if (!(pWitch->m_usSolidFlags() & SolidFlags_t::FSOLID_NOT_SOLID) && pWitch->m_nSequence() <= 70)
										{
											if (pWitch->m_rage() == 1.0f)
												m_mapEntities[EGroup::WITCH_RAGE].push_back(pEntity);

											m_mapEntities[EGroup::WITCH].push_back(pEntity);
										}
									}

									break;
								}
								case EClientClass::Infected:
								{
									if (const auto& pInfected = ToInfected(pEntity))
									{
										if (!(pInfected->m_usSolidFlags() & SolidFlags_t::FSOLID_NOT_SOLID) && pInfected->m_nSequence() <= 305)
											m_mapEntities[EGroup::INFECTED].push_back(pEntity);
									}

									break;
								}
								case EClientClass::Boomer:
								case EClientClass::Jockey:
								case EClientClass::Smoker:
								case EClientClass::Hunter:
								case EClientClass::Spitter:
								case EClientClass::Charger:
								{
									if (const auto& pPlayer = ToTerrorPlayer(pEntity))
									{
										if (pPlayer->IsAlive())
											m_mapEntities[EGroup::SPECIAL_INFECTED].push_back(pEntity);
									}

									break;
								}
								case EClientClass::CWeaponSpawn:
								{
									m_mapEntities[EGroup::WEAPON_SPAWN].push_back(pEntity);
									break;
								}
								case EClientClass::CWeaponAmmoSpawn:
								{
									m_mapEntities[EGroup::AMMO_SPAWN].push_back(pEntity);
									break;
								}
								default:
									break;
							}
						}
					}
				}
			}
		}
	}
}

void CEntityCache::Clear()
{
	m_pLocal = nullptr;
	m_pWeapon = nullptr;

	for (auto& Group : m_mapEntities)
		Group.second.clear();
}

C_TerrorPlayer* CEntityCache::GetLocal() const
{
	return m_pLocal;
}

C_TerrorWeapon* CEntityCache::GetWeapon() const
{
	return m_pWeapon;
}

const std::vector<IClientEntity*>& CEntityCache::GetGroup(EGroup Group)
{
	return m_mapEntities[Group];
}