#pragma once
#include <memory>
#include <string>
#include "curl/curl.h"
#include "curl/easy.h"

class CurlWrapper
{
private:
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

public:
	std::unique_ptr<CURL, void(*)(CURL*)> req;

	CurlWrapper();

	std::string getUrl(std::string url);
};

