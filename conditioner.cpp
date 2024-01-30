
#include "conditioner.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

// #include "conditioner.hpp"
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// #include <algorithm>

// Equal done and tested and little optimised
void Conditioner::equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2) {
  int counter = 0;
  long long result;

  if(strcmp(str1, "") != 0) {
    counter++;
  }
  if(strcmp(str2, "") != 0) {
    counter++;
  }

  switch (counter) {
  case 0: // dwie liczby
    compiler->add_machine_command("RST a");
    if(num1 == num2) {
      compiler->add_machine_command("JPOS "); // r_a <- 0, so not jump
    } else { // values not equal jump outside the scope
      compiler->add_machine_command("JZERO ");
    }
    break;
  case 1:
    int variable_num;
    const char *var;
    const char *var_s;
    if(strcmp(str1, "") != 0) {
      result = num2;
      variable_num = num1;
      var = str1;
      var_s = str1_1;
    } else {
      result = num1;
      variable_num = num2;
      var = str2;
      var_s = str2_2;
    }

    if(result == 0) { // case for n=0
      compiler->get_register_value(variable_num, var, var_s, 1); // wczytanie wartosci z r_b
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b"); // r_a <- p_rb
        }
      }
      compiler->add_machine_command("JPOS "); // jump if r_a > 0(not equal to 0)
    } else { // case for n = 10
      compiler->set_number(result, 2); // r_c <- result
      compiler->get_register_value(variable_num, var, var_s, 1);

      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }

      compiler->add_machine_command("PUT d"); // r_d <- r_a(n)
      compiler->add_machine_command("SUB c"); // n - result
      compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3)); // jump if they are not equal(r_a > 0)
      //need to check otherwise to fully check if they are equal
      compiler->add_machine_command("GET c"); // r_a <- r_c(result)
      compiler->add_machine_command("SUB d"); // result - n
      compiler->add_machine_command("JPOS "); // jump if they are not equal(r_a > 0)
    }
    break;  
  case 2: // n=p
    compiler->get_register_value(num1, str1, str1_1, 1); // do rejestru r_a wczytanie r_b
    if(!compiler->checkLastCommand("STORE b")) {
      if(compiler->checkLastCommand("LOAD b")) {
        compiler->add_machine_command("LOAD a");
      } else {
        compiler->add_machine_command("LOAD b");
      }
    }
    compiler->add_machine_command("PUT c"); // r_c <- r_a(n)
    compiler->get_register_value(num2, str2, str2_2, 3); // r_a <- r_d

    if(!compiler->checkLastCommand("STORE d")) {
      if(compiler->checkLastCommand("LOAD d")) {
        compiler->add_machine_command("LOAD a");
      } else {
        compiler->add_machine_command("LOAD d"); // r_a <- p
      }
    } 
    
    compiler->add_machine_command("PUT e"); // r_e <- p
    compiler->add_machine_command("SUB c"); // p - n
    compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3));
    compiler->add_machine_command("GET c"); // r_a <- r_c(n)
    compiler->add_machine_command("SUB e"); // n - p
    compiler->add_machine_command("JPOS ");
    break;
  }
}   

// Not equal done and tested and optimised
void Conditioner::not_equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2) {
  long long result;
  int counter = 0;

  if(strcmp(str1, "") != 0) {
    counter++;
  }
  if(strcmp(str2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      compiler->add_machine_command("RST a");
      if(num1 == num2) {
        compiler->add_machine_command("JZERO "); // jump if they are equal
      } else {
        compiler->add_machine_command("JPOS "); // continue processing if they are not equal
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str1, "") != 0) {
        result = num2;
        variable_num = num1;
        var = str1;
        var_s = str1_1;
      } else {
        result = num1;
        variable_num = num2;
        var = str2;
        var_s = str2_2;
      }

      if(result == 0) {
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b"); // r_a <- p_rb
          }
        }
        compiler->add_machine_command("JZERO "); // jump if result equals 0
      } 
      else { // n != 5
        compiler->set_number(result, 2); // wczytanie liczby do rejestru r_c
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b"); // r_a <- p_r_b(n)
          }
        }
        
        compiler->add_machine_command("PUT d"); // r_d <- r_a
        compiler->add_machine_command("SUB c"); // r_a -= r_c
        compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3));
        compiler->add_machine_command("GET c"); // r_a <- r_c
        compiler->add_machine_command("SUB d"); // result - n
        compiler->add_machine_command("JZERO "); // jump if r_a = 0
      }
      break;
    case 2: // n != p
      compiler->get_register_value(num1, str1, str1_1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- n
      compiler->get_register_value(num2, str2, str2_2, 3);
      
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("PUT e"); // r_e <- p
      compiler->add_machine_command("SUB c"); // p - n
      compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3)); // wynik > 0, to skacz
      compiler->add_machine_command("GET c"); // r_a <- n
      compiler->add_machine_command("SUB e");  // n - p
      compiler->add_machine_command("JZERO "); // jezeli wynik > 0
      break;
  }
}

// Implemented and tested
void Conditioner::greater(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2) {
  int counter = 0;
  long long result;

  if(strcmp(str1, "") != 0) {
    counter++;
  }
  if(strcmp(str2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      compiler->add_machine_command("RST a");
      if(num1 > num2) {
        compiler->add_machine_command("JPOS ");
      } else { // jump if num1 is not greater than num2
        compiler->add_machine_command("JZERO ");
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str1, "") != 0) {
        result = num2;
        variable_num = num1;
        var = str1;
        var_s = str1_1;
      } else {
        result = num1;
        variable_num = num2;
        var = str2;
        var_s = str2_2;
      }

      if(result == 0) { // n > 0
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b"); // r_a <- p_rb
          }
        }
        compiler->add_machine_command("JZERO ");
      } else { // n > 5
        compiler->set_number(result, 2); // r_c -> result
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("SUB c"); // n - result
        compiler->add_machine_command("JZERO "); // jump if r_a = 0
      }
      break;
    case 2: // n > p
      compiler->get_register_value(num2, str2, str2_2, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- p

      compiler->get_register_value(num1, str1, str1_1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // r_a <- n
        }
      }
      compiler->add_machine_command("SUB c"); // n - p
      compiler->add_machine_command("JZERO "); // jump if r_a is positive
      break;
  }
}

// Implemented and tested
void Conditioner::less(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2) {
  int counter = 0;
  long long result;

  if(strcmp(str1, "") != 0) {
    counter++;
  }
  if(strcmp(str2, "") != 0) {
    counter++;
  }

  switch (counter) {
    case 0:
      compiler->add_machine_command("RST a");
      if(num1 < num2) {
        compiler->add_machine_command("JPOS ");
      } else {
        compiler->add_machine_command("JZERO "); // if num1 is not less than num2 then jump
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str1, "") != 0) {
        result = num2;
        variable_num = num1;
        var = str1;
        var_s = str1_1;
      } else {
        result = num1;
        variable_num = num2;
        var = str2;
        var_s = str2_2;
      }

      // n < 5
      compiler->set_number(result, 2); // r_c <- result
      compiler->get_register_value(variable_num, var, var_s, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if (compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT d"); // r_d <- n
      compiler->add_machine_command("GET c"); // r_a <- result
      compiler->add_machine_command("SUB d"); // result - n
      compiler->add_machine_command("JZERO ");
      break;
    case 2: // n < p
      compiler->get_register_value(num1, str1, str1_1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if (compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- n

      compiler->get_register_value(num2, str2, str2_2, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // r_a <- p
        }
      }
      compiler->add_machine_command("SUB c"); // p - n
      compiler->add_machine_command("JZERO "); // jump if r_a = 0
      break;
  }
}

// Implemented and tested chyba ok
void Conditioner::greater_equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2) {
  int counter = 0;
  long long result;

  if(strcmp(str1, "") != 0) {
    counter++;
  }
  if(strcmp(str2, "") != 0) {
    counter++;
  } 

  switch (counter) {
    case 0:
      compiler->add_machine_command("RST a");
      if(num1 >= num2) {
        compiler->add_machine_command("JPOS ");
      } else {
        compiler->add_machine_command("JZERO "); // if num1 is not greater or equal than num2 then jump
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str1, "") != 0) {
        result = num2;
        variable_num = num1;
        var = str1;
        var_s = str1_1;
      } else {
        result = num1;
        variable_num = num2;
        var = str2;
        var_s = str2_2;
      }

      if(result == 0) { // n >= 0
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b"); // r_a <- p_rb
          }
        }
        compiler->add_machine_command("INC a");
        compiler->add_machine_command("JZERO "); // jump if r_a > 0
        compiler->add_machine_command("DEC a");
      } else { // n >= 5
        compiler->set_number(result, 2); // r_c -> result
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b"); // r_a <- n
          }
        }
        compiler->add_machine_command("INC a");
        compiler->add_machine_command("SUB c"); // n - result
        compiler->add_machine_command("JZERO "); // jump if r_a = 0
        compiler->add_machine_command("DEC a");
      }
      break;
    case 2: // n >= p
      compiler->get_register_value(num2, str2, str2_2, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- r_a(p)
      compiler->get_register_value(num1, str1, str1_1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // r_a <- n
        }
      }
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB c"); // n - p
      compiler->add_machine_command("JZERO "); // jump if r_a = 0
      compiler->add_machine_command("DEC a");
      break;
  }
}

// Implemented and tested chyba git
void Conditioner::less_equal(long long num1, const char *str1, const char *str1_1, long long num2, const char *str2, const char *str2_2) {
  int counter = 0;
  long long result;

  if(strcmp(str1, "") != 0) {
    counter++;
  }
  if(strcmp(str2, "") != 0) {
    counter++;
  }

  switch(counter) {
    case 0:
      compiler->add_machine_command("RST a");
      if(num1 <= num2) {
        compiler->add_machine_command("JPOS ");
      } else {
        compiler->add_machine_command("JZERO "); // if num1 is not less than or equal num2 then jump
      }
      break;
    case 1:
      int variable_num;
      const char *var;
      const char *var_s;
      if(strcmp(str1, "") != 0) {
        result = num2;
        variable_num = num1;
        var = str1;
        var_s = str1_1;
      } else {
        result = num1;
        variable_num = num2;
        var = str2;
        var_s = str2_2;
      }

      if(result == 0) { // n <= 0
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if (compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("JPOS "); // jump if r_a > 0
      } else { // n <= 5
        compiler->set_number(result, 2); // r_c <- result
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if (compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("PUT d"); // r_d <- n(i)
        compiler->add_machine_command("GET c"); // r_a <- result(111110)
        compiler->add_machine_command("INC a");
        compiler->add_machine_command("SUB d"); // result - n
        compiler->add_machine_command("JZERO "); // jump if r_a = 0
        compiler->add_machine_command("DEC a");
      }
      break;
    case 2: // n <= p
      compiler->get_register_value(num1, str1, str1_1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if (compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); // r_c <- n

      compiler->get_register_value(num2, str2, str2_2, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d"); // r_a <- p
        }
      }
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB c"); // p - n
      compiler->add_machine_command("JZERO "); // jump if r_a = 0
      compiler->add_machine_command("DEC a");
      break;
  }
}

