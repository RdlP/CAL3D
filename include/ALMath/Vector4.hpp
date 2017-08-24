#ifndef VECTOR4_HEADER
#define VECTOR4_HEADER


#include <string.h>
#include <math.h>
#include <ostream>

class Vector4{
public:
	Vector4();
	Vector4(double, double, double, double);
	virtual ~Vector4();
	Vector4 clamp(Vector4, Vector4);
	Vector4 floorAM();
	Vector4 ceilAM();
	Vector4 roundAM();
	Vector4 negate();
	double dot(Vector4);
	double length();
	Vector4 normalize();
	double distanceTo(Vector4);
	Vector4 set(double, double, double, double);
	
	//void transform();
	//void makeOrthonormalBasis();
	Vector4& operator+=(const Vector4&);
	Vector4 operator+(const Vector4&);

	Vector4& operator+=(const double&);
	Vector4 operator+(const double&);

	Vector4& operator-=(const Vector4&);
	Vector4 operator-(const Vector4&);

	Vector4& operator-=(const double&);
	Vector4 operator-(const double&);

	Vector4& operator*=(const Vector4&);
	Vector4 operator*(const Vector4&);
	
	Vector4& operator*=(const double&);
	Vector4 operator*(const double&);

	Vector4& operator/=(const Vector4&);
	Vector4 operator/(const Vector4&);

	Vector4& operator/=(const double&);
	Vector4 operator/(const double&);

	Vector4 & operator=(const Vector4&);

	bool operator==(const Vector4&);
	bool operator!=(const Vector4&);

	//std::ostream&  operator << (std::ostream &os);

	friend std::ostream&  operator << (std::ostream &os, const Vector4& v);

	/*friend std::ostream&  operator << (std::ostream &os, const Matrix4& m){
			os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8] << std::endl;
	return os;
	}*/

	double x, y, z, w;

};

#endif