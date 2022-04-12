#include "Teacher.hpp"
#include "Equation.hpp"
#include <tuple>
#include <iterator>
void Teacher::review(std::queue < std::tuple <equation, solution, std::string> >& studQueue) {
	while (!studQueue.empty()) {
		auto pending = studQueue.front();
		studQueue.pop();
		std::string studentName = std::get<std::string>(pending);
		solution teacherSol = std::get<equation>(pending).Solve();
		if (_results.find(studentName) == _results.end()) {
			_results.insert({ studentName, 0 });
		}
		bool solvedRight = teacherSol == std::get<solution>(pending);
		std::map <std::string, int> ::iterator it;
		it = _results.find(studentName);
		if (solvedRight) {
			it->second++;
		}
	}
	return;
}

void Teacher::publishResults() {
	for (auto it : _results) {
		std::cout << it.first << " solved " << it.second << " tasks" << std::endl;
	}
	return;
}