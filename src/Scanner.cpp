#include "Scanner.hpp"

Scanner::Scanner(const char* filename)
:commentsRemoved(false)
{
    /*
    Blanks are ignored, but they separate adjacent identifiers,
    literals and keywords that would otherwise be confused
    as one single identifier, literal or keyword.
    */
    lexicon["blanks"] = "^( |\\[ntrf])+$";

    /*
    Comments are treated as blank characters.
    Comments do not occur inside string or character literals.
    Nested comments are correctly handled.
    */
    lexicon["comments"] = "^\(\*.*\*\)$";

    /*
    Identifiers are sequences of letters,
    digits and _(the underscore character),
    starting with a letter and not ending with _.
    Identifiers cannot contain two adjacent underscore characters
    */
    lexicon["identifiers"] = "^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*$";

    /*
    An integer literal is a sequence of one or more digits,
    optionally preceded by a minus sign.
    */
    lexicon["integer literals"] = "^-?[0-9]+$|^-?0[xX][0-9A-Fa-f]+$|^-?0[oO][0-7]+$|^-?0[bB][0-1]+$";

    /*
    Floating-point decimals consist in an integer part,
    a decimal part and an exponent part.
    The integer part is a sequence of one or more digits,
    optionally preceded by a minus sign.
    The decimal part is a decimal point followed by
    zero, one or more digits.
    The exponent part is the character e or E
    followed by an optional + or - sign, followed by one or more digits.
    The decimal part or the exponent part can be omitted,
    but not both to avoid ambiguity with integer literals.
    */
    lexicon["floating-point literals"] = "^-?[0-9]+(\.[0-9]*|[eE][+-]?[0-9]+|\.[0-9]*[eE][+-]?[0-9]+)$";

    /*
    Character literals are delimited by ` (backquote) characters.
    The two backquotes enclose either one character different from ` and \,
    or one of the escape sequences :
    \\	backslash (\)
    \`	backquote (`)
    \n	newline (LF)
    \r	return (CR)
    \t	horizontal tabulation (TAB)
    \b	backspace (BS)
    \ddd	the character with ASCII code ddd in decimal
    */
    lexicon["character literals"] = "^`[^`\\]`|`\\[\\`ntbr]`|`\\[0-9]{3}`$";

    /*
    String literals are delimited by " (double quote) characters.
    The two double quotes enclose a sequence of
    either characters different from " and \,
    or escape sequences from the table below:
    */
    lexicon["string literals"] = "^\"([^\"\\]|\\[\\\"ntbr]|\\[0-9]{3})*\"$";
    /* Not sure is this one will work since I had to escape " with \ */


    /*
     The identifiers below are reserved as keywords, and cannot be employed otherwise:

        and    as     begin       do      done      downto
        else   end    exception   for     fun       function
        if     in     let         match   mutable   not
        of     or     prefix      rec     then      to
        try    type   value       where   while     with

    The following character sequences are also keywords:

        #    !    !=   &    (    )    *    *.   +    +.
        ,    -    -.   ->   .    .(   /    /.   :    ::
        :=   ;    ;;   <    <.   <-   <=   <=.  <>   <>.
        =    =.   ==   >    >.   >=   >=.  @    [    [|
        ]    ^    _    __   {    |    |]   }    '

    */
    lexicon["keywords"] = "^\b(and|as|begin|do|done|downto|else|end|exception|for|fun|function|if|in|let|match|mutable|not|of|or|prefix|rec|then|to|try|type|value|where|while|with)\b$";
    lexicon["characters keywords"] = "^(#|!|!=|&|\(|\)|\*|\*\.|\+|\+\.|,|-|-\.|->|\.|\.\(|\/|\/\.|:|::|:=|;|;;|<|<\.|<-|<=|<=\.|<>|<>\.|=|=\.|==|>|>\.|>=|>=\.|@|\[|\[\||]|\^|_|__|{|\||\|]|}|')$";

    /*

    Ambiguities

    Lexical ambiguities are resolved according to the ``longest match'' rule:
    when a character sequence can be decomposed into two tokens in several different ways,
    the decomposition retained is the one with the longest first token.

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
