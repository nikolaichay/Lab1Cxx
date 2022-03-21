#include <cmath>
#include <iostream>
const double eps = 1e-8;
int Solving_Quadratic_Equation(const double a, const double b, const double c, double& x1, double& x2);
void ReadingCoef(double& a, double& b, double& c);
void PrintResult(const int count, const double x1, const double x2);
int main(int argc, char* argv[]) {
	double a, b, c;
	ReadingCoef(a, b, c);
	double x1, x2;
	int count = Solving_Quadratic_Equation(a, b, c, x1, x2);
	PrintResult(count, x1, x2);
	return 0;
}
int Solving_Quadratic_Equation(const double a, const double b, const double c, double& x1, double& x2) {
	if (fabs(a) < eps) {
		if (fabs(b) < eps) {
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
	if (fabs(d) < eps) {
		return 1;
	}
	return 2;
}
void ReadingCoef(double& a, double& b, double& c) {
	std::cout << "Enter equation (ax^2 + bx + c) coefficients" << std::endl;
	std::cin >> a >> b >> c;
	return;
}
void PrintResult(const int count, const double x1, const double x2) {
	switch (count) {
	case 0:
		std::cout << "Equation has no roots" << std::endl;
		break;
	case 1:
		std::cout << "Equation root: " << x1 << std::endl;
		break;
	case 2:
		std::cout << "Equation roots: " << x1 << ", " << x2 << std::endl;
		break;
	}
	return;
}