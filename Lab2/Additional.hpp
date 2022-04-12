#pragma once
#include <queue>
#include <map>
#include <tuple>
#include <vector>
#include <iterator>
#include <fstream>
#include "Students.hpp"
#include "Teacher.hpp"
#include "Equation.hpp"
using namespace std;

vector <student*> buildList(istream& in);
queue <tuple <equation, solution, string>> buildQueue(vector <student*>& list, vector <equation>& equations);
vector <equation> readEquations(istream& in);
void Interface();