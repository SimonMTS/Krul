#include <iostream>
#include <crtdbg.h>
#include "../CurlWrapper/CurlWrapper.h"
#include "../Interpreter/Interpreter.h"

int main(int argc, char* argv[]) {
    {
        CurlWrapper curl;

        std::string code;
        std::string url = "start.txt";

        while (true) {
            code = curl.getUrl("https://www.swiftcoder.nl/cpp1/" + url);
            std::cout << url << "\n";

            Interpreter Krul;
            url = Krul.Interpret(code);

            if (Krul.Ended()) {
                std::cout << "\nSecret: \n";
                std::cout << url << "\n";
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
