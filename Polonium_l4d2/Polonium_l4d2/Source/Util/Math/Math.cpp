#include "Math.h"

void CMath::SinCos(const float r, float& s, float& c)
{
	s = sin(r);
	c = cos(r);
}

void CMath::ClampAngles(Vector& v)
{
	v.x = Max<float>(-89.0f, Min<float>(89.0f, NormalizeAngle(v.x)));
	v.y = NormalizeAngle(v.y);
	v.z = 0.0f;
}

void CMath::AngleVectors(const Vector& angles, Vector* forward)
{
	float sp, sy, cp, cy;

	SinCos(DEG2RAD(angles.x), sp, cp);
	SinCos(DEG2RAD(angles.y), sy, cy);

	if (forward)
	{
		forward->x = cp * cy;
		forward->y = cp * sy;
		forward->z = -sp;
	}
}

void CMath::VectorTransform(const Vector& input, const matrix3x4_t& matrix, Vector& output)
{
	for (auto i = 0; i < 3; i++)
		output[i] = input.Dot((Vector&)matrix[i]) + matrix[i][3];
}

void CMath::VectorAngles(const Vector& forward, Vector& angles)
{
	float tmp, yaw, pitch;

	if (forward.y == 0 && forward.x == 0)
	{
		yaw = 0;

		if (forward.z > 0)
			pitch = 270;
		else
			pitch = 90;
	}
	else
	{
		yaw = RAD2DEG(atan2f(forward.y, forward.x));

		if (yaw < 0)
			yaw += 360;

		tmp = forward.Lenght2D();
		pitch = RAD2DEG(atan2f(-forward.z, tmp));

		if (pitch < 0)
			pitch += 360;
	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

float CMath::NormalizeAngle(const float ang)
{
	if (!std::isfinite(ang))
		return 0.0f;

	return std::remainder(ang, 360.0f);
}

float CMath::CalcFov(const Vector& src, const Vector& dst)
{
	Vector v_src;
	AngleVectors(src, &v_src);

	Vector v_dst;
	AngleVectors(dst, &v_dst);

	float result = RAD2DEG(acos(v_dst.Dot(v_src) / v_dst.LenghtSqr()));

	if (!isfinite(result) || isinf(result) || isnan(result))
		result = 0.0f;

	return result;
}

float CMath::RemapValClamped(const float val, const float A, const float B, const float C, const float D)
{
	if (A == B)
		return val >= B ? D : C;

	float flVal = (val - A) / (B - A);
	flVal = Clamp<float>(flVal, 0.0f, 1.0f);

	return C + (D - C) * flVal;
}

Vector CMath::CalcAngle(const Vector& source, const Vector& destination)
{
	const Vector delta = (source - destination);
	const float fHyp = sqrtf((delta.x * delta.x) + (delta.y * delta.y));

	Vector angles = { (atanf(delta.z / fHyp) * M_RADPI), (atanf(delta.y / delta.x) * M_RADPI), 0.0f };

	if (delta.x >= 0.0f)
		angles.y += 180.0f;

	return angles;
}