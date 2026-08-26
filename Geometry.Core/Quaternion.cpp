#include "pch.h"
#include "Quaternion.h"
#include "Utils.h"

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

geocore::Quaternion::Quaternion(double w, Vec3d v)
{
	f64W = w;
	f64X = v.f64X;
	f64Y = v.f64Y;
	f64Z = v.f64Z;
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
	//ÄÓ·¹ 
	return Quaternion(f64W, -f64X, -f64Y, -f64Z);
}

Quaternion geocore::Quaternion::Inverse() const
{
	return Conjugate() / SquaredNorm(); 
}

Quaternion Quaternion::Identity()
{
	return Quaternion(1.0, 0.0, 0.0, 0.0);
}

Vec3d geocore::Quaternion::Rotate(const Vec3d& v) const
{
	Quaternion p(0.0,v);
	Quaternion result =(*this)*p*Inverse();

	return Vec3d(result.f64X, result.f64Y, result.f64Z);
}

Mat3d geocore::Quaternion::ToRotationMatrix() const
{
	//		[1 - 2(y©÷ + z©÷)		2(xy - wz)		2(xz + wy)]
	//R =	[2(xy + wz)		1 - 2(x©÷ + z©÷)		2(yz - wx)]
	//		[2(xz - wy)		2(yz + wx)		1 - 2(x©÷ + y©÷)]


	return Mat3d();
}


Quaternion geocore::Quaternion::FromAxisAngle(const Vec3d& axis, double angleDegree)
{
	// axis : È¸ÀüÃà (´ÜÀ§º¤ÅÍ)
	// angle : degree
	// q = ( cos(theta/2),  axis*sin(theta/2) )

	Vec3d n = axis.Normalized();
	double rad = geocore::DegToRad(angleDegree);
	double half = rad * 0.5;

	return Quaternion(cos(half), axis* sin(half) );
}

Quaternion geocore::Quaternion::FromRotationMatrix(const Mat3d& R)
{
//trace = R00 + R11 + R22


	return Quaternion();
}
