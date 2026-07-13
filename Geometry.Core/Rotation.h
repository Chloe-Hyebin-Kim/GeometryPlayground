#pragma once

#include <Eigen/Core>

namespace geometry
{
	class Rotation
	{
	public:

		static Eigen::Matrix3d Rodrigues(const Eigen::Vector3d& axis,double angle);

		//3차원 벡터의 외적을 행렬곱으로 표현
		static Eigen::Matrix3d Skew(const Eigen::Vector3d& v);

		static bool IsRotationMatrix(const Eigen::Matrix3d& R);
	};
}