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
using std::string;
using std::exception;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

vector<
    shared_ptr<unique_ptr<Action>(*)(MemoryData&, int, const string&)>
    > Action::matchFunctions{};

void Action::Populate() {
    if (Action::matchFunctions.size() != 0) return;

    // Values & Types
    PopulateSingle(PushNumberToStack::Match);
    PopulateSingle(PushStringToStack::Match);
    PopulateSingle(AssignVariableFromStack::Match);
    PopulateSingle(DefineLabel::Match);
    PopulateSingle(PushLabelToStack::Match);
    PopulateSingle(PushVariableToStack::Match);

    // Integer operaties
    PopulateSingle(AddNumbersFromStack::Match);
    PopulateSingle(SubtractNumbersFromStack::Match);
    PopulateSingle(MultiplyNumbersFromStack::Match);
    PopulateSingle(DivideNumbersFromStack::Match);
    PopulateSingle(ModuloNumbersFromStack::Match);
    PopulateSingle(MakeAbsoluteNumberFromStack::Match);
    PopulateSingle(IncrementNumberFromStack::Match);
    PopulateSingle(DecrementNumberFromStack::Match);
    PopulateSingle(NegateNumberFromStack::Match);

    // String operaties
    PopulateSingle(DuplicateStringFromStack::Match);
    PopulateSingle(AddNewLineToStringFromStack::Match);
    PopulateSingle(RotateStringFromStack::Match);
    PopulateSingle(GetLengthOfStringFromStack::Match);
    PopulateSingle(ConcatenateStringFromStack::Match);
    PopulateSingle(IndexStringFromStack::Match);
    PopulateSingle(SubstringStringFromStack::Match);
    PopulateSingle(ReverseStringFromStack::Match);

    // Tests & Jumps
    PopulateSingle(GoToLine::Match);
    PopulateSingle(GoToLineIfEqual::Match);
    PopulateSingle(GoToLineIfGreater::Match);
    PopulateSingle(GoToLineIfGreaterOrEqual::Match);
    PopulateSingle(GoToLineIfLess::Match);
    PopulateSingle(GoToLineIfLessOrEqual::Match);
    PopulateSingle(GoToLineIfNotEqual::Match);

    // Functies
    PopulateSingle(ExecuteFunction::Match);
    PopulateSingle(ReturnFunction::Match);

    // Eindoplossing
    PopulateSingle(End::Match);
}

void Action::PopulateSingle(
    unique_ptr<Action>(matcher)(MemoryData&, int, const string&)) {
    Action::matchFunctions.push_back(make_shared<
        unique_ptr<Action>(*)(MemoryData&, int, const string&)>(matcher));
}

unique_ptr<Action> Action::Match(MemoryData& data, int i, const string& line) {
    for (auto& matchFunction : Action::matchFunctions) {
        auto a = (*(matchFunction.get()))(data, i, line);
        if (a) {
            return a;
        }
    }

    // throw, no match
    throw exception(("Parse Error: line (" + line +
        ") didn't match any action.").c_str());
}
