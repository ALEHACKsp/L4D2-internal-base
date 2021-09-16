#pragma once

#include "../../client/c_basecombatweapon.h"

class FileWeaponInfo_t
{
private:
	void* __pad00;

public: //l4d2hook
	bool m_bParsedScript;
	bool m_bLoadedHudElements;
	char m_szClassName[80];
	char m_szPrintName[80];
	char m_szViewModel[80];
	char m_szWorldModel[80];
	char m_szAnimationPrefix[16];

private:
	char __pad01[2];

public:
	int m_iSlot;
	int m_iPosition;
	int m_iMaxClip1;
	int m_iMaxClip2;
	int m_iDefaultClip1;
	int m_iDefaultClip12;
	int m_iWeight;
	int m_iRumble;
	bool m_bAutoSwitchTo;
	bool m_bAutoSwitchFrom;
	int m_fFlags;

public: //Nanocat
	inline int m_iPenetration() {
		return *reinterpret_cast<int*>(reinterpret_cast<unsigned int>(this) + 0x09C8);
	}

	inline int m_iDamage() {
		return *reinterpret_cast<int*>(reinterpret_cast<unsigned int>(this) + 0x09CC);
	}

	inline float m_flRange() {
		return *reinterpret_cast<float*>(reinterpret_cast<unsigned int>(this) + 0x09D0);
	}

	inline float m_flRangeModifier() {
		return *reinterpret_cast<float*>(reinterpret_cast<unsigned int>(this) + 0x09D4);
	}
};

class C_WeaponCSBase : public C_BaseCombatWeapon
{
public:
	M_NETVAR(m_iExtraPrimaryAmmo, int, "CWeaponCSBase", "m_iExtraPrimaryAmmo");

public:
	FileWeaponInfo_t* GetWpnData();
};