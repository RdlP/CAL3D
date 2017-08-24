#ifndef QUATERNION_HEADER
#define QUATERNION_HEADER


#include <string.h>
#include <math.h>
#include <ostream>
#include "Vector3.hpp"
#include "Matrix3.hpp"
#include "Matrix4.hpp"

class Quaternion{
public:
	Quaternion();
	Quaternion(double, double, double, double);
	virtual ~Quaternion();
	double length();
	Quaternion normalize();
	Quaternion conjugate();
	Quaternion inverse();
	Matrix4 getMatrix4();
	Matrix3 getMatrix3();
	Quaternion integrate(Vector3, double);
	Quaternion rotateByVector(Vector3);
	Quaternion rotateX(double);
	Quaternion rotateY(double);
	Quaternion rotateZ(double);
	Quaternion rotate(Vector3, double);
	Quaternion setFromAxisAngle(Vector3, double);
	Quaternion setFromEuler(Vector3);
	Vector3 getEuler();

	Quaternion& operator*=(const Quaternion&);
	Quaternion operator*(const Quaternion&);
	
	Quaternion & operator=(const Quaternion&);

	bool operator==(const Quaternion&);
	bool operator!=(const Quaternion&);

	//std::ostream&  operator << (std::ostream &os);

	friend std::ostream&  operator << (std::ostream &os, const Quaternion& v);

	/*friend std::ostream&  operator << (std::ostream &os, const Matrix4& m){
			os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8] << std::endl;
	return os;
	}*/

	double x, y, z, w;

};

#endif