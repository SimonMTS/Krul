#include "pch.h"
#include "Interpreter.h"

std::string Interpreter::Interpret(std::string code) {

	Parse(code);
	Execute();

	return Interpreter::stack.size() > 0 ? Interpreter::stack.at(0) : "";
}

void Interpreter::Parse(std::string code) {

	std::istringstream lines(code);
	std::string line;

	Action::Populate();

	while (std::getline(lines, line)) {
		//std::cout << one_line << "\n";

		std::unique_ptr<Action> action{ Action::Match(line) };
		actions.push_back(std::move(action));
	}

}

void Interpreter::Execute() {

	for (auto& action : actions) {
		(*(action.get())).Do( stack );
	}

}