#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Scanner
{
    public:

        /** \brief construct a Scanner object with
         *  the name of the source file to scan
         *
         * \param filename const char*
         *  the name of the source file to scan
         *
         */
        Scanner(const char* filename);

        const std::string& getSrcContent() const;

        std::string nextPhrase();

        void removeComments();

    private:

        std::map<std::string, std::vector<std::string>> lexicon;

        bool commentsRemoved;

        std::string srcContent;
};

#endif // SCANNER_HPP
