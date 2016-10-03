#include "Parser.hpp"

Parser::Parser(std::vector<std::pair<std::string, std::string>> tokens)
{

}

long int Parser::toInt(const std::string& integerLiteral)
{
    return strtol(integerLiteral.c_str(), 0, 0);
}

float Parser::toFloat(const std::string& floatLiteral)
{
    return strtof(floatLiteral.c_str(), 0);
}

char Parser::toChar(const std::string& charLiteral)
{
    return charLiteral.front();
}

