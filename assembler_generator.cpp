
#include "assembler_generator.hpp"
#include <string>
#include <iostream>

// Add done and tested
void AssemblerGenerator::add(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2) {
  long long result;
  int counter = 0;

  if(strcmp(str_, "") != 0) { 
    counter++;
  }
  if(strcmp(str_2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      compiler->add_machine_command("RST a");
      compiler->set_number(num1 + num2, 0); // set to r_a value of S
      break;
    case 1: // 1 variable
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str_, "") != 0) { // str_ is variable, num2 is a number
        result = num2;
        variable_num = num1;
        var = str_;
        var_s = str1;
      } else {
        result = num1;
        variable_num = num2;
        var = str_2;
        var_s = str2;
      }

      if(result == 0) { // a + 0
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
      } 
      else { // a + 5
        compiler->set_number(result, 2); // r_c <- result
        compiler->get_register_value(variable_num, var, var_s, 1); // r_a <- variable_value

        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("ADD c"); // r_a <- r_a + r_c
      } 
      break;
    case 2: // a + b
      compiler->get_register_value(num1, str_, str1, 1); // save var value in r_a
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- r_a
      compiler->get_register_value(num2, str_2, str2, 1);

      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("ADD c"); // ra <- ra + r_c
      break;  
  }
}

// Subtract done and tested
void AssemblerGenerator::subtract(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2) {
  long long result;
  int counter = 0;

  if(strcmp(str_, "") != 0) { 
    counter++;
  }
  if(strcmp(str_2, "") != 0) {
    counter++;
  }

  switch (counter) {
    case 0:
      compiler->add_machine_command("RST a");
      compiler->set_number(num1 - num2, 0);
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str_, "") != 0) { // str_ is variable, num2 is a number
        result = num2;
        variable_num = num1;
        var = str_;
        var_s = str1;
      } else {
        result = num1;
        variable_num = num2;
        var = str_2;
        var_s = str2;
      }

      if(result == 0) { // p=n-0, p=0-n
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
      }
      else {
        if(strcmp(str_, "") != 0) {
          compiler->set_number(result, 2); // r_c <- result
          compiler->get_register_value(variable_num, var, var_s, 1);

          if(!compiler->checkLastCommand("STORE b")) {
            if(compiler->checkLastCommand("LOAD b")) {
              compiler->add_machine_command("LOAD a");
            } else {
              compiler->add_machine_command("LOAD b");
            }
          }
          compiler->add_machine_command("SUB c");
        }
        else {
          compiler->get_register_value(variable_num, var, var_s, 1);
          if(!compiler->checkLastCommand("STORE b")) {
            if(compiler->checkLastCommand("LOAD b")) {
              compiler->add_machine_command("LOAD a");
            } else {
              compiler->add_machine_command("LOAD b");
            }
          }
          compiler->add_machine_command("PUT b"); // r_b <- r_a
          compiler->set_number(result, 0);
          compiler->add_machine_command("SUB b"); // r_a -> r_a - r_b
        }
      }
      break;
    case 2:
      compiler->get_register_value(num2, str_2, str2, 1);

      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }

      compiler->add_machine_command("PUT c"); // r_c <- ra
      compiler->get_register_value(num1, str_, str1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("SUB c"); // r_a <- r_a - r_c
      break;
  }
}

// Multiply done and tested
void AssemblerGenerator::multiply(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2) {
  long long result;
  int counter = 0;
  std::vector<std::string> commands;

  if(strcmp(str_, "") != 0) { 
    counter++;
  }
  if(strcmp(str_2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      compiler->set_number(num1 * num2, 0);
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str_, "") != 0) { // str_ is variable, num2 is a number
        result = num2;
        variable_num = num1;
        var = str_;
        var_s = str1;
      } else {
        result = num1;
        variable_num = num2;
        var = str_2;
        var_s = str2;
      }

      if(result == 0) { // n * 0
        compiler->add_machine_command("RST a");
      } else { // n * 5

        if(result == 2) { // n * 2
          compiler->get_register_value(variable_num, var, var_s, 1); // 
          if(!compiler->checkLastCommand("STORE b")) {
            if(compiler->checkLastCommand("LOAD b")) {
              compiler->add_machine_command("LOAD a");
            } else {
              compiler->add_machine_command("LOAD b"); // zaladowanie zmiennej do r_a <- n
            }
          }
          compiler->add_machine_command("SHL a");
        } 
        else {
          compiler->get_register_value(variable_num, var, var_s, 1); // 
          if(!compiler->checkLastCommand("STORE b")) {
            if(compiler->checkLastCommand("LOAD b")) {
              compiler->add_machine_command("LOAD a");
            } else {
              compiler->add_machine_command("LOAD b"); // zaladowanie zmiennej do r_a <- n
            }
          }
          compiler->add_machine_command("PUT b"); // r_b <- r_a
          long long originalResult = result; 
          compiler->add_machine_command("RST a");
          while(result > 0) {
            if(result % 2 == 0) {
              commands.push_back("SHL a");
              result /= 2;
            } else {
              commands.push_back("ADD b"); // r_a <- r_a + r_b
              result--;
            }
          }

          for(auto comm = commands.rbegin(); comm != commands.rend(); comm++) {
            compiler->add_machine_command(*comm);
          }
        }
      }
      break;
    case 2: // n * p()
      compiler->get_register_value(num2, str_2, str2, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // r_a <- p_rd
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- r_a
      compiler->add_machine_command("PUT e"); // r_e <- r_a

      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // r_a <- n
        }
      }

      long long num_lin = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("PUT d");
      compiler->add_machine_command("RST f");
      compiler->set_number(1, 1);
      compiler->add_machine_command("SHR a");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("SHL b");
      compiler->add_machine_command("SHL c");
      long long num_lin_2 = compiler->getCommandsNumber() - 4;
      compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
      compiler->add_machine_command("GET f");
      compiler->add_machine_command("ADD c");
      compiler->add_machine_command("PUT f");
      compiler->add_machine_command("GET e");
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("GET d"); // r_a < r_d
      compiler->add_machine_command("SUB b");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
      compiler->add_machine_command("PUT d");
      compiler->set_number(1, 1);
      compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
      compiler->add_machine_command("GET f");
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), num_lin, 1);
      break;
  }
}

// Divison done, inspired by algorithm written in BASIC https://retro64.altervista.org/blog/6502-assembly-math-division-simple-algorithm-using-powers-of-two/?doing_wp_cron=1704748696.3601360321044921875000
void AssemblerGenerator::divide(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2) {
  long long result;
  int counter = 0;
  int u;
  std::vector<std::string> commands;

  if(strcmp(str_, "") != 0) { 
    counter++;
  }
  if(strcmp(str_2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      if(num2 != 0) {
        compiler->set_number(num1 / num2, 0);
      } else {
        compiler->add_machine_command("RST a");
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str_, "") != 0) { // str_ is variable, num2 is a number
        result = num2;
        variable_num = num1;
        var = str_;
        var_s = str1;
        u = 1;
      } else {
        result = num1;
        variable_num = num2;
        var = str_2;
        var_s = str2;
        u = 2;
      }

      if(result == 0) {
        compiler->add_machine_command("RST a");
      } 
      else if(result == 1 && u == 1) { // n / 1
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b"); // zaladowanie zmiennej do r_a <- n
          }
        }
      }
      else { 
        if(u == 1) { // case when n/5(result is the divisor)

          if(result == 2) { // n / 2
            compiler->get_register_value(variable_num, var, var_s, 1);
            if(!compiler->checkLastCommand("STORE b")) {
              if(compiler->checkLastCommand("LOAD b")) {
                compiler->add_machine_command("LOAD a");
              } else {
              compiler->add_machine_command("LOAD b"); // zaladowanie zmiennej do r_a <- n
            }
           }
           compiler->add_machine_command("SHR a");
          }

          else {
            compiler->set_number(result, 2); // r_c <- result // ?
            compiler->add_machine_command("GET c");
            compiler->add_machine_command("PUT e"); // r_e <- r_c

            compiler->get_register_value(variable_num, var, var_s, 3);
            if(!compiler->checkLastCommand("STORE d")) {
              if(compiler->checkLastCommand("LOAD d")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD d"); // r_a <- p_rd(n)
              }
            }
            long long commStart = compiler->getCommandsNumber();
            compiler->add_machine_command("JZERO ");
            compiler->add_machine_command("PUT d"); // r_d <- r_a(n)
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("RST g");
            compiler->add_machine_command("RST f"); // counter;
            long long jumpEnd = compiler->getCommandsNumber();
            compiler->add_machine_command("GET e"); // r_a <- r_e(result)
            compiler->add_machine_command("PUT c"); // r_c <- result
            compiler->add_machine_command("SHL c"); // r_c <- r_c * 2
            compiler->add_machine_command("GET d"); // r_a <- r_c
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB c"); // r_a <- r_a - r_c
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
            compiler->add_machine_command("INC f"); // r_f <- r_f + 1
            compiler->add_machine_command("DEC a");
            long long num_lin_2 = compiler->getCommandsNumber() - 7;
            compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
            // compiler->add_machine_command("DEC a");
            compiler->add_machine_command("SHR c"); // discard // r_c = 8(partial dividend)
            compiler->add_machine_command("GET f"); // r_a <- r_f <- 2
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 19));
            compiler->add_machine_command("INC b"); // r_b <- 1
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
            compiler->add_machine_command("SHL b"); // r_b <- 2
            compiler->add_machine_command("DEC f"); // r_f <- 1
            compiler->add_machine_command("GET f"); // r_a <- r_f <- 1
            long long jump_to = compiler->getCommandsNumber() - 4;
            compiler->add_machine_command("JUMP " + std::to_string(jump_to));
            compiler->add_machine_command("GET g");
            compiler->add_machine_command("ADD b");
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("PUT g"); // r_g <- 4
            compiler->add_machine_command("GET d"); // r_a <- r_d(n) <- 15
            compiler->add_machine_command("SUB c"); // r_a <- r_a - r_c = 2(new dividend) = 2
            compiler->add_machine_command("PUT d"); // r_d <- r_a
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB e");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
            compiler->add_machine_command("RST f");
            compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
            compiler->add_machine_command("INC g");
            compiler->add_machine_command("GET g"); // result
            compiler->change_command(std::to_string(compiler->getCommandsNumber()), commStart, 1);
          }
        } 
        else { // case when 5 / n
          if(result == 0) {
            compiler->add_machine_command("RST a");
          } 
          else {
            compiler->set_number(result, 2); // r_c <- result
            compiler->add_machine_command("PUT c"); // r_c <- r_a
            compiler->add_machine_command("PUT e"); // r_e <- r_a

            compiler->get_register_value(variable_num, var, var_s, 3);
            if(!compiler->checkLastCommand("STORE d")) {
              if(compiler->checkLastCommand("LOAD d")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD d"); // r_a <- p_rd(n)
              }
            }

            long long startDivisor = compiler->getCommandsNumber();
            compiler->add_machine_command("JZERO ");
            compiler->add_machine_command("PUT d"); // r_d <- r_a(n)
            compiler->add_machine_command("GET c"); // r_a <- r_c
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB d");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 37));
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("RST g");
            compiler->add_machine_command("RST f"); // counter;
            long long jumpEnd = compiler->getCommandsNumber();
            compiler->add_machine_command("GET d");
            compiler->add_machine_command("PUT c"); 
            compiler->add_machine_command("SHL c"); 
            compiler->add_machine_command("GET e"); // r_a <- r_e <- 5
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB c"); // r_a <- r_a - r_c
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
            compiler->add_machine_command("INC f");
            compiler->add_machine_command("DEC a");
            long long num_lin_2 = compiler->getCommandsNumber() - 7;
            compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
            compiler->add_machine_command("SHR c"); 
            compiler->add_machine_command("GET f");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 19));
            compiler->add_machine_command("INC b");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
            compiler->add_machine_command("SHL b");
            compiler->add_machine_command("DEC f"); // r_f <- 1
            compiler->add_machine_command("GET f"); // r_a <- r_f <- 1
            long long jump_to = compiler->getCommandsNumber() - 4;
            compiler->add_machine_command("JUMP " + std::to_string(jump_to));
            compiler->add_machine_command("GET g"); // r_a <- r_d
            compiler->add_machine_command("ADD b");
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("PUT g"); // r_d <- r_a
            compiler->add_machine_command("GET e"); // r_a <- r_e
            compiler->add_machine_command("SUB c"); // r_a <- r_a - r_g(new dividend)
            compiler->add_machine_command("PUT e"); // r_e <- r_a
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB d"); // new_dividend - divisor
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
            compiler->add_machine_command("RST f");
            compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
            compiler->add_machine_command("INC g");
            compiler->add_machine_command("GET g"); // result
            compiler->change_command(std::to_string(compiler->getCommandsNumber()), startDivisor, 1);
          }
        }
      }
      break;
    case 2: // case when n / p
      compiler->get_register_value(num2, str_2, str2, 1); // wczytanie dzielnika
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b"); // zaladowanie zmiennej do r_a <- p
        }
      }

      long long jumpStartDivisor = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO "); // if divisor = 0 then jump
      compiler->add_machine_command("PUT g"); // r_g <- r_a <- p

      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // zaladowanie zmiennej do r_a <- n
        }
      }
      long long jumpStartDividend = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("PUT c"); // r_c <- n
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 37));
      compiler->add_machine_command("RST e");
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("RST f"); // counter;
      long long jumpEnd = compiler->getCommandsNumber();
      compiler->add_machine_command("GET g"); // r_a <- r_g
      compiler->add_machine_command("PUT b"); // r_b <- r_a
      compiler->add_machine_command("SHL b"); // r_b <- r_b * 2
      compiler->add_machine_command("GET c"); // r_a <- r_c
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB b"); // r_a <- r_a - r_b
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("INC f"); // r_f <- r_f + 1
      compiler->add_machine_command("DEC a");
      long long num_lin_2 = compiler->getCommandsNumber() - 7;
      compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
      compiler->add_machine_command("SHR b"); // r_b(partial dividend)
      compiler->add_machine_command("GET f"); // r_a <- r_f
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 19));
      compiler->add_machine_command("INC h"); // r_h <- 1
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
      compiler->add_machine_command("SHL h"); // r_h <- 2*
      compiler->add_machine_command("DEC f"); // r_f -= 1
      compiler->add_machine_command("GET f"); // r_a <- r_f
      long long jump_to = compiler->getCommandsNumber() - 4;
      compiler->add_machine_command("JUMP " + std::to_string(jump_to));
      compiler->add_machine_command("GET e"); // r_a <- r_e
      compiler->add_machine_command("ADD h"); // r_a += r_h
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("PUT e"); // r_e <- r_a
      compiler->add_machine_command("GET c"); // r_a <- r_c
      compiler->add_machine_command("SUB b"); // r_a <- r_a - r_b
      compiler->add_machine_command("PUT c"); // r_c <- r_a(new dividend)
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g"); // new_dividend - divisor
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("RST f");
      compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
      compiler->add_machine_command("INC e");
      compiler->add_machine_command("GET e"); // result
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartDivisor, 1);
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartDividend, 1);
      break;
  }
}

// Modulo done and tested(like divison but count partial dividends)
void AssemblerGenerator::modulo(long long num1, const char *str_, const char *str1, long long num2, const char *str_2, const char *str2) {
  long long result;
  int counter = 0;

  if(strcmp(str_, "") != 0) { 
    counter++;
  }
  if(strcmp(str_2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      if(num2 != 0) {
        compiler->set_number(num1 % num2, 0);
      } else {
        compiler->add_machine_command("RST a");
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      int u;
      if(strcmp(str_, "") != 0) { // str_ is variable, num2 is a number
        result = num2;
        variable_num = num1;
        var = str_;
        var_s = str1;
        u = 1;
      } else {
        result = num1;
        variable_num = num2;
        var = str_2;
        var_s = str2;
        u = 2;
      }
      // n/1 v 1/n
      if(result == 0 || (u == 1 && result == 1) || (u == 2 && result == 1)) {
        compiler->add_machine_command("RST a");
      } 
      else {
        if(u == 1) { // n mod 2, n mod 5
          if(result == 2) { // n(mod 2)
            compiler->set_number(result, 2); // r_c <- result
            compiler->get_register_value(variable_num, var, var_s, 1);
            if(!compiler->checkLastCommand("STORE b")) {
              if(compiler->checkLastCommand("LOAD b")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD b");
              }
            }
            compiler->add_machine_command("PUT b"); // r_b <- r_a(n)
            compiler->add_machine_command("SHR b"); 
            compiler->add_machine_command("SHL b"); // 
            compiler->add_machine_command("SUB b"); // modulo result
          }
          else { // n(mod 5) itp.
            compiler->set_number(result, 2); // r_c <- result
            compiler->get_register_value(variable_num, var, var_s, 1);
            if(!compiler->checkLastCommand("STORE b")) {
              if(compiler->checkLastCommand("LOAD b")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD b");
              }
            }
            compiler->add_machine_command("INC a"); // n+1
            long long jump = compiler->getCommandsNumber();
            compiler->add_machine_command("PUT b"); // r_b = r_a
            compiler->add_machine_command("SUB c"); //
            compiler->add_machine_command("JPOS " + std::to_string(jump));
            compiler->add_machine_command("GET b");
            compiler->add_machine_command("DEC a");
          }
        }
        else { // 5 mod x
          compiler->get_register_value(variable_num, var, var_s, 1);
          if(!compiler->checkLastCommand("STORE b")) {
            if(compiler->checkLastCommand("LOAD b")) {
              compiler->add_machine_command("LOAD a");
            } else {
              compiler->add_machine_command("LOAD b"); // r_a <- p_rb
            }
          }
          long long jump = compiler->getCommandsNumber();
          compiler->add_machine_command("JZERO ");
          compiler->add_machine_command("PUT b"); // r_b <- r_a(x)
          compiler->set_number(result, 2);
          compiler->add_machine_command("INC a");
          compiler->add_machine_command("PUT c"); // r_c <- r_a
          compiler->add_machine_command("SUB b");
          compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() - 2));
          compiler->add_machine_command("GET c");
          compiler->add_machine_command("DEC a");
          compiler->change_command(std::to_string(compiler->getCommandsNumber()), jump, 1);
        }
      }
      break;
    case 2: // n mod p
      compiler->get_register_value(num2, str_2, str2, 1); // wczytanie dzielnika
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b"); // zaladowanie zmiennej do r_a <- p
        }
      }

      long long jumpStartSecond = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO "); // if divisor = 0 then jump
      compiler->add_machine_command("PUT g"); // r_g <- r_a <- p

      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // zaladowanie zmiennej do r_a <- n
        }
      }

      long long jumpStartFirst = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("PUT e");
      compiler->add_machine_command("PUT c"); // r_c <- n
      // compiler->add_machine_command("GET c"); // r_a <- r_c
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 37));
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("RST d");
      compiler->add_machine_command("RST f"); // counter;
      long long jumpEnd = compiler->getCommandsNumber();
      compiler->add_machine_command("GET g"); // r_a <- r_g
      compiler->add_machine_command("PUT b"); // r_b <- r_a
      compiler->add_machine_command("SHL b"); // r_b <- r_b * 2
      compiler->add_machine_command("GET c"); // r_a <- r_c
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB b"); // r_a <- r_a - r_b
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("INC f"); // r_f <- r_f + 1
      compiler->add_machine_command("DEC a");
      long long num_lin_2 = compiler->getCommandsNumber() - 7;
      compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
      compiler->add_machine_command("SHR b"); // r_b(partial dividend)
      compiler->add_machine_command("GET d"); // r_a <- r_d
      compiler->add_machine_command("ADD b"); // r_a += r_b
      compiler->add_machine_command("PUT d"); // r_d <- r_a
      compiler->add_machine_command("GET f"); // r_a <- r_f
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 16));
      compiler->add_machine_command("INC h"); // r_h <- 1
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
      compiler->add_machine_command("SHL h"); // r_h <- 2*r_h
      compiler->add_machine_command("DEC f"); // r_f -= 1
      compiler->add_machine_command("GET f"); // r_a <- r_f
      long long jump_to = compiler->getCommandsNumber() - 4;
      compiler->add_machine_command("JUMP " + std::to_string(jump_to));
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("GET c"); // r_a <- r_c
      compiler->add_machine_command("SUB b"); // r_a <- r_a - r_b
      compiler->add_machine_command("PUT c"); // r_c <- r_a(new dividend)
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g"); // new_dividend - divisor
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 3));
      compiler->add_machine_command("RST f");
      compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
      compiler->add_machine_command("GET e"); // r_a <- r_e(n)
      compiler->add_machine_command("SUB d"); // r_a <- result of modulo
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartSecond, 1);
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartFirst, 1); 
      break;
  }
}

// Done and tested
void AssemblerGenerator::get_number(long long num, const char *str, const char *str1) {
  if(strcmp(str, "") == 0 && strcmp(str1, "") == 0) { // case when normal number
    compiler->set_number(num, 0);
  } else {
    compiler->get_register_value(num, str, str1, 1);
    if(!compiler->checkLastCommand("STORE b")) {
      if(compiler->checkLastCommand("LOAD b")) {
        compiler->add_machine_command("LOAD a");
      } else {
        compiler->add_machine_command("LOAD b");
      }
    }
  }
}
