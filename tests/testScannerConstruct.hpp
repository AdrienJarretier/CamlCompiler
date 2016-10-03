#include "Scanner.hpp"

#include <iostream>

using namespace std;

using namespace std::regex_constants;

void testScannerConstruct()
{
//    cout << R"(^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*)" << endl;
//    regex re(R"(^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*)");
//
//    cout << R"(^-?(0[xX][0-9A-Fa-f]+|0[oO][0-7]+|0[bB][0-1]+|[0-9]+))" << endl;
//    regex re2(R"(^-?(0[xX][0-9A-Fa-f]+|0[oO][0-7]+|0[bB][0-1]+|[0-9]+))");
//
//    cout << R"(^-?[0-9]+([eE][+-]?[0-9]+|\.[0-9]*([eE][+-]?[0-9]+)?))" << endl;
//    regex re3(R"(^-?[0-9]+([eE][+-]?[0-9]+|\.[0-9]*([eE][+-]?[0-9]+)?))");
//
//    cout << R"(^`([^`\\]|\\[\\`ntbr]|\\[0-9]{3})`)" << endl;
//    regex re4(R"(^`([^`\\]|\\[\\`ntbr]|\\[0-9]{3})`)");
//
//    cout << R"(^\"([^\"\\]|\\[\\\"ntbr]|\\[0-9]{3})*\")" << endl;
//    regex re5(R"(^\"([^\"\\]|\\[\\\"ntbr]|\\[0-9]{3})*\")");
//
//    cout << R"(^\b(and|as|begin|do|done|downto|else|end|exception|for|fun|function|if|in|let|match|mutable|not|of|or|prefix|rec|then|to|try|type|value|where|while|with)\b)" << endl;
//    regex r6e(R"(^\b(and|as|begin|do|done|downto|else|end|exception|for|fun|function|if|in|let|match|mutable|not|of|or|prefix|rec|then|to|try|type|value|where|while|with)\b)");
//
//    cout << R"(^#|^!=|^!|^&|^\(|^\)|^\*\.|^\*|^\+\.|^\+|^,|^-\.|^->|^-|^\.\(|^\.|^\/\.|^\/|^::|^:=|^:|^;;|^;|^<\.|^<-|^<=\.|^<=|^<>\.|^<>|^<|^=\.|^==|^=|^>\.|^>=\.|^>=|^>|^@|^\[\||^\[|^]|^\^|^__|^_|^{|^\|]|^\||^}|^')" << endl;
//    regex re7(R"(^#|^!=|^!|^&|^\(|^\)|^\*\.|^\*|^\+\.|^\+|^,|^-\.|^->|^-|^\.\(|^\.|^\/\.|^\/|^::|^:=|^:|^;;|^;|^<\.|^<-|^<=\.|^<=|^<>\.|^<>|^<|^=\.|^==|^=|^>\.|^>=\.|^>=|^>|^@|^\[\||^\[|^]|^\^|^__|^_|^{|^\|]|^\||^}|^')");

    try
    {

        Scanner sc("testFiles/exC3fonctions.ml");

    }
    catch (std::regex_error& e)
    {

        switch(e.code())
        {
        case error_collate:
            cout << "error_collate" << endl;
            break;
        case error_ctype:
            cout << "error_ctype" << endl;
            break;
        case error_escape:
            cout << "error_escape" << endl;
            break;
        case error_backref:
            cout << "error_backref" << endl;
            break;
        case error_brack:
            cout << "error_brack : The expression contained mismatched [ and ]. " << endl;
            break;
        case error_paren:
            cout << "error_paren : The expression contained mismatched ( and ). " << endl;
            break;
        case error_brace:
            cout << "error_brace" << endl;
            break;
        case error_badbrace:
            cout << "error_badbrace" << endl;
            break;
        case error_range:
            cout << "error_range" << endl;
            break;
        case error_space:
            cout << "error_space" << endl;
            break;
        case error_badrepeat:
            cout << "error_badrepeat" << endl;
            break;
        case error_complexity:
            cout << "error_complexity" << endl;
            break;
        case error_stack:
            cout << "error_stack" << endl;
            break;
        default:
            cout << "another error happened" << endl;
            break;
        }

    }
}
