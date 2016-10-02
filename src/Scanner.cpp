#include "Scanner.hpp"

Scanner::Scanner(const char* filename)
:commentsRemoved(false)
{
    lexicon["blanks"] = {" ", "\n", "\t", "\r", "\f"};
    /*
    Blanks are ignored, but they separate adjacent identifiers,
    literals and keywords that would otherwise be confused
    as one single identifier, literal or keyword.
    */

    lexicon["comments"] = {"(*", "*)"};
    /*
    Comments are treated as blank characters.
    Comments do not occur inside string or character literals.
    Nested comments are correctly handled.
    */

    lexicon["identifiers"] = {"^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*$"};
    /*
    Identifiers are sequences of letters,
    digits and _(the underscore character),
    starting with a letter and not ending with _.
    Identifiers cannot contain two adjacent underscore characters
    */

    lexicon["integerLiterals"] = {"^-?[0-9]+$|^-?0[xX][0-9A-Fa-f]+$|^-?0[oO][0-7]+$|^-?0[bB][0-1]+$"};
    /*
    An integer literal is a sequence of one or more digits,
    optionally preceded by a minus sign.
    */

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
