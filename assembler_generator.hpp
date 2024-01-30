#ifndef ASSEMBLER_GENERATOR_HPP
#define ASSEMBLER_GENERATOR_HPP

#include "compiler.hpp"

class AssemblerGenerator {
  private:
    Compiler *compiler;

  public:
    AssemblerGenerator(Compiler *compiler) : compiler(compiler) {}

    void read(const char *s);
    void write(const char *s);

    void get_number(long long num1, const char *str, const char *str1);
    void add(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2);
    void subtract(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2);
    void multiply(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2);
    void divide(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2);
    void modulo(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2);
};

#endif
