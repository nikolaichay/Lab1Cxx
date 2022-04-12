#pragma once
#include <string> 
#include "equation.hpp"
class student {
public:
	explicit student(std::string name) : _name(name) {};
	std::string getName() const;
	virtual solution Solve(equation& eq) const = 0;
	~student();
private:
	std::string _name;
};
class Good : public student {
public:
	Good(std::string name) : student(name) {};
	solution Solve(equation& eq)const override;
};
class Bad : public student {
public:
	Bad(std::string name) : student(name) {};
	solution Solve(equation& eq)const override;
};
class Norm : public student {
public:
	Norm(std::string name) : student(name) {};
	solution Solve(equation& eq)const override;
};