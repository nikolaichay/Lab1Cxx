#include <cmath>
#include <iostream>
class Square {
public:
	Square(int a) :_a(a) {}
	Square() { _a = 0; }
	virtual double S() { return _a * _a; }
	virtual void Out() {
		std::cout << "W:" << _a << " H:" << _a;
	}
	void Draw() {
		std::cout << "\n";
		for (int i = 0; i < _a; ++i) {
			for (int j = 0; j < _a; ++j) {
				std::cout << "#";
			}
			std::cout << "\n";
		}
	}
protected:
	int _a;
};

class Rectangle: public Square {
public:
	Rectangle(int a, int b) : Square(a) ,_b(b) {};
	virtual double S() { return _a * _b; }
	virtual void Out() {
		std::cout << "W:" << _a << " H:" << _b;
	}
	void Draw() {
		std::cout << "\n";
		for (int i = 0; i < _b; ++i) {
			for (int j = 0; j < _a; ++j) {
				std::cout << "#";
			}
			std::cout << "\n";
		}
	}
protected:
	int _b;
};
int main(void) {
	Square l = Square(3);
	l.Out();
	l.Draw();
	std::cout << l.S() << "\n";
	Rectangle n = Rectangle(3, 2);
	n.Out();
	n.Draw();
	return 0;
}