#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <stdexcept>
#include <string>

class Parser
{
    public:

        /** \brief construct a Parser object with
         *  the name of the source file to parse
         *
         * \param filename const char*
         *  the name of the source file to parse
         *
         */
        Parser(const char* filename);

        std::string nextPhrase();

        const std::string& getSrcContent() const;

        void removeComments();

    private:

        bool commentsRemoved;
//        std::size_t nextPhrasePos;
        std::string srcContent;

        static void eraseTrailingWhiteSpaces (std::string* str);
//        std::string getLine();
};

#endif // PARSER_HPP
