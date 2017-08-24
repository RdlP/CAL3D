#include "Vector4.hpp"

Vector4::Vector4(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Vector4::Vector4(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4(){

}

Vector4 Vector4::clamp(Vector4 min, Vector4 max){
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

	if ( w < min.w ) {
		w = min.w;
	} else if ( w > max.w ) {
		w = max.w;
	}

	return *this;
}

Vector4 Vector4::floorAM(){
	x = floor(x);
	y = floor(y);
	z = floor(z);
	w = floor(w);

	return *this;
}

Vector4 Vector4::ceilAM(){
	x = ceil(x);
	y = ceil(y);
	z = ceil(z);
	w = ceil(w);

	return *this;
}

Vector4 Vector4::roundAM(){
	x = round(x);
	y = round(y);
	z = round(z);
	w = round(w);

	return *this;
}

Vector4 Vector4::negate(){
	x = -x;
	y = -y;
	z = -z;
	w = -w;

	return *this;
}

double Vector4::dot(Vector4 v){
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

double Vector4::length(){
	return sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::normalize(){
	Vector4 v;
	v = *this / length();

	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;

	return *this;
}

double Vector4::distanceTo(Vector4 v){
	return sqrt((x - v.x) * (x - v.x) + (y - v.y) + (y - v.y) + (z - v.z) * (z - v.z) + (w - v.w) * (w - v.w));
}


Vector4 Vector4::set(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;

	return *this;
}

Vector4& Vector4::operator+=(const Vector4& v){
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

Vector4 Vector4::operator+(const Vector4& v){
	Vector4 result = *this;
	result += v;
	return result;
}

Vector4& Vector4::operator+=(const double& n){
	x += n;
	y += n;
	z += n;
	w += n;
	return *this;
}

Vector4 Vector4::operator+(const double& n){
	Vector4 result = *this;
	result += n;
	return result;
}

Vector4& Vector4::operator-=(const Vector4& v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

Vector4 Vector4::operator-(const Vector4& v){
	Vector4 result = *this;
	result -= v;
	return result;
}

Vector4& Vector4::operator-=(const double& n){
	x -= n;
	y -= n;
	z -= n;
	w -= n;
	return *this;
}

Vector4 Vector4::operator-(const double& n){
	Vector4 result = *this;
	result -= n;
	return result;
}

Vector4& Vector4::operator*=(const Vector4& v){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}

Vector4 Vector4::operator*(const Vector4& v){
	Vector4 result = *this;
	result *= v;
	return result;
}

Vector4& Vector4::operator*=(const double& n){
	x *= n;
	y *= n;
	z *= n;
	w *= n;
	return *this;
}

Vector4 Vector4::operator*(const double& n){
	Vector4 result = *this;
	result *= n;
	return result;
}

Vector4& Vector4::operator/=(const Vector4& v){
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

Vector4 Vector4::operator/(const Vector4& v){
	Vector4 result = *this;
	result /= v;
	return result;
}

Vector4& Vector4::operator/=(const double& n){
	x /= n;
	y /= n;
	z /= n;
	w /= n;
	return *this;
}

Vector4 Vector4::operator/(const double& n){
	Vector4 result = *this;
	result /= n;
	return result;
}

Vector4& Vector4::operator=(const Vector4& rhs){
	if (this == &rhs){
		return *this;
	}
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return *this;
}

bool Vector4::operator==(const Vector4& rhs){
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w));
}

bool Vector4::operator!=(const Vector4& rhs){
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const Vector4& v){
	os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return os;
}