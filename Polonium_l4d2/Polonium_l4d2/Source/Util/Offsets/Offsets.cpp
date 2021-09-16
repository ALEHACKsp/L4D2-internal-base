#include "Offsets.h"

#include "../XorString/XorString.h"

#define FAILED_TO_FIND_PATTERN 0x0

void COffsets::Initialize()
{
	m_dwGetWeaponData = g_Pattern.Find(_(L"client.dll"), _(L"0F B7 81 ? ? ? ? 50 E8 ? ? ? ? 83 C4 04 C3"));
	XASSERT(m_dwGetWeaponData == FAILED_TO_FIND_PATTERN);

	m_dwUpdateWeaponSpread = g_Pattern.Find(_(L"client.dll"), _(L"53 8B DC 83 EC 08 83 E4 F0 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 83 EC 28 56 57 8B F9 E8 ? ? ? ? 8B CF 89 45 F0 E8 ? ? ? ? 8B F0 85 F6 75 1B"));
	XASSERT(m_dwUpdateWeaponSpread == FAILED_TO_FIND_PATTERN);

	m_dwSharedRandomFloat = g_Pattern.Find(_(L"client.dll"), _(L"55 8B EC 83 EC 08 A1 ? ? ? ? 53 56 57 8B 7D 14 8D 4D 14 51 89 7D F8 89 45 FC E8 ? ? ? ? 6A 04 8D 55 FC 52 8D 45 14 50 E8 ? ? ? ? 6A 04 8D 4D F8 51 8D 55 14 52 E8 ? ? ? ? 8B 75 08 56 E8 ? ? ? ? 50 8D 45 14 56 50 E8 ? ? ? ? 8D 4D 14 51 E8 ? ? ? ? 8B 15 ? ? ? ? 8B 5D 14 83 C4 30 83 7A 30 00 74 26"));
	XASSERT(m_dwSharedRandomFloat == FAILED_TO_FIND_PATTERN);

	m_dwWeaponAlias = g_Pattern.Find(_(L"client.dll"), _(L"55 8B EC 8B 45 08 83 F8 37"));
	XASSERT(m_dwWeaponAlias == FAILED_TO_FIND_PATTERN);

	m_dwCLMove = g_Pattern.Find(_(L"engine.dll"), _(L"55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 FC 56 E8 ? ? ? ? 8B F0 83 7E 68 02 0F 8C"));
	XASSERT(m_dwCLMove == FAILED_TO_FIND_PATTERN);

	m_dwCLSendMove = g_Pattern.Find(_(L"engine.dll"), _(L"55 8B EC B8 ? ? ? ? E8 ? ? ? ? A1 ? ? ? ? 33 C5 89 45 FC 56 E8 ? ? ? ? 8D B0 ? ? ? ? E8 ? ? ? ? 8B 80 ? ? ? ? 8B 0E 8D 54 08 01 89 95 ? ? ? ? E8 ? ? ? ? 8B 80 ? ? ? ? 8B 0D ? ? ? ? 8B 11 89 85 ? ? ? ? 8B 42 20 FF D0 8B F0 89 B5 ? ? ? ? 83 FE FF 0F 84"));
	XASSERT(m_dwCLSendMove == FAILED_TO_FIND_PATTERN);

	if (const auto dwStartDrawing = g_Pattern.Find(_(L"vguimatsurface.dll"), _(L"33 C5 50 8D 45 F4 64 A3 ? ? ? ? 8B F9 80 3D")))
		m_dwStartDrawing = (dwStartDrawing - 0x1B);

	if (const auto dwFinishDrawing = g_Pattern.Find(_(L"vguimatsurface.dll"), _(L"51 56 A1 ? ? ? ? 33 C5 50 8D 45 F4 64 A3 ? ? ? ? 6A")))
		m_dwFinishDrawing = (dwFinishDrawing - 0x11);

	if (const auto dwClientMode = g_Pattern.Find(_(L"client.dll"), _(L"89 04 B5 ? ? ? ? E8")))
		m_dwClientMode = (dwClientMode + 0x3);

	if (const auto dwGlobalVars = g_Pattern.Find(_(L"client.dll"), _(L"A1 ? ? ? ? D9 40 0C 51 D9 1C 24 57")))
		m_dwGlobalVars = (dwGlobalVars + 0x1);

	if (const auto dwMoveHelper = g_Pattern.Find(_(L"client.dll"), _(L"8B 0D ? ? ? ? 8B 11 8B 52 34")))
		m_dwMoveHelper = (dwMoveHelper + 0x2);

	if (m_dwSharedRandomFloat)
		m_dwRandomSeed = (m_dwSharedRandomFloat + 0x7);

	XASSERT(m_dwRandomSeed == FAILED_TO_FIND_PATTERN);
	XASSERT(m_dwClientMode == FAILED_TO_FIND_PATTERN);
	XASSERT(m_dwGlobalVars == FAILED_TO_FIND_PATTERN);
	XASSERT(m_dwMoveHelper == FAILED_TO_FIND_PATTERN);
	XASSERT(m_dwStartDrawing == FAILED_TO_FIND_PATTERN);
	XASSERT(m_dwFinishDrawing == FAILED_TO_FIND_PATTERN);
}