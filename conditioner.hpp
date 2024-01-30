#ifndef CONDITIONER_HPP
#define CONDITIONER_HPP

#include "compiler.hpp"

class Conditioner {
  private:
    Compiler *compiler;

  public:
    Conditioner(Compiler *compiler) : compiler(compiler) {}
    
    void equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2);
    void not_equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2);
    void greater(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2);
    void less(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2);
    void greater_equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2);
    void less_equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2);
};

#endif