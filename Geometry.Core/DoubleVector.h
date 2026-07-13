#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

namespace geocore
{
	struct Vec2d
	{
		double f64X;
		double f64Y;

		Vec2d();
		Vec2d(double x, double y);

		Vec2d operator+(const Vec2d& rhs)const;
		Vec2d operator-(const Vec2d& rhs)const;
		Vec2d operator*(double scalar)const;
		Vec2d operator/(double scalar)const;


		Vec2d operator+=(const Vec2d& rhs);
		Vec2d operator-=(const Vec2d& rhs);

		double Dot(const Vec2d& rhs) const;
		double SquaredNorm() const;
		double Norm() const;

		Vec2d Normalized() const;

		bool IsApprox(const Vec2d& rhs,double tolerance = 1e-9) const;
	};

	struct Vec3d
	{
		double f64X;
		double f64Y;
		double f64Z;

		Vec3d();
		Vec3d(double x, double y, double z);

		Vec3d operator+(const Vec3d& rhs)const;
		Vec3d operator-(const Vec3d& rhs)const;
		Vec3d operator*(double scalar)const;
		Vec3d operator/(double scalar)const;


		Vec3d operator+=(const Vec3d& rhs);
		Vec3d operator-=(const Vec3d& rhs);

		double Dot(const Vec3d& rhs) const;
		double SquaredNorm() const;
		double Norm() const;

		Vec3d Normalized() const;

		bool IsApprox(const Vec3d& rhs, double tolerance = 1e-9) const;
	};



}

#endif //  DOUBLEVECTOR_H
