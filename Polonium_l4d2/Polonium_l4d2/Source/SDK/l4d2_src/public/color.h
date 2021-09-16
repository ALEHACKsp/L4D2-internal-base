#pragma once

struct Color_t
{
	Color_t() {
		r = g = b = a = 0u;
	}

	Color_t(const int nr, const int ng, const int nb, const int na = 255) {
		r = nr;
		g = ng;
		b = nb;
		a = na;
	}

	Color_t(const Color_t& clr) {
		r = clr.r;
		g = clr.g;
		b = clr.b;
		a = clr.a;
	}

	unsigned char r = 0u;
	unsigned char g = 0u;
	unsigned char b = 0u;
	unsigned char a = 0u;
};