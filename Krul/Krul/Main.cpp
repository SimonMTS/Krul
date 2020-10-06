#include <iostream>
#include "../CurlWrapper/CurlWrapper.h"
#include "../Interpreter/Interpreter.h"

int main(int argc, char* argv[])
{
    CurlWrapper curl;
    Interpreter Krul;

    std::string code;
    std::string url = "start.txt";

    while (true) {
        code = curl.getUrl("https://www.swiftcoder.nl/cpp1/" + url);
        code = "15\n23\nadd\n";
        //std::cout << code;

        url = Krul.Interpret(code);
        std::cout << url << "\n";

        break; // if ( endCondition ) ...
    }

    return 0;
}