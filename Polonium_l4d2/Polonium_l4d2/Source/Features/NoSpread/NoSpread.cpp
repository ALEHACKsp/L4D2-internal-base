#include "NoSpread.h"

#include "../Vars.h"

//Crashed when casted to __cdecl but didn't when I do the same with asm so asm it is.
inline void UpdateWeaponSpread(void* pWeapon)
{
	static DWORD dwOffset = 0x0;

	if (!dwOffset) {
		dwOffset = g_Pattern.Find(_(L"client.dll"), _(L"53 8B DC 83 EC 08 83 E4 F0 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 83 EC 28 56 57 8B F9 E8 ? ? ? ? 8B CF 89 45 F0 E8 ? ? ? ? 8B F0 85 F6 75 1B"));
		return;
	}

	__asm push pWeapon
	__asm call dwOffset
	__asm add esp, 4
}

void CNoSpread::Run(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* cmd)
{
	static const auto SharedRandomFloat = reinterpret_cast<float(*)(const char*, float, float, int)>(g_Offsets.m_dwSharedRandomFloat);
	static int& nSeed = **reinterpret_cast<int**>(g_Offsets.m_dwRandomSeed);

	if (ShouldRun(pLocal, pWeapon, cmd))
	{
		Vector vAngle = cmd->viewangles;

		if (Vars::Misc::NoSpread)
		{
			const int nOldSeed = nSeed;
			nSeed = (MD5_PseudoRandom(cmd->command_number) & INT_MAX);

			const float flOldSpread = pWeapon->GetBulletSpread();
			UpdateWeaponSpread(pWeapon);
			const float flSpread = pWeapon->GetBulletSpread();

			vAngle.x -= SharedRandomFloat(_("CTerrorGun::FireBullet HorizSpread"), -flSpread, flSpread, 0);
			vAngle.y -= SharedRandomFloat(_("CTerrorGun::FireBullet VertSpread"), -flSpread, flSpread, 0);

			pWeapon->GetBulletSpread() = flOldSpread;
			nSeed = nOldSeed;
		}

		if (Vars::Misc::NoRecoil)
		{
			vAngle -= pLocal->m_vecPunchAngle();
		}

		g_Util.FixMovement(vAngle, cmd);
		cmd->viewangles = vAngle;
	}
}

bool CNoSpread::ShouldRun(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* cmd)
{
	//Not necessary to run when not shooting or when trying to use something
	if ((cmd->buttons & IN_ATTACK) && !(cmd->buttons & IN_USE))
	{
		//Can't attack in these cases
		if (pLocal->m_isHangingFromLedge() || pLocal->m_isHangingFromTongue())
			return false;

		//Just filter out everything that's not a gun + shotguns
		switch (pWeapon->GetClientClass()->GetClassID())
		{
			case EClientClass::CRifle_M60:
			case EClientClass::CSMG_MP5:
			case EClientClass::CSMG_Silenced:
			case EClientClass::CSubMachinegun:
			case EClientClass::CRifle_AK47:
			case EClientClass::CRifle_Desert:
			case EClientClass::CRifle_SG552:
			case EClientClass::CAssaultRifle:
			case EClientClass::CSniper_AWP:
			case EClientClass::CSniper_Military:
			case EClientClass::CSniper_Scout:
			case EClientClass::CSniperRifle:
			case EClientClass::CPistol:
			case EClientClass::CMagnumPistol:
				return true;
			default:
				break;
		}
	}

	return false;
}