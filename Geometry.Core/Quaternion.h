#ifndef QUATERNION_H
#define QUATERNION_H

//#include "DoubleVector.h"
//#include "DoubleMatrix.h"

namespace geocore
{
	struct  Quaternion
	{
		double f64W;
		double f64X;
		double f64Y;
		double f64Z;

		Quaternion();
		Quaternion(double w, double x, double y, double z);
		Quaternion(double w, Vec3d v);
		
		// Arithmetic
		Quaternion operator*(const Quaternion& rhs) const;
		Quaternion operator*(double scalar) const;
		Quaternion operator/(double scalar) const;

		// Properties
		double Norm() const;
		double SquaredNorm() const;
		Quaternion Normalized() const; 

		// Quaternion Operations
		Quaternion Conjugate() const;
		Quaternion Inverse() const;

		static Quaternion Identity();

		static Quaternion FromAxisAngle(const Vec3d& axis, double angleDegree);
		Mat3d ToRotationMatrix() const;
		Vec3d Rotate(const Vec3d& v) const;
		static Quaternion FromRotationMatrix(const Mat3d& R);
	};


}
#endif // QUATERNION_H