#include <crtdbg.h>
#include <iostream>
#include "../CurlWrapper/CurlWrapper.h"
#include "../Interpreter/Interpreter.h"
using std::string;
using std::cout;

int main() {
    {
        CurlWrapper curl;

        string code;
        string url = "start.txt";

        while (true) {
            code = curl.getUrl("https://www.swiftcoder.nl/cpp1/" + url);
            cout << url << "\n";

            Interpreter Krul;
            url = Krul.Interpret(code);

            if (Krul.Ended()) {
                cout << "\nSecret: \n";
                cout << url << "\n";
                break;
            }
        }
    }

    // clean static (global) vector
    Action::matchFunctions.~vector();
    // display memory leaks
    /* test * new int{123}; /* test */
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
    return 0;
}
