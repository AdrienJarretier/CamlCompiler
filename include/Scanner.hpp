#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <string>

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

        void removeComments();

    private:

        bool commentsRemoved;

        std::string srcContent;
};

#endif // SCANNER_HPP
