#include "Assert.hh"

/*template<class T>
inline const TVec3<T> TVec3<T>::ZERO{ 0 };*/

template<class T>
inline void TVec3<T>::operator*=(float scalar) {
	x *= scalar, y *= scalar, z *= scalar;
}

template<class T>
inline void TVec3<T>::operator/=(float scalar) {
	x /= scalar, y /= scalar, z /= scalar;
}

template<class T>
inline void TVec3<T>::operator+=(const TVec3<T> &rhs) {
	x += rhs.x, y += rhs.y, z += rhs.z;
}

template<class T>
inline void TVec3<T>::operator-=(const TVec3<T> &rhs) {
	x -= rhs.x, y -= rhs.y, z -= rhs.z;
}

template<class T>
inline T &TVec3<T>::operator[](unsigned i) {
	ASSERT(i >= 0 && i < 3);
	return v[i];
}

template<class T>
inline T TVec3<T>::length() {
	return sqrt(x*x + y*y + z*z);
}

template<class T>
inline TVec3<T> TVec3<T>::normalize() {
	const auto len{ length() };
	return TVec3<T>(x / len, y / len, z / len);
}

////////////////////////////
// Vector external operators

template<class T>
inline TVec3<T> operator*(const TVec3<T>& vec, float scalar) {
	return TVec3<T>(vec.x*scalar, vec.y*scalar, vec.z*scalar);
}

template<class T>
inline TVec3<T> operator*(float scalar, const TVec3<T> &vec) {
	return vec*scalar;
}

template<class T>
inline TVec3<T> operator/(const TVec3<T> & vec, float scalar) {
	return TVec3<T>(vec.x/scalar, vec.y/scalar, vec.z/scalar);
}

template<class T>
inline TVec3<T> operator/(float scalar, const TVec3<T> & vec) {
	return vec/scalar;
}

template<class T>
inline T operator*(const TVec3<T> &lhs, const TVec3<T> &rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template<class T>
inline TVec3<T> operator+(const TVec3<T> &lhs, const TVec3<T> &rhs) {
	return TVec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template<class T>
inline TVec3<T> operator-(const TVec3<T> &lhs, const TVec3<T> &rhs) {
	return TVec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template<class T>
std::ostream& operator<<(std::ostream &os, const TVec3<T> &vec) {
	return os << "{ " << vec.x << ", " << vec.y << ", " << vec.z << " }";
}

////////////////////////////
// Vector external methods

template<class T>
inline float Dot(const TVec3<T> &P, const TVec3<T> &Q) {
	return P * Q;
}

template<class T>
inline TVec3<T> Cross(const TVec3<T> &P, const TVec3<T> &Q) {
	return TVec3<T>(P.y*Q.z - P.z*Q.y, P.z*Q.x - P.x*Q.z, P.x*Q.y - P.y*Q.x);
}

template<class T>
float Distance(const TVec3<T> &P, const TVec3<T> &Q) {
	return (Q - P).length();
}

template<class T>
inline bool AreOrthogonal(const TVec3<T> &P, const TVec3<T> &Q) {
	return !(P * Q);
}

template<class T>
inline bool SameSide(const TVec3<T> &P, const TVec3<T> &Q) {
	return (P * Q) > 0;
}

template<class T>
inline TVec3<T> Projection(TVec3<T> &P, TVec3<T> &Q) {
	const auto len = Q.length();
	return ((P*Q)*Q) / (len*len);
}

template<class T>
inline TVec3<T> Perpendicular(TVec3<T> &P, TVec3<T> &Q) {
	return P - Projection(P, Q);
}

template<class T>
inline float TriangleArea(TVec3<T> & P, TVec3<T> & Q) {
	return Cross(P, Q).length();
}
