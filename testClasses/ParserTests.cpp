#include "ParserTests.hpp"

void writeTestFile(const char *text) {
  std::ofstream myfile;
  myfile.open ("testFiles/example.ml");
  myfile << text;
  myfile.close();
}

void removeFile() {
    remove(pathFile.c_str());
}
