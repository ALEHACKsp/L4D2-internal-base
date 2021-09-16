#pragma once

#include "c_baseanimating.h"

class C_BreakableProp : public C_BaseAnimating
{
public:
	M_NETVAR(m_noGhostCollision, int, "CBreakableProp", "m_noGhostCollision");
	M_NETVAR(m_bClientPhysics, bool, "CBreakableProp", "m_bClientPhysics");
};

class C_DynamicProp : public C_BreakableProp
{
public:
	M_NETVAR(m_bUseHitboxesForRenderBox, bool, "CDynamicProp", "m_bUseHitboxesForRenderBox");
};