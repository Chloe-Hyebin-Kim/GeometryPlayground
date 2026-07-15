#include "pch.h"
#include "DoubleMatrix.h"

#include "DoubleVector.h"
using namespace geocore;

#pragma region Mat2d

geocore::Mat2d::Mat2d()
{
	m[0] = 0.0;
	m[1] = 0.0;
	m[2] = 0.0;
	m[3] = 0.0;
}

geocore::Mat2d::Mat2d(double m00, double m01, double m10, double m11)
{
	m[0] = m00;
	m[1] = m01;
	m[2] = m10;
	m[3] = m11;
}

double& geocore::Mat2d::operator[](int index)
{
	return m[index];
}

double& geocore::Mat2d::operator()(int row, int col)
{
	return m[row*2 + col];
}

const double& geocore::Mat2d::operator[](int index) const
{
	return m[index];
}

const double& geocore::Mat2d::operator()(int row, int col) const
{
	return m[row * 2 + col];
}

Mat2d geocore::Mat2d::operator=(const Mat2d& rhs) const
{
	Mat2d result;
	result.m[0] = m[0] + rhs.m[0];
	result.m[1] = m[1] + rhs.m[1];
	result.m[2] = m[2] + rhs.m[2];
	result.m[3] = m[3] + rhs.m[3];


	return result;
}

Mat2d geocore::Mat2d::operator+(const Mat2d& rhs) const
{
	Mat2d result;

	result.m[0] = m[0] + rhs.m[0];
	result.m[1] = m[1] + rhs.m[1];
	result.m[2] = m[2] + rhs.m[2];
	result.m[3] = m[3] + rhs.m[3];

	return result;

	//return Mat2d(m[0] + rhs.m[0], m[1] + rhs.m[1], m[2] + rhs.m[2], m[3] + rhs.m[3]);
}

Mat2d geocore::Mat2d::operator-(const Mat2d& rhs) const
{
	Mat2d result;

	result.m[0] = m[0] - rhs.m[0];
	result.m[1] = m[1] - rhs.m[1];
	result.m[2] = m[2] - rhs.m[2];
	result.m[3] = m[3] - rhs.m[3];

	return result;
	//return Mat2d(m[0] - rhs.m[0], m[1] - rhs.m[1], m[2] - rhs.m[2], m[3] - rhs.m[3]);
}

Mat2d geocore::Mat2d::operator*(double scalar) const
{
	Mat2d result;

	result.m[0] = m[0] * scalar;
	result.m[1] = m[1] * scalar;
	result.m[2] = m[2] * scalar;
	result.m[3] = m[3] * scalar;

	return result;
	//return Mat2d(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);

}

Mat2d geocore::Mat2d::operator/(double scalar) const
{
	if (abs(scalar) < 1e-12)	{
		throw runtime_error("Mat2d division by zero.");
	}

	Mat2d result;

	result.m[0] = m[0] / scalar;
	result.m[1] = m[1] / scalar;
	result.m[2] = m[2] / scalar;
	result.m[3] = m[3] / scalar;

	return result;
	//return Mat2d(m[0] / scalar, m[1] / scalar, m[2] / scalar, m[3] / scalar);
}

Mat2d geocore::Mat2d::operator*(const Mat2d& rhs) const
{
	Mat2d result;

	result(0, 0) = (*this)(0, 0) * rhs(0, 0) + (*this)(0, 1) * rhs(1, 0);
	result(0, 1) = (*this)(0, 0) * rhs(0, 1) + (*this)(0, 1) * rhs(1, 1);
	result(1, 0) = (*this)(1, 0) * rhs(0, 0) + (*this)(1, 1) * rhs(1, 0);
	result(1, 1) = (*this)(1, 0) * rhs(0, 1) + (*this)(1, 1) * rhs(1, 1);

	return result;
}

bool geocore::Mat2d::IsApprox(const Mat2d& rhs, double tolerance) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (abs(m[i] - rhs.m[i]) > tolerance)
		{
			return false;
		}
	}

	return true;
}

Mat2d geocore::Mat2d::Transpose() const
{
	Mat2d result;

	result(0, 0) = (*this)(0, 0);
	result(0, 1) = (*this)(1, 0);
	result(1, 0) = (*this)(0, 1);
	result(1, 1) = (*this)(1, 1);

	return result;
}

Mat2d geocore::Mat2d::Identity()
{
	return Mat2d(1.0, 0.0, 0.0, 1.0);
}

double geocore::Mat2d::Determinant() const
{
	return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
}

Mat2d geocore::Mat2d::Inverse() const
{
	const double det = Determinant();

	if (abs(det) < 1e-12)	{
		throw runtime_error("Mat2d is singular and cannot be inverted.");
	}	
	
	return Mat2d(
		(*this)(1, 1) / det,
		-(*this)(0, 1) / det,
		-(*this)(1, 0) / det,
		(*this)(0, 0) / det);
}


#pragma endregion Mat2d
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region Mat3d

geocore::Mat3d::Mat3d()
{
	m[0] = 0.0;
	m[1] = 0.0;
	m[2] = 0.0;

	m[3] = 0.0;
	m[4] = 0.0;
	m[5] = 0.0;

	m[6] = 0.0;
	m[7] = 0.0;
	m[8] = 0.0;
}

geocore::Mat3d::Mat3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22)
{
	m[0] = m00;
	m[1] = m01;
	m[2] = m02;

	m[3] = m10;
	m[4] = m11;
	m[5] = m12;

	m[6] = m20;
	m[7] = m21;
	m[8] = m22;
}

double& geocore::Mat3d::operator[](int index)
{
	return m[index];
}

double& geocore::Mat3d::operator()(int row, int col)
{
	return m[row * 3 + col];
}

const double& geocore::Mat3d::operator[](int index) const
{
	return m[index];
}

const double& geocore::Mat3d::operator()(int row, int col) const
{
	return m[row * 3 + col];
}

Mat3d geocore::Mat3d::operator=(const Mat3d& rhs) const
{
	Mat3d result;

	result[0] = rhs.m[0];
	result[1] = rhs.m[1];
	result[2] = rhs.m[2];

	result[3] = rhs.m[3];
	result[4] = rhs.m[4];
	result[5] = rhs.m[5];

	result[6] = rhs.m[6];
	result[7] = rhs.m[7];
	result[8] = rhs.m[8];

	return result;
}

Mat3d geocore::Mat3d::operator+(const Mat3d& rhs) const
{
	Mat3d result;

	result.m[0] = m[0] + rhs.m[0];
	result.m[1] = m[1] + rhs.m[1];
	result.m[2] = m[2] + rhs.m[2];

	result.m[3] = m[3] + rhs.m[3];
	result.m[4] = m[4] + rhs.m[4];
	result.m[5] = m[5] + rhs.m[5];

	result.m[6] = m[6] + rhs.m[6];
	result.m[7] = m[7] + rhs.m[7];
	result.m[8] = m[8] + rhs.m[8];

	return result;
}

Mat3d geocore::Mat3d::operator-(const Mat3d& rhs) const
{
	Mat3d result;

	result.m[0] = m[0] - rhs.m[0];
	result.m[1] = m[1] - rhs.m[1];
	result.m[2] = m[2] - rhs.m[2];
	
	result.m[3] = m[3] - rhs.m[3];
	result.m[4] = m[4] - rhs.m[4];
	result.m[5] = m[5] - rhs.m[5];
	
	result.m[6] = m[6] - rhs.m[6];
	result.m[7] = m[7] - rhs.m[7];
	result.m[8] = m[8] - rhs.m[8];

	return result;
}

Mat3d geocore::Mat3d::operator*(double scalar) const
{
	Mat3d result;

	result.m[0] = m[0] * scalar;
	result.m[1] = m[1] * scalar;
	result.m[2] = m[2] * scalar;

	result.m[3] = m[3] * scalar;
	result.m[4] = m[4] * scalar;
	result.m[5] = m[5] * scalar;

	result.m[6] = m[6] * scalar;
	result.m[7] = m[7] * scalar;
	result.m[8] = m[8] * scalar;

	return result;
}

Mat3d geocore::Mat3d::operator/(double scalar) const
{
	if (abs(scalar) < 1e-12)	{
		throw runtime_error("Mat3d division by zero.");
	}

	Mat3d result;

	result.m[0] = m[0] / scalar;
	result.m[1] = m[1] / scalar;
	result.m[2] = m[2] / scalar;
	
	result.m[3] = m[3] / scalar;
	result.m[4] = m[4] / scalar;
	result.m[5] = m[5] / scalar;
	
	result.m[6] = m[6] / scalar;
	result.m[7] = m[7] / scalar;
	result.m[8] = m[8] / scalar;

	return result;
}

Mat3d geocore::Mat3d::operator*(const Mat3d& rhs) const
{
	Mat3d result;

	result(0, 0) = (*this)(0, 0) * rhs(0, 0) + (*this)(0, 1) * rhs(1, 0) + (*this)(0, 2) * rhs(2, 0);
	result(0, 1) = (*this)(0, 0) * rhs(0, 1) + (*this)(0, 1) * rhs(1, 1) + (*this)(0, 2) * rhs(2, 1);
	result(0, 2) = (*this)(0, 0) * rhs(0, 2) + (*this)(0, 1) * rhs(1, 2) + (*this)(0, 2) * rhs(2, 2);

	result(1, 0) = (*this)(1, 0) * rhs(0, 0) + (*this)(1, 1) * rhs(1, 0) + (*this)(1, 2) * rhs(2, 0);
	result(1, 1) = (*this)(1, 0) * rhs(0, 1) + (*this)(1, 1) * rhs(1, 1) + (*this)(1, 2) * rhs(2, 1);
	result(1, 2) = (*this)(1, 0) * rhs(0, 2) + (*this)(1, 1) * rhs(1, 2) + (*this)(1, 2) * rhs(2, 2);

	result(2, 0) = (*this)(2, 0) * rhs(0, 0) + (*this)(2, 1) * rhs(1, 0) + (*this)(2, 2) * rhs(2, 0);
	result(2, 1) = (*this)(2, 0) * rhs(0, 1) + (*this)(2, 1) * rhs(1, 1) + (*this)(2, 2) * rhs(2, 1);
	result(2, 2) = (*this)(2, 0) * rhs(0, 2) + (*this)(2, 1) * rhs(1, 2) + (*this)(2, 2) * rhs(2, 2);

	return result;
}

Vec3d geocore::Mat3d::operator*(const Vec3d& rhs) const
{
	Vec3d result;

	result.f64X =
		(*this)(0, 0) * rhs.f64X +
		(*this)(0, 1) * rhs.f64Y +
		(*this)(0, 2) * rhs.f64Z;

	result.f64Y =
		(*this)(1, 0) * rhs.f64X +
		(*this)(1, 1) * rhs.f64Y +
		(*this)(1, 2) * rhs.f64Z;

	result.f64Z =
		(*this)(2, 0) * rhs.f64X +
		(*this)(2, 1) * rhs.f64Y +
		(*this)(2, 2) * rhs.f64Z;

	return result;
}

bool geocore::Mat3d::IsApprox(const Mat3d& rhs, double tolerance) const
{
	for (int i = 0; i < 9; ++i)
	{
		if (abs(m[i] - rhs.m[i]) > tolerance)
		{
			return false;
		}
	}

	return true;
}

Mat3d geocore::Mat3d::Transpose() const
{
	Mat3d result;

	result(0, 0) = (*this)(0, 0);
	result(0, 1) = (*this)(1, 0);
	result(0, 2) = (*this)(2, 0);

	result(1, 0) = (*this)(0, 1);
	result(1, 1) = (*this)(1, 1);
	result(1, 2) = (*this)(2, 1);

	result(2, 0) = (*this)(0, 2);
	result(2, 1) = (*this)(1, 2);
	result(2, 2) = (*this)(2, 2);

	return result;
}

Mat3d geocore::Mat3d::Identity()
{
	return Mat3d(
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0);
}

double geocore::Mat3d::Determinant() const
{
	const double m00 = (*this)(0, 0);
	const double m01 = (*this)(0, 1);
	const double m02 = (*this)(0, 2);

	const double m10 = (*this)(1, 0);
	const double m11 = (*this)(1, 1);
	const double m12 = (*this)(1, 2);

	const double m20 = (*this)(2, 0);
	const double m21 = (*this)(2, 1);
	const double m22 = (*this)(2, 2);

	//det (A) = a(ei-fh) - b(di-fg) + c(dh-eg)

	double det =  m00 * (m11 * m22 - m12 * m21)
				- m01 * (m10 * m22 - m12 * m20)
				+ m02 * (m10 * m21 - m11 * m20);

	return det;
}

Mat3d geocore::Mat3d::CofactorMatrix() const
{
	//  CofactorMatrix(A)
	//
	//  C = [ +(m11*m22 - m12*m21)   -(m10*m22 - m12*m20)   +(m10*m21 - m11*m20) ]
	//      [ -(m01*m22 - m02*m21)   +(m00*m22 - m02*m20)   -(m00*m21 - m01*m20) ]
	//      [ +(m01*m12 - m02*m11)   -(m00*m12 - m02*m10)   +(m00*m11 - m01*m10) ]
	//
	const double m00 = (*this)(0, 0);
	const double m01 = (*this)(0, 1);
	const double m02 = (*this)(0, 2);

	const double m10 = (*this)(1, 0);
	const double m11 = (*this)(1, 1);
	const double m12 = (*this)(1, 2);

	const double m20 = (*this)(2, 0);
	const double m21 = (*this)(2, 1);
	const double m22 = (*this)(2, 2);

	Mat3d result;

	result(0, 0) = +(m11 * m22 - m12 * m21);
	result(0, 1) = -(m10 * m22 - m12 * m20);
	result(0, 2) = +(m10 * m21 - m11 * m20);

	result(1, 0) = -(m01 * m22 - m02 * m21);
	result(1, 1) = +(m00 * m22 - m02 * m20);
	result(1, 2) = -(m00 * m21 - m01 * m20);

	result(2, 0) = +(m01 * m12 - m02 * m11);
	result(2, 1) = -(m00 * m12 - m02 * m10);
	result(2, 2) = +(m00 * m11 - m01 * m10);
	
	return result;
}

Mat3d geocore::Mat3d::AdjugateMatrix() const
{
	return CofactorMatrix().Transpose();
}

Mat3d geocore::Mat3d::Inverse() const
{
	//  A = [ m00  m01  m02 ]
	//      [ m10  m11  m12 ]
	//      [ m20  m21  m22 ]
	//
	//  det(A)
	//  = m00 * (m11 * m22 - m12 * m21)
	//  - m01 * (m10 * m22 - m12 * m20)
	//  + m02 * (m10 * m21 - m11 * m20)
	//
	//              1
	//  A^(-1) = -------* AdjugateMatrix
	//            det(A)
	//
	
	const double det = Determinant();

	if (abs(det) < 1e-12)	{
		throw runtime_error("Mat3d is singular and cannot be inverted.");
	}
	
	Mat3d Adj = AdjugateMatrix();
	
	return (Adj / det);
}


#pragma endregion Mat3d

geocore::Mat4d::Mat4d()
{
	m[0] = 0.0;
	m[1] = 0.0;
	m[2] = 0.0;
	m[3] = 0.0;

	m[4] = 0.0;
	m[5] = 0.0;
	m[6] = 0.0;
	m[7] = 0.0;

	m[8] = 0.0;
	m[9] = 0.0;
	m[10] = 0.0;
	m[11] = 0.0;

	m[12] = 0.0;
	m[13] = 0.0;
	m[14] = 0.0;
	m[15] = 0.0;
}

geocore::Mat4d::Mat4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33)
{
	m[0] = m00;
	m[1] = m01;
	m[2] = m02;
	m[3] = m03;

	m[4] = m10;
	m[5] = m11;
	m[6] = m12;
	m[7] = m13;
	
	m[8]  = m20;
	m[9]  = m21;
	m[10] = m22;
	m[11] = m23;

	m[12] = m30;
	m[13] = m31;
	m[14] = m32;
	m[15] = m33;
}

double& geocore::Mat4d::operator[](int index)
{
	return m[index];
}

double& geocore::Mat4d::operator()(int row, int col)
{
	return m[row * 4 + col];
}

const double& geocore::Mat4d::operator[](int index) const
{
	return m[index];
}

const double& geocore::Mat4d::operator()(int row, int col) const
{
	return m[row * 4 + col];
}

Mat4d geocore::Mat4d::operator=(const Mat4d& rhs) const
{
	Mat4d result;

	result[0] = rhs.m[0];
	result[1] = rhs.m[1];
	result[2] = rhs.m[2];
	result[3] = rhs.m[3];

	result[4] = rhs.m[4];
	result[5] = rhs.m[5];
	result[6] = rhs.m[6];
	result[7] = rhs.m[7];

	result[8] = rhs.m[8];
	result[9] = rhs.m[9];
	result[10] = rhs.m[10];
	result[11] = rhs.m[11];

	result[12] = rhs.m[12];
	result[13] = rhs.m[13];
	result[14] = rhs.m[14];
	result[15] = rhs.m[15];


	//for (int i = 0; i < 16; ++i)	result.m[i] = rhs.m[i];
	return result;
}

Mat4d geocore::Mat4d::operator+(const Mat4d& rhs) const
{
	Mat4d result;

	result.m[0] = m[0] + rhs.m[0];
	result.m[1] = m[1] + rhs.m[1];
	result.m[2] = m[2] + rhs.m[2];
	result.m[3] = m[3] + rhs.m[3];

	result.m[4] = m[4] + rhs.m[4];
	result.m[5] = m[5] + rhs.m[5];
	result.m[6] = m[6] + rhs.m[6];
	result.m[7] = m[7] + rhs.m[7];

	result.m[8] = m[8] + rhs.m[8];
	result.m[9] = m[9] + rhs.m[9];
	result.m[10] = m[10] + rhs.m[10];
	result.m[11] = m[11] + rhs.m[11];

	result.m[12] = m[12] + rhs.m[12];
	result.m[13] = m[13] + rhs.m[13];
	result.m[14] = m[14] + rhs.m[14];
	result.m[15] = m[15] + rhs.m[15];
	
	//for (int i = 0; i < 16; ++i)	result.m[i] = m[i] + rhs.m[i];
	return result;
}

Mat4d geocore::Mat4d::operator-(const Mat4d& rhs) const
{
	Mat4d result;

	result.m[0] = m[0] - rhs.m[0];
	result.m[1] = m[1] - rhs.m[1];
	result.m[2] = m[2] - rhs.m[2];
	result.m[3] = m[3] - rhs.m[3];

	result.m[4] = m[4] - rhs.m[4];
	result.m[5] = m[5] - rhs.m[5];
	result.m[6] = m[6] - rhs.m[6];
	result.m[7] = m[7] - rhs.m[7];

	result.m[8] = m[8] - rhs.m[8];
	result.m[9] = m[9] - rhs.m[9];
	result.m[10] = m[10] - rhs.m[10];
	result.m[11] = m[11] - rhs.m[11];

	result.m[12] = m[12] - rhs.m[12];
	result.m[13] = m[13] - rhs.m[13];
	result.m[14] = m[14] - rhs.m[14];
	result.m[15] = m[15] - rhs.m[15];

	//for (int i = 0; i < 16; ++i)	result.m[i] = m[i] - rhs.m[i];
	return result;
}

Mat4d geocore::Mat4d::operator*(double scalar) const
{
	Mat4d result;

	result.m[0] = m[0] * scalar;
	result.m[1] = m[1] * scalar;
	result.m[2] = m[2] * scalar;
	result.m[3] = m[3] * scalar;

	result.m[4] = m[4] * scalar;
	result.m[5] = m[5] * scalar;
	result.m[6] = m[6] * scalar;
	result.m[7] = m[7] * scalar;

	result.m[8] = m[8] * scalar;
	result.m[9] = m[9] * scalar;
	result.m[10] = m[10] * scalar;
	result.m[11] = m[11] * scalar;

	result.m[12] = m[12] * scalar;
	result.m[13] = m[13] * scalar;
	result.m[14] = m[14] * scalar;
	result.m[15] = m[15] * scalar;

	//for (int i = 0; i < 16; ++i)	result.m[i] = m[i] * scalar;
	return result;
}

Mat4d geocore::Mat4d::operator/(double scalar) const
{
	if (abs(scalar) < 1e-12)	{
		throw runtime_error("Mat4d division by zero.");
	}

	Mat4d result;

	result.m[0] = m[0] / scalar;
	result.m[1] = m[1] / scalar;
	result.m[2] = m[2] / scalar;
	result.m[3] = m[3] / scalar;

	result.m[4] = m[4] / scalar;
	result.m[5] = m[5] / scalar;
	result.m[6] = m[6] / scalar;
	result.m[7] = m[7] / scalar;

	result.m[8] = m[8] / scalar;
	result.m[9] = m[9] / scalar;
	result.m[10] = m[10] / scalar;
	result.m[11] = m[11] / scalar;

	result.m[12] = m[12] / scalar;
	result.m[13] = m[13] / scalar;
	result.m[14] = m[14] / scalar;
	result.m[15] = m[15] / scalar;

	//for (int i = 0; i < 16; ++i)	result.m[i] = m[i] /scalar;
	return result;
}

Mat4d geocore::Mat4d::operator*(const Mat4d& rhs) const
{
	Mat4d result;

	result(0, 0) = (*this)(0, 0) * rhs(0, 0) + (*this)(0, 1) * rhs(1, 0) + (*this)(0, 2) * rhs(2, 0) + (*this)(0, 3) * rhs(3, 0);
	result(0, 1) = (*this)(0, 0) * rhs(0, 1) + (*this)(0, 1) * rhs(1, 1) + (*this)(0, 2) * rhs(2, 1) + (*this)(0, 3) * rhs(3, 1);
	result(0, 2) = (*this)(0, 0) * rhs(0, 2) + (*this)(0, 1) * rhs(1, 2) + (*this)(0, 2) * rhs(2, 2) + (*this)(0, 3) * rhs(3, 2);
	result(0, 3) = (*this)(0, 0) * rhs(0, 3) + (*this)(0, 1) * rhs(1, 3) + (*this)(0, 2) * rhs(2, 3) + (*this)(0, 3) * rhs(3, 3);
	
	result(1, 0) = (*this)(1, 0) * rhs(0, 0) + (*this)(1, 1) * rhs(1, 0) + (*this)(1, 2) * rhs(2, 0) + (*this)(1, 3) * rhs(3, 0);
	result(1, 1) = (*this)(1, 0) * rhs(0, 1) + (*this)(1, 1) * rhs(1, 1) + (*this)(1, 2) * rhs(2, 1) + (*this)(1, 3) * rhs(3, 1);
	result(1, 2) = (*this)(1, 0) * rhs(0, 2) + (*this)(1, 1) * rhs(1, 2) + (*this)(1, 2) * rhs(2, 2) + (*this)(1, 3) * rhs(3, 2);
	result(1, 3) = (*this)(1, 0) * rhs(0, 3) + (*this)(1, 1) * rhs(1, 3) + (*this)(1, 2) * rhs(2, 3) + (*this)(1, 3) * rhs(3, 3);
	
	result(2, 0) = (*this)(2, 0) * rhs(0, 0) + (*this)(2, 1) * rhs(1, 0) + (*this)(2, 2) * rhs(2, 0) + (*this)(2, 3) * rhs(3, 0);
	result(2, 1) = (*this)(2, 0) * rhs(0, 1) + (*this)(2, 1) * rhs(1, 1) + (*this)(2, 2) * rhs(2, 1) + (*this)(2, 3) * rhs(3, 1);
	result(2, 2) = (*this)(2, 0) * rhs(0, 2) + (*this)(2, 1) * rhs(1, 2) + (*this)(2, 2) * rhs(2, 2) + (*this)(2, 3) * rhs(3, 2);
	result(2, 3) = (*this)(2, 0) * rhs(0, 3) + (*this)(2, 1) * rhs(1, 3) + (*this)(2, 2) * rhs(2, 3) + (*this)(2, 3) * rhs(3, 3);
	
	result(3, 0) = (*this)(3, 0) * rhs(0, 0) + (*this)(3, 1) * rhs(1, 0) + (*this)(3, 2) * rhs(2, 0) + (*this)(3, 3) * rhs(3, 0);
	result(3, 1) = (*this)(3, 0) * rhs(0, 1) + (*this)(3, 1) * rhs(1, 1) + (*this)(3, 2) * rhs(2, 1) + (*this)(3, 3) * rhs(3, 1);
	result(3, 2) = (*this)(3, 0) * rhs(0, 2) + (*this)(3, 1) * rhs(1, 2) + (*this)(3, 2) * rhs(2, 2) + (*this)(3, 3) * rhs(3, 2);
	result(3, 3) = (*this)(3, 0) * rhs(0, 3) + (*this)(3, 1) * rhs(1, 3) + (*this)(3, 2) * rhs(2, 3) + (*this)(3, 3) * rhs(3, 3);

	return result;
}

bool geocore::Mat4d::IsApprox(const Mat4d& rhs, double tolerance) const
{
	for (int i = 0; i < 16; ++i)
	{
		if (abs(m[i] - rhs.m[i]) > tolerance)
		{
			return false;
		}
	}

	return true;
}

Mat4d geocore::Mat4d::Transpose() const
{
	Mat4d result;

	result(0, 0) = (*this)(0, 0);
	result(0, 1) = (*this)(1, 0);
	result(0, 2) = (*this)(2, 0);
	result(0, 3) = (*this)(3, 0);

	result(1, 0) = (*this)(0, 1);
	result(1, 1) = (*this)(1, 1);
	result(1, 2) = (*this)(2, 1);
	result(1, 3) = (*this)(3, 1);

	result(2, 0) = (*this)(0, 2);
	result(2, 1) = (*this)(1, 2);
	result(2, 2) = (*this)(2, 2);
	result(2, 3) = (*this)(3, 2);

	result(3, 0) = (*this)(0, 3);
	result(3, 1) = (*this)(1, 3);
	result(3, 2) = (*this)(2, 3);
	result(3, 3) = (*this)(3, 3);

	return result;
}

Mat4d geocore::Mat4d::Identity()
{
	return Mat4d(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

double geocore::Mat4d::Determinant() const
{
	//det(A) = m00 C00 + m01 C01 + m02 C02 + m03 C03
	double determinant = 0.0;

	for (int col = 0; col < 4; ++col)
	{
		const double sign = (col % 2 == 0) ? 1.0 : -1.0;
		determinant += sign * (*this)(0, col) * MinorDeterminant3x3(*this, 0, col);
	}

	return determinant;
}

double geocore::Mat4d::MinorDeterminant3x3(const Mat4d& matrix, int excludedRow, int excludedCol) const
{
	double values[9];
	int index = 0;

	for (int row = 0; row < 4; ++row)
	{
		if (row == excludedRow)	{
			continue;
		}

		for (int col = 0; col < 4; ++col)
		{
			if (col == excludedCol)	{
				continue;
			}

			values[index] = matrix(row, col);
			++index;
		}
	}

	Mat3d minor(
		values[0], values[1], values[2],
		values[3], values[4], values[5],
		values[6], values[7], values[8]);

	return minor.Determinant();
}

Mat4d geocore::Mat4d::CofactorMatrix() const
{
	Mat4d result;

	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			const double sign = ((row + col) % 2 == 0) ? 1.0 : -1.0;
			result(row, col) = sign * MinorDeterminant3x3( *this, row, col);
		}
	}

	return result;
}

Mat4d geocore::Mat4d::AdjugateMatrix() const
{
	return CofactorMatrix().Transpose();
}

Mat4d geocore::Mat4d::Inverse() const
{
	const double det = Determinant();

	if (abs(det) < 1e-12)	{
		throw runtime_error("Mat4d is singular and cannot be inverted.");
	}

	return AdjugateMatrix() / det;
}
