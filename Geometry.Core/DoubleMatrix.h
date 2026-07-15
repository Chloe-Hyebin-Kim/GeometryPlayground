#ifndef DOUBLEMATRIX_H
#define DOUBLEMATRIX_H

namespace geocore
{
	struct Mat2d
	{
		double m[4];
		
		Mat2d();
		Mat2d(double m00, double m01, double m10, double m11);

		double& operator[](int index);
		double& operator()(int row, int col);

		const double& operator[](int index) const;
		const double& operator()(int row, int col) const;

		Mat2d operator=(const Mat2d& rhs)const;
		Mat2d operator+(const Mat2d& rhs)const;
		Mat2d operator-(const Mat2d& rhs)const;
		Mat2d operator*(double scalar)const;
		Mat2d operator/(double scalar)const;

		Mat2d operator*(const Mat2d& rhs) const;

		bool IsApprox(const Mat2d& rhs, double tolerance) const;

		Mat2d Transpose() const;
		static Mat2d Identity();

		double Determinant() const;
		Mat2d Inverse() const;
	};


	struct Mat3d
	{
		double m[9];

		Mat3d();
		Mat3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22);

		double& operator[](int index);
		double& operator()(int row, int col);

		const double& operator[](int index) const;
		const double& operator()(int row, int col) const;

		Mat3d operator=(const Mat3d& rhs)const;
		Mat3d operator+(const Mat3d& rhs)const;
		Mat3d operator-(const Mat3d& rhs)const;
		Mat3d operator*(double scalar)const;
		Mat3d operator/(double scalar)const;

		Mat3d operator*(const Mat3d& rhs) const;
		Vec3d operator*(const Vec3d& rhs) const;

		bool IsApprox(const Mat3d& rhs, double tolerance) const;

		Mat3d Transpose() const;
		static Mat3d Identity();

		double Determinant() const;
		Mat3d CofactorMatrix() const;
		Mat3d AdjugateMatrix() const;
		Mat3d Inverse() const;
	};


	struct Mat4d
	{
		double m[16];

		Mat4d();
		Mat4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33);

		double& operator[](int index);
		double& operator()(int row, int col);

		const double& operator[](int index) const;
		const double& operator()(int row, int col) const;

		Mat4d operator=(const Mat4d& rhs)const;
		Mat4d operator+(const Mat4d& rhs)const;
		Mat4d operator-(const Mat4d& rhs)const;
		Mat4d operator*(double scalar)const;
		Mat4d operator/(double scalar)const;

		Mat4d operator*(const Mat4d& rhs) const;

		bool IsApprox(const Mat4d& rhs, double tolerance) const;

		Mat4d Transpose() const;
		static Mat4d Identity();

		double Determinant() const;
		double MinorDeterminant3x3(const Mat4d& matrix,int excludedRow, int excludedCol) const;
		Mat4d CofactorMatrix() const;
		Mat4d AdjugateMatrix() const;
		Mat4d Inverse() const;
	};
}

#endif //  DOUBLEMATRIX_H
