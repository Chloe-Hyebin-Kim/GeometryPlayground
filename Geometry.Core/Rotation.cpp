#include "pch.h"
#include "Rotation.h"

namespace geometry
{
	double DegreeToRadian(double degree)
	{
		constexpr double pi = 3.14159265358979323846;
		return degree * pi / 180.0;
	}
}