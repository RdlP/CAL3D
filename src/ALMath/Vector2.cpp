#include "Vector2.hpp"

Vector2::Vector2(){
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(double x, double y){
	this->x = x;
	this->y = y;
}

Vector2::~Vector2(){

}

Vector2 Vector2::clamp(Vector2 min, Vector2 max){
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

	return *this;
}

Vector2 Vector2::floorAM(){
	x = floor(x);
	y = floor(y);

	return *this;
}

Vector2 Vector2::ceilAM(){
	x = ceil(x);
	y = ceil(y);

	return *this;
}

Vector2 Vector2::roundAM(){
	x = round(x);
	y = round(y);

	return *this;
}

Vector2 Vector2::negate(){
	x = -x;
	y = -y;

	return *this;
}

double Vector2::dot(Vector2 v){
	return x * v.x + y * v.y;
}

double Vector2::length(){
	return sqrt(x * x + y * y);
}

Vector2 Vector2::normalize(){
	Vector2 v;
	v = *this / length();

	x = v.x;
	y = v.y;

	return *this;
}

double Vector2::distanceTo(Vector2 v){
	return sqrt((x - v.x)*(x - v.x) + (y - v.y) * (y - v.y));
}


Vector2 Vector2::set(double x, double y){
	this->x = x;
	this->y = y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& v){
	x += v.x;
	y += v.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& v){
	Vector2 result = *this;
	result += v;
	return result;
}

Vector2& Vector2::operator+=(const double& n){
	x += n;
	y += n;
	return *this;
}

Vector2 Vector2::operator+(const double& n){
	Vector2 result = *this;
	result += n;
	return result;
}

Vector2& Vector2::operator-=(const Vector2& v){
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v){
	Vector2 result = *this;
	result -= v;
	return result;
}

Vector2& Vector2::operator-=(const double& n){
	x -= n;
	y -= n;
	return *this;
}

Vector2 Vector2::operator-(const double& n){
	Vector2 result = *this;
	result -= n;
	return result;
}

Vector2& Vector2::operator*=(const Vector2& v){
	x *= v.x;
	y *= v.y;
	return *this;
}

Vector2 Vector2::operator*(const Vector2& v){
	Vector2 result = *this;
	result *= v;
	return result;
}

Vector2& Vector2::operator*=(const double& n){
	x *= n;
	y *= n;
	return *this;
}

Vector2 Vector2::operator*(const double& n){
	Vector2 result = *this;
	result *= n;
	return result;
}

Vector2& Vector2::operator/=(const Vector2& v){
	x /= v.x;
	y /= v.y;
	return *this;
}

Vector2 Vector2::operator/(const Vector2& v){
	Vector2 result = *this;
	result /= v;
	return result;
}

Vector2& Vector2::operator/=(const double& n){
	x /= n;
	y /= n;
	return *this;
}

Vector2 Vector2::operator/(const double& n){
	Vector2 result = *this;
	result /= n;
	return result;
}

Vector2& Vector2::operator=(const Vector2& rhs){
	if (this == &rhs){
		return *this;
	}
	x = rhs.x;
	y = rhs.y;
	return *this;
}

bool Vector2::operator==(const Vector2& rhs){
	return ((x == rhs.x) && (y == rhs.y));
}

bool Vector2::operator!=(const Vector2& rhs){
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const Vector2& v){
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}