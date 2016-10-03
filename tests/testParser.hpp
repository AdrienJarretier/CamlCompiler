#include "Parser.hpp"
#include "Scanner.hpp"
#include "testScanner.hpp"

void testParserConstruct()
{
    auto toks = testTokenize("testFiles/basicTypes.ml");
    Parser pa(toks);;
}
