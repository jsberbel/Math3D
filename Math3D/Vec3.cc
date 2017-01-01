#include "Vec3.hh"

const Vec3 Vec3::ZERO{ 0.f };

void Vec3::operator*=(float scalar) {
	x *= scalar, y *= scalar, z *= scalar;
}

void Vec3::operator/=(float scalar) {
	x /= scalar, y /= scalar, z /= scalar;
}

void Vec3::operator+=(const Vec3 &rhs) {
	x += rhs.x, y += rhs.y, z += rhs.z;
}

void Vec3::operator-=(const Vec3 &rhs) {
	x -= rhs.x, y -= rhs.y, z -= rhs.z;
}

float Vec3::length() {
	return sqrt(x*x + y*y + z*z);
}

Vec3 Vec3::normalize() {
	const auto len{ length() };
	return Vec3(x / len, y / len, z / len);
}

Vec3 operator*(const Vec3 &vec, float scalar) {
	return Vec3(vec.x*scalar, vec.y*scalar, vec.z*scalar);
}

Vec3 operator*(float scalar, const Vec3 &vec) {
	return vec*scalar;
}

Vec3 operator/(const Vec3 & vec, float scalar) {
	return Vec3(vec.x/scalar, vec.y/scalar, vec.z/scalar);
}

Vec3 operator/(float scalar, const Vec3 & vec) {
	return vec/scalar;
}

float operator*(const Vec3 &lhs, const Vec3 &rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs) {
	return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs) {
	return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

std::ostream& operator<<(std::ostream &os, const Vec3 &vec) {
	return os << "{ " << vec.x << ", " << vec.y << ", " << vec.z << " }";
}

float Dot(const Vec3 &P, const Vec3 &Q) {
	return P * Q;
}

Vec3 Cross(const Vec3 &P, const Vec3 &Q) {
	return Vec3(P.y*Q.z - P.z*Q.y, P.z*Q.x - P.x*Q.z, P.x*Q.y - P.y*Q.x);
}

float Distance(const Vec3 &P, const Vec3 &Q) {
	return (Q - P).length();
}

bool AreOrthogonal(const Vec3 &P, const Vec3 &Q) {
	return !(P * Q);
}

bool SameSide(const Vec3 &P, const Vec3 &Q) {
	return (P * Q) > 0;
}

Vec3 Projection(Vec3 &P, Vec3 &Q) {
	const auto len = Q.length();
	return ((P*Q)*Q) / (len*len);
}

Vec3 Perpendicular(Vec3 &P, Vec3 &Q) {
	return P - Projection(P, Q);
}
