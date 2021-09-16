#include "Draw.h"

void CDraw::Initialize()
{
	g_pEngine->GetScreenSize(m_nScreenW, m_nScreenH);

	m_mapFonts[EFont::DEBUG]      = { "Consolas",  16, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::ESP]        = { "Tahoma",    11, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::ESP_NAME]   = { "Arial",     14, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::ESP_WEAPON] = { "Verdana",   12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::TAHOMA]     = { "Tahoma",    12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::CONSOLAS]   = { "Consolas",  12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::VERDANA]    = { "Verdana",   12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::ARIAL]      = { "Arial",     12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_mapFonts[EFont::MENU_TAB]   = { "Verdana",   30, FW_HEAVY   , EFontFlags::FONTFLAG_OUTLINE | EFontFlags::FONTFLAG_ANTIALIAS };

	for (auto& font : m_mapFonts)
	{
		if (font.second.m_hFont == 0)
			font.second.m_hFont = g_pSurface->CreateFont();

		g_pSurface->SetFontGlyphSet(font.second.m_hFont, font.second.m_szName, font.second.m_nHeight, font.second.m_nWeight, font.second.m_nFlags);
	}
}

int CDraw::GetFontHeight(const EFont fnt)
{
	return m_mapFonts[fnt].m_nHeight;
}

void CDraw::String(const EFont& font, int x, int y, const Color_t clr, const short align, const char* const str, ...)
{
	va_list va_alist;
	char cbuffer[1024] = { '\0' };
	wchar_t wstr[1024] = { '\0' };

	va_start(va_alist, str);
	vsprintf_s(cbuffer, str, va_alist);
	va_end(va_alist);

	wsprintfW(wstr, _(L"%hs"), cbuffer);

	if (align)
	{
		int w = 0, h = 0;
		g_pSurface->GetTextSize(m_mapFonts[font].m_hFont, wstr, w, h);

		if (align & TXT_LEFT)
			x -= w;

		if (align & TXT_TOP)
			y -= h;

		if (align & TXT_CENTERX)
			x -= (w / 2);

		if (align & TXT_CENTERY)
			y -= (h / 2);
	}

	g_pSurface->DrawSetTextPos(x, y);
	g_pSurface->DrawSetTextFont(m_mapFonts[font].m_hFont);
	g_pSurface->DrawSetTextColor(clr);
	g_pSurface->DrawPrintText(wstr, wcslen(wstr));
}

void CDraw::String(const EFont& font, int x, int y, const Color_t clr, const short align, const wchar_t* const str, ...)
{
	va_list va_alist;
	wchar_t wstr[1024] = { '\0' };

	va_start(va_alist, str);
	vswprintf_s(wstr, str, va_alist);
	va_end(va_alist);

	if (align)
	{
		int w = 0, h = 0;
		g_pSurface->GetTextSize(m_mapFonts[font].m_hFont, wstr, w, h);

		if (align & TXT_LEFT)
			x -= w;

		if (align & TXT_TOP)
			y -= h;

		if (align & TXT_CENTERX)
			x -= (w / 2);

		if (align & TXT_CENTERY)
			y -= (h / 2);
	}

	g_pSurface->DrawSetTextPos(x, y);
	g_pSurface->DrawSetTextFont(m_mapFonts[font].m_hFont);
	g_pSurface->DrawSetTextColor(clr);
	g_pSurface->DrawPrintText(wstr, wcslen(wstr));
}

void CDraw::OutlinedRect(const int x, const int y, const int w, const int h, const Color_t clr)
{
	g_pSurface->DrawSetColor(clr);
	g_pSurface->DrawOutlinedRect(x, y, w, h);
}

void CDraw::OutlinedCircle(const int x, const int y, const int radius, const int segments, const Color_t clr)
{
	g_pSurface->DrawSetColor(clr);
	g_pSurface->DrawOutlinedCircle(x, y, radius, segments);
}

void CDraw::Rect(const int x, const int y, const int w, const int h, const Color_t clr)
{
	g_pSurface->DrawSetColor(clr);
	g_pSurface->DrawFilledRect(x, y, w, h);
}

void CDraw::Circle(const int x, const int y, const int radius, const int segments, const Color_t clr)
{
	std::vector<Vertex_t> vecVertices = { };

	const float flStep = (6.28318530718f / static_cast<float>(segments));

	for (float n = 0.0f; n < 6.28318530718f; n += flStep)
		vecVertices.push_back(Vertex_t({ (static_cast<float>(radius) * cosf(n) + x), (static_cast<float>(radius) * sinf(n) + y) }));

	if (!vecVertices.empty())
	{
		g_pSurface->DrawSetColor(clr);
		g_pSurface->DrawTexturedPolygon(segments, vecVertices.data());
	}
}

void CDraw::Line(const int x0, const int y0, const int x1, const int y1, const Color_t clr)
{
	g_pSurface->DrawSetColor(clr);
	g_pSurface->DrawLine(x0, y0, x1, y1);
}