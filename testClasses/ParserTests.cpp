#include <fstream>
#include "ParserTests.hpp"

const std::string pathFile = "example.ml";
const std::string PathTestCamlFile = "testFiles/srcTest.ml";

void writeTestFile(const char *text) {
  std::ofstream myfile;
  myfile.open (pathFile.c_str());
  myfile << text;
  myfile.close();
}

void removeFile() {
    remove(pathFile.c_str());
}

void ParserTests::SetUp() {
}

void ParserTests::TearDown() {
    removeFile();
}


TEST_F(ParserTests, CreateParse) {
    ASSERT_NO_THROW(
        Parser parser(PathTestCamlFile.c_str());
    );
}

TEST_F(ParserTests, LoadFile) {
    const char * content = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
    writeTestFile(content);
    Parser parser(pathFile.c_str());
    ASSERT_EQ(std::string(content), parser.getSrcContent().c_str());
}

TEST_F(ParserTests, NextPhrase) {
    const char * content = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
    const std::string firstOperation = "-2 * 3";
    const std::string secondOperation = "2+3*5";
    writeTestFile(content);
    Parser parser(pathFile.c_str());
    ASSERT_EQ(firstOperation, parser.nextPhrase());
    ASSERT_EQ(secondOperation, parser.nextPhrase());
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
}

