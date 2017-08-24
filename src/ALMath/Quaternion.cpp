#include "Quaternion.hpp"

Quaternion::Quaternion(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Quaternion::Quaternion(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Quaternion::~Quaternion(){

}

double Quaternion::length(){
	return sqrt(x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::normalize(){
	double d = length();
	if (d == 0){
		x = y = z = w = 0;
	}else{
		d = 1.0 / d;
		x *= d;
		y *= d;
		z *= d;
		w *= d;
	}

	return *this;
}

Quaternion Quaternion::conjugate(){
	x *= -1;
	y *= -1;
	z *= -1;

	return *this;
}

Quaternion Quaternion::inverse(){
	return conjugate().normalize();
}

Matrix4 Quaternion::getMatrix4(){
	double n11 = 1-2*y*y-2*z*z,
			n12 = 2*x*y - 2*w*z,
			n13 = 2*x*z + 2*y*w,
			n21 = 2*x*y + 2*z*w,
			n22 = 1-2*x*x - 2*z*z,
			n23 = 2*y*z - 2*x*w,
			n31 = 2*x*z - 2*y*w,
			n32 = 2*y*z + 2*x*w,
			n33 = 1-2*x*x - 2*y*y;
	Matrix4 matrix;
	matrix.set(
		n11, n12, n13, 0,
		n21, n22, n23, 0,
		n31, n32, n33, 0,
		0,   0,   0,   1
	);
	return matrix;
}

Matrix3 Quaternion::getMatrix3(){
	double n11 = 1-2*y*y-2*z*z,
			n12 = 2*x*y - 2*w*z,
			n13 = 2*x*z + 2*y*w,
			n21 = 2*x*y + 2*z*w,
			n22 = 1-2*x*x - 2*z*z,
			n23 = 2*y*z - 2*x*w,
			n31 = 2*x*z - 2*y*w,
			n32 = 2*y*z + 2*x*w,
			n33 = 1-2*x*x - 2*y*y;
	Matrix3 matrix;
	matrix.set(
		n11, n12, n13,
		n21, n22, n23,
		n31, n32, n33
	);
	return matrix;
}

Quaternion Quaternion::integrate(Vector3 v, double t){
	Quaternion q(v.x*t, v.y*t, v.z*t, 0);
	q *= *this;
	w = q.w * 0.5;
	x = q.x * 0.5;
	y = q.y * 0.5;
	z = q.z * 0.5;
	return normalize();
}

Quaternion Quaternion::rotateByVector(Vector3 v){
	Quaternion q (v.x, v.y, v.z, 0);
	*this *= q;
	return *this;
}

Quaternion Quaternion::rotateX(double theta){
	Quaternion q(sin(theta/2), 0, 0, cos(theta/2));
	*this *= q;
	return *this;
}

Quaternion Quaternion::rotateY(double theta){
	Quaternion q(0, sin(theta/2), 0, cos(theta/2));
	*this *= q;
	return *this;
}

Quaternion Quaternion::rotateZ(double theta){
	Quaternion q(0, 0, sin(theta/2), cos(theta/2));
	*this *= q;
	return *this;
}

Quaternion Quaternion::rotate(Vector3 axis, double theta){
	Quaternion q(axis.x*sin(theta/2), axis.y*sin(theta/2), axis.z*sin(theta/2), cos(theta/2));
	*this *= q;
	return *this;
}

Quaternion Quaternion::setFromAxisAngle(Vector3 axis, double theta){
	axis.normalize();
	w = cos(theta/2);
	x *= sin(theta/2);
	y *= sin(theta/2);
	z *= sin(theta/2);
}

Quaternion& Quaternion::operator*=(const Quaternion& q){
	w = w*q.w - x*q.x - y*q.y - z*q.z;
	x = w*q.x + x*q.w + y*q.z - z*q.y;
	y = w*q.y + y*q.w + z*q.x - x*q.z;
	z = w*q.z + z*q.w + x*q.y - y*q.x;
	return *this;
}

Quaternion Quaternion::operator*(const Quaternion& q){
	Quaternion result = *this;
	result *= q;
	return result;
}

Quaternion& Quaternion::operator=(const Quaternion& rhs){
	if (this == &rhs){
		return *this;
	}
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return *this;
}

bool Quaternion::operator==(const Quaternion& rhs){
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w));
}

bool Quaternion::operator!=(const Quaternion& rhs){
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const Quaternion& v){
	os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return os;
}