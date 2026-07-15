#include "pch.h"
#include "Quaternion.h"

using namespace geocore;

geocore::Quaternion::Quaternion()
{
	f64W = 1.0;
	f64X = 0.0;
	f64Y = 0.0;
	f64Z = 0.0;
}

geocore::Quaternion::Quaternion(double w, double x, double y, double z)
{
	f64W = w;
	f64X = x;
	f64Y = y;
	f64Z = z;
}

Quaternion geocore::Quaternion::operator*(double scalar) const
{

	return Quaternion(f64W * scalar, f64X * scalar, f64Y * scalar, f64Z * scalar);
}

Quaternion geocore::Quaternion::operator/(double scalar) const
{
	if (std::abs(scalar) < 1e-12)	{
		throw std::runtime_error("Quaternion division by zero.");
	}

	return Quaternion(f64W / scalar, f64X / scalar, f64Y / scalar, f64Z / scalar);
}

double geocore::Quaternion::Norm() const
{
	return sqrt((f64W * f64W) + (f64X * f64X) + (f64Y * f64Y) + (f64Z * f64Z));
}

double geocore::Quaternion::SquaredNorm() const
{
	return (f64W * f64W) + (f64X * f64X) + (f64Y * f64Y) + (f64Z * f64Z);
}

Quaternion geocore::Quaternion::Normalized() const
{
	const double norm = Norm();

	if (norm < 1e-12)	{
		throw std::runtime_error("Cannot normalize zero quaternion.");
	}

	return (*this) / norm;
}

Quaternion geocore::Quaternion::Conjugate() const
{
	return Quaternion(f64W, -f64X, -f64Y, -f64Z);
}

Quaternion geocore::Quaternion::Inverse() const
{
	return Conjugate() / SquaredNorm(); 
}
