#include "pch.h"
#include "Action.h"
#include "PushNumberToStack.h"
#include "AddNumbersFromStack.h"
#include "SubtractNumbersFromStack.h"
#include "MultiplyNumbersFromStack.h"
#include "DivideNumbersFromStack.h"
#include "ModuloNumbersFromStack.h"
#include "MakeAbsoluteNumberFromStack.h"
#include "DecrementNumberFromStack.h"
#include "IncrementNumberFromStack.h"

std::vector< std::shared_ptr<std::unique_ptr<Action>(*)(std::string)> > Action::matchFunctions{};

void Action::Populate() {
	// Values & Types
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(PushNumberToStack::Match));

	// Integer operaties
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(AddNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(SubtractNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(MultiplyNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(DivideNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(ModuloNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(MakeAbsoluteNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(IncrementNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(DecrementNumberFromStack::Match));
}

std::unique_ptr<Action> Action::Match(std::string line) {

	for (auto& matchFunction : Action::matchFunctions) {
		auto a = (*(matchFunction.get()))(line);
		if (a) {
			return a;
		}
	}

	// throw, no match
	return std::unique_ptr<Action>(nullptr);

}