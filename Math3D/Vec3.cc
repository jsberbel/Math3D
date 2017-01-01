#include "Vec3.hh"
#include "Assert.hh"

template class TVec3<int>;
template class TVec3<float>;
template class TVec3<unsigned>;

////////////////////
// Static constants
////////////////////

template <class T> const TVec3<T> TVec3<T>::ZERO(0);

//////////////////
// Member methods
//////////////////

template<class T>
void TVec3<T>::operator*=(T scalar) {
	x *= scalar, y *= scalar, z *= scalar;
}

template<class T>
void TVec3<T>::operator/=(T scalar) {
	x /= scalar, y /= scalar, z /= scalar;
}

template<class T>
void TVec3<T>::operator+=(const TVec3<T> &rhs) {
	x += rhs.x, y += rhs.y, z += rhs.z;
}

template<class T>
void TVec3<T>::operator-=(const TVec3<T> &rhs) {
	x -= rhs.x, y -= rhs.y, z -= rhs.z;
}

template<class T>
T &TVec3<T>::operator[](unsigned i) {
	ASSERT(i >= 0 && i < 3);
	return v[i];
}

template<class T>
T TVec3<T>::length() {
	return static_cast<T>(sqrt(x*x + y*y + z*z));
}

template<class T>
TVec3<T> TVec3<T>::normalize() {
	const auto len{ length() };
	return TVec3<T>(x / len, y / len, z / len);
}

////////////////////////////
// Vector external operators

template<class T>
TVec3<T> operator*(const TVec3<T>& vec, T scalar) {
	return TVec3<T>(vec.x*scalar, vec.y*scalar, vec.z*scalar);
}

template<class T>
TVec3<T> operator*(float scalar, const TVec3<T> &vec) {
	return vec*scalar;
}

template<class T>
TVec3<T> operator/(const TVec3<T> & vec, T scalar) {
	return TVec3<T>(vec.x/scalar, vec.y/scalar, vec.z/scalar);
}

template<class T>
TVec3<T> operator/(T scalar, const TVec3<T> & vec) {
	return vec/scalar;
}

template<class T>
T operator*(const TVec3<T> &lhs, const TVec3<T> &rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template<class T>
TVec3<T> operator+(const TVec3<T> &lhs, const TVec3<T> &rhs) {
	return TVec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template<class T>
TVec3<T> operator-(const TVec3<T> &lhs, const TVec3<T> &rhs) {
	return TVec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template<class T>
std::ostream& operator<<(std::ostream &os, const TVec3<T> &vec) {
	return os << "{ " << vec.x << ", " << vec.y << ", " << vec.z << " }";
}

template std::ostream& operator<<(std::ostream &os, const TVec3<int> &vec);
template std::ostream& operator<<(std::ostream &os, const TVec3<float> &vec);
template std::ostream& operator<<(std::ostream &os, const TVec3<unsigned> &vec);

////////////////////////////
// Vector external methods

template<class T>
T Dot(const TVec3<T> &P, const TVec3<T> &Q) {
	return P * Q;
}

template<class T>
TVec3<T> Cross(const TVec3<T> &P, const TVec3<T> &Q) {
	return TVec3<T>(P.y*Q.z - P.z*Q.y, P.z*Q.x - P.x*Q.z, P.x*Q.y - P.y*Q.x);
}

template<class T>
T Distance(const TVec3<T> &P, const TVec3<T> &Q) {
	return (Q - P).length();
}

template<class T>
bool AreOrthogonal(const TVec3<T> &P, const TVec3<T> &Q) {
	return !(P * Q);
}

template<class T>
bool SameSide(const TVec3<T> &P, const TVec3<T> &Q) {
	return (P * Q) > 0;
}

template<class T>
TVec3<T> Projection(TVec3<T> &P, TVec3<T> &Q) {
	const auto len = Q.length();
	return ((P*Q)*Q) / (len*len);
}

template<class T>
TVec3<T> Perpendicular(TVec3<T> &P, TVec3<T> &Q) {
	return P - Projection(P, Q);
}

template<class T>
float TriangleArea(TVec3<T> & P, TVec3<T> & Q) {
	return Cross(P, Q).length();
}