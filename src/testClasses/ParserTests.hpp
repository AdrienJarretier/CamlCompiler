#ifndef PARSERTESTS_HPP
#define PARSERTESTS_HPP

#include <gtest/gtest.h>

class ParserTests : public testing::Test {
public:
    virtual void SetUp();
    virtual void TearDown();
};
void writeTestFile(const char *text);

void removeFile();


#endif // PARSERTESTS_HPP
