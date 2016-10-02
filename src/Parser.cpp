#include "Parser.hpp"

Parser::Parser(const char* filename)
    :commentsRemoved(false)
{
    std::ifstream srcFile(filename);
    std::string line;

    while(std::getline(srcFile, line))
    {
        srcContent.append(line);
    }
}

const std::string& Parser::getSrcContent() const
{
    return srcContent;
}

void Parser::removeComments()
{
    std::size_t comPos, comEnd;
    while( (comPos = srcContent.find("(*")) != std::string::npos )
    {
        comEnd = srcContent.find("*)") + 2;
        srcContent.erase(comPos, comEnd-comPos);
    }
    commentsRemoved = true;
}

//std::string Parser::getLine()
//{
//    std::string line;
//    std::getline(srcFile, line);
//
//    if( srcFile.eof() )
//    {
//        throw std::runtime_error("end of file reached");
//    }
//
//    return line;
//}

void Parser::eraseTrailingWhiteSpaces(std::string* str)
{
    std::string whitespaces (" \t\f\v\n\r");

    std::size_t found = str->find_last_not_of(whitespaces);
    if (found!=std::string::npos)
        str->erase(found+1);
    else
        str->clear();            // str is all whitespace
}

std::string Parser::nextPhrase()
{
    std::size_t pos = srcContent.find(";;");

    std::string phrase = srcContent.substr(0, pos);

    srcContent.erase(0, pos+2);

    return phrase;
}
