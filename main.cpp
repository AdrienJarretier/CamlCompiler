#include "Parser.hpp"
#include <gtest/gtest.h>
using namespace std;

const string pathFile = "testFiles/example.ml";
const string PathTestCamlFile = "testFiles/srcTest.ml";


void writeTestFile(const char *text) {
  ofstream myfile;
  myfile.open ("testFiles/example.ml");
  myfile << text;
  myfile.close();
}

void removeFile() {
    remove(pathFile.c_str());
}


TEST(ParserTest, CreateParse) {
    ASSERT_NO_THROW(
        Parser parser(PathTestCamlFile.c_str());
        removeFile();
    );
}

TEST(ParserTest, LoadFile) {
    const char * content = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
    writeTestFile(content);
    Parser parser(pathFile.c_str());
    ASSERT_EQ(string(content), parser.getSrcContent().c_str());
    removeFile();
}

TEST(ParserTest, NextPhrase) {
    const char * content = "-2 * 3;;2+3*5;;-(5+1)*(-2+5)+2*3;;";
    const string firstOperation = "-2 * 3";
    const string secondOperation = "2+3*5";
    writeTestFile(content);
    Parser parser(pathFile.c_str());
    ASSERT_EQ(firstOperation, parser.nextPhrase());
    ASSERT_EQ(secondOperation, parser.nextPhrase());
    removeFile();
}

TEST(ParserTest, RemoveContent) {
    const char *text = "(* Ecrire une fonction pair qui a un entier n associe un booléen valant"
                            "vrai ssi n est pair. *)"
                            "let pair = fun n -> n mod 2 = 0;;";
    writeTestFile(text);
    Parser parser(pathFile.c_str());
    const string expectedResult = "let pair = fun n -> n mod 2 = 0;;";
    parser.removeComments();
    ASSERT_EQ(expectedResult, parser.getSrcContent());
    removeFile();
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
