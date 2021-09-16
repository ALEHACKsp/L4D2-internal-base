#include "weapon_csbase.h"

#include "../../../../../Util/Offsets/Offsets.h"

FileWeaponInfo_t* C_WeaponCSBase::GetWpnData()
{
	static const auto GetWeaponDataFn = reinterpret_cast<FileWeaponInfo_t* (__thiscall*)(void*)>(g_Offsets.m_dwGetWeaponData);
	return GetWeaponDataFn(this);
}