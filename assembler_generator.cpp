
#include "assembler_generator.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

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
      compiler->set_number(num1 + num2, 0);
      break;
    case 1: 
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str_, "") != 0) {
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

      if(result == 0) {
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
        compiler->set_number(result, 2);
        compiler->get_register_value(variable_num, var, var_s, 1);

        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("ADD c");
      } 
      break;
    case 2: 
      compiler->get_register_value(num1, str_, str1, 1); 
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c");

      compiler->get_register_value(num2, str_2, str2, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("ADD c");
      break;  
  }
}

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
      if(strcmp(str_, "") != 0) {
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

      if(result == 0) {
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
          compiler->set_number(result, 2);
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
          compiler->add_machine_command("PUT b");
          compiler->set_number(result, 0);
          compiler->add_machine_command("SUB b");
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
      compiler->add_machine_command("PUT c");
      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("SUB c");
      break;
  }
}

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
      if(strcmp(str_, "") != 0) {
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

      if(result == 0) {
        compiler->add_machine_command("RST a");
      } else {
        if(result == 2) {
          compiler->get_register_value(variable_num, var, var_s, 1); 
          if(!compiler->checkLastCommand("STORE b")) {
            if(compiler->checkLastCommand("LOAD b")) {
              compiler->add_machine_command("LOAD a");
            } else {
              compiler->add_machine_command("LOAD b");
            }
          }
          compiler->add_machine_command("SHL a");
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
          compiler->add_machine_command("PUT b");
          long long originalResult = result; 
          compiler->add_machine_command("RST a");
          while(result > 0) {
            if(result % 2 == 0) {
              commands.push_back("SHL a");
              result /= 2;
            } else {
              commands.push_back("ADD b");
              result--;
            }
          }
          for(auto comm = commands.rbegin(); comm != commands.rend(); comm++) {
            compiler->add_machine_command(*comm);
          }
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
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("PUT g"); 

      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
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
      compiler->add_machine_command("GET g");
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("GET d");
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
      if(strcmp(str_, "") != 0) {
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
      else if(result == 1 && u == 1) {
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
        if(u == 1) {
          if(result == 2) {
            compiler->get_register_value(variable_num, var, var_s, 1);
            if(!compiler->checkLastCommand("STORE b")) {
              if(compiler->checkLastCommand("LOAD b")) {
                compiler->add_machine_command("LOAD a");
              } else {
              compiler->add_machine_command("LOAD b");
            }
           }
           compiler->add_machine_command("SHR a");
          }
          else {
            compiler->set_number(result, 2); 
            compiler->add_machine_command("GET c");
            compiler->add_machine_command("PUT e");
            compiler->get_register_value(variable_num, var, var_s, 3);
            if(!compiler->checkLastCommand("STORE d")) {
              if(compiler->checkLastCommand("LOAD d")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD d");
              }
            }
            long long commStart = compiler->getCommandsNumber();
            compiler->add_machine_command("JZERO ");
            compiler->add_machine_command("PUT d");
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("RST g");
            compiler->add_machine_command("RST f");
            long long jumpEnd = compiler->getCommandsNumber();
            compiler->add_machine_command("GET e"); 
            compiler->add_machine_command("PUT c"); 
            compiler->add_machine_command("SHL c"); 
            compiler->add_machine_command("GET d"); 
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB c");
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
            compiler->add_machine_command("DEC f");
            compiler->add_machine_command("GET f");
            long long jump_to = compiler->getCommandsNumber() - 4;
            compiler->add_machine_command("JUMP " + std::to_string(jump_to));
            compiler->add_machine_command("GET g");
            compiler->add_machine_command("ADD b");
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("PUT g");
            compiler->add_machine_command("GET d");
            compiler->add_machine_command("SUB c");
            compiler->add_machine_command("PUT d");
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB e");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 8));
            compiler->add_machine_command("RST f");
            compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
            compiler->add_machine_command("GET d");
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB c");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 3));
            compiler->add_machine_command("INC g");
            compiler->add_machine_command("GET g");
            compiler->add_machine_command("JUMP " + std::to_string(compiler->getCommandsNumber() + 2));
            compiler->add_machine_command("RST a");
            compiler->change_command(std::to_string(compiler->getCommandsNumber()), commStart, 1);
          }
        } 
        else {
          if(result == 0) {
            compiler->add_machine_command("RST a");
          } 
          else {
            compiler->set_number(result, 2); 
            compiler->add_machine_command("GET c"); 
            compiler->add_machine_command("PUT e");
            compiler->get_register_value(variable_num, var, var_s, 3);
            if(!compiler->checkLastCommand("STORE d")) {
              if(compiler->checkLastCommand("LOAD d")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD d");
              }
            }
            long long startDivisor = compiler->getCommandsNumber();
            compiler->add_machine_command("JZERO ");
            compiler->add_machine_command("PUT d"); 
            compiler->add_machine_command("GET c");
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB d");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 37));
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("RST g");
            compiler->add_machine_command("RST f");
            long long jumpEnd = compiler->getCommandsNumber();
            compiler->add_machine_command("GET d");
            compiler->add_machine_command("PUT c"); 
            compiler->add_machine_command("SHL c"); 
            compiler->add_machine_command("GET e");
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB c");
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
            compiler->add_machine_command("DEC f");
            compiler->add_machine_command("GET f");
            long long jump_to = compiler->getCommandsNumber() - 4;
            compiler->add_machine_command("JUMP " + std::to_string(jump_to));
            compiler->add_machine_command("GET g");
            compiler->add_machine_command("ADD b");
            compiler->add_machine_command("RST b");
            compiler->add_machine_command("PUT g");
            compiler->add_machine_command("GET e");
            compiler->add_machine_command("SUB c");
            compiler->add_machine_command("PUT e");
            compiler->add_machine_command("INC a");
            compiler->add_machine_command("SUB d");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
            compiler->add_machine_command("RST f");
            compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
            compiler->add_machine_command("INC g");
            compiler->add_machine_command("GET g");
            compiler->change_command(std::to_string(compiler->getCommandsNumber()), startDivisor, 1);
          }
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
      long long jumpStartDivisor = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("PUT g");
      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      long long jumpStartDividend = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 37));
      compiler->add_machine_command("RST e");
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("RST f");
      long long jumpEnd = compiler->getCommandsNumber();
      compiler->add_machine_command("GET g");
      compiler->add_machine_command("PUT b");
      compiler->add_machine_command("SHL b");
      compiler->add_machine_command("GET c");
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB b");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("INC f");
      compiler->add_machine_command("DEC a");
      long long num_lin_2 = compiler->getCommandsNumber() - 7;
      compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
      compiler->add_machine_command("SHR b");
      compiler->add_machine_command("GET f");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 19));
      compiler->add_machine_command("INC h");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
      compiler->add_machine_command("SHL h");
      compiler->add_machine_command("DEC f");
      compiler->add_machine_command("GET f");
      long long jump_to = compiler->getCommandsNumber() - 4;
      compiler->add_machine_command("JUMP " + std::to_string(jump_to));
      compiler->add_machine_command("GET e");
      compiler->add_machine_command("ADD h");
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("PUT e");
      compiler->add_machine_command("GET c");
      compiler->add_machine_command("SUB b");
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("RST f");
      compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
      compiler->add_machine_command("INC e");
      compiler->add_machine_command("GET e");
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartDivisor, 1);
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartDividend, 1);
      break;
  }
}

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
      if(strcmp(str_, "") != 0) {
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

      if((result == 0 && u == 1) || (result == 1 && u == 1)) {
        compiler->add_machine_command("RST a");
      }
      else if(result == 0 && u == 2) { // 0 mod p
        compiler->add_machine_command("RST a");
      }
      else {
        if(u == 1) {
          if(result == 2) {
            compiler->set_number(result, 2);
            compiler->add_machine_command("GET c");
            compiler->add_machine_command("PUT c");
            compiler->get_register_value(variable_num, var, var_s, 1);
            if(!compiler->checkLastCommand("STORE b")) {
              if(compiler->checkLastCommand("LOAD b")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD b");
              }
            }
            compiler->add_machine_command("PUT b");
            compiler->add_machine_command("SHR b"); 
            compiler->add_machine_command("SHL b"); 
            compiler->add_machine_command("SUB b");
          }
          else {
            compiler->set_number(result, 2); 
            compiler->add_machine_command("GET c"); 
            compiler->add_machine_command("PUT c");
            compiler->get_register_value(variable_num, var, var_s, 1);
            if(!compiler->checkLastCommand("STORE b")) {
              if(compiler->checkLastCommand("LOAD b")) {
                compiler->add_machine_command("LOAD a");
              } else {
                compiler->add_machine_command("LOAD b");
              }
            }
            compiler->add_machine_command("INC a");
            long long jump = compiler->getCommandsNumber();
            compiler->add_machine_command("PUT b");
            compiler->add_machine_command("SUB c");
            compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 2));
            compiler->add_machine_command("JPOS " + std::to_string(jump));
            compiler->add_machine_command("GET b");
            compiler->add_machine_command("DEC a");
          }
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
          long long jump = compiler->getCommandsNumber();
          compiler->add_machine_command("JZERO ");
          compiler->add_machine_command("PUT b");
          compiler->set_number(result, 2);
          compiler->add_machine_command("GET c");
          compiler->add_machine_command("INC a");
          long long jumpLoop = compiler->getCommandsNumber();
          compiler->add_machine_command("PUT c");
          compiler->add_machine_command("SUB b");
          compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 2));
          compiler->add_machine_command("JPOS " + std::to_string(jumpLoop));
          compiler->add_machine_command("GET c");
          compiler->add_machine_command("DEC a");
          compiler->change_command(std::to_string(compiler->getCommandsNumber()), jump, 1);
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
      long long jumpStartSecond = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO "); 
      compiler->add_machine_command("PUT g");
      compiler->get_register_value(num1, str_, str1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      long long jumpStartFirst = compiler->getCommandsNumber();
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("PUT e");
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 38));
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("RST d");
      compiler->add_machine_command("RST f");
      long long jumpEnd = compiler->getCommandsNumber();
      compiler->add_machine_command("GET g"); 
      compiler->add_machine_command("PUT b"); 
      compiler->add_machine_command("SHL b"); 
      compiler->add_machine_command("GET c"); 
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB b");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      compiler->add_machine_command("INC f");
      compiler->add_machine_command("DEC a");
      long long num_lin_2 = compiler->getCommandsNumber() - 7;
      compiler->add_machine_command("JUMP " + std::to_string(num_lin_2));
      compiler->add_machine_command("SHR b");
      compiler->add_machine_command("GET d");
      compiler->add_machine_command("ADD b");
      compiler->add_machine_command("PUT d");
      compiler->add_machine_command("GET f");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 16));
      compiler->add_machine_command("INC h");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 5));
      compiler->add_machine_command("SHL h");
      compiler->add_machine_command("DEC f");
      compiler->add_machine_command("GET f");
      long long jump_to = compiler->getCommandsNumber() - 4;
      compiler->add_machine_command("JUMP " + std::to_string(jump_to));
      compiler->add_machine_command("RST h");
      compiler->add_machine_command("GET c");
      compiler->add_machine_command("SUB b");
      compiler->add_machine_command("PUT c");
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB g");
      compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 3));
      compiler->add_machine_command("RST f");
      compiler->add_machine_command("JUMP " + std::to_string(jumpEnd));
      compiler->add_machine_command("GET e");
      compiler->add_machine_command("SUB d");
      compiler->add_machine_command("JUMP " + std::to_string(compiler->getCommandsNumber() + 2));
      compiler->add_machine_command("GET c");
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartSecond, 1);
      compiler->change_command(std::to_string(compiler->getCommandsNumber()), jumpStartFirst, 1); 
      break;
  }
}

void AssemblerGenerator::get_number(long long num, const char *str, const char *str1) {
  if(strcmp(str, "") == 0 && strcmp(str1, "") == 0) {
    compiler->add_machine_command("RST a");
    compiler->set_number(num, 0);
  } else {
    compiler->get_register_value(num, str, str1, 3);
    if(!compiler->checkLastCommand("STORE d")) {
      if(compiler->checkLastCommand("LOAD d")) {
        compiler->add_machine_command("LOAD a");
      } else {
        compiler->add_machine_command("LOAD d");
      }
    }
  }
}
