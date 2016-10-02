#include "Scanner.hpp"

Scanner::Scanner(const char* filename)
:commentsRemoved(false)
{
    std::ifstream srcFile(filename);
    std::string line;

    while(std::getline(srcFile, line))
    {
        srcContent.append(line);
    }
}

const std::string& Scanner::getSrcContent() const
{
    return srcContent;
}

void Scanner::removeComments()
{
    std::size_t comPos, comEnd;
    while( (comPos = srcContent.find("(*")) != std::string::npos )
    {
        comEnd = srcContent.find("*)") + 2;
        srcContent.erase(comPos, comEnd-comPos);
    }
    commentsRemoved = true;
}
