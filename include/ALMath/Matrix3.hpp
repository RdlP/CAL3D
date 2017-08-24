#ifndef MATRIX3_HEADER
#define MATRIX3_HEADER

#include <string.h>
#include <ostream>
#include "Vector3.hpp"

class Matrix3{
public:
	Matrix3();
	virtual ~Matrix3();
	Matrix3 set(double n11,double n12,double n13,double n21,double n22,double n23,double n31,double n32,double n33);
	Matrix3 identity();
	double determinant();
	Matrix3 transpose();
	Matrix3 inverse();
	Vector3 transform(Vector3);
	Matrix3 makeOrthonormalBasis(Vector3, Vector3);
	Matrix3& operator+=(const Matrix3&);
	Matrix3 operator+(const Matrix3&);

	Matrix3& operator+=(const double&);
	Matrix3 operator+(const double&);

	Matrix3& operator-=(const Matrix3&);
	Matrix3 operator-(const Matrix3&);

	Matrix3& operator-=(const double&);
	Matrix3 operator-(const double&);

	Matrix3& operator*=(const Matrix3&);
	Matrix3 operator*(const Matrix3&);
	
	Matrix3& operator*=(const double&);
	Matrix3 operator*(const double&);

	Vector3 operator*(const Vector3&);

	Matrix3& operator/=(const double&);
	Matrix3 operator/(const double&);

	Matrix3 & operator=(const Matrix3&);

	bool operator==(const Matrix3&);
	bool operator!=(const Matrix3&);

	//std::ostream&  operator << (std::ostream &os);

	friend std::ostream&  operator << (std::ostream &os, const Matrix3& m);

	/*friend std::ostream&  operator << (std::ostream &os, const Matrix3& m){
			os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8] << std::endl;
	return os;
	}*/

	double c[9];

};

#endif