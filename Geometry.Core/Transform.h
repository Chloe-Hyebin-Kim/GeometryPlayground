#ifndef TRANSFORM_H
#define TRANSFORM_H

//#include <Eigen/Core>

namespace geocore
{
	class Transform
	{
	public:

		static Mat4d Identity();
		static Mat4d Translate(const Vec3d& t);
		static Mat4d Rotate(const Mat3d& R);
		static Mat4d FromRotationTranslation(const Mat3d& R, const Vec3d& t);
		static Mat4d Inverse(const Mat4d& T);
	};
}

#endif //  TRANSFORM_H