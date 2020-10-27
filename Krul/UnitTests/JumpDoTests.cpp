#include "pch.h"
#include "../Interpreter/GoToLineIfNotEqual.h"
#include "../Interpreter/GoToLineIfEqual.h"
#include "../Interpreter/GoToLine.h"
#include "../Interpreter/GoToLineIfGreater.h"
#include "../Interpreter/GoToLineIfGreaterOrEqual.h"
#include "../Interpreter/GoToLineIfLess.h"
#include "../Interpreter/GoToLineIfLessOrEqual.h"


TEST(Jumps_DoTests, GoToLine_DoTest) {
    MemoryData data;
    data.stack.push_back("|12");

    GoToLine action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}


TEST(Jumps_DoTests, GoToLineIfEqual_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("some value");
    data.stack.push_back("some value");
    data.stack.push_back("|12");

    GoToLineIfEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}

TEST(Jumps_DoTests, GoToLineIfEqual_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("some value");
    data.stack.push_back("some other value");
    data.stack.push_back("|12");

    GoToLineIfEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 42);
}


TEST(Jumps_DoTests, GoToLineIfGreater_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("5"); //val1
    data.stack.push_back("8"); //val2
    data.stack.push_back("|12");

    GoToLineIfGreater action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 42);
}

TEST(Jumps_DoTests, GoToLineIfGreater_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("8");
    data.stack.push_back("5");
    data.stack.push_back("|12");

    GoToLineIfGreater action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}


TEST(Jumps_DoTests, GoToLineIfNotEqual_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("some value");
    data.stack.push_back("some value");
    data.stack.push_back("|12");

    GoToLineIfNotEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 42);
}

TEST(Jumps_DoTests, GoToLineIfNotEqual_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("some value");
    data.stack.push_back("some other value");
    data.stack.push_back("|12");

    GoToLineIfNotEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}


TEST(Jumps_DoTests, GoToLineIfGreaterOrEqual_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("6"); //val1
    data.stack.push_back("7"); //val2
    data.stack.push_back("|12");

    GoToLineIfGreaterOrEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 42);
}

TEST(Jumps_DoTests, GoToLineIfGreaterOrEqual_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("6");
    data.stack.push_back("6");
    data.stack.push_back("|12");

    GoToLineIfGreaterOrEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}


TEST(Jumps_DoTests, GoToLineIfLess_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("7"); //val1
    data.stack.push_back("6"); //val2
    data.stack.push_back("|12");

    GoToLineIfLess action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 42);
}

TEST(Jumps_DoTests, GoToLineIfLess_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("6");
    data.stack.push_back("7");
    data.stack.push_back("|12");

    GoToLineIfLess action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}


TEST(Jumps_DoTests, GoToLineIfLessOrEqual_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("7"); //val1
    data.stack.push_back("6"); //val2
    data.stack.push_back("|12");

    GoToLineIfLessOrEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 42);
}

TEST(Jumps_DoTests, GoToLineIfLessOrEqual_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("6");
    data.stack.push_back("6");
    data.stack.push_back("|12");

    GoToLineIfLessOrEqual action;
    int i = action.Do(data, 42);

    ASSERT_EQ(i, 12);
}