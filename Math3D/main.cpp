#include "Vec3.hh"
#include <iostream>

int main() {
	// -------
	// VECTORS
	// -------

	Vec3 v{ 2.f, 4.f, 1.f };
	std::cout << v << std::endl;

	system("pause");
	return 0;
}


//// Proof 1: ||P|| >= 0
//Vec3 v0{ -4.f, -2.f, -1.f };
//std::cout << v0.length() << std::endl;

//// Proof 2: ||P|| = 0 if P = {0,0,0}
//Vec3 v1{ 0.f };
//std::cout << v1.length() << std::endl;

//// Proof 2: ||a * P|| = |a| * ||P||
//float sc{ -3.f };
//Vec3 v2{ 4.f, 3.f, -1.f };
//std::cout << (abs(sc) * v2).length() << std::endl;
//std::cout << v2.length() * abs(sc) << std::endl;

//// Proof 4: ||P + Q|| <= ||P|| + ||Q||
//Vec3 v3{ 3.f, 5.f, -2.f };
//Vec3 v4{ 1.f, 2.f, 1.f };
//std::cout << (v3 + v4).normalize() << std::endl;
//std::cout << v3.normalize() + v4.normalize() << std::endl;

//// Cauchy-Schwarz inequality: |P * Q| <= ||P|| * ||Q||
//Vec3 v1{ 5.f, 1.f, 3.f };
//Vec3 v2{ 2.f, 2.f, 0.f };
//std::cout << abs(v1*v2) << std::endl;
//std::cout << v1.length()*v2.length() << std::endl;