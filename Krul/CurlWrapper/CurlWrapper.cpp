#include "pch.h"
#include "CurlWrapper.h"

CurlWrapper::CurlWrapper() {
    req = std::unique_ptr<CURL, std::function<void(CURL*)>>(curl_easy_init(), curl_easy_cleanup);
}

size_t CurlWrapper::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string CurlWrapper::getUrl(std::string url) {

    CURLcode res;
    std::string readBuffer;
    if (req) {
        curl_easy_setopt(req.get(), CURLOPT_URL, url.c_str());
        curl_easy_setopt(req.get(), CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(req.get(), CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(req.get(), CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(req.get());

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_operation() failed : %s\n", curl_easy_strerror(res));
        }
    }

	return readBuffer;
}