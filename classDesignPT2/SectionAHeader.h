#include <string>
class URLparser {
private:
     std::string URL;
public:
    URLparser(std::string inputedURL);

    std::string getURL() const;
    std::string getScheme() const;
    std::string getAuthority() const;
    std::string getPath() const;

};

std::ostream& operator << (std::ostream& out, URLparser URL);