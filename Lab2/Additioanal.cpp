#include "Additional.hpp"

vector <student*> buildList(istream& in) {
	vector <student*> student_list;
	while (!in.eof()) {
		string name;
		getline(in, name);
		switch (rand() % 3) {
		case 0:
			student_list.push_back(new Bad(name));
			break;
		case 1:
			student_list.push_back(new Norm(name));
			break;
		case 2:
			student_list.push_back(new Good(name));
			break;
		}
	}
	return student_list;
}
queue <tuple <equation, solution, string>> buildQueue(vector <student*>& list, vector <equation>& equations) {
	queue <tuple <equation, solution, string>> answers;
	for (auto it_stud : list) {
		for (auto& it_eq : equations) {
			solution sol = it_stud->Solve(it_eq);
			answers.push({ it_eq, sol, it_stud->getName() });
		}
	}
	return answers;
}
vector <equation> readEquations(istream& in) {
	vector <equation> equations;
	while (!in.eof()) {
		equation tmp;
		in >> tmp;
		equations.push_back(tmp);
	}
	return equations;
}

void Interface() {
	srand(time(0));
	ifstream l("list.txt");
	ifstream eq("input.txt");
	vector <student*> students = buildList(l);
	vector <equation> equations = readEquations(eq);
	auto answers = buildQueue(students, equations);
	map <string, int> results;
	Teacher prepod(results);
	prepod.review(answers);
	prepod.publishResults();
	return;
}