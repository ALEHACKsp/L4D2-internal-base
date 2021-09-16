#pragma once

namespace Vars
{
	void Load();
	void Save();

	namespace ESP
	{
		inline bool Enabled = true;

		inline bool Players = true;
		inline bool Infected = true;
		inline bool Specials = true;
		inline bool Tanks = true;
		inline bool Witches = true;
		inline bool Weapons = true;
		inline bool Ammo = true;
	}

	namespace Misc
	{
		inline bool Bunnyhop = true;
		inline bool AutoJockeyTeleport = true;

		inline bool NoRecoil = true;
		inline bool NoSpread = true;
	}
}