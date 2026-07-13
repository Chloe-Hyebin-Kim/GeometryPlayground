#include "pch.h"
#include "Rotation.h"

#include <cmath>

using namespace geometry;

Eigen::Matrix3d Rotation::Rodrigues(const Eigen::Vector3d& axis, double angle)
{
	//Matrix3d R = Matrix3d::Identity() + sin(angle) * K + (1 - cos(angle)) * K * K;
	
	if (axis.norm() < 1e-12)
	{
		return Eigen::Matrix3d::Identity();
	}

	Eigen::Vector3d normalizedAxis = axis.normalized();
	Eigen::Matrix3d K = Skew(normalizedAxis);
	Eigen::Matrix3d R = Eigen::Matrix3d::Identity() + sin(angle) * K + (1.0 - cos(angle)) * K * K;

	return R;
}


Eigen::Matrix3d Rotation::Skew(const Eigen::Vector3d& v)
{
//a.cross(b) == Skew(a) * b 3차원 벡터 외적을 행렬곱으로 표현
//      ┌                 ┐
//      │  0   -az   ay   │
//K(a)= │ az    0   -ax   │
//      │-ay   ax    0    │
//      └                 ┘
	Eigen::Matrix3d K;

	K << 0.0, -v.z(), v.y(),
		 v.z(), 0.0, -v.x(),
		-v.y(), v.x(), 0.0;

	return K;
}

bool Rotation::IsRotationMatrix(const Eigen::Matrix3d& R)
{
	Eigen::Matrix3d identity = Eigen::Matrix3d::Identity();

	Eigen::Matrix3d result = R.transpose() * R;

	bool orthogonal = result.isApprox(identity, 1e-9);

	bool determinant = abs(R.determinant() - 1.0) < 1e-9;

	return orthogonal && determinant;

}
