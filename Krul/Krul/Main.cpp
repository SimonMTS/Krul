#include <iostream>
#include "../CurlWrapper/CurlWrapper.h"

int main(int argc, char* argv[])
{
    CurlWrapper curl;

    std::string code;
    std::string url = "start.txt";

    while (true) {
        code = curl.getUrl("https://www.swiftcoder.nl/cpp1/" + url);

        std::cout << code;

        break; // interperate

        url = "start.txt";

        std::cout << url;
    }

    return 0;
}