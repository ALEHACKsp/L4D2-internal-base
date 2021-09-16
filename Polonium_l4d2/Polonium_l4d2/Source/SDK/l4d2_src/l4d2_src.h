#pragma once

#include "Interfaces/IBaseClientDLL.h"
#include "Interfaces/IClientEntityList.h"
#include "Interfaces/IEngineTrace.h"
#include "Interfaces/IEngineVGui.h"
#include "Interfaces/IGameMovement.h"
#include "Interfaces/IInput.h"
#include "Interfaces/IPlayerInfoManager.h"
#include "Interfaces/IMoveHelper.h"
#include "Interfaces/IPrediction.h"
#include "Interfaces/IStudioRender.h"
#include "Interfaces/ISurface.h"
#include "Interfaces/IVDebugOverlay.h"
#include "Interfaces/IVEngineClient.h"
#include "Interfaces/IVRenderView.h"

#include "game/client/l4d2/c_infected.h"
#include "game/shared/l4d2/c_basebackpackitem.h"
#include "game/shared/l4d2/c_basemountedweapon.h"
#include "game/shared/l4d2/c_terrorweapon.h"
#include "game/shared/l4d2/c_weaponspawn.h"

#include "public/tier1/checksum_md5.h"
#include "public/bspflags.h"
#include "public/client_class.h"
#include "public/const.h"
#include "public/globalvars_base.h"
#include "public/in_buttons.h"
#include "public/model_types.h"
#include "public/texture_group_names.h"
#include "public/usercmd.h"
#include "public/view_shared.h"

#include "../GlobalInfo/GlobalInfo.h"

inline void* g_pClientMode = nullptr;