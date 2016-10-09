#include "Parser.hpp"
#include <gtest/gtest.h>
using namespace std;

const string PathTestCamlFile = "testFiles/srcTest.ml";
const string contentCamlFile = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
const string firstOperation = "-2 * 3";
const string secondOperation = "2+3*5";

TEST(ParserTest, CreateParse) {
    ASSERT_NO_THROW(
        Parser parser(PathTestCamlFile.c_str());
    );
}

TEST(ParserTest, LoadFile) {
    Parser parser(PathTestCamlFile.c_str());
    ASSERT_EQ(contentCamlFile, parser.getSrcContent());
}

TEST(ParserTest, NextPhrase) {
    Parser parser(PathTestCamlFile.c_str());
    ASSERT_EQ(firstOperation, parser.nextPhrase());
    ASSERT_EQ(secondOperation, parser.nextPhrase());
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
