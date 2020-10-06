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
#include "PushStringToStack.h"
#include "DuplicateStringFromStack.h"
#include "AddNewLineToStringFromStack.h"
#include "RotateStringFromStack.h"
#include "GetLengthOfStringFromStack.h"
#include "ConcatenateStringFromStack.h"
#include "IndexStringFromStack.h"
#include "SubstringStringFromStack.h"
#include "ReverseStringFromStack.h"

std::vector< std::shared_ptr<std::unique_ptr<Action>(*)(std::string)> > Action::matchFunctions{};

void Action::Populate() {
	// Values & Types
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(PushNumberToStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(PushStringToStack::Match));

	// Integer operaties
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(AddNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(SubtractNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(MultiplyNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(DivideNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(ModuloNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(MakeAbsoluteNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(IncrementNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(DecrementNumberFromStack::Match));

	// String operaties
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(DuplicateStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(AddNewLineToStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(RotateStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(GetLengthOfStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(ConcatenateStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(IndexStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(SubstringStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(std::string)>(ReverseStringFromStack::Match));
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