#include <iostream>
#include <crtdbg.h>
#include "../CurlWrapper/CurlWrapper.h"
#include "../Interpreter/Interpreter.h"

int main(int argc, char* argv[]) {
    //CurlWrapper curl;

    std::string code;
    std::string url = "start.txt";

    while (true) {
        std::cout << url << "\n";

        //code = curl.getUrl("https://www.swiftcoder.nl/cpp1/" + url);
        code = "\\a\n"
            "=result\n"
            "5\n"
            "=ctr\n"
            ":loop\n"
            "$result\n"
            "dup\n"
            "cat\n"
            "=result\n"
            "$ctr\n"
            "dec\n"
            "=ctr\n"
            "$ctr\n"
            "0\n"
            ">loop\n"
            "gne\n"
            "$result\n"
            "\\.txt\n"
            "cat\n";
        std::cout << url << "\n\n";
        std::cout << code << "\n\n";

        Interpreter Krul;
        url = Krul.Interpret(code);
        //std::cout << url << "\n\n";

        //break; // if ( endCondition ) ...
        if (Krul.Ended() || true) {
            std::cout << "\nSecret: \n";
            std::cout << url << "\n";
            break;
        }
    }

    _CrtDumpMemoryLeaks();
    return 0;
}