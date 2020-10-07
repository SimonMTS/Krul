#include "pch.h"
#include "Interpreter.h"

std::string Interpreter::Interpret(std::string code) {

	Parse(code);
	Execute();

	return data.stack.size() > 0 ? data.stack.at(data.stack.size() - 1) : "";
}

bool Interpreter::Ended()
{
	return data.ended;
}

void Interpreter::Parse(std::string code) {

	std::istringstream lines(code);
	std::string line;

	Action::Populate();

	int i = 0;
	while (std::getline(lines, line)) {
		std::unique_ptr<Action> action{ Action::Match(data, i, line) };
		actions.push_back(std::move(action));
		i++;
	}

}

void Interpreter::Execute() {

	int len = actions.size();

	for (int i = 0; i < len; i++) {
		i = (*((actions.at(i)).get())).Do(data, i);
	}

}