#include <exception>
#include "pch.h"
#include "../Interpreter/PushNumberToStack.h"
#include "../Interpreter/PushStringToStack.h"
#include "../Interpreter/AssignVariableFromStack.h"
#include "../Interpreter/PushVariableToStack.h"
#include "../Interpreter/DefineLabel.h"
#include "../Interpreter/PushLabelToStack.h"
using std::exception;
using std::string;

TEST(Value_DoTests, PushNumber_DoTest) {
    MemoryData data;

    PushNumberToStack action{ "42" };
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "42");
}

TEST(Value_DoTests, PushString_DoTest) {
    MemoryData data;

    PushStringToStack action{ "some string" };
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string");
}

TEST(Value_DoTests, AssignVariable_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("some value");

    AssignVariableFromStack action{ "some variable name" };
    action.Do(data, 0);

    ASSERT_EQ(data.variables["some variable name"], "some value");
}
TEST(Value_DoTests, AssignVariable_neg_DoTest) {
    MemoryData data;

    AssignVariableFromStack action{ "some variable name" };
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: AssignVariableFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Value_DoTests, PushVariable_pos_DoTest) {
    MemoryData data;
    data.variables["some variable name"] = "some value";

    PushVariableToStack action{ "some variable name" };
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some value");
}
TEST(Value_DoTests, PushVariable_neg_DoTest) {
    MemoryData data;

    PushVariableToStack action{ "some variable name" };
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: PushVariableToStack called with undeclared variable name. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Value_DoTests, DefineLabel_DoTest) {
    MemoryData data;

    DefineLabel action{ "some label" };
    int i = action.Do(data, 42);

    ASSERT_EQ(data.labels["some label"], 42);
    ASSERT_EQ(i, 42);
}

TEST(Value_DoTests, PushLabel_pos_DoTest) {
    MemoryData data;
    data.labels["some label"] = 42;

    PushLabelToStack action{ "some label" };
    int i = action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "|42");
    ASSERT_EQ(i, 0);
}
TEST(Value_DoTests, PushLabel_neg_DoTest) {
    MemoryData data;

    PushLabelToStack action{ "some label" };
    try {
        int i = action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: PushLabelToStack called with undeclared label name. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}