#ifndef PARSER_HPP
#define PARSER_HPP

#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

class Parser
{
    public:

        Parser(std::vector<std::pair<std::string, std::string>> tokens);

        static long int toInt(const std::string& integerLiteral);
        static float toFloat(const std::string& floatLiteral);
        static char toChar(const std::string& charLiteral);

    private:
};

#endif // PARSER_HPP
