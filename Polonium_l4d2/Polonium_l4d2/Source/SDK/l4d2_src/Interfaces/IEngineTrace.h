#pragma once

#include "../../../Util/VFunc/VFunc.h"
#include "../../../Util/Math/Math.h"

class C_BaseEntity;

struct Ray_t
{
	Ray_t() { 

	}

	Ray_t(const Vector vStart, const Vector vEnd)
	{
		m_Delta = VectorAligned(vEnd - vStart);
		m_IsSwept = (m_Delta.LenghtSqr() != 0);
		m_Extents.Init();
		m_pWorldAxisTransform = 0;
		m_IsRay = true;
		m_StartOffset.Init();
		m_Start = vStart;
	}

	VectorAligned m_Start;
	VectorAligned m_Delta;
	VectorAligned m_StartOffset;
	VectorAligned m_Extents;
	const matrix3x4_t* m_pWorldAxisTransform;
	bool m_IsRay;
	bool m_IsSwept;

	void Init(const Vector vStart, const Vector vEnd)
	{
		m_Delta = VectorAligned(vEnd - vStart);
		m_IsSwept = (m_Delta.LenghtSqr() != 0);
		m_Extents.Init();
		m_pWorldAxisTransform = 0;
		m_IsRay = true;
		m_StartOffset.Init();
		m_Start = vStart;
	}
};

#define DISPSURF_FLAG_SURFACE		(1 << 0)
#define DISPSURF_FLAG_WALKABLE		(1 << 1)
#define DISPSURF_FLAG_BUILDABLE		(1 << 2)
#define DISPSURF_FLAG_SURFPROP1		(1 << 3)
#define DISPSURF_FLAG_SURFPROP2		(1 << 4)

struct cplane_t
{
	Vector normal;
	float dist;
	unsigned char type;
	unsigned char signbits;
	unsigned char __pad00[2];
};

class CBaseTrace
{
public:
	Vector startpos;
	Vector endpos;
	cplane_t plane;

	float fraction;

	int contents;
	unsigned short dispFlags;

	bool allsolid;
	bool startsolid;

	CBaseTrace() {}
};

struct csurface_t
{
	const char* name;
	short surfaceProps;
	unsigned short flags;
};

class CGameTrace : public CBaseTrace
{
public:
	// Returns true if there was any kind of impact at all
	bool DidHit() const;

public:
	float fractionleftsolid;
	csurface_t surface;
	int hitgroup;
	short physicsbone;
	unsigned short worldSurfaceIndex;
	C_BaseEntity* m_pEnt;
	int hitbox;

	CGameTrace() { }

private:
	CGameTrace(const CGameTrace& vOther);
};

//-----------------------------------------------------------------------------
// Returns true if there was any kind of impact at all
//-----------------------------------------------------------------------------
inline bool CGameTrace::DidHit() const
{
	return fraction < 1 || allsolid || startsolid;
}

typedef CGameTrace trace_t;

//-----------------------------------------------------------------------------
// The standard trace filter... NOTE: Most normal traces inherit from CTraceFilter!!!
//-----------------------------------------------------------------------------
enum class TraceType_t
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,				// NOTE: This does *not* test static props!!!
	TRACE_ENTITIES_ONLY,			// NOTE: This version will *not* test static props
	TRACE_EVERYTHING_FILTER_PROPS,	// NOTE: This version will pass the IHandleEntity for props through the filter, unlike all other filters
};

class ITraceFilter
{
public:
	virtual bool ShouldHitEntity(C_BaseEntity* pEntity, int contentsMask) = 0;
	virtual TraceType_t	GetTraceType() const = 0;
};

//-----------------------------------------------------------------------------
// Classes are expected to inherit these + implement the ShouldHitEntity method
//-----------------------------------------------------------------------------
// This is the one most normal traces will inherit from
class CTraceFilter : public ITraceFilter
{
public:
	virtual TraceType_t	GetTraceType() const
	{
		return TraceType_t::TRACE_EVERYTHING;
	}
};

class CTraceFilterEntitiesOnly : public ITraceFilter
{
public:
	virtual TraceType_t	GetTraceType() const
	{
		return TraceType_t::TRACE_ENTITIES_ONLY;
	}
};

//-----------------------------------------------------------------------------
// Classes need not inherit from these
//-----------------------------------------------------------------------------
class CTraceFilterWorldOnly : public ITraceFilter
{
public:
	bool ShouldHitEntity(C_BaseEntity* pServerEntity, int contentsMask)
	{
		return false;
	}
	virtual TraceType_t	GetTraceType() const
	{
		return TraceType_t::TRACE_WORLD_ONLY;
	}
};

class CTraceFilterWorldAndPropsOnly : public ITraceFilter
{
public:
	bool ShouldHitEntity(C_BaseEntity* pServerEntity, int contentsMask)
	{
		return false;
	}
	virtual TraceType_t	GetTraceType() const
	{
		return TraceType_t::TRACE_EVERYTHING;
	}
};

class CTraceFilterHitAll : public CTraceFilter
{
public:
	virtual bool ShouldHitEntity(C_BaseEntity* pServerEntity, int contentsMask)
	{
		return true;
	}
};

class IEngineTrace
{
public:
	inline void TraceRay(const Ray_t& ray, const int nMask, ITraceFilter* pFilter, trace_t* pTrace) {
		VFunc_Get<void(__thiscall*)(void*, const Ray_t&, int, ITraceFilter*, trace_t*)>(this, 5u)(this, ray, nMask, pFilter, pTrace);
	}
};

inline IEngineTrace* g_pEngineTrace = nullptr;