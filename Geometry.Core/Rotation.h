#ifndef ROTATION_H
#define ROTATION_H

//#include <Eigen/Core>

namespace geocore
{
	Mat3d Rodrigues(const Vec3d& axis,double angle);

	//3차원 벡터의 외적을 행렬곱으로 표현
	Mat3d Skew(const Vec3d& v);

	bool IsRotationMatrix(const Mat3d& R);

}
#endif //  ROTATION_H