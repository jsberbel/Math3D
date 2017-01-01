#pragma once
#include <iostream>

// Vector 3D class
class Vec3 {
public:
	// Default constructor
	Vec3() : x(0.f), y(0.f), z(0.f) {};
	// Overloaded constructor
	Vec3(float val) : x(val), y(val), z(val) {};
	Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
	// Copy constructor
	Vec3(const Vec3 &cpy) = default;
	Vec3& operator=(const Vec3& cpy) = default;
	// Move constructor
	Vec3(Vec3 &&mov) = default;
	Vec3& operator=(Vec3&& mov) = default;
	// Destructor
	~Vec3() = default;
	// Internal operators
	void operator*=(float scalar);
	void operator/=(float scalar);
	void operator+=(const Vec3 &rhs);
	void operator-=(const Vec3 &rhs);
	// Methods
	float length();
	Vec3 normalize();
public:
	// Attributes
	float x, y, z;
	static const Vec3 ZERO;
};

// Vector external operators
Vec3 operator*(const Vec3 &vec, float scalar);
Vec3 operator*(float scalar, const Vec3 &vec);
Vec3 operator/(const Vec3 &vec, float scalar);
Vec3 operator/(float scalar, const Vec3 &vec);
float operator*(const Vec3 &lhs, const Vec3 &rhs);
Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs);
Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs);
std::ostream& operator<<(std::ostream &os, const Vec3 &vec);

// Vector external methods
float Dot(const Vec3 &P, const Vec3 &Q);
Vec3 Cross(const Vec3 &P, const Vec3 &Q);
float Distance(const Vec3 &P, const Vec3 &Q);		// Get the distance between 2 points or directions
bool AreOrthogonal(const Vec3 &P, const Vec3 &Q);	// Whether or not 2 vectors are perpendicular
bool SameSide(const Vec3 &P, const Vec3 &Q);		// Whether or not 2 vectors lie on the same side of a plane
Vec3 Projection(Vec3 &P, Vec3 &Q);						// Vector projection of P onto Q
Vec3 Perpendicular(Vec3 &P, Vec3 &Q);					// Vector perpendicular of P with respect to Q