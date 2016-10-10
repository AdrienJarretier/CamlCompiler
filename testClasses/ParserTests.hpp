#ifndef PARSERTESTS_HPP
#define PARSERTESTS_HPP

#include <gtest/gtest.h>
#include "Parser.hpp"

typedef ::testing::Test ParserTests;
const std::string pathFile = "testFiles/example.ml";
const std::string PathTestCamlFile = "testFiles/srcTest.ml";

void writeTestFile(const char *text);

void removeFile();


TEST_F(ParserTests, CreateParse) {
    ASSERT_NO_THROW(
        Parser parser(PathTestCamlFile.c_str());
        removeFile();
    );
}

TEST_F(ParserTests, LoadFile) {
    const char * content = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
    writeTestFile(content);
    Parser parser(pathFile.c_str());
    ASSERT_EQ(std::string(content), parser.getSrcContent().c_str());
    removeFile();
}

TEST_F(ParserTests, NextPhrase) {
    const char * content = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
    const std::string firstOperation = "-2 * 3";
    const std::string secondOperation = "2+3*5";
    writeTestFile(content);
    Parser parser(pathFile.c_str());
    ASSERT_EQ(firstOperation, parser.nextPhrase());
    ASSERT_EQ(secondOperation, parser.nextPhrase());
    removeFile();
}

TEST_F(ParserTests, RemoveContent) {
    const char *text = "(* Ecrire une fonction pair qui a un entier n associe un booléen valant"
                            "vrai ssi n est pair. *)"
                            "let pair = fun n -> n mod 2 = 0;;";
    writeTestFile(text);
    Parser parser(pathFile.c_str());
    const std::string expectedResult = "let pair = fun n -> n mod 2 = 0;;";
    parser.removeComments();
    ASSERT_EQ(expectedResult, parser.getSrcContent());
    removeFile();
}

#endif // PARSERTESTS_HPP
