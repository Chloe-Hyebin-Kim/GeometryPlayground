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

	};


}
#endif // QUATERNION_H