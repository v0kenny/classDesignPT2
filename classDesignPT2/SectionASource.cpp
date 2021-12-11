#include <iostream>
#include <string>
#include "SectionAHeader.h"

URLparser::URLparser(std::string inputedURL)
    :URL{ inputedURL }
{
}

std::string URLparser::getURL() const{
    return URL;
}

std::string URLparser::getScheme() const{
    std::string scheme = URL.substr(0, URL.find_first_of("/"));

    return scheme;
}

std::string URLparser::getAuthority() const{
    int x = 0;
    int index = 0;
    for (int i = 0; i < URL.length(); i++) {
        if (URL[i] == '/') {
            x += 1;
        }

        if (x == 3) {
            break;
        }
        index += 1;
    }
    std::string auth = URL.substr(URL.find_first_of("//"), index - URL.find("/"));

    return auth;
}

 std::string URLparser::getPath() const{
    int x = 0;
    int index = 0;
    for (int i = 0; i < URL.length(); i++) {
        if (URL[i] == '/') {
            x += 1;
        }

        if (x == 3) {
            break;
        }
        index += 1;
    }
    std::string path = URL.substr(index, URL.length());

    return path;
}
std::ostream& operator<<(std::ostream& out, URLparser URL) {
    out << "URL: " << URL.getURL() << "\n" << "SCHEME: " << URL.getScheme() << "\n" << "AUTHORITY: " << URL.getAuthority() << "\n" << "PATH: " << URL.getPath();
    return out;
}
