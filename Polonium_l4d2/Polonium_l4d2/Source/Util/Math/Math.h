#pragma once

#include <cmath>
#include <cfloat>

#include "Vector/Vector.h"

using matrix3x4_t = float[3][4];

class CMath
{
public:
	void SinCos(const float r, float& s, float& c);
	void ClampAngles(Vector& v);
	void AngleVectors(const Vector& angles, Vector* forward);
	void VectorTransform(const Vector& input, const matrix3x4_t& matrix, Vector& output);
	void VectorAngles(const Vector& forward, Vector& angles);

	float NormalizeAngle(const float ang);
	float CalcFov(const Vector& src, const Vector& dst);
	float RemapValClamped(const float val, const float A, const float B, const float C, const float D);

	Vector CalcAngle(const Vector& source, const Vector& destination);

public:
	template<typename T>
	inline T Clamp(T const& val, T const& minVal, T const& maxVal) {
		if (val < minVal)
			return minVal;
		else if (val > maxVal)
			return maxVal;
		else
			return val;
	}

	template<typename T>
	inline T Min(T const& val1, T const& val2) {
		return val1 < val2 ? val1 : val2;
	}

	template<typename T>
	inline T Max(T const& val1, T const& val2) {
		return val1 > val2 ? val1 : val2;
	}
};

inline CMath g_Math;