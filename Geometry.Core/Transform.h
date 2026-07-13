#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <Eigen/Core>

namespace geocore
{
	class Transform
	{
	public:

		static Eigen::Matrix4d Identity();
		static Eigen::Matrix4d Translate(const Eigen::Vector3d& t);
		static Eigen::Matrix4d Rotate(const Eigen::Matrix3d& R);
		static Eigen::Matrix4d FromRotationTranslation(const Eigen::Matrix3d& R, const Eigen::Vector3d& t);
		static Eigen::Matrix4d Inverse(const Eigen::Matrix4d& T);
	};
}

#endif //  TRANSFORM_H