//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef CONST_H
#define CONST_H
#ifdef _WIN32
#pragma once
#endif

// the command line param that tells the engine to use steam
#define STEAM_PARM					"-steam"
// the command line param to tell dedicated server to restart 
// if they are out of date
#define AUTO_RESTART "-autoupdate"

// the message a server sends when a clients steam login is expired
#define INVALID_STEAM_TICKET "Invalid STEAM UserID Ticket\n"
#define INVALID_STEAM_VACBANSTATE "VAC banned from secure server\n"
#define INVALID_STEAM_LOGGED_IN_ELSEWHERE "This Steam account is being used in another location\n"
#define INVALID_STEAM_LOGON_NOT_CONNECTED "Client not connected to Steam\n"
#define INVALID_STEAM_LOGON_TICKET_CANCELED "Client left game (Steam auth ticket has been canceled)\n"

#define CLIENTNAME_TIMED_OUT "%s timed out"

// This is the default, see shareddefs.h for mod-specific value, which can override this
#define DEFAULT_TICK_INTERVAL	(0.015)				// 15 msec is the default
#define MINIMUM_TICK_INTERVAL   (0.001)
#define MAXIMUM_TICK_INTERVAL	(0.1)

// This is the max # of players the engine can handle
#define ABSOLUTE_PLAYER_LIMIT 255  // not 256, so we can send the limit as a byte 
#define ABSOLUTE_PLAYER_LIMIT_DW	( (ABSOLUTE_PLAYER_LIMIT/32) + 1 )

// a player name may have 31 chars + 0 on the PC.
// the 360 only allows 15 char + 0, but stick with the larger PC size for cross-platform communication
#define MAX_PLAYER_NAME_LENGTH		32

#ifdef _X360
#define MAX_PLAYERS_PER_CLIENT		XUSER_MAX_COUNT	// Xbox 360 supports 4 players per console
#else
#define MAX_PLAYERS_PER_CLIENT		1	// One player per PC
#endif

// Max decorated map name, with things like workshop/cp_foo.ugc123456
#define MAX_MAP_NAME				96

// Max name used in save files. Needs to be left at 32 for SourceSDK compatibility.
#define MAX_MAP_NAME_SAVE			32

// Max non-decorated map name for e.g. server browser (just cp_foo)
#define MAX_DISPLAY_MAP_NAME		32

#define	MAX_NETWORKID_LENGTH		64  // num chars for a network (i.e steam) ID

// BUGBUG: Reconcile with or derive this from the engine's internal definition!
// FIXME: I added an extra bit because I needed to make it signed
#define SP_MODEL_INDEX_BITS			13

// How many bits to use to encode an edict.
#define	MAX_EDICT_BITS				11			// # of bits needed to represent max edicts
// Max # of edicts in a level
#define	MAX_EDICTS					(1<<MAX_EDICT_BITS)

// How many bits to use to encode an server class index
#define MAX_SERVER_CLASS_BITS		9
// Max # of networkable server classes
#define MAX_SERVER_CLASSES			(1<<MAX_SERVER_CLASS_BITS)

#define SIGNED_GUID_LEN 32 // Hashed CD Key (32 hex alphabetic chars + 0 terminator )

// Used for networking ehandles.
#define NUM_ENT_ENTRY_BITS		(MAX_EDICT_BITS + 1)
#define NUM_ENT_ENTRIES			(1 << NUM_ENT_ENTRY_BITS)
#define ENT_ENTRY_MASK			(NUM_ENT_ENTRIES - 1)
#define INVALID_EHANDLE_INDEX	0xFFFFFFFF

#define NUM_SERIAL_NUM_BITS		(32 - NUM_ENT_ENTRY_BITS)


// Networked ehandles use less bits to encode the serial number.
#define NUM_NETWORKED_EHANDLE_SERIAL_NUMBER_BITS	10
#define NUM_NETWORKED_EHANDLE_BITS					(MAX_EDICT_BITS + NUM_NETWORKED_EHANDLE_SERIAL_NUMBER_BITS)
#define INVALID_NETWORKED_EHANDLE_VALUE				((1 << NUM_NETWORKED_EHANDLE_BITS) - 1)

// This is the maximum amount of data a PackedEntity can have. Having a limit allows us
// to use static arrays sometimes instead of allocating memory all over the place.
#define MAX_PACKEDENTITY_DATA	(16384)

// This is the maximum number of properties that can be delta'd. Must be evenly divisible by 8.
#define MAX_PACKEDENTITY_PROPS	(4096)

// a client can have up to 4 customization files (logo, sounds, models, txt).
#define MAX_CUSTOM_FILES		4		// max 4 files
#define MAX_CUSTOM_FILE_SIZE	524288	// Half a megabyte

#define COLOR_RED		 { 255, 64, 64, 255   }
#define COLOR_REDINDIAN  { 205, 92, 92, 255   }
#define COLOR_BLUE		 { 153, 204, 255, 255 }
#define COLOR_BLUEAZURE  { 0, 127, 255, 255   }
#define COLOR_BlUEYONDER { 80, 114, 167, 255  }
#define COLOR_BLUEAERO   { 124, 185, 232, 255 }
#define COLOR_YELLOW	 { 255, 178, 0, 255   }
#define COLOR_GREEN		 { 153, 255, 153, 255 }
#define COLOR_GREENNEON  { 57, 255, 20, 255   }
#define COLOR_GREENDARK  { 0, 255, 64, 255    }
#define COLOR_GREY		 { 204, 204, 204, 255 }
#define COLOR_WHITE		 { 255, 255, 255, 255 }
#define COLOR_PURPLE     { 133, 16, 216, 255  }
#define COLOR_BLACK		 { 0, 0, 0, 255       }

enum class ClientFrameStage_t
{
	FRAME_UNDEFINED = -1,			// (haven't run any frames yet)
	FRAME_START,

	// A network packet is being recieved
	FRAME_NET_UPDATE_START,
	// Data has been received and we're going to start calling PostDataUpdate
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	// Data has been received and we've called PostDataUpdate on all data recipients
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	// We've received all packets, we can now do interpolation, prediction, etc..
	FRAME_NET_UPDATE_END,

	// We're about to start rendering the scene
	FRAME_RENDER_START,
	// We've finished rendering the scene.
	FRAME_RENDER_END
};

//
// Constants shared by the engine and dlls
// This header file included by engine files and DLL files.
// Most came from server.h

// CBaseEntity::m_fFlags
// PLAYER SPECIFIC FLAGS FIRST BECAUSE WE USE ONLY A FEW BITS OF NETWORK PRECISION
#define	FL_ONGROUND				(1<<0)	// At rest / on the ground
#define FL_DUCKING				(1<<1)	// Player flag -- Player is fully crouched
#define FL_ANIMDUCKING			(1<<2)	// Player flag -- Player is in the process of crouching or uncrouching but could be in transition
// examples:                                   Fully ducked:  FL_DUCKING &  FL_ANIMDUCKING
//           Previously fully ducked, unducking in progress:  FL_DUCKING & !FL_ANIMDUCKING
//                                           Fully unducked: !FL_DUCKING & !FL_ANIMDUCKING
//           Previously fully unducked, ducking in progress: !FL_DUCKING &  FL_ANIMDUCKING
#define	FL_WATERJUMP			(1<<3)	// player jumping out of water
#define FL_ONTRAIN				(1<<4) // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN				(1<<5)	// Indicates the entity is standing in rain
#define FL_FROZEN				(1<<6) // Player is frozen for 3rd person camera
#define FL_ATCONTROLS			(1<<7) // Player can't move, but keeps key inputs for controlling another entity
#define	FL_CLIENT				(1<<8)	// Is a player
#define FL_FAKECLIENT			(1<<9)	// Fake client, simulated server side; don't send network messages to them
// NON-PLAYER SPECIFIC (i.e., not used by GameMovement or the client .dll ) -- Can still be applied to players, though
#define	FL_INWATER				(1<<10)	// In water

// NOTE if you move things up, make sure to change this value
#define PLAYER_FLAG_BITS		11

#define	FL_FLY					(1<<11)	// Changes the SV_Movestep() behavior to not need to be on ground
#define	FL_SWIM					(1<<12)	// Changes the SV_Movestep() behavior to not need to be on ground (but stay in water)
#define	FL_CONVEYOR				(1<<13)
#define	FL_NPC					(1<<14)
#define	FL_GODMODE				(1<<15)
#define	FL_NOTARGET				(1<<16)
#define	FL_AIMTARGET			(1<<17)	// set if the crosshair needs to aim onto the entity
#define	FL_PARTIALGROUND		(1<<18)	// not all corners are valid
#define FL_STATICPROP			(1<<19)	// Eetsa static prop!		
#define FL_GRAPHED				(1<<20) // worldgraph has this ent listed as something that blocks a connection
#define FL_GRENADE				(1<<21)
#define FL_STEPMOVEMENT			(1<<22)	// Changes the SV_Movestep() behavior to not do any processing
#define FL_DONTTOUCH			(1<<23)	// Doesn't generate touch functions, generates Untouch() for anything it was touching when this flag was set
#define FL_BASEVELOCITY			(1<<24)	// Base velocity has been applied this frame (used to convert base velocity into momentum)
#define FL_WORLDBRUSH			(1<<25)	// Not moveable/removeable brush entity (really part of the world, but represented as an entity for transparency or something)
#define FL_OBJECT				(1<<26) // Terrible name. This is an object that NPCs should see. Missiles, for example.
#define FL_KILLME				(1<<27)	// This entity is marked for death -- will be freed by game DLL
#define FL_ONFIRE				(1<<28)	// You know...
#define FL_DISSOLVING			(1<<29) // We're dissolving!
#define FL_TRANSRAGDOLL			(1<<30) // In the process of turning into a client side ragdoll.
#define FL_UNBLOCKABLE_BY_PLAYER (1<<31) // pusher that can't be blocked by the player

// edict->movetype values
enum MoveType_t
{
	MOVETYPE_NONE = 0,	// never moves
	MOVETYPE_ISOMETRIC,			// For players -- in TF2 commander view, etc.
	MOVETYPE_WALK,				// Player only - moving on the ground
	MOVETYPE_STEP,				// gravity, special edge handling -- monsters use this
	MOVETYPE_FLY,				// No gravity, but still collides with stuff
	MOVETYPE_FLYGRAVITY,		// flies through the air + is affected by gravity
	MOVETYPE_VPHYSICS,			// uses VPHYSICS for simulation
	MOVETYPE_PUSH,				// no clip to world, push and crush
	MOVETYPE_NOCLIP,			// No gravity, no collisions, still do velocity/avelocity
	MOVETYPE_LADDER,			// Used by players only when going onto a ladder
	MOVETYPE_OBSERVER,			// Observer movement, depends on player's observer mode
	MOVETYPE_CUSTOM,			// Allows the entity to describe its own physics

	// should always be defined as the last item in the list
	MOVETYPE_LAST = MOVETYPE_CUSTOM,

	MOVETYPE_MAX_BITS = 4
};

// edict->movecollide values
enum MoveCollide_t
{
	MOVECOLLIDE_DEFAULT = 0,

	// These ones only work for MOVETYPE_FLY + MOVETYPE_FLYGRAVITY
	MOVECOLLIDE_FLY_BOUNCE,	// bounces, reflects, based on elasticity of surface and object - applies friction (adjust velocity)
	MOVECOLLIDE_FLY_CUSTOM,	// Touch() will modify the velocity however it likes
	MOVECOLLIDE_FLY_SLIDE,  // slides along surfaces (no bounce) - applies friciton (adjusts velocity)

	MOVECOLLIDE_COUNT,		// Number of different movecollides

	// When adding new movecollide types, make sure this is correct
	MOVECOLLIDE_MAX_BITS = 3
};

// edict->solid values
// NOTE: Some movetypes will cause collisions independent of SOLID_NOT/SOLID_TRIGGER when the entity moves
// SOLID only effects OTHER entities colliding with this one when they move - UGH!

// Solid type basically describes how the bounding volume of the object is represented
// NOTE: SOLID_BBOX MUST BE 2, and SOLID_VPHYSICS MUST BE 6
// NOTE: These numerical values are used in the FGD by the prop code (see prop_dynamic)
enum SolidType_t
{
	SOLID_NONE = 0,	// no solid model
	SOLID_BSP = 1,	// a BSP tree
	SOLID_BBOX = 2,	// an AABB
	SOLID_OBB = 3,	// an OBB (not implemented yet)
	SOLID_OBB_YAW = 4,	// an OBB, constrained so that it can only yaw
	SOLID_CUSTOM = 5,	// Always call into the entity for tests
	SOLID_VPHYSICS = 6,	// solid vphysics object, get vcollide from the model and collide with that
	SOLID_LAST,
};

enum SolidFlags_t
{
	FSOLID_CUSTOMRAYTEST = 0x0001,	// Ignore solid type + always call into the entity for ray tests
	FSOLID_CUSTOMBOXTEST = 0x0002,	// Ignore solid type + always call into the entity for swept box tests
	FSOLID_NOT_SOLID = 0x0004,	// Are we currently not solid?
	FSOLID_TRIGGER = 0x0008,	// This is something may be collideable but fires touch functions
								// even when it's not collideable (when the FSOLID_NOT_SOLID flag is set)
								FSOLID_NOT_STANDABLE = 0x0010,	// You can't stand on this
								FSOLID_VOLUME_CONTENTS = 0x0020,	// Contains volumetric contents (like water)
								FSOLID_FORCE_WORLD_ALIGNED = 0x0040,	// Forces the collision rep to be world-aligned even if it's SOLID_BSP or SOLID_VPHYSICS
								FSOLID_USE_TRIGGER_BOUNDS = 0x0080,	// Uses a special trigger bounds separate from the normal OBB
								FSOLID_ROOT_PARENT_ALIGNED = 0x0100,	// Collisions are defined in root parent's local coordinate space
								FSOLID_TRIGGER_TOUCH_DEBRIS = 0x0200,	// This trigger will touch debris objects

								FSOLID_MAX_BITS = 10
};

//-----------------------------------------------------------------------------
// A couple of inline helper methods
//-----------------------------------------------------------------------------
inline bool IsSolid(SolidType_t solidType, int nSolidFlags)
{
	return (solidType != SOLID_NONE) && ((nSolidFlags & FSOLID_NOT_SOLID) == 0);
}

// m_lifeState values
#define	LIFE_ALIVE				0 // alive
#define	LIFE_DYING				1 // playing death animation or still falling off of a ledge waiting to hit ground
#define	LIFE_DEAD				2 // dead. lying still.
#define LIFE_RESPAWNABLE		3
#define LIFE_DISCARDBODY		4

// entity effects
enum
{
	EF_BONEMERGE = 0x001,	// Performs bone merge on client side
	EF_BRIGHTLIGHT = 0x002,	// DLIGHT centered at entity origin
	EF_DIMLIGHT = 0x004,	// player flashlight
	EF_NOINTERP = 0x008,	// don't interpolate the next frame
	EF_NOSHADOW = 0x010,	// Don't cast no shadow
	EF_NODRAW = 0x020,	// don't draw entity
	EF_NORECEIVESHADOW = 0x040,	// Don't receive no shadow
	EF_BONEMERGE_FASTCULL = 0x080,	// For use with EF_BONEMERGE. If this is set, then it places this ent's origin at its
										// parent and uses the parent's bbox + the max extents of the aiment.
										// Otherwise, it sets up the parent's bones every frame to figure out where to place
										// the aiment, which is inefficient because it'll setup the parent's bones even if
										// the parent is not in the PVS.
										EF_ITEM_BLINK = 0x100,	// blink an item so that the user notices it.
										EF_PARENT_ANIMATES = 0x200,	// always assume that the parent entity is animating
										EF_MAX_BITS = 10
};

#define EF_PARITY_BITS	3
#define EF_PARITY_MASK  ((1<<EF_PARITY_BITS)-1)

// How many bits does the muzzle flash parity thing get?
#define EF_MUZZLEFLASH_BITS 2

// plats
#define	PLAT_LOW_TRIGGER	1

// Trains
#define	SF_TRAIN_WAIT_RETRIGGER	1
#define SF_TRAIN_PASSABLE		8		// Train is not solid -- used to make water trains

// view angle update types for CPlayerState::fixangle
#define FIXANGLE_NONE			0
#define FIXANGLE_ABSOLUTE		1
#define FIXANGLE_RELATIVE		2

// Break Model Defines

#define BREAK_GLASS		0x01
#define BREAK_METAL		0x02
#define BREAK_FLESH		0x04
#define BREAK_WOOD		0x08

#define BREAK_SMOKE		0x10
#define BREAK_TRANS		0x20
#define BREAK_CONCRETE	0x40

// If this is set, then we share a lighting origin with the last non-slave breakable sent down to the client
#define BREAK_SLAVE		0x80

// Colliding temp entity sounds

#define BOUNCE_GLASS	BREAK_GLASS
#define	BOUNCE_METAL	BREAK_METAL
#define BOUNCE_FLESH	BREAK_FLESH
#define BOUNCE_WOOD		BREAK_WOOD
#define BOUNCE_SHRAP	0x10
#define BOUNCE_SHELL	0x20
#define	BOUNCE_CONCRETE BREAK_CONCRETE
#define BOUNCE_SHOTSHELL 0x80

// Temp entity bounce sound types
#define TE_BOUNCE_NULL		0
#define TE_BOUNCE_SHELL		1
#define TE_BOUNCE_SHOTSHELL	2

// Rendering constants
// if this is changed, update common/MaterialSystem/Sprite.cpp
enum RenderMode_t
{
	kRenderNormal = 0,		// src
	kRenderTransColor,		// c*a+dest*(1-a)
	kRenderTransTexture,	// src*a+dest*(1-a)
	kRenderGlow,			// src*a+dest -- No Z buffer checks -- Fixed size in screen space
	kRenderTransAlpha,		// src*srca+dest*(1-srca)
	kRenderTransAdd,		// src*a+dest
	kRenderEnvironmental,	// not drawn, used for environmental effects
	kRenderTransAddFrameBlend, // use a fractional frame value to blend between animation frames
	kRenderTransAlphaAdd,	// src + dest*(1-a)
	kRenderWorldGlow,		// Same as kRenderGlow but not fixed size in screen space
	kRenderNone,			// Don't render.

	kRenderModeCount,		// must be last
};

enum RenderFx_t
{
	kRenderFxNone = 0,
	kRenderFxPulseSlow,
	kRenderFxPulseFast,
	kRenderFxPulseSlowWide,
	kRenderFxPulseFastWide,
	kRenderFxFadeSlow,
	kRenderFxFadeFast,
	kRenderFxSolidSlow,
	kRenderFxSolidFast,
	kRenderFxStrobeSlow,
	kRenderFxStrobeFast,
	kRenderFxStrobeFaster,
	kRenderFxFlickerSlow,
	kRenderFxFlickerFast,
	kRenderFxNoDissipation,
	kRenderFxDistort,			// Distort/scale/translate flicker
	kRenderFxHologram,			// kRenderFxDistort + distance fade
	kRenderFxExplode,			// Scale up really big!
	kRenderFxGlowShell,			// Glowing Shell
	kRenderFxClampMinScale,		// Keep this sprite from getting very small (SPRITES only!)
	kRenderFxEnvRain,			// for environmental rendermode, make rain
	kRenderFxEnvSnow,			//  "        "            "    , make snow
	kRenderFxSpotlight,			// TEST CODE for experimental spotlight
	kRenderFxRagdoll,			// HACKHACK: TEST CODE for signalling death of a ragdoll character
	kRenderFxPulseFastWider,
	kRenderFxMax
};

enum Collision_Group_t
{
	COLLISION_GROUP_NONE = 0,
	COLLISION_GROUP_DEBRIS,			// Collides with nothing but world and static stuff
	COLLISION_GROUP_DEBRIS_TRIGGER, // Same as debris, but hits triggers
	COLLISION_GROUP_INTERACTIVE_DEBRIS,	// Collides with everything except other interactive debris or debris
	COLLISION_GROUP_INTERACTIVE,	// Collides with everything except interactive debris or debris
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_BREAKABLE_GLASS,
	COLLISION_GROUP_VEHICLE,
	COLLISION_GROUP_PLAYER_MOVEMENT,  // For HL2, same as Collision_Group_Player, for
										// TF2, this filters out other players and CBaseObjects
										COLLISION_GROUP_NPC,			// Generic NPC group
										COLLISION_GROUP_IN_VEHICLE,		// for any entity inside a vehicle
										COLLISION_GROUP_WEAPON,			// for any weapons that need collision detection
										COLLISION_GROUP_VEHICLE_CLIP,	// vehicle clip brush to restrict vehicle movement
										COLLISION_GROUP_PROJECTILE,		// Projectiles!
										COLLISION_GROUP_DOOR_BLOCKER,	// Blocks entities not permitted to get near moving doors
										COLLISION_GROUP_PASSABLE_DOOR,	// Doors that the player shouldn't collide with
										COLLISION_GROUP_DISSOLVING,		// Things that are dissolving are in this group
										COLLISION_GROUP_PUSHAWAY,		// Nonsolid on client and server, pushaway in player code

										COLLISION_GROUP_NPC_ACTOR,		// Used so NPCs in scripts ignore the player.
										COLLISION_GROUP_NPC_SCRIPTED,	// USed for NPCs in scripts that should not collide with each other

										LAST_SHARED_COLLISION_GROUP
};

#define SOUND_NORMAL_CLIP_DIST	1000.0f

// How many networked area portals do we allow?
#define MAX_AREA_STATE_BYTES		32
#define MAX_AREA_PORTAL_STATE_BYTES 24

// user message max payload size (note, this value is used by the engine, so MODs cannot change it)
#define MAX_USER_MSG_DATA 255
#define MAX_ENTITY_MSG_DATA 255

//18.06.2021
enum class EClientClass
{
	INVALID = -1,
	Jockey = 265,
	Spitter = 272,
	Charger = 99,
	Hunter = 263,
	Smoker = 270,
	Boomer = 0,
	Tank = 276,
	Witch = 277,
	Infected = 264,
	CVomitJarProjectile = 252,
	CTerrorWeapon = 235,
	CTerrorMeleeWeapon = 231,
	CTerrorGun = 230,
	CTankClaw = 187,
	CSubMachinegun = 182,
	CSpitterProjectile = 176,
	CSpitterClaw = 175,
	CSniperRifle = 172,
	CSniper_Scout = 171,
	CSniper_Military = 170,
	CSniper_AWP = 169,
	CSmokerClaw = 167,
	CSMG_Silenced = 166,
	CSMG_MP5 = 165,
	CShotgun_SPAS = 163,
	CShotgun_Chrome = 162,
	CRifle_SG552 = 155,
	CRifle_M60 = 154,
	CRifle_Desert = 153,
	CRifle_AK47 = 152,
	CPumpShotgun = 148,
	CPropaneTank = 142,
	CMagnumPistol = 116,
	CPistol = 131,
	CPipeBombProjectile = 130,
	CPipeBomb = 129,
	CPainPills = 121,
	COxygenTank = 120,
	CBaseMountedWeapon = 18,
	CPropMountedGun = 146,
	CMolotovProjectile = 119,
	CMolotov = 118,
	CPropMinigun = 145,
	CJockeyClaw = 112,
	CItem_VomitJar = 106,
	CItemUpgradePackIncendiary = 111,
	CItemUpgradePackExplosive = 110,
	CItemDefibrillator = 109,
	CItemBaseUpgradePack = 108,
	CItemAmmoPack = 107,
	CItem_Adrenaline = 105,
	CHunterClaw = 100,
	CGrenadeLauncher_Projectile = 97,
	CGrenadeLauncher = 96,
	CGnome = 95,
	CGasCan = 94,
	CFirstAidKit = 73,
	CFireworkCrate = 72,
	CColaBottles = 44,
	CClaw = 42,
	CChargerClaw = 41,
	CChainsaw = 39,
	CPointPropUseTarget = 135,
	CTEBullets = 206,
	CBoomerClaw = 34,
	CBaseSniperRifle = 24,
	CBaseShotgun = 23,
	CBaseRifle = 22,
	CBaseBeltItem = 8,
	CBaseBackpackItem = 7,
	CBaseAutoShotgun = 6,
	CAutoShotgun = 2,
	CAssaultRifle = 1,
	SurvivorBot = 275,
	NextBotCombatCharacter = 267,
	CFireCrackerBlast = 69,
	CInsectSwarm = 104,
	CInferno = 101,
	CVomit = 251,
	CTongue = 246,
	CThrow = 245,
	CSpitAbility = 174,
	CSelfDestruct = 160,
	CLunge = 115,
	CLeap = 113,
	CCharge = 40,
	CBaseAbility = 3,
	CTutorLesson = 249,
	CTransitioningPlayer = 247,
	CTerrorViewModel = 234,
	CFuncRagdollFader = 87,
	CTerrorGameRulesProxy = 229,
	CSurvivorPosition = 185,
	CScavengeProgressDisplay = 157,
	CPropHealthCabinet = 144,
	CFinaleTrigger = 68,
	CClientPath = 43,
	CTerrorPlayerResource = 233,
	CTerrorPlayer = 232,
	CSurvivorRescue = 186,
	CSurvivorDeathModel = 184,
	CBaseUpgradeItem = 29,
	CWeaponScavengeItemSpawn = 259,
	CWeaponAmmoSpawn = 256,
	CWeaponSpawn = 260,
	CTeamTrainWatcher = 0,
	CSoundMixLayer = 173,
	CPointScriptUseTarget = 136,
	CEnvWeaponFire = 66,
	CWeaponCSBaseGun = 258,
	CWeaponCSBase = 257,
	CBaseCSGrenade = 12,
	CCSGameRulesProxy = 47,
	CWeaponCubemap = 0,
	CWeaponCycler = 0,
	CPlantedC4 = 0,
	CCSTeam = 50,
	CCSPlayer = 48,
	CCSRagdoll = 49,
	CTEPlayerAnimEvent = 226,
	CBaseCSGrenadeProjectile = 13,
	CTestTraceline = 243,
	CTEWorldDecal = 244,
	CTESpriteSpray = 241,
	CTESprite = 240,
	CTESparks = 239,
	CTESmoke = 238,
	CTEShowLine = 237,
	CTEProjectedDecal = 228,
	CTEPlayerDecal = 227,
	CTEPhysicsProp = 225,
	CTEParticleSystem = 224,
	CTEMuzzleFlash = 223,
	CTELargeFunnel = 221,
	CTEKillPlayerAttachments = 220,
	CTEImpact = 219,
	CTEGlowSprite = 218,
	CTEShatterSurface = 236,
	CTEFootprintDecal = 215,
	CTEFizz = 214,
	CTEExplosion = 213,
	CTEEnergySplash = 212,
	CTEEffectDispatch = 211,
	CTEDynamicLight = 210,
	CTEDecal = 208,
	CTEClientProjectile = 207,
	CTEBubbleTrail = 205,
	CTEBubbles = 204,
	CTEBSPDecal = 203,
	CTEBreakModel = 202,
	CTEBloodStream = 201,
	CTEBloodSprite = 200,
	CTEBeamSpline = 199,
	CTEBeamRingPoint = 198,
	CTEBeamRing = 197,
	CTEBeamPoints = 196,
	CTEBeamLaser = 195,
	CTEBeamFollow = 194,
	CTEBeamEnts = 193,
	CTEBeamEntPoint = 192,
	CTEBaseBeam = 191,
	CTEArmorRicochet = 190,
	CTEMetalSparks = 222,
	CSteamJet = 181,
	CSmokeStack = 168,
	DustTrail = 262,
	CFireTrail = 71,
	SporeTrail = 274,
	SporeExplosion = 273,
	RocketTrail = 269,
	SmokeTrail = 271,
	CPropVehicleDriveable = 147,
	ParticleSmokeGrenade = 268,
	CParticleFire = 122,
	MovieExplosion = 266,
	CTEGaussExplosion = 217,
	CEnvQuadraticBeam = 62,
	CEmbers = 53,
	CEnvWind = 67,
	CPrecipitation = 139,
	CPrecipitationBlocker = 140,
	CBaseTempEntity = 26,
	CHandleTest = 98,
	CTeamplayRoundBasedRulesProxy = 189,
	CSpriteTrail = 180,
	CSpriteOriented = 179,
	CSprite = 178,
	CRagdollPropAttached = 151,
	CRagdollProp = 150,
	CPredictedViewModel = 141,
	CPoseController = 137,
	CGameRulesProxy = 93,
	CFuncSimpleLadder = 90,
	CInfoLadderDismount = 102,
	CFuncLadder = 82,
	CTEFoundryHelpers = 216,
	CEnvDetailController = 57,
	CWorld = 261,
	CWaterLODControl = 255,
	CWaterBullet = 254,
	CVoteController = 253,
	CVGuiScreen = 250,
	CPropJeep = 0,
	CPropVehicleChoreoGeneric = 0,
	CFuncPlayerGhostInfectedClip = 85,
	CFuncPlayerInfectedClip = 86,
	CTriggerPlayerMovement = 248,
	CBaseTrigger = 28,
	CTest_ProxyToggle_Networkable = 242,
	CBaseTeamObjectiveResource = 25,
	CTeam = 188,
	CFlare = 0,
	CSun = 183,
	CParticlePerformanceMonitor = 123,
	CSpotlightEnd = 177,
	CSlideshowDisplay = 164,
	CShadowControl = 161,
	CSceneEntity = 158,
	CRopeKeyframe = 156,
	CRagdollManager = 149,
	CPhysBoxMultiplayer = 126,
	CPropDoorRotatingCheckpoint = 143,
	CBasePropDoor = 21,
	CDynamicProp = 52,
	CPostProcessController = 138,
	CPointCommentaryNode = 134,
	CPlayerResource = 133,
	CPlasma = 132,
	CPhysMagnet = 128,
	CPhysicsProp = 127,
	CBreakable = 35,
	CPhysBox = 125,
	CParticleSystem = 124,
	CMaterialModifyControl = 117,
	CLightGlow = 114,
	CInfoOverlayAccessor = 103,
	CFuncTrackTrain = 92,
	CFuncSmokeVolume = 91,
	CFuncRotating = 89,
	CFuncReflectiveGlass = 88,
	CFuncOccluder = 84,
	CFuncMoveLinear = 83,
	CFuncMonitor = 0,
	CFunc_LOD = 77,
	CFuncElevator = 81,
	CTEDust = 209,
	CFunc_Dust = 76,
	CFuncConveyor = 80,
	CFuncBrush = 79,
	CBreakableSurface = 37,
	CFuncAreaPortalWindow = 78,
	CFish = 74,
	CFireSmoke = 70,
	CEnvTonemapController = 65,
	CEnvScreenEffect = 63,
	CEnvScreenOverlay = 64,
	CEnvProjectedTexture = 61,
	CEnvParticleScript = 59,
	CFogController = 75,
	CEnvDOFController = 58,
	CEnvPhysicsBlocker = 60,
	CEntityParticleTrail = 56,
	CEntityFlame = 55,
	CEntityDissolve = 54,
	CDynamicLight = 51,
	CColorCorrectionVolume = 46,
	CColorCorrection = 45,
	CBreakableProp = 36,
	CBeamSpotlight = 32,
	CButtonTimed = 38,
	CScriptBaseButton = 159,
	CBaseButton = 9,
	CBaseToggle = 27,
	CBasePlayer = 20,
	CBaseFlex = 16,
	CBaseEntity = 15,
	CBaseDoor = 14,
	CBaseCombatCharacter = 10,
	CBaseAnimatingOverlay = 5,
	CBoneFollower = 33,
	CBaseAnimating = 4,
	CAI_BaseNPC = 0,
	CBeam = 31,
	CBaseViewModel = 30,
	CBaseParticleEntity = 19,
	CBaseGrenade = 17,
	CBaseCombatWeapon = 11
};

#endif