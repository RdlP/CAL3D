#include "Matrix3.hpp"

Matrix3::Matrix3(){
	c[0] = 1.0f;
	c[1] = 0.0f;
	c[2] = 0.0f;

	c[3] = 0.0f;
	c[4] = 1.0f;
	c[5] = 0.0f;

	c[6] = 0.0f;
	c[7] = 0.0f;
	c[8] = 1.0f;
}

Matrix3::~Matrix3(){

}

Matrix3 Matrix3::set(double n11,double n12,double n13,double n21,double n22,double n23,double n31,double n32,double n33){
	c[0] = n11;
	c[1] = n21;
	c[2] = n31;

	c[3] = n12;
	c[4] = n22;
	c[5] = n32;

	c[6] = n13;
	c[7] = n23;
	c[8] = n33;
	return *this;
}

Matrix3 Matrix3::identity(){
	this->set(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
	return *this;
}

double Matrix3::determinant(){
	return this->c[0]*this->c[4]*this->c[8]-this->c[0]*this->c[5]*this->c[7]-this->c[1]*this->c[3]*this->c[8]+this->c[1]*this->c[5]*this->c[6]+this->c[1]*this->c[3]*this->c[7]-this->c[2]*this->c[4]*this->c[6];
}

Matrix3 Matrix3::transpose(){
	double tmp;
	tmp = this->c[1];
	c[1] = c[3];
	c[3] = tmp;

	tmp = c[2];
	c[2] = c[6];
	c[6] = tmp;

	tmp = c[5];
	c[5] = c[7];
	c[7] = tmp;
	return *this;
}

Matrix3 Matrix3::inverse(){
	double n11,n12,n13,n21,n22,n23,n31,n32,n33;
	n11 = this->c[4]*this->c[8] - this->c[5]*this->c[7],
	n12 = -1*(this->c[1]*this->c[8] - this->c[2]*this->c[7]),
	n13 = this->c[1]*this->c[5] - this->c[2]*this->c[4],

	n21 = -1*(this->c[3]*this->c[8] - this->c[5]*this->c[6]),
	n22 = this->c[0]*this->c[8] - this->c[2]*this->c[6],
	n23 = -1*(this->c[0]*this->c[5] - this->c[2]*this->c[3]),

	n31 = this->c[3]*this->c[7] - this->c[4]*this->c[6],
	n32 = -1*(this->c[0]*this->c[7] - this->c[1]*this->c[6]),
	n33 = this->c[0]*this->c[4] - this->c[1]*this->c[3];

	double determinant = this->determinant();
	if (determinant == 0.0f){
		Matrix3 m;
		return m;
	}
	this->set(
		n11, n12, n13,
		n21, n22, n23,
		n31, n32, n33
	);

	Matrix3 m;
	m = *this * (1.0f/determinant);
	memcpy(this->c, m.c, 9*sizeof(double));
	return *this;
}

Vector3 Matrix3::transform(Vector3 v){
	Vector3 r;
	r.x = c[0]*v.x+c[3]*v.y+c[6]*v.z;
	r.y = c[1]*v.x+c[4]*v.y+c[7]*v.z;
	r.z = c[2]*v.x+c[5]*v.y+c[8]*v.z;

	return r;
}

Matrix3 Matrix3::makeOrthonormalBasis(Vector3 x, Vector3 y){
	Vector3 z = x.cross(y);
	if (z.length() == 0){
		y = Vector3(1,0,0);
		z = x.cross(y);
	}

	y = z.cross(x);
	y.normalize();
	z.normalize();
	Matrix3 matrix;

	matrix.set(x.x, y.x, z.x, x.y, y.y, z.y, x.z, y.z, z.z);
	return matrix;
}

Matrix3& Matrix3::operator+=(const Matrix3& m){
	this->c[0] += m.c[0];
	this->c[1] += m.c[1];
	this->c[2] += m.c[2];
	this->c[3] += m.c[3];
	this->c[4] += m.c[4];
	this->c[5] += m.c[5];
	this->c[6] += m.c[6];
	this->c[7] += m.c[7];
	this->c[8] += m.c[8];
}

Matrix3 Matrix3::operator+(const Matrix3& m){
	Matrix3 result = *this;
	result += m;
	return result;
}

Matrix3& Matrix3::operator+=(const double& n){
	this->c[0] += n;
	this->c[1] += n;
	this->c[2] += n;
	this->c[3] += n;
	this->c[4] += n;
	this->c[5] += n;
	this->c[6] += n;
	this->c[7] += n;
	this->c[8] += n;
}

Matrix3 Matrix3::operator+(const double& n){
	Matrix3 result = *this;
	result += n;
	return result;
}

Matrix3& Matrix3::operator-=(const Matrix3& m){
	this->c[0] -= m.c[0];
	this->c[1] -= m.c[1];
	this->c[2] -= m.c[2];
	this->c[3] -= m.c[3];
	this->c[4] -= m.c[4];
	this->c[5] -= m.c[5];
	this->c[6] -= m.c[6];
	this->c[7] -= m.c[7];
	this->c[8] -= m.c[8];
}

Matrix3 Matrix3::operator-(const Matrix3& m){
	Matrix3 result = *this;
	result -= m;
	return result;
}

Matrix3& Matrix3::operator-=(const double& n){
	this->c[0] -= n;
	this->c[1] -= n;
	this->c[2] -= n;
	this->c[3] -= n;
	this->c[4] -= n;
	this->c[5] -= n;
	this->c[6] -= n;
	this->c[7] -= n;
	this->c[8] -= n;
}

Matrix3 Matrix3::operator-(const double& n){
	Matrix3 result = *this;
	result -= n;
	return result;
}

Matrix3& Matrix3::operator*=(const Matrix3& rhs){
	double r[9];
	double o11 = rhs.c[0], o12 =  rhs.c[3], o13 =  rhs.c[6];
	double o21 =  rhs.c[1], o22 =  rhs.c[4], o23 =  rhs.c[7];
	double o31 =  rhs.c[2], o32 =  rhs.c[5], o33 =  rhs.c[8];

	r[0] = c[0] * o11 + c[3] * o21 + c[6] * o31;
	r[3] = c[0] * o12 + c[3] * o22 + c[6] * o32;
	r[6] = c[0] * o13 + c[3] * o23 + c[6] * o33;

	r[1] = c[1] * o11 + c[4] * o21 + c[7] * o31;
	r[4] = c[1] * o12 + c[4] * o22 + c[7] * o32;
	r[7] = c[1] * o13 + c[4] * o23 + c[7] * o33;

	r[2] = c[2] * o11 + c[5] * o21 + c[8] * o31;
	r[5] = c[2] * o12 + c[5] * o22 + c[8] * o32;
	r[8] = c[2] * o13 + c[5] * o23 + c[8] * o33;

	memcpy(this->c, r, 9*sizeof(double));
	return *this;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs){
	Matrix3 result = *this;
	result *= rhs;
	return result;
}

Matrix3& Matrix3::operator*=(const double& n){
	c[0] *= n;
	c[1] *= n;
	c[2] *= n;
	c[3] *= n;
	c[4] *= n;
	c[5] *= n;
	c[6] *= n;
	c[7] *= n;
	c[8] *= n;
	return *this;
}

Matrix3 Matrix3::operator*(const double& n){
	Matrix3 result = *this;
	result *= n;
	return result;
}

Vector3 Matrix3::operator*(const Vector3& v){
	Vector3 r;
	r.x = c[0]*v.x+c[3]*v.y+c[6]*v.z;
	r.y = c[1]*v.x+c[4]*v.y+c[7]*v.z;
	r.z = c[2]*v.x+c[5]*v.y+c[8]*v.z;

	return r;
}

Matrix3& Matrix3::operator/=(const double& n){
	this->c[0] /= n;
	this->c[1] /= n;
	this->c[2] /= n;
	this->c[3] /= n;
	this->c[4] /= n;
	this->c[5] /= n;
	this->c[6] /= n;
	this->c[7] /= n;
	this->c[8] /= n;
	return *this;
}

Matrix3 Matrix3::operator/(const double& n){
	Matrix3 result = *this;
	result /= n;
	return result;
}

Matrix3& Matrix3::operator=(const Matrix3& rhs){
	if (this == &rhs){
		return *this;
	}
	memcpy(this->c, rhs.c, 9*sizeof(double));
	return *this;
}

bool Matrix3::operator==(const Matrix3& rhs){
	return ((this->c[0] == rhs.c[0]) && (this->c[1] == rhs.c[1]) && (this->c[2] == rhs.c[2]) && (this->c[3] == rhs.c[3]) && (this->c[4] == rhs.c[4]) && (this->c[5] == rhs.c[5]) && (this->c[6] == rhs.c[6]) && (this->c[7] == rhs.c[7]) && (this->c[8] == rhs.c[8]));
}

bool Matrix3::operator!=(const Matrix3& rhs){
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const Matrix3& m){
	os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8];
	return os;
}