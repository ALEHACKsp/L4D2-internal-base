#pragma once

#include "../../../../Util/Math/Math.h"
#include "../../Interfaces/IVModelInfo.h"
#include "../../public/globalvars_base.h"

#include "c_baseentity.h"

class C_BaseAnimating : public C_BaseEntity, public IClientModelRenderable
{
public:
	M_NETVAR(m_nSequence, int, "CBaseAnimating", "m_nSequence");
	M_NETVAR(m_nForceBone, int, "CBaseAnimating", "m_nForceBone");
	M_NETVAR(m_vecForce, Vector, "CBaseAnimating", "m_vecForce");
	M_NETVAR(m_nSkin, int, "CBaseAnimating", "m_nSkin");
	M_NETVAR(m_nBody, int, "CBaseAnimating", "m_nBody");
	M_NETVAR(m_nHitboxSet, int, "CBaseAnimating", "m_nHitboxSet");
	M_NETVAR(m_flModelScale, float, "CBaseAnimating", "m_flModelScale");
	M_NETVAR(m_flPoseParameter, void*, "CBaseAnimating", "m_flPoseParameter");
	M_NETVAR(m_flPlaybackRate, float, "CBaseAnimating", "m_flPlaybackRate");
	M_NETVAR(m_flEncodedController, void*, "CBaseAnimating", "m_flEncodedController");
	M_NETVAR(m_bClientSideAnimation, bool, "CBaseAnimating", "m_bClientSideAnimation");
	M_NETVAR(m_bClientSideFrameReset, bool, "CBaseAnimating", "m_bClientSideFrameReset");
	M_NETVAR(m_bClientSideRagdoll, bool, "CBaseAnimating", "m_bClientSideRagdoll");
	M_NETVAR(m_nNewSequenceParity, int, "CBaseAnimating", "m_nNewSequenceParity");
	M_NETVAR(m_nResetEventsParity, int, "CBaseAnimating", "m_nResetEventsParity");
	M_NETVAR(m_nMuzzleFlashParity, int, "CBaseAnimating", "m_nMuzzleFlashParity");
	M_NETVAR(m_hLightingOrigin, EHANDLE, "CBaseAnimating", "m_hLightingOrigin");
	M_NETVAR(m_flCycle, float, "CBaseAnimating", "m_flCycle");
	M_NETVAR(m_flFrozen, float, "CBaseAnimating", "m_flFrozen");

	inline int GetNumOfHitboxes()
	{
		if (const auto pModel = GetModel())
		{
			if (const auto pHDR = g_pModelInfo->GetStudioModel(pModel))
			{
				if (const auto pSet = pHDR->pHitboxSet(this->m_nHitboxSet()))
					return pSet->numhitboxes;
			}
		}

		return 0;
	}

	inline Vector GetHitboxPositionByGroup(const int nGroup)
	{
		Vector vOut = { };

		if (const auto pModel = this->GetModel())
		{
			if (const auto pHDR = g_pModelInfo->GetStudioModel(pModel))
			{
				if (const auto pSet = pHDR->pHitboxSet(this->m_nHitboxSet()))
				{
					matrix3x4_t Matrix[128];
					if (SetupBones(Matrix, 128, 0x100, g_pGlobals->curtime))
					{
						mstudiobbox* pFinalBox = nullptr;

						int n;
						for (n = 0; n < pSet->numhitboxes; n++)
						{
							if (mstudiobbox* pBox = pSet->pHitbox(n))
							{
								if (pBox->group == nGroup)
									pFinalBox = pBox;
							}
						}

						if (pFinalBox)
						{
							Vector vPos = ((pFinalBox->bbmin + pFinalBox->bbmax) * 0.5f);
							g_Math.VectorTransform(vPos, Matrix[pFinalBox->bone], vOut);
						}
					}
				}
			}
		}

		return vOut;
	}

	inline Vector GetHitboxPosition(const int nHitbox)
	{
		Vector vOut = { };

		if (const auto pModel = this->GetModel())
		{
			if (const auto pHDR = g_pModelInfo->GetStudioModel(pModel))
			{
				matrix3x4_t Matrix[128];
				if (SetupBones(Matrix, 128, 0x100, g_pGlobals->curtime))
				{
					if (const auto pSet = pHDR->pHitboxSet(this->m_nHitboxSet()))
					{
						if (const auto pBox = pSet->pHitbox(nHitbox))
						{
							Vector vPos = ((pBox->bbmin + pBox->bbmax) * 0.5f);
							g_Math.VectorTransform(vPos, Matrix[pBox->bone], vOut);
							return vOut;
						}
					}
				}
			}
		}

		return vOut;
	}
};

class C_BaseAnimatingOverlay : public C_BaseAnimating
{
public:
	M_NETVAR(m_flPrevCycle, float, "CBaseAnimatingOverlay", "m_flPrevCycle");
	M_NETVAR(m_flWeight, float, "CBaseAnimatingOverlay", "m_flWeight");
	M_NETVAR(m_nOrder, int, "CBaseAnimatingOverlay", "m_nOrder");
};

class C_BaseFlex : public C_BaseAnimatingOverlay
{
public:
	M_NETVAR(m_flexWeight, void*, "CBaseFlex", "m_flexWeight");
	M_NETVAR(m_blinktoggle, int, "CBaseFlex", "m_blinktoggle");
	M_NETVAR(m_viewtarget, Vector, "CBaseFlex", "m_viewtarget");
};

inline C_BaseAnimating* ToBaseAnimating(IClientEntity* pClientEntity)
{
	if (!pClientEntity)
		return nullptr;

#ifdef _DEBUG
	return dynamic_cast<C_BaseAnimating*>(pClientEntity);
#else
	return static_cast<C_BaseAnimating*>(pClientEntity);
#endif
}