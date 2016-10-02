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

std::string Scanner::nextPhrase()
{
    std::size_t pos = srcContent.find(";;");

    std::string phrase = srcContent.substr(0, pos);

    srcContent.erase(0, pos+2);

    return phrase;
}

void Scanner::removeComments()
{
    if(!commentsRemoved)
    {
        std::size_t comPos, comEnd;
        while( (comPos = srcContent.find("(*")) != std::string::npos )
        {
            comEnd = srcContent.find("*)") + 2;
            srcContent.erase(comPos, comEnd-comPos);
        }
        commentsRemoved = true;
    }
}
