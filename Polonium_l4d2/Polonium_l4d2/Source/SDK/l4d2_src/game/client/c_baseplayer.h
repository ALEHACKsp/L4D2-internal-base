#pragma once

#include "c_basecombatcharacter.h"

class C_BasePlayer : public C_BaseCombatCharacter
{
public:
	M_NETVAR(m_Local, void*, "CBasePlayer", "m_Local");
	M_NETVAR(m_chAreaBits, void*, "CBasePlayer", "m_chAreaBits");
	M_NETVAR(m_chAreaPortalBits, void*, "CBasePlayer", "m_chAreaPortalBits");
	M_NETVAR(m_iHideHUD, int, "CBasePlayer", "m_iHideHUD");
	M_NETVAR(m_flFOVRate, float, "CBasePlayer", "m_flFOVRate");
	M_NETVAR(m_bDucked, bool, "CBasePlayer", "m_bDucked");
	M_NETVAR(m_bDucking, bool, "CBasePlayer", "m_bDucking");
	M_NETVAR(m_bInDuckJump, bool, "CBasePlayer", "m_bInDuckJump");
	M_NETVAR(m_nDuckTimeMsecs, int, "CBasePlayer", "m_nDuckTimeMsecs");
	M_NETVAR(m_nDuckJumpTimeMsecs, int, "CBasePlayer", "m_nDuckJumpTimeMsecs");
	M_NETVAR(m_nJumpTimeMsecs, int, "CBasePlayer", "m_nJumpTimeMsecs");
	M_NETVAR(m_flFallVelocity, float, "CBasePlayer", "m_flFallVelocity");
	M_NETVAR(m_vecPunchAngle, Vector, "CBasePlayer", "m_vecPunchAngle");
	M_NETVAR(m_vecPunchAngleVel, Vector, "CBasePlayer", "m_vecPunchAngleVel");
	M_NETVAR(m_bDrawViewmodel, bool, "CBasePlayer", "m_bDrawViewmodel");
	M_NETVAR(m_bWearingSuit, bool, "CBasePlayer", "m_bWearingSuit");
	M_NETVAR(m_bPoisoned, bool, "CBasePlayer", "m_bPoisoned");
	M_NETVAR(m_flStepSize, float, "CBasePlayer", "m_flStepSize");
	M_NETVAR(m_bAllowAutoMovement, bool, "CBasePlayer", "m_bAllowAutoMovement");
	M_NETVAR(m_bAutoAimTarget, bool, "CBasePlayer", "m_bAutoAimTarget");
	M_NETVAR(m_skybox3d_scale, int, "CBasePlayer", "m_skybox3d.scale");
	M_NETVAR(m_skybox3d_origin, Vector, "CBasePlayer", "m_skybox3d.origin");
	M_NETVAR(m_skybox3d_area, int, "CBasePlayer", "m_skybox3d.area");
	M_NETVAR(m_skybox3d_bClip3DSkyBoxNearToWorldFar, int, "CBasePlayer", "m_skybox3d.bClip3DSkyBoxNearToWorldFar");
	M_NETVAR(m_skybox3d_flClip3DSkyBoxNearToWorldFarOffset, float, "CBasePlayer", "m_skybox3d.flClip3DSkyBoxNearToWorldFarOffset");
	M_NETVAR(m_skybox3d_fog_enable, int, "CBasePlayer", "m_skybox3d.fog.enable");
	M_NETVAR(m_skybox3d_fog_blend, int, "CBasePlayer", "m_skybox3d.fog.blend");
	M_NETVAR(m_skybox3d_fog_dirPrimary, Vector, "CBasePlayer", "m_skybox3d.fog.dirPrimary");
	M_NETVAR(m_skybox3d_fog_colorPrimary, int, "CBasePlayer", "m_skybox3d.fog.colorPrimary");
	M_NETVAR(m_skybox3d_fog_colorSecondary, int, "CBasePlayer", "m_skybox3d.fog.colorSecondary");
	M_NETVAR(m_skybox3d_fog_start, float, "CBasePlayer", "m_skybox3d.fog.start");
	M_NETVAR(m_skybox3d_fog_end, float, "CBasePlayer", "m_skybox3d.fog.end");
	M_NETVAR(m_skybox3d_fog_maxdensity, float, "CBasePlayer", "m_skybox3d.fog.maxdensity");
	M_NETVAR(m_skybox3d_fog_HDRColorScale, float, "CBasePlayer", "m_skybox3d.fog.HDRColorScale");
	M_NETVAR(m_audio_localSound0, Vector, "CBasePlayer", "m_audio.localSound[0]");
	M_NETVAR(m_audio_localSound3, Vector, "CBasePlayer", "m_audio.localSound[3]");
	M_NETVAR(m_audio_localSound4, Vector, "CBasePlayer", "m_audio.localSound[4]");
	M_NETVAR(m_audio_localSound5, Vector, "CBasePlayer", "m_audio.localSound[5]");
	M_NETVAR(m_audio_localSound6, Vector, "CBasePlayer", "m_audio.localSound[6]");
	M_NETVAR(m_audio_localSound7, Vector, "CBasePlayer", "m_audio.localSound[7]");
	M_NETVAR(m_audio_soundscapeIndex, int, "CBasePlayer", "m_audio.soundscapeIndex");
	M_NETVAR(m_audio_localBits, int, "CBasePlayer", "m_audio.localBits");
	M_NETVAR(m_audio_entIndex, int, "CBasePlayer", "m_audio.entIndex");
	M_NETVAR(m_flFriction, float, "CBasePlayer", "m_flFriction");
	M_NETVAR(m_iAmmo, void*, "CBasePlayer", "m_iAmmo");
	M_NETVAR(m_fOnTarget, int, "CBasePlayer", "m_fOnTarget");
	M_NETVAR(m_nTickBase, int, "CBasePlayer", "m_nTickBase");
	M_NETVAR(m_nNextThinkTick, int, "CBasePlayer", "m_nNextThinkTick");
	M_NETVAR(m_vecVelocity, Vector, "CBasePlayer", "m_vecVelocity[0]");
	M_NETVAR(m_vecBaseVelocity, Vector, "CBasePlayer", "m_vecBaseVelocity");
	M_NETVAR(m_hConstraintEntity, EHANDLE, "CBasePlayer", "m_hConstraintEntity");
	M_NETVAR(m_vecConstraintCenter, Vector, "CBasePlayer", "m_vecConstraintCenter");
	M_NETVAR(m_flConstraintRadius, float, "CBasePlayer", "m_flConstraintRadius");
	M_NETVAR(m_flConstraintWidth, float, "CBasePlayer", "m_flConstraintWidth");
	M_NETVAR(m_flConstraintSpeedFactor, float, "CBasePlayer", "m_flConstraintSpeedFactor");
	M_NETVAR(m_bConstraintPastRadius, bool, "CBasePlayer", "m_bConstraintPastRadius");
	M_NETVAR(m_flDeathTime, float, "CBasePlayer", "m_flDeathTime");
	M_NETVAR(m_flLaggedMovementValue, float, "CBasePlayer", "m_flLaggedMovementValue");
	M_NETVAR(m_hTonemapController, EHANDLE, "CBasePlayer", "m_hTonemapController");
	M_NETVAR(pl, void*, "CBasePlayer", "pl");
	M_NETVAR(deadflag, unsigned char, "CBasePlayer", "deadflag");
	M_NETVAR(m_vecViewOffset, Vector, "CBasePlayer", "m_vecViewOffset[0]");
	M_NETVAR(m_iFOV, int, "CBasePlayer", "m_iFOV");
	M_NETVAR(m_iFOVStart, int, "CBasePlayer", "m_iFOVStart");
	M_NETVAR(m_flFOVTime, float, "CBasePlayer", "m_flFOVTime");
	M_NETVAR(m_iDefaultFOV, int, "CBasePlayer", "m_iDefaultFOV");
	M_NETVAR(m_hZoomOwner, EHANDLE, "CBasePlayer", "m_hZoomOwner");
	M_NETVAR(m_hVehicle, EHANDLE, "CBasePlayer", "m_hVehicle");
	M_NETVAR(m_hUseEntity, EHANDLE, "CBasePlayer", "m_hUseEntity");
	M_NETVAR(m_hViewEntity, EHANDLE, "CBasePlayer", "m_hViewEntity");
	M_NETVAR(m_hGroundEntity, EHANDLE, "CBasePlayer", "m_hGroundEntity");
	M_NETVAR(m_hLastWeapon, EHANDLE, "CBasePlayer", "m_hLastWeapon");
	M_NETVAR(m_hElevator, EHANDLE, "CBasePlayer", "m_hElevator");
	M_NETVAR(m_iHealth, int, "CBasePlayer", "m_iHealth");
	M_NETVAR(m_lifeState, unsigned char, "CBasePlayer", "m_lifeState");
	M_NETVAR(m_iBonusProgress, int, "CBasePlayer", "m_iBonusProgress");
	M_NETVAR(m_iBonusChallenge, int, "CBasePlayer", "m_iBonusChallenge");
	M_NETVAR(m_flMaxspeed, float, "CBasePlayer", "m_flMaxspeed");
	M_NETVAR(m_fFlags, int, "CBasePlayer", "m_fFlags");
	M_NETVAR(m_iObserverMode, int, "CBasePlayer", "m_iObserverMode");
	M_NETVAR(m_hObserverTarget, EHANDLE, "CBasePlayer", "m_hObserverTarget");
	M_NETVAR(m_hViewModel, EHANDLE, "CBasePlayer", "m_hViewModel[0]");
	M_NETVAR(m_szLastPlaceName, const char*, "CBasePlayer", "m_szLastPlaceName");
	M_NETVAR(m_vecLadderNormal, Vector, "CBasePlayer", "m_vecLadderNormal");
	M_NETVAR(m_ladderSurfaceProps, int, "CBasePlayer", "m_ladderSurfaceProps");
	M_NETVAR(m_ubEFNoInterpParity, int, "CBasePlayer", "m_ubEFNoInterpParity");
	M_NETVAR(m_nWaterLevel, int, "CBasePlayer", "m_nWaterLevel");
	M_NETVAR(m_hPostProcessCtrl, int, "CBasePlayer", "m_hPostProcessCtrl");
	M_NETVAR(m_hColorCorrectionCtrl, EHANDLE, "CBasePlayer", "m_hColorCorrectionCtrl");
	M_NETVAR(m_PlayerFog_m_hCtrl, int, "CBasePlayer", "m_PlayerFog.m_hCtrl");

public:
	//Not the real deal
	inline Vector Weapon_ShootPosition() {
		return (GetAbsOrigin() + m_vecViewOffset());
	}

	//Simple lifeState == LIFE_ALIVE check
	inline bool IsAlive() {
		return (m_lifeState() == 0);
	}
};

inline C_BasePlayer* ToBasePlayer(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_BasePlayer*>(pClientEntity);
#else
	return static_cast<C_BasePlayer*>(pClientEntity);
#endif
}