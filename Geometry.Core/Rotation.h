#ifndef ROTATION_H
#define ROTATION_H

#include <Eigen/Core>

namespace geocore
{
	Eigen::Matrix3d Rodrigues(const Eigen::Vector3d& axis,double angle);

	//3차원 벡터의 외적을 행렬곱으로 표현
	Eigen::Matrix3d Skew(const Eigen::Vector3d& v);

	bool IsRotationMatrix(const Eigen::Matrix3d& R);

}
#endif //  ROTATION_H