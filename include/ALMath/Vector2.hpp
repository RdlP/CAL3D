#ifndef VECTOR2_HEADER
#define VECTOR2_HEADER


 #include <string.h>
 #include <math.h>
 #include <ostream>

class Vector2{
public:
	Vector2();
	Vector2(double, double);
	virtual ~Vector2();
	Vector2 clamp(Vector2, Vector2);
	Vector2 floorAM();
	Vector2 ceilAM();
	Vector2 roundAM();
	Vector2 negate();
	double dot(Vector2);
	double length();
	Vector2 normalize();
	double distanceTo(Vector2);
	Vector2 set(double, double);
	
	//void transform();
	//void makeOrthonormalBasis();
	Vector2& operator+=(const Vector2&);
	Vector2 operator+(const Vector2&);

	Vector2& operator+=(const double&);
	Vector2 operator+(const double&);

	Vector2& operator-=(const Vector2&);
	Vector2 operator-(const Vector2&);

	Vector2& operator-=(const double&);
	Vector2 operator-(const double&);

	Vector2& operator*=(const Vector2&);
	Vector2 operator*(const Vector2&);
	
	Vector2& operator*=(const double&);
	Vector2 operator*(const double&);

	Vector2& operator/=(const Vector2&);
	Vector2 operator/(const Vector2&);

	Vector2& operator/=(const double&);
	Vector2 operator/(const double&);

	Vector2 & operator=(const Vector2&);

	bool operator==(const Vector2&);
	bool operator!=(const Vector2&);

	//std::ostream&  operator << (std::ostream &os);

	friend std::ostream&  operator << (std::ostream &os, const Vector2& v);

	/*friend std::ostream&  operator << (std::ostream &os, const Matrix4& m){
			os << m.c[0] << " " << m.c[1] << " " << m.c[2] << std::endl;
	os << m.c[3] << " " << m.c[4] << " " << m.c[5] << std::endl;
	os << m.c[6] << " " << m.c[7] << " " << m.c[8] << std::endl;
	return os;
	}*/

	double x, y, z;

};

#endif