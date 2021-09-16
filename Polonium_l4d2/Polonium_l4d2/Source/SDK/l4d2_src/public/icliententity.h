#pragma once

#include "iclientthinkable.h"
#include "IClientNetworkable.h"
#include "iclientrenderable.h"

#include "../game/shared/ehandle.h"
#include "../../NetVarManager/NetVarManager.h"

struct Ray_t;
class CGameTrace;
typedef CGameTrace trace_t;
class CMouthInfo;
class IClientEntityInternal;
struct SpatializationInfo_t;

class IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
	inline Vector& GetAbsOrigin() {
		return VFunc_Get<Vector& (__thiscall*)(void*)>(this, 11u)(this);
	}

	inline Vector GetWorldSpaceCenter() {
		Vector vMins, vMaxs;
		GetRenderBounds(vMins, vMaxs);

		Vector vCenter = GetAbsOrigin();
		vCenter.z += ((vMins.z + vMaxs.z) / 2.0f);
		return vCenter;
	}
};