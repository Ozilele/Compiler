
#include <iostream>
#include "parser.hpp"

int execute(const char* input_file, const char* output_file);

int main(int argc, const char* argv[]) {
  if(argc < 3) {
    std::cout << "Nastąpił błąd " << std::endl;
    return 1;
  }

  return execute(argv[1], argv[2]);
}