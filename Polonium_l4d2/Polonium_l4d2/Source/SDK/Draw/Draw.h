#pragma once

#include "../l4d2_src/l4d2_src.h"
#include "../../Util/Util.h"

#ifdef CreateFont
#undef CreateFont
#endif

enum class EFont
{
	DEBUG,
	ESP,
	ESP_NAME,
	ESP_WEAPON,
	TAHOMA,
	VERDANA,
	ARIAL,
	CONSOLAS,
	MENU_TAB
};

struct FontInfo_t
{
	const char* m_szName  = nullptr;
	int         m_nHeight = 0;
	int         m_nWeight = 0;
	int         m_nFlags  = FONTFLAG_NONE;
	HFont       m_hFont   = 0;
};

class CDraw
{
public:
	void Initialize();
	int GetFontHeight(const EFont fnt);

public:
	void String(const EFont& font, int x, int y, const Color_t clr, const short align, const char* const str, ...);
	void String(const EFont& font, int x, int y, const Color_t clr, const short align, const wchar_t* const str, ...);
	void OutlinedRect(const int x, const int y, const int w, const int h, const Color_t clr);
	void OutlinedCircle(const int x, const int y, const int radius, const int segments, const Color_t clr);
	void Rect(const int x, const int y, const int w, const int h, const Color_t clr);
	void Circle(const int x, const int y, const int radius, const int segments, const Color_t clr);
	void Line(const int x0, const int y0, const int x1, const int y1, const Color_t clr);

public:
	std::map<EFont, FontInfo_t> m_mapFonts = { };

	int m_nScreenW = 0, m_nScreenH = 0;
};

#define TXT_DEFAULT		(1 << 0)
#define TXT_LEFT		(1 << 1)
#define TXT_TOP			(1 << 2)
#define TXT_CENTERX		(1 << 3)
#define TXT_CENTERY		(1 << 4)
#define TXT_CENTERXY	TXT_CENTERX | TXT_CENTERY

inline CDraw g_Draw;