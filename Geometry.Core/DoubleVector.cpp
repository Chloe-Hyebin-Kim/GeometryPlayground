#include "pch.h"
#include "DoubleVector.h"

using namespace geocore;


#pragma region Vector2d

Vec2d::Vec2d() : f64X(0.0), f64Y(0.0)
{
}

Vec2d::Vec2d(double x, double y) : f64X(x), f64Y(y)
{
}

Vec2d Vec2d::operator+(const Vec2d& rhs) const
{
	return Vec2d(f64X + rhs.f64X, f64Y + rhs.f64Y);
}

Vec2d Vec2d::operator-(const Vec2d& rhs) const
{
	return Vec2d(f64X - rhs.f64X, f64Y - rhs.f64Y);
}

Vec2d Vec2d::operator*(double scalar) const
{
	return Vec2d(f64X * scalar, f64Y * scalar);
}

Vec2d Vec2d::operator/(double scalar) const
{
	if (abs(scalar) < 1e-12)
	{
		//return Vec2d();
		throw invalid_argument("Vec2d division by zero.");
	}

	return Vec2d(f64X / scalar, f64Y / scalar);
}

Vec2d Vec2d::operator+=(const Vec2d& rhs)
{
	f64X += rhs.f64X;
	f64Y += rhs.f64Y;

	return Vec2d();
}

Vec2d Vec2d::operator-=(const Vec2d& rhs)
{
	f64X -= rhs.f64X;
	f64Y -= rhs.f64Y;

	return Vec2d();
}

double Vec2d::Dot(const Vec2d& rhs) const
{
	return f64X * rhs.f64X + f64Y * rhs.f64Y;
}

double Vec2d::SquaredNorm() const
{
	return f64X * f64X + f64Y* f64Y;
}

double Vec2d::Norm() const
{
	return sqrt(Vec2d::SquaredNorm());
}

Vec2d Vec2d::Normalized() const
{
	const double f64Norm = Vec2d::Norm();

	if (f64Norm < 1e-12)
	{
		throw runtime_error("Cannot normalize a zero Vec2d.");
	}

	return *this / f64Norm;

	return Vec2d();
}

bool Vec2d::IsApprox(const Vec2d& rhs, double tolerance) const
{
	return abs(f64X - rhs.f64X) <= tolerance
		&& abs(f64Y - rhs.f64Y) <= tolerance;
}

#pragma endregion Vector2d

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region Vector3d

Vec3d::Vec3d() : f64X(0.0), f64Y(0.0), f64Z(0.0)
{
}

Vec3d::Vec3d(double x, double y, double z) : f64X(x), f64Y(y), f64Z(z)
{
}

Vec3d Vec3d::operator+(const Vec3d& rhs) const
{
	return Vec3d(f64X + rhs.f64X, f64Y + rhs.f64Y, f64Z + rhs.f64Z);
}

Vec3d Vec3d::operator-(const Vec3d& rhs) const
{
	return Vec3d(f64X - rhs.f64X, f64Y - rhs.f64Y, f64Z - rhs.f64Z);
}

Vec3d Vec3d::operator*(double scalar) const
{
	return Vec3d(f64X * scalar, f64Y * scalar, f64Z * scalar);
}

Vec3d Vec3d::operator/(double scalar) const
{
	if (abs(scalar) < 1e-12)
	{
		//return Vec3d();
		throw invalid_argument("Vec3d division by zero.");
	}

	return Vec3d(f64X / scalar, f64Y / scalar, f64Z / scalar);
}

Vec3d Vec3d::operator+=(const Vec3d& rhs)
{
	f64X += rhs.f64X;
	f64Y += rhs.f64Y;
	f64Z += rhs.f64Z;

	return Vec3d();
}

Vec3d Vec3d::operator-=(const Vec3d& rhs)
{
	f64X -= rhs.f64X;
	f64Y -= rhs.f64Y;
	f64Z -= rhs.f64Z;

	return Vec3d();
}

double Vec3d::Dot(const Vec3d& rhs) const
{
	return f64X * rhs.f64X + f64Y * rhs.f64Y + f64Z*rhs.f64Z;
}

double Vec3d::SquaredNorm() const
{
	return f64X * f64X + f64Y * f64Y + f64Z* f64Z;
}

double Vec3d::Norm() const
{
	return sqrt(Vec3d::SquaredNorm());
}

Vec3d Vec3d::Normalized() const
{
	const double f64Norm = Vec3d::Norm();

	if (f64Norm < 1e-12)
	{
		throw runtime_error("Cannot normalize a zero Vec3d.");
	}

	return *this / f64Norm;

	return Vec3d();
}

bool Vec3d::IsApprox(const Vec3d& rhs, double tolerance) const
{
	return abs(f64X - rhs.f64X) <= tolerance
		&& abs(f64Y - rhs.f64Y) <= tolerance
		&& abs(f64Z - rhs.f64Z) <= tolerance;
}
#pragma endregion Vector3d