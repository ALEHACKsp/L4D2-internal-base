#pragma once

#include "../../public/icliententity.h"

class C_BaseEntity : public IClientEntity
{
public:
	M_NETVAR(m_flSimulationTime, float, "CBaseEntity", "m_flSimulationTime");
	M_NETVAR(m_flAnimTime, float, "CBaseEntity", "m_flAnimTime");
	M_NETVAR(m_flCreateTime, float, "CBaseEntity", "m_flCreateTime");
	M_NETVAR(m_cellbits, int, "CBaseEntity", "m_cellbits");
	M_NETVAR(m_cellX, int, "CBaseEntity", "m_cellX");
	M_NETVAR(m_cellY, int, "CBaseEntity", "m_cellY");
	M_NETVAR(m_cellZ, int, "CBaseEntity", "m_cellZ");
	M_NETVAR(m_vecOrigin, Vector, "CBaseEntity", "m_vecOrigin");
	M_NETVAR(m_angRotation, Vector, "CBaseEntity", "m_angRotation");
	M_NETVAR(m_nModelIndex, int, "CBaseEntity", "m_nModelIndex");
	M_NETVAR(m_fEffects, int, "CBaseEntity", "m_fEffects");
	M_NETVAR(m_nRenderMode, int, "CBaseEntity", "m_nRenderMode");
	M_NETVAR(m_nRenderFX, int, "CBaseEntity", "m_nRenderFX");
	M_NETVAR(m_clrRender, int, "CBaseEntity", "m_clrRender");
	M_NETVAR(m_iTeamNum, int, "CBaseEntity", "m_iTeamNum");
	M_NETVAR(m_CollisionGroup, int, "CBaseEntity", "m_CollisionGroup");
	M_NETVAR(m_flElasticity, float, "CBaseEntity", "m_flElasticity");
	M_NETVAR(m_flShadowCastDistance, float, "CBaseEntity", "m_flShadowCastDistance");
	M_NETVAR(m_hOwnerEntity, EHANDLE, "CBaseEntity", "m_hOwnerEntity");
	M_NETVAR(m_hEffectEntity, EHANDLE, "CBaseEntity", "m_hEffectEntity");
	M_NETVAR(moveparent, int, "CBaseEntity", "moveparent");
	M_NETVAR(m_iParentAttachment, int, "CBaseEntity", "m_iParentAttachment");
	M_NETVAR(m_hScriptUseTarget, EHANDLE, "CBaseEntity", "m_hScriptUseTarget");
	M_NETVAR(m_Collision, ICollideable*, "CBaseEntity", "m_Collision");
	M_NETVAR(m_vecMins, Vector, "CBaseEntity", "m_vecMins");
	M_NETVAR(m_vecMaxs, Vector, "CBaseEntity", "m_vecMaxs");
	M_NETVAR(m_nSolidType, int, "CBaseEntity", "m_nSolidType");
	M_NETVAR(m_usSolidFlags, unsigned short, "CBaseEntity", "m_usSolidFlags");
	M_NETVAR(m_nSurroundType, int, "CBaseEntity", "m_nSurroundType");
	M_NETVAR(m_triggerBloat, int, "CBaseEntity", "m_triggerBloat");
	M_NETVAR(m_vecSpecifiedSurroundingMins, Vector, "CBaseEntity", "m_vecSpecifiedSurroundingMins");
	M_NETVAR(m_vecSpecifiedSurroundingMaxs, Vector, "CBaseEntity", "m_vecSpecifiedSurroundingMaxs");
	M_NETVAR(m_Glow, void*, "CBaseEntity", "m_Glow");
	M_NETVAR(m_iGlowType, int, "CBaseEntity", "m_iGlowType");
	M_NETVAR(m_nGlowRange, int, "CBaseEntity", "m_nGlowRange");
	M_NETVAR(m_nGlowRangeMin, int, "CBaseEntity", "m_nGlowRangeMin");
	M_NETVAR(m_glowColorOverride, int, "CBaseEntity", "m_glowColorOverride");
	M_NETVAR(m_bFlashing, bool, "CBaseEntity", "m_bFlashing");
	M_NETVAR(m_iTextureFrameIndex, int, "CBaseEntity", "m_iTextureFrameIndex");
	M_NETVAR(m_bSimulatedEveryTick, bool, "CBaseEntity", "m_bSimulatedEveryTick");
	M_NETVAR(m_bAnimatedEveryTick, bool, "CBaseEntity", "m_bAnimatedEveryTick");
	M_NETVAR(m_bAlternateSorting, bool, "CBaseEntity", "m_bAlternateSorting");
	M_NETVAR(m_bGlowBackfaceMult, bool, "CBaseEntity", "m_bGlowBackfaceMult");
	M_NETVAR(m_Gender, int, "CBaseEntity", "m_Gender");
	M_NETVAR(m_fadeMinDist, float, "CBaseEntity", "m_fadeMinDist");
	M_NETVAR(m_fadeMaxDist, float, "CBaseEntity", "m_fadeMaxDist");
	M_NETVAR(m_flFadeScale, float, "CBaseEntity", "m_flFadeScale");
	M_NETVAR(m_nMinCPULevel, int, "CBaseEntity", "m_nMinCPULevel");
	M_NETVAR(m_nMaxCPULevel, int, "CBaseEntity", "m_nMaxCPULevel");
	M_NETVAR(m_nMinGPULevel, int, "CBaseEntity", "m_nMinGPULevel");
	M_NETVAR(m_nMaxGPULevel, int, "CBaseEntity", "m_nMaxGPULevel");
};

inline C_BaseEntity* ToBaseEntity(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_BaseEntity*>(pClientEntity);
#else
	return static_cast<C_BaseEntity*>(pClientEntity);
#endif
}