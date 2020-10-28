#include <exception>
#include "pch.h"
#include "../Interpreter/End.h"
#include "../Interpreter/ExecuteFunction.h"
#include "../Interpreter/ReturnFunction.h"
using std::exception;
using std::string;

TEST(FunctionEnd_DoTests, End_DoTest) {
    MemoryData data;

    ASSERT_EQ(data.ended, false);

    End action;
    action.Do(data, 0);

    ASSERT_EQ(data.ended, true);
}

TEST(FunctionEnd_DoTests, ExecuteFunction_pos_DoTest) {
    MemoryData data;

    data.stack.push_back("|20");

    ExecuteFunction action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 20);
    ASSERT_EQ(data.callStack.at(0), "|42");
    ASSERT_EQ(data.stack.size(), 0);
}

TEST(FunctionEnd_DoTests, ExecuteFunction_neg_1_DoTest) {
    MemoryData data;

    ExecuteFunction action;
    try {
        int i = action.Do(data, 42);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ExecuteFunction called on stack, with to few arguments. On line number 43.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(FunctionEnd_DoTests, ExecuteFunction_neg_2_DoTest) {
    MemoryData data;

    data.stack.push_back("|asd");

    ExecuteFunction action;
    try {
        int i = action.Do(data, 42);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ExecuteFunction called on a non linenumber value. On line number 43.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(FunctionEnd_DoTests, ReturnFunction_pos_DoTest) {
    MemoryData data;

    data.callStack.push_back("|20");

    ReturnFunction action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 20);
    ASSERT_EQ(data.callStack.size(), 0);
}

TEST(FunctionEnd_DoTests, ReturnFunction_neg_1_DoTest) {
    MemoryData data;

    ReturnFunction action;
    try {
        int i = action.Do(data, 42);
        ASSERT_EQ(true, false);
    }
    catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ReturnFunction called on callStack, with to few arguments. On line number 43.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(FunctionEnd_DoTests, ReturnFunction_neg_2_DoTest) {
    MemoryData data;

    data.callStack.push_back("|asd");

    ReturnFunction action;
    try {
        int i = action.Do(data, 42);
        ASSERT_EQ(true, false);
    }
    catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ReturnFunction called on a non linenumber value. On line number 43.";
        ASSERT_EQ(msg, shouldBe);
    }
}