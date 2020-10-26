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
#include "GoToLineIfNotEqual.h"
#include "AssignVariableFromStack.h"
#include "DefineLabel.h"
#include "PushLabelToStack.h"
#include "PushVariableToStack.h"
#include "GoToLine.h"
#include "GoToLineIfEqual.h"
#include "GoToLineIfLess.h"
#include "GoToLineIfGreaterOrEqual.h"
#include "GoToLineIfGreater.h"
#include "GoToLineIfLessOrEqual.h"
#include "ExecuteFunction.h"
#include "ReturnFunction.h"
#include "NegateNumberFromStack.h"
#include "End.h"

std::vector<std::shared_ptr<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>> Action::matchFunctions{};

void Action::Populate() {
	// Values & Types
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(PushNumberToStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(PushStringToStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(AssignVariableFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(DefineLabel::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(PushLabelToStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(PushVariableToStack::Match));

	// Integer operaties
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(AddNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(SubtractNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(MultiplyNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(DivideNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(ModuloNumbersFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(MakeAbsoluteNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(IncrementNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(DecrementNumberFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(NegateNumberFromStack::Match));

	// String operaties
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(DuplicateStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(AddNewLineToStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(RotateStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GetLengthOfStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(ConcatenateStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(IndexStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(SubstringStringFromStack::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(ReverseStringFromStack::Match));

	// Tests & Jumps
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLine::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLineIfEqual::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLineIfGreater::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLineIfGreaterOrEqual::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLineIfLess::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLineIfLessOrEqual::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(GoToLineIfNotEqual::Match));
	
	// Functies
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(ExecuteFunction::Match));
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(ReturnFunction::Match));
	
	// Eindoplossing
	Action::matchFunctions.push_back(std::make_shared<std::unique_ptr<Action>(*)(MemoryData&, int, std::string)>(End::Match));
}

std::unique_ptr<Action> Action::Match(MemoryData& data, int i, std::string line) {

	for (auto& matchFunction : Action::matchFunctions) {
		auto a = (*(matchFunction.get()))(data, i, line);
		if (a) {
			return a;
		}
	}

	// throw, no match
	std::string msg = "Parse Error: line (" + line + ") didn't match any action.";
	throw std::exception(msg.c_str());
	// return std::unique_ptr<Action>(nullptr);

}