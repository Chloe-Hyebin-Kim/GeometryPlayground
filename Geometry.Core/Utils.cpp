#include "pch.h"
#include "Utils.h"

using namespace geocore;

constexpr double pi = 3.14159265358979323846;

void geocore::PrintMatrix2d(const Mat2d& m)
{
	cout << fixed << setprecision(6);
	cout << setw(12) << m[0] << setw(12) << m[1]  << '\n';
	cout << setw(12) << m[2] << setw(12) << m[3]  << '\n';
}

void geocore::PrintMatrix3d(const Mat3d& m)
{
	cout << fixed << setprecision(6);
	cout << setw(12) << m[0] << setw(12) << m[1] << setw(12) << m[2] << '\n';
	cout << setw(12) << m[3] << setw(12) << m[4] << setw(12) << m[5] << '\n';
	cout << setw(12) << m[6] << setw(12) << m[7]<< setw(12) << m[8] << '\n';
	//cout << "  " << m[0] << "  " << m[1] << "  " << m[2] << "\n";
	//cout << "  " << m[3] << "  " << m[4] << "  " << m[5] << "\n";
	//cout << "  " << m[6] << "  " << m[7] << "  " << m[8] << "\n\n";
}

void geocore::PrintMatrix4d(const Mat4d& m)
{
	cout << fixed << setprecision(6);
	cout << setw(12) << m[0] << setw(12) << m[1] << setw(12) << m[2] << setw(12) << m[3] << '\n';
	cout << setw(12) << m[4] << setw(12) << m[5] << setw(12) << m[6] << setw(12) << m[7] << '\n';
	cout << setw(12) << m[8] << setw(12) << m[9] << setw(12) << m[10] << setw(12) << m[11] << '\n';
	cout << setw(12) << m[12] << setw(12) << m[13] << setw(12) << m[14] << setw(12) << m[15] << '\n';
	//cout << "  " << m[0] << "  " << m[1] << "  " << m[2] << "\n";
	//cout << "  " << m[3] << "  " << m[4] << "  " << m[5] << "\n";
	//cout << "  " << m[6] << "  " << m[7] << "  " << m[8] << "\n\n";
}

double geocore::DegToRad(double degree)
{
	return degree * pi / 180.0;
}

double geocore::RadToDeg(double radian)
{
	return radian * 180.0 / pi;
}