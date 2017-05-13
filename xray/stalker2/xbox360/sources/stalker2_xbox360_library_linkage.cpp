////////////////////////////////////////////////////////////////////////////
//	Created 	: 06.10.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <xray/core/library_linkage.h>
#include <xray/engine/library_linkage.h>
#include <xray/game/library_linkage.h>

#ifdef XRAY_STATIC_LIBRARIES
	#include <xray/linkage_helper.h>
	INCLUDE_TO_LINKAGE(sound_library_linkage)
#endif // #ifdef XRAY_STATIC_LIBRARIES
		
#if XRAY_PLATFORM_XBOX_360
#	pragma comment( lib, "xapilib.lib" )
#endif // #if XRAY_PLATFORM_XBOX_360