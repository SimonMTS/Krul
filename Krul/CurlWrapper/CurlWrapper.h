#pragma once
#include <memory>
#include <string>
#include <functional>
#include "curl/curl.h"
#include "curl/easy.h"
using std::string;
using std::unique_ptr;
using std::function;

class CurlWrapper {
private:
    static size_t WriteCallback(
        void* contents, size_t size, size_t nmemb, void* userp);

public:
    unique_ptr<CURL, function<void(CURL*)>> req;

    CurlWrapper();

    string getUrl(const string& url);
};
