#include "pch.h"
#include "Utils.h"

using namespace geocore;

constexpr double pi = 3.14159265358979323846;

double geocore::DegToRad(double degree)
{
	return degree * pi / 180.0;
}

double geocore::RadToDeg(double radian)
{
	return radian * 180.0 / pi;
}