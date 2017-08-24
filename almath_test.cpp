#include "include/ALMath/Matrix3.hpp"
#include "include/ALMath/Matrix4.hpp"
#include "include/ALMath/Vector2.hpp"
#include "include/ALMath/Vector3.hpp"
#include "include/ALMath/Vector4.hpp"
#include <iostream>

int main(int argc, char** argv){
	std::cout << "=============================" << std::endl;
	std::cout << "=         Vector2           =" << std::endl;
	std::cout << "=============================" << std::endl;

	Vector2 v21(3,5), v22(1,7);

	Vector2 r2 = v21 + v22;
	std::cout << "Suma:" << std::endl;
	std::cout << v21 << " + " << v22 << " = " << r2 << std::endl;

	r2 = v21 - v22;
	std::cout << "Resta:" << std::endl;
	std::cout << v21 << " - " << v22 << " = " << r2 << std::endl;

	r2 = v21 / v22;
	std::cout << "Division:" << std::endl;
	std::cout << v21 << " / " << v22 << " = " << r2 << std::endl;

	r2 = v21 * v22;
	std::cout << "Multiplicacion:" << std::endl;
	std::cout << v21 << " * " << v22 << " = " << r2 << std::endl;

	double result = v21.distanceTo(v22);
	std::cout << "Distance entre los puntos " << v21 << " y " << v22 << std::endl;
	std::cout << result << std::endl;

	result = v21.dot(v22);
	std::cout << "Producto punto:" << std::endl;
	std::cout << v21 << " · " << v22 << " = " << result << std::endl;

	std::cout << "longitud de " << v21 << std::endl;
	std::cout << v21.length() << std::endl;

	std::cout << v21 << " normalizado" << std::endl;
	std::cout << v21.normalize() << std::endl;



	std::cout << "=============================" << std::endl;
	std::cout << "=         Vector3           =" << std::endl;
	std::cout << "=============================" << std::endl;

	Vector3 v31(5,2,9), v32(1,3,4);

	Vector3 r3 = v31 + v32;
	std::cout << "Suma:" << std::endl;
	std::cout << v31 << " + " << v32 << " = " << r3 << std::endl;

	r3 = v31 - v32;
	std::cout << "Resta:" << std::endl;
	std::cout << v31 << " - " << v32 << " = " << r3 << std::endl;

	r3 = v31 / v32;
	std::cout << "Division:" << std::endl;
	std::cout << v31 << " / " << v32 << " = " << r3 << std::endl;

	r3 = v31 * v32;
	std::cout << "Multiplicacion:" << std::endl;
	std::cout << v31 << " * " << v32 << " = " << r3 << std::endl;

	result = v31.distanceTo(v32);
	std::cout << "Distance entre los puntos " << v31 << " y " << v32 << std::endl;
	std::cout << result << std::endl;

	result = v31.dot(v32);
	std::cout << "Producto punto:" << std::endl;
	std::cout << v31 << " · " << v32 << " = " << result << std::endl;

	r3 = v31.cross(v32);
	std::cout << "Producto vectorial:" << std::endl;
	std::cout << v31 << " x " << v32 << " = " << r3 << std::endl;

	std::cout << "longitud de " << v31 << std::endl;
	std::cout << v31.length() << std::endl;

	std::cout << v31 << " normalizado" << std::endl;
	std::cout << v31.normalize() << std::endl;



	std::cout << "=============================" << std::endl;
	std::cout << "=         Vector4           =" << std::endl;
	std::cout << "=============================" << std::endl;

	Vector4 v41(6,3,7,2), v42(4,3,1,8);

	Vector4 r4 = v41 + v42;
	std::cout << "Suma:" << std::endl;
	std::cout << v41 << " + " << v42 << " = " << r4 << std::endl;

	r4 = v41 - v42;
	std::cout << "Resta:" << std::endl;
	std::cout << v41 << " - " << v42 << " = " << r4 << std::endl;

	r4 = v41 / v42;
	std::cout << "Division:" << std::endl;
	std::cout << v41 << " / " << v42 << " = " << r4 << std::endl;

	r4 = v41 * v42;
	std::cout << "Multiplicacion:" << std::endl;
	std::cout << v41 << " * " << v42 << " = " << r4 << std::endl;

	result = v41.distanceTo(v42);
	std::cout << "Distance entre los puntos " << v41 << " y " << v42 << std::endl;
	std::cout << result << std::endl;

	result = v41.dot(v42);
	std::cout << "Producto punto:" << std::endl;
	std::cout << v41 << " · " << v42 << " = " << result << std::endl;

	std::cout << "longitud de " << v41 << std::endl;
	std::cout << v41.length() << std::endl;

	std::cout << v41 << " normalizado" << std::endl;
	std::cout << v41.normalize() << std::endl;

	std::cout << "=============================" << std::endl;
	std::cout << "=         Matrix3           =" << std::endl;
	std::cout << "=============================" << std::endl;
	Matrix3 identity;
	std::cout << "Matriz identidad" << std::endl;
	std::cout << identity << std::endl << std::endl;
	Matrix3 m3a,m3r,m3b;
	m3a.set(1,2,3,4,5,6,7,8,9);
	m3b.set(3,8,2,0,4,7,1,4,2);

	std::cout << "Matriz A" << std::endl;
	std::cout << m3a << std::endl << std::endl;

	m3r = m3a;
	std::cout << "Matriz A transpuesta" << std::endl;
	std::cout << m3r.transpose() << std::endl << std::endl;

	m3r = m3a;
	std::cout << "Matriz A inversa" << std::endl;
	std::cout << m3r.inverse() << std::endl << std::endl;

	std::cout << "Determinante de la matriz A" << std::endl;
	std::cout << m3a.determinant() << std::endl << std::endl;

	std::cout << "Matriz B" << std::endl;
	std::cout << m3b << std::endl << std::endl << std::endl;

	std::cout << "A + B" << std::endl;
	std::cout << (m3a + m3b) << std::endl << std::endl;

	std::cout << "A - B" << std::endl;
	std::cout << (m3a - m3b) << std::endl << std::endl;

	std::cout << "A * B" << std::endl;
	std::cout << (m3a * m3b) << std::endl << std::endl;

	std::cout << "Vector A" << std::endl;
	std::cout <<v31 << std::endl;

	std::cout << "Transformación del vector A por la matrix A" << std::endl;
	std::cout << m3a.transform(v31) << std::endl;


	std::cout << "=============================" << std::endl;
	std::cout << "=         Matrix4           =" << std::endl;
	std::cout << "=============================" << std::endl;

	Matrix4 identity4;
	std::cout << "Matriz identidad" << std::endl;
	std::cout << identity4 << std::endl << std::endl;
	Matrix4 m4a,m4r,m4b;
	m4a.set(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
	m4b.set(3,8,2,0,4,7,1,4,2,5,2,8,5,3,6,3);

	std::cout << "Matriz A" << std::endl;
	std::cout << m4a << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz A transpuesta" << std::endl;
	std::cout << m4r.transpose() << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz A inversa" << std::endl;
	std::cout << m4r.inverse() << std::endl << std::endl;

	std::cout << "Determinante de la matriz A" << std::endl;
	std::cout << m4a.determinant() << std::endl << std::endl;

	std::cout << "Matriz B" << std::endl;
	std::cout << m4b << std::endl << std::endl << std::endl;

	std::cout << "A + B" << std::endl;
	std::cout << (m4a + m4b) << std::endl << std::endl;

	std::cout << "A - B" << std::endl;
	std::cout << (m4a - m4b) << std::endl << std::endl;

	std::cout << "A * B" << std::endl;
	std::cout << (m4a * m4b) << std::endl << std::endl;

	std::cout << "Vector A" << std::endl;
	std::cout <<v31 << std::endl;

	std::cout << "Transformación del vector A por la matrix A" << std::endl;
	std::cout << m4a.transform(v31) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de rotación en el eje X por 1 radian" << std::endl;
	std::cout << m4r.rotateX(1.0) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de rotación en el eje Y por 1 radian" << std::endl;
	std::cout << m4r.rotateY(1.0) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de rotación en el eje Z por 1 radian" << std::endl;
	std::cout << m4r.rotateZ(1.0) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de rotación en el eje X,Y,Z por 1 radian" << std::endl;
	std::cout << m4r.rotate(1.0,1.0,1.0) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de translación por el vector (2,6,8)" << std::endl;
	std::cout << m4r.translate(2,6,8) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de scala por el vector (2,6,8)" << std::endl;
	std::cout << m4r.scale(2,6,8) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de projección ortografica con left=-2 right=2 top=-2 bottom=2 far=1000 near=0.1" << std::endl;
	std::cout << m4r.orthographicProjection(-2,2,-2,2,0.1,1000) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz de projección perspectiva con Field of View= 1 (45 grados) aspect ratio=1 zNear=0.1 zFar=1000" << std::endl;
	std::cout << m4r.perspectiveProjection(1,1,0.1,1000) << std::endl << std::endl;

	m4r = m4a;
	std::cout << "Matriz lookAt con eye=(0,0,0) target=(0,1,-3) y up=(0,1,0)" << std::endl;
	std::cout << m4r.lookAt(Vector3(0,0,0), Vector3(0,1,-3), Vector3(0,1,0)) << std::endl << std::endl;



	return 0;	
}