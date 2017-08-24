#include "Matrix4.hpp"

Matrix4::Matrix4(){
	c[0] = 1.0f;
	c[1] = 0.0f;
	c[2] = 0.0f;
	c[3] = 0.0f;

	c[4] = 0.0f;
	c[5] = 1.0f;
	c[6] = 0.0f;
	c[7] = 0.0f;

	c[8] = 0.0f;
	c[9] = 0.0f;
	c[10] = 1.0f;
	c[11] = 0.0f;

	c[12] = 0.0f;
	c[13] = 0.0f;
	c[14] = 0.0f;
	c[15] = 1.0f;
}

Matrix4::~Matrix4(){

}

Matrix4 Matrix4::set(double n11,double n12,double n13,double n14, double n21,double n22,double n23,double n24,double n31,double n32,double n33,double n34,double n41,double n42,double n43,double n44){
	c[0] = n11;
	c[1] = n21;
	c[2] = n31;
	c[3] = n41;

	c[4] = n12;
	c[5] = n22;
	c[6] = n32;
	c[7] = n42;

	c[8] = n13;
	c[9] = n23;
	c[10] = n33;
	c[11] = n43;

	c[12] = n14;
	c[13] = n24;
	c[14] = n34;
	c[15] = n44;
}

Matrix4 Matrix4::identity(){
	this->set(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	return *this;
}

double Matrix4::determinant(){
	return this->c[0]*this->c[4]*this->c[8]-this->c[0]*this->c[5]*this->c[7]-this->c[1]*this->c[3]*this->c[8]+this->c[1]*this->c[5]*this->c[6]+this->c[1]*this->c[3]*this->c[7]-this->c[2]*this->c[4]*this->c[6];
}

Matrix4 Matrix4::transpose(){
	double tmp;
	tmp = c[1];
	c[1] = c[4];
	c[4] = tmp;

	tmp = c[2];
	c[2] = c[8];
	c[8] = tmp;

	tmp = c[6];
	c[6] = c[9];
	c[9] = tmp;

	tmp = c[3];
	c[3] = c[12];
	c[12] = tmp;

	tmp = c[7];
	c[7] = c[13];
	c[13] = tmp;

	tmp = c[11];
	c[11] = c[14];
	c[14] = tmp;

	return *this;
}

Matrix4 Matrix4::translate(double x, double y, double z){
	set(
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	);

	return *this;
}

Matrix4 Matrix4::rotateX(double theta){
	double c = cos(theta);
	double s = sin(theta);
	set(
		1, 0, 0, 0,
		0, c, -s, 0,
		0, s, c, 0,
		0, 0, 0, 1
	);

	return *this;
}

Matrix4 Matrix4::rotateY(double theta){
	double c = cos(theta);
	double s = sin(theta);
	set(
		c, 0, s, 0,
		0, 1, 0, 0,
		-s, 0, c, 0,
		0, 0, 0, 1
	);

	return *this;
}

Matrix4 Matrix4::rotateZ(double theta){
	double c = cos(theta);
	double s = sin(theta);
	set(
		c, -s, 0, 0,
		s, c, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	return *this;
}

Matrix4 Matrix4::rotate(double x, double y, double z){
	Matrix4 rx, ry, rz, r;
	rx.rotateX(x);
	ry.rotateY(y);
	rz.rotateZ(z);
	r = rz * ry * rx;
	memcpy(this->c, r.c, 9*sizeof(double));

	return *this;
}

Matrix4 Matrix4::scale(double x, double y, double z){
	set(
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	);

	return *this;
}

Matrix4 Matrix4::orthographicProjection(double left, double right, double top, double bottom, double near, double far){
	double a = 2/(right-left);
	double b = 2/(top-bottom);
	double cc = -2/(far-near);
	double d = -((right+left)/(right-left));
	double e = -((top+bottom)/(top-bottom));
	double f = -((far+near)/(far-near));

	c[0] = a;		c[4] = 0;		c[8] = 0;		c[12] = 0;
	c[1] = 0;		c[5] = b;		c[9] = 0;		c[13] = 0;
	c[2] = 0;		c[6] = 0;		c[10] = cc;		c[14] = 0;
	c[3] = d;		c[7] = e;		c[11] = f;		c[15] = 1;

	return *this;
}

Matrix4 Matrix4::perspectiveProjection(double fov, double aspect, double zNear, double zFar){
	double a = aspect;

	double t=tan((0.5*fov));
    double A=-(zFar+zNear)/(zFar-zNear);
    double B=(-2*zFar*zNear)/(zFar-zNear);

    c[0] = 0.5/t;			c[4] = 0;				c[8] = 0;			c[ 12 ] = 0;
	c[1] = 0;				c[5] = (0.5*a/t);		c[9] = 0;			c[ 13 ] = 0;
	c[2] = 0;				c[6] = 0;				c[10] = A;		c[ 14 ] = B;
	c[3] = 0;				c[7] = 0;				c[11] =-1;	

	return *this;
}

Matrix3 Matrix4::getNormalMatrix(bool scale){
	Matrix3 m3;
	if (scale == true){
		m3.set(
			c[0], c[1], c[2],
			c[4], c[5], c[6],
			c[8], c[9], c[10]
		);
		m3.inverse().transpose();
	}else{
		m3.set(
			c[0], c[4], c[8],
			c[1], c[5], c[9],
			c[2], c[6], c[10]
		);
	}
	return m3;
}


Matrix4 Matrix4::inverse(){
	Matrix4 inv;

	double n11 = c[ 0 ], n21 = c[ 1 ], n31 = c[ 2 ], n41 = c[ 3 ];
	double n12 = c[ 4 ], n22 = c[ 5 ], n32 = c[ 6 ], n42 = c[ 7 ];
	double n13 = c[ 8 ], n23 = c[ 9 ], n33 = c[ 10 ], n43 = c[ 11 ];
	double n14 = c[ 12 ], n24 = c[ 13 ], n34 = c[ 14 ], n44 = c[ 15 ];

	double t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
	double t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
	double t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
	double t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

	double det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;


	double detInv = 1.0 / det;

	inv.c[ 0 ] = t11 * detInv;
	inv.c[ 1 ] = ( n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44 ) * detInv;
	inv.c[ 2 ] = ( n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44 ) * detInv;
	inv.c[ 3 ] = ( n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43 ) * detInv;

	inv.c[ 4 ] = t12 * detInv;
	inv.c[ 5 ] = ( n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44 ) * detInv;
	inv.c[ 6 ] = ( n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44 ) * detInv;
	inv.c[ 7 ] = ( n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43 ) * detInv;

	inv.c[ 8 ] = t13 * detInv;
	inv.c[ 9 ] = ( n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44 ) * detInv;
	inv.c[ 10 ] = ( n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44 ) * detInv;
	inv.c[ 11 ] = ( n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43 ) * detInv;

	inv.c[ 12 ] = t14 * detInv;
	inv.c[ 13 ] = ( n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34 ) * detInv;
	inv.c[ 14 ] = ( n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34 ) * detInv;
	inv.c[ 15 ] = ( n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33 ) * detInv;

	memcpy(c,inv.c, 16*sizeof(double));

	return *this;
}

Vector3 Matrix4::transform(Vector3 v){
	Vector3 r;
	double v0 = v.x, v1 = v.y, v2 = v.z;
	double d = v0 * c[0 * 4 + 3] + v1 * c[1 * 4 + 3] + v2 * c[2 * 4 + 3] + c[3 * 4 + 3];
	r.x = (v0 * c[0 * 4 + 0] + v1 * c[1 * 4 + 0] + v2 * c[2 * 4 + 0] + c[3 * 4 + 0]) / d;
	r.y = (v0 * c[0 * 4 + 1] + v1 * c[1 * 4 + 1] + v2 * c[2 * 4 + 1] + c[3 * 4 + 1]) / d;
	r.z = (v0 * c[0 * 4 + 2] + v1 * c[1 * 4 + 2] + v2 * c[2 * 4 + 2] + c[3 * 4 + 2]) / d;

	return r;
}

Matrix4 Matrix4::lookAt(Vector3 eye, Vector3 target, Vector3 up){
	Vector3 z = target - eye;
	z.normalize();

	Vector3 x = z.cross(up);
	x.normalize();

	Vector3 y = x.cross(z);
	y.normalize();

	c[0] = x.x; c[1] = x.y; c[2] = x.z; c[3] = 0;
	c[4] = y.x; c[5] = y.y; c[6] = y.z; c[7] = 0;
	c[8] = -z.x; c[9] = -z.y; c[10] = -z.z; c[11] = 0;
	c[12] = eye.x; c[13] = eye.y; c[14] = eye.z; c[15] = 1;

	return *this;
}

Matrix4& Matrix4::operator+=(const Matrix4& m){
	this->c[0] += m.c[0];
	this->c[1] += m.c[1];
	this->c[2] += m.c[2];
	this->c[3] += m.c[3];
	this->c[4] += m.c[4];
	this->c[5] += m.c[5];
	this->c[6] += m.c[6];
	this->c[7] += m.c[7];
	this->c[8] += m.c[8];
	this->c[9] += m.c[9];
	this->c[10] += m.c[10];
	this->c[11] += m.c[11];
	this->c[12] += m.c[12];
	this->c[13] += m.c[13];
	this->c[14] += m.c[14];
	this->c[15] += m.c[15];
	return *this;
}

Matrix4 Matrix4::operator+(const Matrix4& m){
	Matrix4 result = *this;
	result += m;
	return result;
}

Matrix4& Matrix4::operator+=(const double& n){
	this->c[0] += n;
	this->c[1] += n;
	this->c[2] += n;
	this->c[3] += n;
	this->c[4] += n;
	this->c[5] += n;
	this->c[6] += n;
	this->c[7] += n;
	this->c[8] += n;
	this->c[9] += n;
	this->c[10] += n;
	this->c[11] += n;
	this->c[12] += n;
	this->c[13] += n;
	this->c[14] += n;
	this->c[15] += n;
	return *this;
}

Matrix4 Matrix4::operator+(const double& n){
	Matrix4 result = *this;
	result += n;
	return result;
}

Matrix4& Matrix4::operator-=(const Matrix4& m){
	this->c[0] -= m.c[0];
	this->c[1] -= m.c[1];
	this->c[2] -= m.c[2];
	this->c[3] -= m.c[3];
	this->c[4] -= m.c[4];
	this->c[5] -= m.c[5];
	this->c[6] -= m.c[6];
	this->c[7] -= m.c[7];
	this->c[8] -= m.c[8];
	this->c[9] -= m.c[9];
	this->c[10] -= m.c[10];
	this->c[11] -= m.c[11];
	this->c[12] -= m.c[12];
	this->c[13] -= m.c[13];
	this->c[14] -= m.c[14];
	this->c[15] -= m.c[15];
	return *this;
}

Matrix4 Matrix4::operator-(const Matrix4& m){
	Matrix4 result = *this;
	result -= m;
	return result;
}

Matrix4& Matrix4::operator-=(const double& n){
	this->c[0] -= n;
	this->c[1] -= n;
	this->c[2] -= n;
	this->c[3] -= n;
	this->c[4] -= n;
	this->c[5] -= n;
	this->c[6] -= n;
	this->c[7] -= n;
	this->c[8] -= n;
	this->c[9] -= n;
	this->c[10] -= n;
	this->c[11] -= n;
	this->c[12] -= n;
	this->c[13] -= n;
	this->c[14] -= n;
	this->c[15] -= n;
	return *this;
}

Matrix4 Matrix4::operator-(const double& n){
	Matrix4 result = *this;
	result -= n;
	return result;
}

Matrix4& Matrix4::operator*=(const Matrix4& rhs){
	double r[16];
	
	double o11 = rhs.c[0], o12 = rhs.c[4], o13 = rhs.c[8], o14 = rhs.c[12];
	double o21 = rhs.c[1], o22 = rhs.c[5], o23 = rhs.c[9], o24 = rhs.c[13];
	double o31 = rhs.c[2], o32 = rhs.c[6], o33 = rhs.c[10], o34 = rhs.c[14];
	double o41 = rhs.c[3], o42 = rhs.c[7], o43 = rhs.c[11], o44 = rhs.c[15];

	r[0] = c[0] * o11 + c[4] * o21 + c[8] * o31 + c[12] * o41;
	r[4] = c[0] * o12 + c[4] * o22 + c[8] * o32 + c[12] * o42;
	r[8] = c[0] * o13 + c[4] * o23 + c[8] * o33 + c[12] * o43;
	r[12] = c[0] * o14 + c[4] * o24 + c[8] * o34 + c[12] * o44;

	r[1] = c[1] * o11 + c[5] * o21 + c[9] * o31 + c[13] * o41;
	r[5] = c[1] * o12 + c[5] * o22 + c[9] * o32 + c[13] * o42;
	r[9] = c[1] * o13 + c[5] * o23 + c[9] * o33 + c[13] * o43;
	r[13] = c[1] * o14 + c[5] * o24 + c[9] * o34 + c[13] * o44;

	r[2] = c[2] * o11 + c[6] * o21 + c[10] * o31 + c[14] * o41;
	r[6] = c[2] * o12 + c[6] * o22 + c[10] * o32 + c[14] * o42;
	r[10] = c[2] * o13 + c[6] * o23 + c[10] * o33 + c[14] * o43;
	r[14] = c[2] * o14 + c[6] * o24 + c[10] * o34 + c[14] * o44;

	r[3] = c[3] * o11 + c[7] * o21 + c[11] * o31 + c[15] * o41;
	r[7] = c[3] * o12 + c[7] * o22 + c[11] * o32 + c[15] * o42;
	r[11] = c[3] * o13 + c[7] * o23 + c[11] * o33 + c[15] * o43;
	r[15] = c[3] * o14 + c[7] * o24 + c[11] * o34 + c[15] * o44;

	memcpy(this->c, r, 16*sizeof(double));
	return *this;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs){
	Matrix4 result = *this;
	result *= rhs;
	return result;
}

Matrix4& Matrix4::operator*=(const double& n){
	c[0] *= n;
	c[1] *= n;
	c[2] *= n;
	c[3] *= n;
	c[4] *= n;
	c[5] *= n;
	c[6] *= n;
	c[7] *= n;
	c[8] *= n;
	c[9] *= n;
	c[10] *= n;
	c[11] *= n;
	c[12] *= n;
	c[13] *= n;
	c[14] *= n;
	c[15] *= n;
	return *this;
}

Matrix4 Matrix4::operator*(const double& n){
	Matrix4 result = *this;
	result *= n;
	return result;
}

Vector3 Matrix4::operator*(const Vector3& v){
	Vector3 r;
	r.x = c[0]*v.x+c[4]*v.y+c[8]*v.z+c[12];
	r.y = c[1]*v.x+c[5]*v.y+c[9]*v.z+c[13];
	r.z = c[2]*v.x+c[6]*v.y+c[10]*v.z+c[14];
	
	return r;
}

Vector4 Matrix4::operator*(const Vector4& v){
	Vector4 r;
	r.x = c[0]*v.x+c[4]*v.y+c[8]*v.z+c[12]*v.w;
	r.y = c[1]*v.x+c[5]*v.y+c[9]*v.z+c[13]*v.w;
	r.z = c[2]*v.x+c[6]*v.y+c[10]*v.z+c[14]*v.w;
	r.w = c[3]*v.x+c[7]*v.y+c[11]*v.z+c[15]*v.w;

	return r;
}

Matrix4& Matrix4::operator/=(const double& n){
	this->c[0] /= n;
	this->c[1] /= n;
	this->c[2] /= n;
	this->c[3] /= n;
	this->c[4] /= n;
	this->c[5] /= n;
	this->c[6] /= n;
	this->c[7] /= n;
	this->c[8] /= n;
	this->c[9] /= n;
	this->c[10] /= n;
	this->c[11] /= n;
	this->c[12] /= n;
	this->c[13] /= n;
	this->c[14] /= n;
	this->c[15] /= n;
	return *this;
}

Matrix4 Matrix4::operator/(const double& n){
	Matrix4 result = *this;
	result /= n;
	return result;
}

Matrix4& Matrix4::operator=(const Matrix4& rhs){
	if (this == &rhs){
		return *this;
	}
	memcpy(this->c, rhs.c, 9*sizeof(double));
	return *this;
}

bool Matrix4::operator==(const Matrix4& rhs){
	return ((this->c[0] == rhs.c[0]) && (this->c[1] == rhs.c[1]) && (this->c[2] == rhs.c[2]) && (this->c[3] == rhs.c[3]) && (this->c[4] == rhs.c[4]) && (this->c[5] == rhs.c[5]) && (this->c[6] == rhs.c[6]) && (this->c[7] == rhs.c[7]) && (this->c[8] == rhs.c[8]) && (this->c[9] == rhs.c[9]) && (this->c[10] == rhs.c[10]) && (this->c[11] == rhs.c[11]) && (this->c[12] == rhs.c[12]) && (this->c[13] == rhs.c[13]) && (this->c[14] == rhs.c[14]) && (this->c[15] == rhs.c[15]));
}

bool Matrix4::operator!=(const Matrix4& rhs){
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const Matrix4& m){
	os << m.c[0] << " " << m.c[1] << " " << m.c[2] << " " << m.c[3] << std::endl;
	os << m.c[4] << " " << m.c[5] << " " << m.c[6] << " " << m.c[7] << std::endl;
	os << m.c[8] << " " << m.c[9] << " " << m.c[10] << " " << m.c[11] << std::endl;
	os << m.c[12] << " " << m.c[13] << " " << m.c[14] << " " << m.c[15];
	return os;
}