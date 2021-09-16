#pragma once

#include "../../../Util/Math/Math.h"
#include "IMaterialSystem.h"

struct studiohdr_t;
class IClientRenderable;
typedef unsigned short ModelInstanceHandle_t;

enum
{
	MODEL_INSTANCE_INVALID = (ModelInstanceHandle_t)~0
};

struct ModelRenderInfo_t
{
	Vector  origin = {     };
	Vector  angles = {     };
	void* pRenderable = nullptr;
	const void* pModel = nullptr;
	const matrix3x4_t* pModelToWorld = nullptr;
	const matrix3x4_t* pLightingOffset = nullptr;
	const Vector* pLightingOrigin = nullptr;
	int flags = 0;
	int entity_index = 0;
	int skin = 0;
	int body = 0;
	int hitboxset = 0;
	ModelInstanceHandle_t instance = 0;

	ModelRenderInfo_t()
	{
		pModelToWorld = nullptr;
		pLightingOffset = nullptr;
		pLightingOrigin = nullptr;
	}
};

struct DrawModelState_t
{
	studiohdr_t*       m_pStudioHdr;
	void*              m_pStudioHWData;
	IClientRenderable* m_pRenderable;
	const matrix3x4_t* m_pModelToWorld;
	void*		       m_decals;
	int				   m_drawFlags;
	int				   m_lod;
};

class IVModelRender
{
public:
	inline void ForcedMaterialOverride(IMaterial* newMaterial, const int nOverrideType = 0) {
		VFunc_Get<void(__thiscall*)(void*, IMaterial*, int)>(this, 1u)(this, newMaterial, nOverrideType);
	}
};

inline IVModelRender* g_pModelRender = nullptr;