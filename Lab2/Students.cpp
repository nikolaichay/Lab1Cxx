#include "Students.hpp"

std::string student::getName() const {
	return this->_name;
}
solution Good::Solve(equation& eq) const {
	return eq.Solve();
}
solution Bad::Solve(equation& eq) const {
	return { 1,0,0 };
}
solution Norm::Solve(equation& eq) const {
	if (rand() % 2) {
		return { 1,0,0 };
	}
	return eq.Solve();
}