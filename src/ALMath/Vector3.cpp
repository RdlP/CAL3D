#include "Vector3.hpp"

Vector3::Vector3(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3(){

}

Vector3 Vector3::clamp(Vector3 min, Vector3 max){
	if ( x < min.x ) {
		x = min.x;
	} else if ( x > max.x ) {
		x = max.x;
	}

	if ( y < min.y ) {
		y = min.y;
	} else if ( y > max.y ) {
		y = max.y;
	}

	if ( z < min.z ) {
		z = min.z;
	} else if ( z > max.z ) {
		z = max.z;
	}

	return *this;
}

Vector3 Vector3::floorAM(){
	x = floor(x);
	y = floor(y);
	z = floor(z);

	return *this;
}

Vector3 Vector3::ceilAM(){
	x = ceil(x);
	y = ceil(y);
	z = ceil(z);

	return *this;
}

Vector3 Vector3::roundAM(){
	x = round(x);
	y = round(y);
	z = round(z);

	return *this;
}

Vector3 Vector3::negate(){
	x = -x;
	y = -y;
	z = -z;

	return *this;
}

double Vector3::dot(Vector3 v){
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(Vector3 v){
	Vector3 r;
	r.x = y * v.z - z * v.y;
	r.y = z * v.x - x * v.z;
	r.z = x * v.y - y * v.x;

	return r;
}

double Vector3::length(){
	return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize(){
	Vector3 v;
	v = *this / length();

	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

double Vector3::distanceTo(Vector3 v){
	return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
}


Vector3 Vector3::set(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

Vector3& Vector3::operator+=(const Vector3& v){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& v){
	Vector3 result = *this;
	result += v;
	return result;
}

Vector3& Vector3::operator+=(const double& n){
	x += n;
	y += n;
	z += n;
	return *this;
}

Vector3 Vector3::operator+(const double& n){
	Vector3 result = *this;
	result += n;
	return result;
}

Vector3& Vector3::operator-=(const Vector3& v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3& v){
	Vector3 result = *this;
	result -= v;
	return result;
}

Vector3& Vector3::operator-=(const double& n){
	x -= n;
	y -= n;
	z -= n;
	return *this;
}

Vector3 Vector3::operator-(const double& n){
	Vector3 result = *this;
	result -= n;
	return result;
}

Vector3& Vector3::operator*=(const Vector3& v){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

Vector3 Vector3::operator*(const Vector3& v){
	Vector3 result = *this;
	result *= v;
	return result;
}

Vector3& Vector3::operator*=(const double& n){
	x *= n;
	y *= n;
	z *= n;
	return *this;
}

Vector3 Vector3::operator*(const double& n){
	Vector3 result = *this;
	result *= n;
	return result;
}

Vector3& Vector3::operator/=(const Vector3& v){
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

Vector3 Vector3::operator/(const Vector3& v){
	Vector3 result = *this;
	result /= v;
	return result;
}

Vector3& Vector3::operator/=(const double& n){
	x /= n;
	y /= n;
	z /= n;
	return *this;
}

Vector3 Vector3::operator/(const double& n){
	Vector3 result = *this;
	result /= n;
	return result;
}

Vector3& Vector3::operator=(const Vector3& rhs){
	if (this == &rhs){
		return *this;
	}
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

bool Vector3::operator==(const Vector3& rhs){
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
}

bool Vector3::operator!=(const Vector3& rhs){
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const Vector3& v){
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}