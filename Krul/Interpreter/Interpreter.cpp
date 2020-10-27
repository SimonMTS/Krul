#include "pch.h"
#include "Interpreter.h"
using std::string;
using std::unique_ptr;
using std::exception;
using std::cout;

string Interpreter::Interpret(const string& code) {
    Parse(code);
    Execute();

    return data.stack.size() > 0 ? data.stack.at(data.stack.size() - 1) : "";
}

bool Interpreter::Ended() const {
    return data.ended;
}

void Interpreter::Parse(const string& code) {
    std::istringstream lines(code);
    string line;

    Action::Populate();

    int i = 0;
    while (std::getline(lines, line)) {
        try {
            unique_ptr<Action> action{ Action::Match(data, i, line) };
            actions.push_back(std::move(action));
            i++;
        } catch (exception e) {
            cout << e.what() << "\n";
            std::exit(1);
        }
    }
}

void Interpreter::Execute() {
    int len = actions.size();

    for (int i = 0; i < len; i++) {
        try {
            i = (*((actions.at(i)).get())).Do(data, i);
        } catch (exception e) {
            cout << e.what() << "\n";
            std::exit(1);
        }
    }
}
