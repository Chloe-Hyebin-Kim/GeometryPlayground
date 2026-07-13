#include "pch.h"
#include "Transform.h"

using namespace geocore;

Eigen::Matrix4d geocore::Transform::Identity()
{
	return Eigen::Matrix4d();
}

Eigen::Matrix4d geocore::Transform::Translate(const Eigen::Vector3d& t)
{
	/////////////////////
	//	[ 1  0  0  tx ]
	//	[ 0  1  0  ty ]
	//	[ 0  0  1  tz ]
	//	[ 0  0  0   1 ]
	/////////////////////

	Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
	//T.block<3, 1>(0, 3) = t;

	//T(0, 3) = t.x();
	//T(1, 3) = t.y();
	//T(2, 3) = t.z();

	T<< 1.0, 0.0, 0.0, t.x(),
		0.0, 1.0, 0.0, t.y(),
		0.0, 0.0, 1.0, t.z(),
		0.0, 0.0, 0.0, 1.0;

	return T;
}

Eigen::Matrix4d geocore::Transform::Rotate(const Eigen::Matrix3d& R)
{
	/////////////////////
	//	[R11 R12 R13 0]
	//	[R21 R22 R23 0]
	//	[R31 R32 R33 0]
	//	[ 0   0   0  1]
	/////////////////////

	Eigen::Matrix4d R4d = Eigen::Matrix4d::Identity();
	//R4d.block<3, 3>(0, 0) = R;

	R4d <<  R(0, 0), R(0, 1), R(0, 2), 0.0,
			R(1, 0), R(1, 1), R(1, 2), 0.0,
			R(2, 0), R(2, 1), R(2, 2), 0.0,
			0.0,	 0.0,	  0.0,	   1.0;

	return R4d;
}

Eigen::Matrix4d geocore::Transform::FromRotationTranslation(const Eigen::Matrix3d& R, const Eigen::Vector3d& t)
{
	/////////////////////
	// Transformation Matrix(SE(3))
	// [R11 R12 R13 tx]
	// [R21 R22 R23 ty]
	// [R31 R32 R33 tz]
	// [ 0   0   0  1 ]
	/////////////////////

	Eigen::Matrix4d Compo = Eigen::Matrix4d::Identity();


	return Compo;
}

Eigen::Matrix4d geocore::Transform::Inverse(const Eigen::Matrix4d& T)
{

	Eigen::Matrix4d InverseMatrix = Eigen::Matrix4d::Identity();


	return InverseMatrix;
}
