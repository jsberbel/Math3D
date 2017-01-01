#pragma once
#include <iostream>

// Vector 3D class
template<class T>
class TVec3 {
public:
	// Default constructor
	TVec3() : x(0), y(0), z(0) {};
	// Overloaded constructor
	TVec3(T val) : x(val), y(val), z(val) {};
	TVec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {};
	// Copy constructor
	TVec3(const TVec3 &cpy) = default;
	TVec3& operator=(const TVec3& cpy) = default;
	// Move constructor
	TVec3(TVec3 &&mov) = default;
	TVec3& operator=(TVec3&& mov) = default;
	// Destructor
	~TVec3() = default;
	// Internal operators
	void operator*=(float scalar);
	void operator/=(float scalar);
	void operator+=(const TVec3 &rhs);
	void operator-=(const TVec3 &rhs);
	T &operator[](unsigned i);
	// Methods
	T length();
	TVec3<T> normalize();
public:
	// Attributes
	union {
		T v[3];
		struct { T x, y, z; };
		struct { T r, g, b; };
		struct { T s, t, p; };
	};
	static const TVec3 ZERO;
};

////////////////////////////
// Vector external operators
template<class T> TVec3<T> operator*(const TVec3<T> &vec, float scalar);
template<class T> TVec3<T> operator*(float scalar, const TVec3<T> &vec);
template<class T> TVec3<T> operator/(const TVec3<T> &vec, float scalar);
template<class T> TVec3<T> operator/(float scalar, const TVec3<T> &vec);
template<class T> T operator*(const TVec3<T> &lhs, const TVec3<T> &rhs);
template<class T> TVec3<T> operator+(const TVec3<T> &lhs, const TVec3<T> &rhs);
template<class T> TVec3<T> operator-(const TVec3<T> &lhs, const TVec3<T> &rhs);

///////////////////////////
// Vector external methods
template<class T> float Dot(const TVec3<T> &P, const TVec3<T> &Q);			// P * Q = ||P|| * ||Q|| * cos α
template<class T> TVec3<T> Cross(const TVec3<T> &P, const TVec3<T> &Q);		// ||P x Q|| = ||P|| * ||Q|| * sin α
template<class T> float Distance(const TVec3<T> &P, const TVec3<T> &Q);		// Get the distance between 2 points or directions
template<class T> bool AreOrthogonal(const TVec3<T> &P, const TVec3<T> &Q);	// Whether or not 2 vectors are perpendicular
template<class T> bool SameSide(const TVec3<T> &P, const TVec3<T> &Q);		// Whether or not 2 vectors lie on the same side of a plane
template<class T> TVec3<T> Projection(TVec3<T> &P, TVec3<T> &Q);			// Vector projection of P onto Q
template<class T> TVec3<T> Perpendicular(TVec3<T> &P, TVec3<T> &Q);			// Vector perpendicular of P with respect to Q
template<class T> float TriangleArea(TVec3<T> &P, TVec3<T> &Q);				// Get the area of the triangle formed by P and Q

/////////////////////////
// Vector specialization
typedef TVec3<int> iVec3;
typedef TVec3<float> Vec3;
typedef TVec3<unsigned> uVec3;

#ifndef EXTERNAL_TEMPLATE
#include "Vec3.inl"
#endif //EXTERNAL_TEMPLATE