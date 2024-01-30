
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
  case 0:
    compiler->add_machine_command("RST a");
    if(num1 == num2) {
      compiler->add_machine_command("JPOS ");
    } else {
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

    if(result == 0) {
      compiler->get_register_value(variable_num, var, var_s, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("JPOS ");
    } else {
      compiler->set_number(result, 2);
      compiler->get_register_value(variable_num, var, var_s, 1);

      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }

      compiler->add_machine_command("PUT d");
      compiler->add_machine_command("SUB c");
      compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3));
      compiler->add_machine_command("GET c");
      compiler->add_machine_command("SUB d"); 
      compiler->add_machine_command("JPOS ");
    }
    break;  
  case 2: 
    compiler->get_register_value(num1, str1, str1_1, 1);
    if(!compiler->checkLastCommand("STORE b")) {
      if(compiler->checkLastCommand("LOAD b")) {
        compiler->add_machine_command("LOAD a");
      } else {
        compiler->add_machine_command("LOAD b");
      }
    }
    compiler->add_machine_command("PUT c"); 
    compiler->get_register_value(num2, str2, str2_2, 3);

    if(!compiler->checkLastCommand("STORE d")) {
      if(compiler->checkLastCommand("LOAD d")) {
        compiler->add_machine_command("LOAD a");
      } else {
        compiler->add_machine_command("LOAD d");
      }
    } 
    
    compiler->add_machine_command("PUT e"); 
    compiler->add_machine_command("SUB c"); 
    compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3));
    compiler->add_machine_command("GET c"); 
    compiler->add_machine_command("SUB e");
    compiler->add_machine_command("JPOS ");
    break;
  }
}   

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
        compiler->add_machine_command("JZERO ");
      } else {
        compiler->add_machine_command("JPOS ");
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
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("JZERO ");
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
        
        compiler->add_machine_command("PUT d"); 
        compiler->add_machine_command("SUB c"); 
        compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3));
        compiler->add_machine_command("GET c"); 
        compiler->add_machine_command("SUB d"); 
        compiler->add_machine_command("JZERO "); 
      }
      break;
    case 2:
      compiler->get_register_value(num1, str1, str1_1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c");
      compiler->get_register_value(num2, str2, str2_2, 3);
      
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("PUT e");
      compiler->add_machine_command("SUB c"); 
      compiler->add_machine_command("JPOS " + std::to_string(compiler->getCommandsNumber() + 3));
      compiler->add_machine_command("GET c"); 
      compiler->add_machine_command("SUB e");  
      compiler->add_machine_command("JZERO "); 
      break;
  }
}

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
      } else {
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

      if(result == 0) {
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("JZERO ");
      } else { 
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
        compiler->add_machine_command("JZERO "); 
      }
      break;
    case 2:
      compiler->get_register_value(num2, str2, str2_2, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c"); 
      compiler->get_register_value(num1, str1, str1_1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("SUB c");
      compiler->add_machine_command("JZERO ");
      break;
  }
}

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

      compiler->set_number(result, 2);
      compiler->get_register_value(variable_num, var, var_s, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if (compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT d");
      compiler->add_machine_command("GET c");
      compiler->add_machine_command("SUB d");
      compiler->add_machine_command("JZERO ");
      break;
    case 2: 
      compiler->get_register_value(num1, str1, str1_1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if (compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c");

      compiler->get_register_value(num2, str2, str2_2, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("SUB c");
      compiler->add_machine_command("JZERO ");
      break;
  }
}

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

      if(result == 0) {
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("INC a");
        compiler->add_machine_command("JZERO ");
        compiler->add_machine_command("DEC a");
      } else {
        compiler->set_number(result, 2);
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if(compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("INC a");
        compiler->add_machine_command("SUB c");
        compiler->add_machine_command("JZERO ");
        compiler->add_machine_command("DEC a");
      }
      break;
    case 2:
      compiler->get_register_value(num2, str2, str2_2, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if(compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c");
      compiler->get_register_value(num1, str1, str1_1, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB c");
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("DEC a");
      break;
  }
}

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

      if(result == 0) {
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if (compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("JPOS ");
      } else {
        compiler->set_number(result, 2);
        compiler->get_register_value(variable_num, var, var_s, 1);
        if(!compiler->checkLastCommand("STORE b")) {
          if (compiler->checkLastCommand("LOAD b")) {
            compiler->add_machine_command("LOAD a");
          } else {
            compiler->add_machine_command("LOAD b");
          }
        }
        compiler->add_machine_command("PUT d");
        compiler->add_machine_command("GET c"); 
        compiler->add_machine_command("INC a");
        compiler->add_machine_command("SUB d"); 
        compiler->add_machine_command("JZERO ");
        compiler->add_machine_command("DEC a");
      }
      break;
    case 2:
      compiler->get_register_value(num1, str1, str1_1, 1);
      if(!compiler->checkLastCommand("STORE b")) {
        if (compiler->checkLastCommand("LOAD b")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD b");
        }
      }
      compiler->add_machine_command("PUT c");
      compiler->get_register_value(num2, str2, str2_2, 3);
      if(!compiler->checkLastCommand("STORE d")) {
        if(compiler->checkLastCommand("LOAD d")) {
          compiler->add_machine_command("LOAD a");
        } else {
          compiler->add_machine_command("LOAD d");
        }
      }
      compiler->add_machine_command("INC a");
      compiler->add_machine_command("SUB c");
      compiler->add_machine_command("JZERO ");
      compiler->add_machine_command("DEC a");
      break;
  }
}

