#pragma once

#include "../../SDK/SDK.h"

class CESP
{
public:
	void Render();

private:
	bool GetStaticBounds(IClientEntity* pEntity, int& x, int& y, int& w, int& h);
};

inline CESP g_ESP;