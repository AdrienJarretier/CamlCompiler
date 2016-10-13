#ifndef PARSERTESTS_HPP
#define PARSERTESTS_HPP

#include <gtest/gtest.h>
#include "Parser.hpp"
const std::string pathFile = "testFiles/example.ml";
const std::string PathTestCamlFile = "testFiles/srcTest.ml";

class ParserTests : public testing::Test {
public:
    virtual void SetUp();
    virtual void TearDown();
};
void writeTestFile(const char *text);

void removeFile();


#endif // PARSERTESTS_HPP
