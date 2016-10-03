#include "Scanner.hpp"

#include <iostream>

using namespace std;

using namespace std::regex_constants;

void testScannerConstruct()
{
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
            cout << "error_brack" << endl;
            break;
        case error_paren:
            cout << "error_paren" << endl;
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
        }

    }
}
