#include "ParserTests.hpp"
#include <string.h>

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES "
              << "Options:\n"
              << "\t-h,--help\tShow this help message\n"
              << "\t-t,--test\tLaunch tests\n"
              << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        show_usage(argv[0]);
        return 1;
    }

    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "h") == 0) {
        show_usage(argv[0]);
        return 0;
    }
    if(strcmp(argv[1], "--test") == 0 || strcmp(argv[1], "t") == 0) {
       testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

}
