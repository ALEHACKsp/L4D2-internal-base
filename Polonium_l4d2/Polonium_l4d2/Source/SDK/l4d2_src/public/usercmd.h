#pragma once

#include "../../../Util/Math/Vector/Vector.h"

class CUserCmd
{
public:
	CUserCmd() {
		Reset();
	}

	virtual ~CUserCmd() { };

	__inline void Reset() {
		viewangles.Init();

		command_number = 0;
		tick_count = 0;
		forwardmove = 0.0f;
		sidemove = 0.0f;
		upmove = 0.0f;
		buttons = 0;
		impulse = 0;
		weaponselect = 0;
		weaponsubtype = 0;
		random_seed = 0;
		mousedx = 0;
		mousedy = 0;
		hasbeenpredicted = false;
	}

	CUserCmd& operator =(const CUserCmd& src) {
		if (this == &src)
			return *this;

		command_number = src.command_number;
		tick_count = src.tick_count;
		viewangles = src.viewangles;
		forwardmove = src.forwardmove;
		sidemove = src.sidemove;
		upmove = src.upmove;
		buttons = src.buttons;
		impulse = src.impulse;
		weaponselect = src.weaponselect;
		weaponsubtype = src.weaponsubtype;
		random_seed = src.random_seed;
		mousedx = src.mousedx;
		mousedy = src.mousedy;
		hasbeenpredicted = src.hasbeenpredicted;

		return *this;
	}

	CUserCmd(const CUserCmd& src) {
		*this = src;
	}

	inline void MakeInert() {
		viewangles.Init();

		forwardmove = 0.0f;
		sidemove = 0.0f;
		upmove = 0.0f;
		buttons = 0;
		impulse = 0;
	}

	inline void MakeViewanglesInvalid() {
		viewangles = { 22249223523413423454322345.9499621213f, 22249223532141231232143.949962143f, 0.0f };
	}

	inline void MakeTickCountInvalid() {
		tick_count = 2147483647;
	}

	int		      command_number = 0;
	int		      tick_count = 0;
	Vector	      viewangles = {  };
	float	      forwardmove = 0.0f;
	float	      sidemove = 0.0f;
	float	      upmove = 0.0f;
	int		      buttons = 0;
	unsigned char impulse = 0;
	int		      weaponselect = 0;
	int		      weaponsubtype = 0;
	int		      random_seed = 0;
	short	      mousedx = 0;
	short	      mousedy = 0;
	bool	      hasbeenpredicted = false;
};