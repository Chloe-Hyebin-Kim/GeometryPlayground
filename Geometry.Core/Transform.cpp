#include "pch.h"
#include "Transform.h"

using namespace geocore;

Mat4d geocore::Transform::Identity()
{
	return Mat4d::Identity();
}

Mat4d geocore::Transform::Translate(const Vec3d& t)
{
	/////////////////////
	//	[ 1  0  0  tx ]
	//	[ 0  1  0  ty ]
	//	[ 0  0  1  tz ]
	//	[ 0  0  0   1 ]
	/////////////////////

	Mat4d T = Mat4d::Identity();
	
	T(0, 3) = t.f64X;
	T(1, 3) = t.f64Y;
	T(2, 3) = t.f64Z;

	return T;
}

Mat4d geocore::Transform::Rotate(const Mat3d& R)
{
	/////////////////////
	//	[R11 R12 R13 0]
	//	[R21 R22 R23 0]
	//	[R31 R32 R33 0]
	//	[ 0   0   0  1]
	/////////////////////

	//Mat4d R4d = Mat4d::Identity();
	//R4d.block<3, 3>(0, 0) = R;
	//return R4d;
	
	return Mat4d(  R(0, 0), R(0, 1), R(0, 2), 0.0,
				   R(1, 0), R(1, 1), R(1, 2), 0.0,
				   R(2, 0), R(2, 1), R(2, 2), 0.0,
				   0.0,		 0.0,	  0.0,	  1.0);
}

Mat4d geocore::Transform::FromRotationTranslation(const Mat3d& R, const Vec3d& t)
{
	/////////////////////
	// Transformation Matrix(SE(3))
	// [R11 R12 R13 tx]
	// [R21 R22 R23 ty]
	// [R31 R32 R33 tz]
	// [ 0   0   0  1 ]
	/////////////////////

	return Mat4d(
		R(0, 0), R(0, 1), R(0, 2), t.f64X,
		R(1, 0), R(1, 1), R(1, 2), t.f64Y,
		R(2, 0), R(2, 1), R(2, 2), t.f64Z,
			0.0,	0.0,	0.0,	1.0);
}

Mat4d geocore::Transform::Inverse(const Mat4d& T)
{
//////////////////////////////////////////////////////
//      [ R11 R12 R13 tx ]
//  T = [ R21 R22 R23 ty ]
//      [ R31 R32 R33 tz ]
//      [  0   0   0   1 ]
//
//       [ R^T   -R^T t ]
// T^-1 =[              ]
//       [  0       1   ]
//
//		[ R11 R21 R31 ]
// R^T =[ R12 R22 R32 ]
//		[ R13 R23 R33 ]
//
//			[ -(R11*tx + R21*ty + R31*tz) ]
//	-R^T t =[ -(R12*tx + R22*ty + R32*tz) ]
//			[ -(R13*tx + R23*ty + R33*tz) ]
//////////////////////////////////////////////////////

	Mat3d R(
		T(0, 0), T(0, 1), T(0, 2),
		T(1, 0), T(1, 1), T(1, 2),
		T(2, 0), T(2, 1), T(2, 2));

	Vec3d t(T(0, 3),T(1, 3),T(2, 3));

	Mat3d Rt = R.Transpose();
	Vec3d inverseTranslation = Rt * (t * -1.0);
	Mat4d inverseMatrix = FromRotationTranslation(Rt, inverseTranslation);
	return inverseMatrix;
}