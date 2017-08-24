#ifndef VECTOR3_HEADER
#define VECTOR3_HEADER


#include <string.h>
#include <math.h>
#include <ostream>

class Vector3{
public:
	Vector3();
	Vector3(double, double, double);
	virtual ~Vector3();
	Vector3 clamp(Vector3, Vector3);
	Vector3 floorAM();
	Vector3 ceilAM();
	Vector3 roundAM();
	Vector3 negate();
	double dot(Vector3);
	Vector3 cross(Vector3);
	double length();
	Vector3 normalize();
	double distanceTo(Vector3);
	Vector3 set(double, double, double);
	
	//void transform();
	//void makeOrthonormalBasis();
	Vector3& operator+=(const Vector3&);
	Vector3 operator+(const Vector3&);

	Vector3& operator+=(const double&);
	Vector3 operator+(const double&);

	Vector3& operator-=(const Vector3&);
	Vector3 operator-(const Vector3&);

	Vector3& operator-=(const double&);
	Vector3 operator-(const double&);

	Vector3& operator*=(const Vector3&);
	Vector3 operator*(const Vector3&);
	
	Vector3& operator*=(const double&);
	Vector3 operator*(const double&);

	Vector3& operator/=(const Vector3&);
	Vector3 operator/(const Vector3&);

	Vector3& operator/=(const double&);
	Vector3 operator/(const double&);

	Vector3 & operator=(const Vector3&);

	bool operator==(const Vector3&);
	bool operator!=(const Vector3&);

	//std::ostream&  operator << (std::ostream &os);

	friend std::ostream&  operator << (std::ostream &os, const Vector3& v);

	/*friend std::ostream&  operator << (std::ostream &os, const Matrix4& m){
			os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8] << std::endl;
	return os;
	}*/

	double x, y, z;

};

#endif