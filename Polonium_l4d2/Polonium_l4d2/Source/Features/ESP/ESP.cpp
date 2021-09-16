#include "ESP.h"

#include "../Vars.h"

void CESP::Render()
{
	if (Vars::ESP::Enabled)
	{
		int x = 0, y = 0, w = 0, h = 0;

		if (Vars::ESP::Players)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::PLAYER_SURVIVOR))
			{
				const auto& pPlayer = ToTerrorPlayer(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pPlayer)
				{
					const int nDrawX = x + (w / 2);
					int nDrawY       = y + (h / 2);

					const int nHealth    = pPlayer->m_iHealth();
					const int nMaxHealth = pPlayer->m_iMaxHealth();

					player_info_t pi;
					if (g_pEngine->GetPlayerInfo(pPlayer->entindex(), &pi))
					{
						g_Draw.String(EFont::ESP_NAME, nDrawX, nDrawY, COLOR_BLUE, TXT_CENTERXY, g_Util.Utf8ToWide(pi.name).c_str());
						nDrawY += g_Draw.GetFontHeight(EFont::ESP_NAME);
					}

					g_Draw.String(EFont::ESP, nDrawX, nDrawY, g_Util.GetHealthColor(nHealth, nMaxHealth), TXT_CENTERXY, _(L"%i/%ihp"), nHealth, nMaxHealth);
					nDrawY += g_Draw.GetFontHeight(EFont::ESP);

					if (pPlayer->m_isHangingFromLedge() || pPlayer->m_isHangingFromTongue())
					{
						g_Draw.String(EFont::ESP, nDrawX, nDrawY, COLOR_YELLOW, TXT_CENTERXY, _(L"HANGING"));
						nDrawY += g_Draw.GetFontHeight(EFont::ESP);
					}

					if (pPlayer->m_isIncapacitated())
					{
						g_Draw.String(EFont::ESP, nDrawX, nDrawY, COLOR_YELLOW, TXT_CENTERXY, _(L"INCAPACITATED"));
						nDrawY += g_Draw.GetFontHeight(EFont::ESP);
					}

					if (const auto& pWeapon = ToTerrorWeapon(pPlayer->m_hActiveWeapon().Get()))
					{
						if (const auto& pInfo = pWeapon->GetWpnData())
						{
							g_Draw.String(EFont::ESP_WEAPON, nDrawX, nDrawY, COLOR_GREY, TXT_CENTERXY, pInfo->m_szPrintName);
							nDrawY += g_Draw.GetFontHeight(EFont::ESP_WEAPON);
						}
					}
				}
			}

			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::PLAYER_INFECTED))
			{
				const auto& pPlayer = ToTerrorPlayer(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pPlayer)
				{
					const int nDrawX = x + (w / 2);
					int nDrawY       = y + (h / 2);

					const int nHealth    = pPlayer->m_iHealth();
					const int nMaxHealth = pPlayer->m_iMaxHealth();

					player_info_t pi;
					if (g_pEngine->GetPlayerInfo(pPlayer->entindex(), &pi))
					{
						g_Draw.String(EFont::ESP_NAME, nDrawX, nDrawY, COLOR_BLUE, TXT_CENTERXY, g_Util.Utf8ToWide(pi.name).c_str());
						nDrawY += g_Draw.GetFontHeight(EFont::ESP_NAME);
					}

					g_Draw.String(EFont::ESP, nDrawX, nDrawY, g_Util.GetHealthColor(nHealth, nMaxHealth), TXT_CENTERXY, _(L"%i/%ihp"), nHealth, nMaxHealth);
					nDrawY += g_Draw.GetFontHeight(EFont::ESP);

					if (pPlayer->m_isGhost())
					{
						g_Draw.String(EFont::ESP, nDrawX, nDrawY, COLOR_YELLOW, TXT_CENTERXY, _(L"GHOST"));
						nDrawY += g_Draw.GetFontHeight(EFont::ESP);
					}
				}
			}
		}

		if (Vars::ESP::Infected)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::INFECTED))
			{
				const auto& pInfected = ToInfected(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pInfected)
				{
					const int nDrawX = x + (w / 2);
					int nDrawY       = y + (h / 2);

					g_Draw.String(EFont::ESP_NAME, nDrawX, nDrawY, COLOR_RED, TXT_CENTERXY, _(L"Infected"));
					nDrawY += g_Draw.GetFontHeight(EFont::ESP_NAME);

					if (pInfected->m_mobRush())
					{
						g_Draw.String(EFont::ESP, nDrawX, nDrawY, COLOR_YELLOW, TXT_CENTERXY, _(L"RUSHING"));
						nDrawY += g_Draw.GetFontHeight(EFont::ESP);
					}

					if (pInfected->m_bIsBurning())
					{
						g_Draw.String(EFont::ESP, nDrawX, nDrawY, COLOR_YELLOW, TXT_CENTERXY, _(L"BURNING"));
						nDrawY += g_Draw.GetFontHeight(EFont::ESP);
					}
				}
			}
		}

		if (Vars::ESP::Specials)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::SPECIAL_INFECTED))
			{
				const auto& pSpecial = ToTerrorPlayer(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pSpecial)
				{
					const int nDrawX = x + (w / 2);
					int nDrawY       = y + (w / 2);

					const int nHealth    = pSpecial->m_iHealth();
					const int nMaxHealth = pSpecial->m_iMaxHealth();

					g_Draw.String(EFont::ESP_NAME, nDrawX, nDrawY, COLOR_RED, TXT_CENTERXY, pEntity->GetClientClass()->GetName());
					nDrawY += g_Draw.GetFontHeight(EFont::ESP_NAME);

					g_Draw.String(EFont::ESP, nDrawX, nDrawY, g_Util.GetHealthColor(nHealth, nMaxHealth), TXT_CENTERXY, _(L"%i/%ihp"), nHealth, nMaxHealth);
					nDrawY += g_Draw.GetFontHeight(EFont::ESP);
				}
			}
		}

		if (Vars::ESP::Witches)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::WITCH))
			{
				const auto& pWitch = ToWitch(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pWitch)
				{
					const int nDrawX = x + (w / 2);
					int nDrawY       = y + (h / 2);

					g_Draw.String(EFont::ESP_NAME, nDrawX, nDrawY, COLOR_RED, TXT_CENTERXY, _(L"Witch"));
					nDrawY += g_Draw.GetFontHeight(EFont::ESP_NAME);

					if (pWitch->m_rage() == 1.0f)
					{
						g_Draw.String(EFont::ESP, nDrawX, nDrawY, COLOR_YELLOW, TXT_CENTERXY, _(L"HOES MAD"));
						nDrawY += g_Draw.GetFontHeight(EFont::ESP);
					}
				}
			}
		}

		if (Vars::ESP::Tanks)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::TANK))
			{
				const auto& pTank = ToTank(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pTank)
				{
					const int nDrawX = x + (w / 2);
					int nDrawY       = y + (h / 2);

					const int nHealth    = pTank->m_iHealth();
					const int nMaxHealth = pTank->m_iMaxHealth();

					g_Draw.String(EFont::ESP_NAME, nDrawX, nDrawY, COLOR_RED, TXT_CENTERXY, _(L"Tank"));
					nDrawY += g_Draw.GetFontHeight(EFont::ESP_NAME);

					g_Draw.String(EFont::ESP, nDrawX, nDrawY, g_Util.GetHealthColor(nHealth, nMaxHealth), TXT_CENTERXY, _(L"%i/%ihp"), nHealth, nMaxHealth);
					nDrawY += g_Draw.GetFontHeight(EFont::ESP);
				}
			}
		}

		if (Vars::ESP::Weapons)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::WEAPON_SPAWN))
			{
				const auto& pSpawn = ToWeaponSpawn(pEntity);

				if (GetStaticBounds(pEntity, x, y, w, h) && pSpawn)
					g_Draw.String(EFont::ESP_WEAPON, x + (w / 2), y + (h / 2), COLOR_GREY, TXT_CENTERXY, g_Util.GetWeaponAlias(pSpawn->m_weaponID()));
			}
		}

		if (Vars::ESP::Ammo)
		{
			for (const auto& pEntity : g_EntityCache.GetGroup(EGroup::AMMO_SPAWN))
			{
				if (GetStaticBounds(pEntity, x, y, w, h))
					g_Draw.String(EFont::ESP, x + (w / 2), y + (h / 2), COLOR_GREY, TXT_CENTERXY, _(L"ammo pile"));
			}
		}
	}
}

bool CESP::GetStaticBounds(IClientEntity* pEntity, int& x, int& y, int& w, int& h)
{
	const Vector vOrigin = pEntity->GetAbsOrigin();

	Vector vMins, vMaxs;
	pEntity->GetRenderBoundsWorldspace(vMins, vMaxs);

	Vector vBot, vTop;
	if (g_Util.W2S({ vOrigin.x, vOrigin.y, vMins.z }, vBot) && g_Util.W2S({ vOrigin.x, vOrigin.y, vMaxs.z }, vTop))
	{
		h = static_cast<int>(vBot.y - vTop.y);
		w = static_cast<int>(static_cast<float>(h) / 2.0f);
		x = static_cast<int>(vBot.x - (static_cast<float>(w) / 2.0f));
		y = static_cast<int>(vBot.y - static_cast<float>(h));

		return (x > 0 && y > 0);
	}

	return false;
}