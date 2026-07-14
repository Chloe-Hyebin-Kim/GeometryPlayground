#include "pch.h"
#include "DoubleMatrix.h"

using namespace geocore;

#pragma region Matrix2d

geocore::Matrix2d::Matrix2d()
{
	m[0] = 0.0;
	m[1] = 0.0;
	m[2] = 0.0;
	m[3] = 0.0;
}

geocore::Matrix2d::Matrix2d(double m00, double m01, double m10, double m11)
{
	m[0] = m00;
	m[1] = m01;
	m[2] = m10;
	m[3] = m11;
}

double& geocore::Matrix2d::operator[](int index)
{
	return m[index];
}

double& geocore::Matrix2d::operator()(int row, int col)
{
	return m[row*2 + col];
}

const double& geocore::Matrix2d::operator[](int index) const
{
	return m[index];
}

const double& geocore::Matrix2d::operator()(int row, int col) const
{
	return m[row * 2 + col];
}

Matrix2d geocore::Matrix2d::operator+(const Matrix2d& rhs) const
{
	Matrix2d result;

	result.m[0] = m[0] + rhs.m[0];
	result.m[1] = m[1] + rhs.m[1];
	result.m[2] = m[2] + rhs.m[2];
	result.m[3] = m[3] + rhs.m[3];

	return result;

	//return Matrix2d(m[0] + rhs.m[0], m[1] + rhs.m[1], m[2] + rhs.m[2], m[3] + rhs.m[3]);
}

Matrix2d geocore::Matrix2d::operator-(const Matrix2d& rhs) const
{
	Matrix2d result;

	result.m[0] = m[0] - rhs.m[0];
	result.m[1] = m[1] - rhs.m[1];
	result.m[2] = m[2] - rhs.m[2];
	result.m[3] = m[3] - rhs.m[3];

	return result;
	//return Matrix2d(m[0] - rhs.m[0], m[1] - rhs.m[1], m[2] - rhs.m[2], m[3] - rhs.m[3]);
}

Matrix2d geocore::Matrix2d::operator*(double scalar) const
{
	Matrix2d result;

	result.m[0] = m[0] * scalar;
	result.m[1] = m[1] * scalar;
	result.m[2] = m[2] * scalar;
	result.m[3] = m[3] * scalar;

	return result;
	//return Matrix2d(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);

}

Matrix2d geocore::Matrix2d::operator/(double scalar) const
{
	Matrix2d result;

	result.m[0] = m[0] / scalar;
	result.m[1] = m[1] / scalar;
	result.m[2] = m[2] / scalar;
	result.m[3] = m[3] / scalar;

	return result;
	//return Matrix2d(m[0] / scalar, m[1] / scalar, m[2] / scalar, m[3] / scalar);
}

Matrix2d geocore::Matrix2d::operator*(const Matrix2d& rhs) const
{
	Matrix2d result;

	result(0, 0) = (*this)(0, 0) * rhs(0, 0) + (*this)(0, 1) * rhs(1, 0);
	result(0, 1) = (*this)(0, 0) * rhs(0, 1) + (*this)(0, 1) * rhs(1, 1);
	result(1, 0) = (*this)(1, 0) * rhs(0, 0) + (*this)(1, 1) * rhs(1, 0);
	result(1, 1) = (*this)(1, 0) * rhs(0, 1) + (*this)(1, 1) * rhs(1, 1);

	return result;
}

Matrix2d geocore::Matrix2d::Transpose() const
{
	Matrix2d result;

	result(0, 0) = (*this)(0, 0);
	result(0, 1) = (*this)(1, 0);
	result(1, 0) = (*this)(0, 1);
	result(1, 1) = (*this)(1, 0);

	return result;
}

double geocore::Matrix2d::Determinant() const
{
	return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
}

Matrix2d geocore::Matrix2d::Identity()
{
	return Matrix2d(1.0, 0.0, 0.0, 1.0);
}


#pragma endregion Matrix2d
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region Matrix3d

geocore::Matrix3d::Matrix3d()
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

geocore::Matrix3d::Matrix3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22)
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

double& geocore::Matrix3d::operator[](int index)
{
	return m[index];
}

double& geocore::Matrix3d::operator()(int row, int col)
{
	return m[row * 3 + col];
}

const double& geocore::Matrix3d::operator[](int index) const
{
	return m[index];
}

const double& geocore::Matrix3d::operator()(int row, int col) const
{
	return m[row * 3 + col];
}

Matrix3d geocore::Matrix3d::operator+(const Matrix3d& rhs) const
{
	Matrix3d result;

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

Matrix3d geocore::Matrix3d::operator-(const Matrix3d& rhs) const
{
	Matrix3d result;

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

Matrix3d geocore::Matrix3d::operator*(double scalar) const
{
	Matrix3d result;

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

Matrix3d geocore::Matrix3d::operator/(double scalar) const
{
	Matrix3d result;
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

Matrix3d geocore::Matrix3d::operator*(const Matrix3d& rhs) const
{
	Matrix3d result;

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

Matrix3d geocore::Matrix3d::Transpose() const
{
	Matrix3d result;

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

double geocore::Matrix3d::Determinant() const
{
//det (A) = a(ei-fh) - b(di-fg) + c(dh-eg)
	return
		(*this)(0, 0) *
		((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) -

		(*this)(0, 1) *
		((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) +

		(*this)(0, 2) *
		((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0));
}

Matrix3d geocore::Matrix3d::Identity()
{
	return Matrix3d(
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0);
}


#pragma endregion Matrix3d
