#ifndef UTILS_H
#define UTILS_H

//#pragma once

#include "DoubleVector.h"
#include "DoubleMatrix.h"

namespace geocore
{
	void PrintMatrix2d(const geocore::Mat2d& m);
	void PrintMatrix3d(const geocore::Mat3d& m);
	void PrintMatrix4d(const geocore::Mat4d& m);

	double DegToRad(double degree);
	double RadToDeg(double radian);
}

#endif // UTILS_H