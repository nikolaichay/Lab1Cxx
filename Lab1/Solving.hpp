#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <cmath>

using namespace std;
class solution {
public:
	solution(int root_count, double x1, double x2) : _root_count(root_count), _x1(x1), _x2(x2) {};
	void print() const;
private:
	int _root_count;
	double _x1;
	double _x2;
};

class equation {
public:
	equation(istream& in) {
		in >> this->_a;
		in >> this->_b;
		in >> this->_c;
	}
	solution Solve() const;
private:
	double _a;
	double _b;
	double _c;
};
#endif