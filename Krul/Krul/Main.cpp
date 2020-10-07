#include <iostream>
#include <crtdbg.h>
#include "../CurlWrapper/CurlWrapper.h"
#include "../Interpreter/Interpreter.h"

int main(int argc, char* argv[]) {
    CurlWrapper curl;

    std::string code;
    std::string url = "start.txt";

    while (true) {
        std::cout << url << "\n";

        code = curl.getUrl("https://www.swiftcoder.nl/cpp1/" + url);
        //code = "1\n3\nadd\n";
        //std::cout << code << "\n\n";

        Interpreter Krul;
        url = Krul.Interpret(code);
        //std::cout << url << "\n\n";

        //break; // if ( endCondition ) ...
        if (Krul.Ended()) {
            std::cout << "\nSecret: \n";
            std::cout << url << "\n";
            break;
        }
    }

    _CrtDumpMemoryLeaks();
    return 0;
}