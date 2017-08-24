#ifndef MATRIX4_HEADER
#define MATRIX4_HEADER

#include "Matrix3.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include <string.h>
#include <math.h>
#include <ostream>

class Matrix4{
public:
	Matrix4();
	virtual ~Matrix4();
	Matrix4 set(double n11,double n12,double n13,double n14, double n21,double n22,double n23,double n24,double n31,double n32,double n33,double n34,double n41,double n42,double n43,double n44);
	Matrix4 identity();
	double determinant();
	Matrix4 transpose();
	Matrix4 inverse();
	Matrix4 translate(double, double, double);
	Matrix4 rotateX(double);
	Matrix4 rotateY(double);
	Matrix4 rotateZ(double);
	Matrix4 rotate(double, double, double);
	Matrix4 scale(double, double, double);
	Matrix4 orthographicProjection(double, double, double, double, double, double);
	Matrix4 perspectiveProjection(double, double, double, double);
	Matrix3 getNormalMatrix(bool);
	Vector3 transform(Vector3);
	Matrix4 lookAt(Vector3, Vector3, Vector3);

	Matrix4& operator+=(const Matrix4&);
	Matrix4 operator+(const Matrix4&);

	Matrix4& operator+=(const double&);
	Matrix4 operator+(const double&);

	Matrix4& operator-=(const Matrix4&);
	Matrix4 operator-(const Matrix4&);

	Matrix4& operator-=(const double&);
	Matrix4 operator-(const double&);

	Matrix4& operator*=(const Matrix4&);
	Matrix4 operator*(const Matrix4&);
	
	Matrix4& operator*=(const double&);
	Matrix4 operator*(const double&);

	Vector3 operator*(const Vector3&);
	Vector4 operator*(const Vector4&);

	Matrix4& operator/=(const double&);
	Matrix4 operator/(const double&);

	Matrix4 & operator=(const Matrix4&);

	bool operator==(const Matrix4&);
	bool operator!=(const Matrix4&);

	//std::ostream&  operator << (std::ostream &os);

	friend std::ostream&  operator << (std::ostream &os, const Matrix4& m);

	/*friend std::ostream&  operator << (std::ostream &os, const Matrix4& m){
			os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8] << std::endl;
	return os;
	}*/

	double c[16];

};

#endif