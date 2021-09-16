#pragma once

#include "../../../Util/VFunc/VFunc.h"
#include "../public/color.h"

struct Vertex_t;
typedef unsigned long HFont;

enum EFontFlags
{
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800
};

class ISurface
{
public:
	inline void DrawSetColor(const Color_t clr) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 11u)(this, clr.r, clr.g, clr.b, clr.a);
	}

	inline void DrawSetColor(const int r, const int g, const int b, const int a) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 11u)(this, r, g, b, a);
	}

	inline void DrawSetTextFont(const HFont fnt) {
		VFunc_Get<void(__thiscall*)(void*, HFont)>(this, 17u)(this, fnt);
	}

	inline void DrawFilledRect(const int x, const int y, const int w, const int h) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 12u)(this, x, y, (x + w), (y + h));
	}

	inline void DrawOutlinedRect(const int x, const int y, const int w, const int h) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 14u)(this, x, y, (x + w), (y + h));
	}

	inline void DrawLine(const int x0, const int y0, const int x1, const int y1) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 15u)(this, x0, y0, x1, y1);
	}

	inline void DrawSetTextColor(const Color_t clr) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 19u)(this, clr.r, clr.g, clr.b, clr.a);
	}

	inline void DrawSetTextColor(const int r, const int g, const int b, const int a) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 19u)(this, r, g, b, a);
	}

	inline void DrawSetTextPos(const int x, const int y) {
		VFunc_Get<void(__thiscall*)(void*, int, int)>(this, 20u)(this, x, y);
	}

	inline void DrawPrintText(const wchar_t* const wsz, const int nLength) {
		VFunc_Get<void(__thiscall*)(void*, const wchar_t*, int, int)>(this, 22u)(this, wsz, nLength, 0);
	}

	inline void SetCursorAlwaysVisible(const bool bState) {
		VFunc_Get<void(__thiscall*)(void*, bool)>(this, 49u)(this, bState);
	}

	inline HFont CreateFont() {
		return VFunc_Get<HFont(__thiscall*)(void*)>(this, 63u)(this);
	}

	inline void GetTextSize(const HFont hFont, const wchar_t* const wsz, int& w, int& h) {
		VFunc_Get<void(__thiscall*)(void*, HFont, const wchar_t*, int&, int&)>(this, 72u)(this, hFont, wsz, w, h);
	}

	inline void SetFontGlyphSet(const HFont hFont, const char* const szFont, const int nTall, const int nWeight, const int nFlags, const int nBlur = 0, const int nScanlines = 0) {
		VFunc_Get<void(__thiscall*)(void*, HFont, const char*, int, int, int, int, int, int, int)>(this, 64u)(this, hFont, szFont, nTall, nWeight, nBlur, nScanlines, nFlags, 0, 0);
	}

	inline void SurfaceGetCursorPos(int& x, int& y) {
		VFunc_Get<void(__thiscall*)(void*, int&, int&)>(this, 93u)(this, x, y);
	}

	inline void DrawOutlinedCircle(const int x, const int y, const int radius, const int segments) {
		VFunc_Get<void(__thiscall*)(void*, int, int, int, int)>(this, 96u)(this, x, y, radius, segments);
	}

	inline void DrawTexturedPolygon(const int n, Vertex_t* pVertice, const bool bClipVertices = true) {
		VFunc_Get<void(__thiscall*)(void*, int, Vertex_t*, bool)>(this, 99u)(this, n, pVertice, bClipVertices);
	}
};

inline ISurface* g_pSurface = nullptr;