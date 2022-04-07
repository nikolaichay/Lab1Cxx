#include "Solving.hpp"
const double eps = 1e-10;

void solution::print() const {
	switch (_root_count) {
	case 0:
		cout << "No roots or incorrect input";
		break;
	case 1:
		cout << "Root is: " << _x1;
		break;
	case 2:
		cout << "Roots are: " << _x1 << "," << _x2;
		break;
	}
}

solution equation::Solve() const {
	double x_1 = 0;
	double x_2 = 0;
	if (abs(_a) < eps) {
		if (abs(_b) < eps) {
			return { 0,0,0 };
		}
		x_1 = -_c / _b;
		x_2 = -_c / _b;
		return { 1,x_1,x_2 };
	}
	double d = _b * _b - 4 * _a * _c;
	if (d < 0) {
		return { 0,0,0 };
	}
	x_1 = (-_b + sqrt(d)) / (2 * _a);
	x_2 = (-_b - sqrt(d)) / (2 * _a);
	if (fabs(d) < eps) {
		return { 1,x_1,x_2 };
	}
	return { 2, x_1,x_2 };
}

int main() {
	equation eq(cin);
	eq.Solve();
	const solution sol = eq.Solve();
	sol.print();
	return 0;
}