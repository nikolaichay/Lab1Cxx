#include <cmath>
#include <iostream>
int Solving_Quadratic_Equation(const double a, const double b, const double c, double& x1, double& x2) {
	if (a == 0) {
		if (b == 0) {
			return 0;
		}
		x1 = x2 = -c / b;
		return 1;
	}
	double d = b * b - 4 * a * c;
	if (d < 0) {
		return 0;
	}
	x1 = (-b + sqrt(d)) / (2 * a);
	x2 = (-b - sqrt(d)) / (2 * a);
	if (d==0) {
		return 1;
	}
	return 2;
}
int main() {
	double x1, x2;
	double a;
	double b;
	double c;
	std::cin >> a >> b >> c;
	int count = Solving_Quadratic_Equation(a, b, c, x1, x2);
	std::cout << "Count of solution = " << count << "\nRoot = " << x1 << ", " << x2;
	return 0;
}