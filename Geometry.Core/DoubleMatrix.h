#ifndef DOUBLEMATRIX_H
#define DOUBLEMATRIX_H

namespace geocore
{
	struct Matrix2d
	{
		double m[4];
		
		Matrix2d();
		Matrix2d(double m00, double m01, double m10, double m11);

		double& operator[](int index);
		double& operator()(int row, int col);

		const double& operator[](int index) const;
		const double& operator()(int row, int col) const;

		Matrix2d operator+(const Matrix2d& rhs)const;
		Matrix2d operator-(const Matrix2d& rhs)const;
		Matrix2d operator*(double scalar)const;
		Matrix2d operator/(double scalar)const;



	};


	struct Matrix3d
	{
		double m[9];

		Matrix3d();
		Matrix3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22);

		double& operator[](int index);
		double& operator()(int row, int col);

		const double& operator[](int index) const;
		const double& operator()(int row, int col) const;

		Matrix3d operator+(const Matrix3d& rhs)const;
		Matrix3d operator-(const Matrix3d& rhs)const;
		Matrix3d operator*(double scalar)const;
		Matrix3d operator/(double scalar)const;



	};
}

#endif //  DOUBLEMATRIX_H
