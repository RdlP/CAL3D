CC = g++
CFLAGS = -g -std=c++11
INCFLAGS = -I./include/ALMath/
LDFLAGS = 

RM = /bin/rm -f
BUILDDIR = build
ALMATH = almath_test

all: createBuild almath
createBuild:
	mkdir -p $(BUILDDIR)

almath: almath_test.o Matrix3.o Matrix4.o Vector4.o Vector3.o Vector2.o Quaternion.o
	$(CC) $(CFLAGS) -o $(ALMATH) $(BUILDDIR)/almath_test.o $(BUILDDIR)/Matrix3.o $(BUILDDIR)/Matrix4.o $(BUILDDIR)/Vector4.o $(BUILDDIR)/Vector3.o $(BUILDDIR)/Vector2.o $(BUILDDIR)/Quaternion.o $(INCFLAGS) $(LDFLAGS) 
almath_test.o: almath_test.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/almath_test.o -c almath_test.cpp  
Matrix3.o: src/ALMath/Matrix3.cpp include/ALMath/Matrix3.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Matrix3.o -c src/ALMath/Matrix3.cpp 
Matrix4.o: src/ALMath/Matrix4.cpp include/ALMath/Matrix4.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Matrix4.o -c src/ALMath/Matrix4.cpp 
Vector4.o: src/ALMath/Vector4.cpp include/ALMath/Vector4.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Vector4.o -c src/ALMath/Vector4.cpp 
Vector3.o: src/ALMath/Vector3.cpp include/ALMath/Vector3.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Vector3.o -c src/ALMath/Vector3.cpp 
Vector2.o: src/ALMath/Vector2.cpp include/ALMath/Vector2.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Vector2.o -c src/ALMath/Vector2.cpp 
Quaternion.o: src/ALMath/Quaternion.cpp include/ALMath/Quaternion.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Quaternion.o -c src/ALMath/Quaternion.cpp 

clean: 
	$(RM) $(BUILDDIR)/*.o $(APPNAME)
	rmdir $(BUILDDIR)


 
