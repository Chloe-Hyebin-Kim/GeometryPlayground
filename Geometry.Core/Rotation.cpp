#include "pch.h"
#include "Rotation.h"


#include "Utils.h"
using namespace geocore;

//using Mat3d;
//using Vec3d;
//using Vector2d;


Mat3d geocore::Rodrigues(const Vec3d& axis, double angle)
{
	//Mat3d R = Mat3d::Identity() +  K *sin(angle) + K * K *(1 - cos(angle));
	double radian = geocore::DegToRad(angle);
	Mat3d I = Mat3d::Identity();
	if (axis.Norm() < 1e-12)	{
		return I;
	}

	Vec3d normalizedAxis = axis.Normalized();
	Mat3d K = Skew(normalizedAxis);
	Mat3d R = I + K * sin(radian) + K * K * (1.0 - cos(radian));

	return R;
}


Mat3d geocore::Skew(const Vec3d& v)
{
//	a.cross(b) == Skew(a) * b 3차원 벡터 외적을 행렬곱으로 표현
//	SkewSymmetric Matrix
//
//      [ 0    -az   ay ]
//K(a)= [ az    0   -ax ]
//      [ -ay   ax   0  ]

	return Mat3d(0.0, -v.f64Z, v.f64Y,
				v.f64Z, 0.0, -v.f64X,
				-v.f64Y, v.f64X, 0.0);
}

bool geocore::IsRotationMatrix(const Mat3d& R)
{
	Mat3d identity = Mat3d::Identity();
	Mat3d result = R.Transpose() * R;
	bool bOrthogonal = result.IsApprox(identity, 1e-9);
	bool bDdeterminant = abs(R.Determinant() - 1.0) < 1e-9;

	return bOrthogonal && bDdeterminant;

}
