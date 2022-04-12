#pragma once
#include <iostream>
#include <cmath>

class solution {
public:
	solution(int root_count, double x1, double x2) : _root_count(root_count), _x1(x1), _x2(x2) {};
	bool operator == (const solution& to_compare);
	void print(std::ostream& out) const;

private:
	int _root_count;
	double _x1;
	double _x2;
};

class equation {
public:
	friend std::istream& operator>>(std::istream& is, equation& eqn);
	equation() : _a(0), _b(0), _c(0) {};
	equation(std::istream& in) {
		if (!(in >> _a >> _b >> _c))
			throw std::runtime_error("unable to read coefficients");
	}
	solution Solve() const;
private:
	double _a;
	double _b;
	double _c;
};
