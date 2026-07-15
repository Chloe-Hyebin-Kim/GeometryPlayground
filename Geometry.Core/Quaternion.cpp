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

Quaternion geocore::Quaternion::operator*(const Quaternion& rhs) const
{
	//////////////////////////////////////////////////////
	// Hamilton Product : q1 * q2 = (w1 + x1i + y1j + z1k) * (w2 + x2i + y2j + z2k) = (w1, v1) * (w2, v2)
	// 
	// ½Ç¼öºÎ(w) = ½Ç¼öºÎ³¢¸® - º¤ÅÍ ³»Àû
	// º¤ÅÍºÎ(v) = (½ºÄ®¶ó*º¤ÅÍ) + (½ºÄ®¶ó*º¤ÅÍ) + º¤ÅÍ ¿ÜÀû
	//
	// w =  w1w2 - x1x2 - y1y2 - z1z2
	// x =  w1x2 + x1w2 + y1z2 - z1y2
	// y =  w1y2 - x1z2 + y1w2 + z1x2
	// z =  w1z2 + x1y2 - y1x2 + z1w2
	//////////////////////////////////////////////////////
	return Quaternion(
		f64W * rhs.f64W
		- f64X * rhs.f64X
		- f64Y * rhs.f64Y
		- f64Z * rhs.f64Z,

		f64W * rhs.f64X
		+ f64X * rhs.f64W
		+ f64Y * rhs.f64Z
		- f64Z * rhs.f64Y,

		f64W * rhs.f64Y
		- f64X * rhs.f64Z
		+ f64Y * rhs.f64W
		+ f64Z * rhs.f64X,

		f64W * rhs.f64Z
		+ f64X * rhs.f64Y
		- f64Y * rhs.f64X
		+ f64Z * rhs.f64W
	);
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
