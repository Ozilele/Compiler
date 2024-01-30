
#include "compiler.hpp"
#include<iostream>
#include<vector>
#include<sstream>
#include<cstring>
#include<algorithm>

// #include "compiler.hpp"
// #include <iostream>
// #include <string>
// #include <vector>
// #include <sstream>
// #include <cstring>
// #include <algorithm>

extern void yyerror(const char *s);

void Compiler::add_declaration(const char *s, int size) {
  int isVariableAlreadyDeclared = get_declaration(s);
  // if(isVariableAlreadyDeclared != -1) {
  //   return yyerror((std::string("Druga deklaracja zmiennej ") + s).c_str());
  // }
  declarationList.push_back(std::make_pair(s, memoryCell));
  initializationList.push_back(std::make_pair(s, false));
  memoryCell += size;
};

int Compiler::get_declaration(const char *s) {
  for(const auto i : declarationList) {
    if(strcmp(i.first, s) == 0) {
      return i.second;
    }
  }
  return -1;
}

int Compiler::get_next_declaration(const char *s) {
  auto it = std::find_if(declarationList.begin(), declarationList.end(), [s](const auto &pair) {
    return strcmp(pair.first, s) == 0;
  });
  if(it != declarationList.end()) {
    return std::next(it)->second;
  }
  return -1;
}

int Compiler::get_first_declaration() {
  if(declarationList.size() > 0) {
    return declarationList[0].second;
  }
  return -1;
}

void Compiler::clear_declaration() {
  declarationList.clear();
  initializationList.clear();
}

void Compiler::get_register_value(int num, const char *str, const char *str1, int registerNum) {
  if(num == -1) {
    set_number(get_declaration(str), 1);
    for(auto argument : function_arguments) {
      if(argument.first <= get_declaration(str) && get_declaration(str) < argument.second) {
        add_machine_command("LOAD b");
        add_machine_command("PUT b");
        break;
      }
    }
    set_number(get_declaration(str1), 0);
    for(auto argument : function_arguments) {
      if(argument.first <= get_declaration(str1) && get_declaration(str1) < argument.second) {
        add_machine_command("LOAD a");
        break;
      }
    }
    add_machine_command("LOAD a");
    add_machine_command("ADD b");
    add_machine_command(std::string("PUT ") + registerList[registerNum]);
  }
  else {
    set_number(get_declaration(str) + num, registerNum);
    for(auto argument : function_arguments) {
      if(argument.first <= get_declaration(str) && get_declaration(str) < argument.second) {
        add_machine_command(std::string("LOAD ") + registerList[registerNum]);
        add_machine_command(std::string("PUT ") + registerList[registerNum]);
        break;
      }
    }
  }
};

void Compiler::set_number(long long value, int r) {
  long long originalValue = value;
  std::vector<std::string> commandsToDo;
  bool decrement = false;
  bool isNewRegisterApplied = false;
  long long value_2_reg_1 = 1;
  long long value_2_reg_2 = 1;
  
  if(value == registers[r]) {
    return;
  }
  
  if(value == 0 && registers[r] != -1) {
    add_machine_command(std::string("RST ") + registerList[r]);
  }

  if(registers[r] == -1) {
    add_machine_command(std::string("RST ") + registerList[r]);
  } 

  if(registers[r] > value) {
    decrement = true;
  }

  if((value <= registers[r] - value) && decrement) {
    decrement = false;
    add_machine_command(std::string("RST ") + registerList[r]);
  }

  while(value > 0) {
    std::string command;
    if(value == registers[r]) {
      break;
    } 
    else if(value - registers[r] == -1 && registers[r] != -1) {
      command = std::string("DEC ") + registerList[r];
      commandsToDo.push_back(command);
      value++;
      break;
    } 
    else if(value - registers[r] == -2 && registers[r] != -1) {
      command = std::string("DEC ") + registerList[r];
      commandsToDo.push_back(command);
      commandsToDo.push_back(command);
      value += 2;
      break;
    } 
    else if(value - registers[r] == 1 && registers[r] != -1) {
      command = std::string("INC ") + registerList[r];
      commandsToDo.push_back(command);
      value--;
      break;
    } 
    else if(value - registers[r] == 2 && registers[r] != -1) {
      command = std::string("INC ") + registerList[r];
      commandsToDo.push_back(command);
      commandsToDo.push_back(command);
      value -= 2;
      break;
    }
    else if(value - registers[r] == 3 && registers[r] != -1) {
      command = std::string("INC ") + registerList[r];
      commandsToDo.push_back(command);
      commandsToDo.push_back(command);
      commandsToDo.push_back(command);
      value -= 3;
      break;
    }
    else if(value - registers[r] == -3 && registers[r] != -1) {
      command = std::string("DEC ") + registerList[r];
      commandsToDo.push_back(command);
      commandsToDo.push_back(command);
      commandsToDo.push_back(command);
      value += 3;
      break;
    }

    if(value_2_reg_1 * 2 < value && value > registers[r]) {
      if(registers[r] != 1) {
        commandsToDo.push_back(std::string("INC ") + registerList[r]);
      }
      while(value_2_reg_1 * 2 <= value) {
        command = std::string("SHL ") + registerList[r];
        commandsToDo.push_back(command);
        value_2_reg_1 *= 2; 
      }
      value -= value_2_reg_1;
    } 
    else if(value < registers[r]) {
      int tempRegisterValue = registers[r];

      while((tempRegisterValue / 2) >= value) {
        command = std::string("SHR ") + registerList[r];
        commandsToDo.push_back(command);
        tempRegisterValue /= 2;
      }
      registers[r] = tempRegisterValue;
    }

    if(registers[r] == value) {
      break;
    }

    if(value_2_reg_2 * 2 < value && !decrement && value > 4) { 
      isNewRegisterApplied = true;
      command = std::string("RST e");
      commandsToDo.push_back(command);
      command = std::string("INC e");
      commandsToDo.push_back(command);
      while(value_2_reg_2 * 2 <= value) {
        command = std::string("SHL e");
        commandsToDo.push_back(command);
        value_2_reg_2 *= 2; 
      }
      value -= value_2_reg_2;
    }

    if(decrement && (registers[r] - value) >= 4) {
      isNewRegisterApplied = true;
      command = std::string("RST e");
      commandsToDo.push_back(command);
      command = std::string("INC e");
      commandsToDo.push_back(command);
      while(value_2_reg_2 * 2 <= (registers[r] - value)) {
        command = std::string("SHL e");
        commandsToDo.push_back(command);
        value_2_reg_2 *= 2; 
      }
      registers[r] -= value_2_reg_2;
    }

    if((registerList[r] != 'a') && (value_2_reg_2 * 2 > value || value_2_reg_2 * 2 > (registers[r] - value))) {
      if(isNewRegisterApplied && !decrement) {
        commandsToDo.push_back("PUT g"); 
        commandsToDo.push_back("GET e"); 
        commandsToDo.push_back(std::string("ADD ") + registerList[r]);
        while(value > 0) {
          if(value == 1) {
            commandsToDo.push_back("INC a");
            break;
          }
          if(value <= 4) {
            for(size_t i = 1; i <= value; i++) {
              commandsToDo.push_back("INC a");
            }
            break;
          }
          long long tmp = 1;
          commandsToDo.push_back("RST f");
          commandsToDo.push_back("INC f");
          while(tmp * 2 <= value) {
            commandsToDo.push_back("SHL f");
            tmp *= 2;
          }
          commandsToDo.push_back("ADD f");
          value -= tmp;
        }
        commandsToDo.push_back(std::string("PUT ") + registerList[r]); 
        commandsToDo.push_back("GET g");
        break;
      } 
      else if(isNewRegisterApplied && decrement) {
        commandsToDo.push_back("PUT g");
        commandsToDo.push_back(std::string("GET ") + registerList[r]); 
        commandsToDo.push_back(std::string("SUB e")); 

        while((registers[r] - value) > 0) {
          if((registers[r] - value) == 1) {
            commandsToDo.push_back("DEC a");
            break;
          }
          if((registers[r] - value) <= 4) {
            for(size_t i = 1; i <= (registers[r] - value); i++) {
              commandsToDo.push_back("DEC a");
            }
            break;
          }
          long long tmp = 1;
          commandsToDo.push_back("RST f");
          commandsToDo.push_back("INC f");
          while(tmp * 2 <= (registers[r] - value)) {
            commandsToDo.push_back("SHL f");
            tmp *= 2;
          }
          commandsToDo.push_back("SUB f");
          registers[r] -= tmp;
        }

        commandsToDo.push_back(std::string("PUT ") + registerList[r]);
        commandsToDo.push_back("GET g");
        break;
      }
      else if(!isNewRegisterApplied && !decrement) {
        if(value <= 4) {
          for(size_t i = 1; i <= value; i++) {
            commandsToDo.push_back(std::string("INC ") + registerList[r]);
          }
          break;
        }
        commandsToDo.push_back("PUT g"); 
        commandsToDo.push_back(std::string("GET ") + registerList[r]); 

        while(value > 0) {
          if(value == 1) {
            commandsToDo.push_back("INC a");
            break;
          }
          if(value <= 4) {
            for(size_t i = 1; i <= value; i++) {
              commandsToDo.push_back("INC a");
            }
            break;
          }
          long long tmp = 1;
          commandsToDo.push_back("RST f");
          commandsToDo.push_back("INC f");
          while(tmp * 2 <= value) {
            commandsToDo.push_back("SHL f");
            tmp *= 2;
          }
          commandsToDo.push_back("ADD f");
          value -= tmp;
        }
        commandsToDo.push_back(std::string("PUT ") + registerList[r]);
        commandsToDo.push_back("GET g");
        break;
      }
      else if(!isNewRegisterApplied && decrement) {
        if((registers[r] - value) <= 4) {
          for(size_t i = 1; i <= (registers[r] - value); i++) {
            commandsToDo.push_back(std::string("DEC ") + registerList[r]);
          }
          break;
        }
        commandsToDo.push_back("PUT g"); 
        commandsToDo.push_back(std::string("GET ") + registerList[r]); 

        while((registers[r] - value) > 0) {
          if((registers[r] - value) == 1) {
            commandsToDo.push_back("DEC a");
            break;
          }
          if((registers[r] - value) <= 4) {
            for(size_t i = 1; i <= (registers[r] - value); i++) {
              commandsToDo.push_back("DEC a");
            }
            break;
          }
          long long tmp = 1;
          commandsToDo.push_back("RST f");
          commandsToDo.push_back("INC f");
          while(tmp * 2 <= (registers[r] - value)) {
            commandsToDo.push_back("SHL f");
            tmp *= 2;
          }
          commandsToDo.push_back("SUB f");
          registers[r] -= tmp;
        }
        commandsToDo.push_back(std::string("PUT ") + registerList[r]);
        commandsToDo.push_back("GET g");
        break;
      }
    }

    if((registerList[r] == 'a') && (value_2_reg_2 * 2 > value || value_2_reg_2 * 2 > (registers[r] - value))) {
      if(!decrement) {
        if(isNewRegisterApplied) {
          commandsToDo.push_back(std::string("ADD e")); 
        }
        while(value > 0) {
          if(value == 1) {
            commandsToDo.push_back("INC a");
            break;
          }
          if(value <= 4) {
            for(size_t i = 1; i <= value; i++) {
              commandsToDo.push_back("INC a");
            }
            break;
          }
          long long tmp = 1;
          commandsToDo.push_back("RST f");
          commandsToDo.push_back("INC f");
          while(tmp * 2 <= value) {
            commandsToDo.push_back("SHL f"); 
            tmp *= 2;
          }
          commandsToDo.push_back("ADD f");
          value -= tmp;
        }
        break;
      } 
      else {
        if(isNewRegisterApplied) {
          commandsToDo.push_back(std::string("SUB e")); 
        }
        while((registers[r] - value) > 0) {
          if(registers[r] - value == 1) {
            commandsToDo.push_back("DEC a");
            break;
          }
          if(registers[r] - value <= 4) {
            for(size_t i = 1; i <= registers[r] - value; i++) {
              commandsToDo.push_back("DEC a");
            }
            break;
          }
          long long tmp = 1;
          commandsToDo.push_back("RST f");
          commandsToDo.push_back("INC f");
          while(tmp * 2 <= registers[r] - value) {
            commandsToDo.push_back("SHL f");
            tmp *= 2;
          }
          commandsToDo.push_back("SUB f");
          registers[r] -= tmp;
        }
        break;
      }
    }
  }
  
  for(auto command : commandsToDo) {
    add_machine_command(command);
  }
}

void Compiler::add_machine_command(std::string wholeCommand) {
  int spaceIndex = wholeCommand.find(" ");
  std::string command = wholeCommand.substr(0, spaceIndex);
  std::string reg = wholeCommand.substr(spaceIndex + 1, wholeCommand.size());

  if(command == "READ") {
    registers[0] = -1;
  }
  else if(command == "LOAD") {
    registers[0] = -1;
  }
  else if(command == "ADD") {
    if(registers[0] == -1 || registers[registerList.find(reg)] == -1) {
      registers[0] = -1;
    } else {
      registers[0] += registers[registerList.find(reg)];
    }
  }
  else if(command == "SUB") {
    if(registers[0] == -1 || registers[registerList.find(reg)] == -1) {
      registers[0] = -1;
    } else {
      registers[0] -= registers[registerList.find(reg)];
      if(registers[0] < 0) {
        registers[0] = 0;
      }
    }
  }
  else if(command == "RST") {
    registers[registerList.find(reg)] = 0;
  }
  else if(command == "GET") {
    registers[0] = registers[registerList.find(reg)];
  }
  else if(command == "PUT") {
    registers[registerList.find(reg)] = registers[0]; 
  }
  else if(command == "INC") {
    registers[registerList.find(reg)] += 1;
  } 
  else if(command == "DEC") {
    registers[registerList.find(reg)] -= 1;
  }
  else if(command == "SHR") {
    if(registers[registerList.find(reg)] == -1) {
      registers[registerList.find(reg)] = -1;
    } else {
      registers[registerList.find(reg)] /= 2;
    }
  }
  else if(command == "SHL") {
    registers[registerList.find(reg)] *= 2;
  } 
  else if(command == "JPOS") {
    clear_register_value();
  } else if(command == "JUMP") {
    clear_register_value();
  } else if(command == "JZERO") {
    clear_register_value();
  } else if(command == "STRK") {
    registers[registerList.find(reg)] = getCommandsNumber();
  } else if(command == "JUMPR") {
    clear_register_value();
  }

  for(auto &i : registers) {
    if(i < -1) {
      i = -1;
    }
  }
  machineCommands.push_back(wholeCommand);
}

bool Compiler::checkLastCommand(std::string s) {
  return machineCommands[machineCommands.size() - 1] == s;
}

int Compiler::getCommandsNumber() {
  return machineCommands.size();
}

void Compiler::clear_register_value() {
  for(int i = 0; i < registers.size(); i++) {
    registers[i] = -1;
  }
}

void Compiler::change_command(std::string s, int i, int number) {
  if(machineCommands[i] == "JUMP " || machineCommands[i] == "JPOS " || machineCommands[i] == "JZERO " || machineCommands[i] == "JUMPR ") {
    machineCommands[i] += s;
    number--;
  }
  
  if(number == 0) {
    return;
  }

  for(int k = i; k >= 0; k--) {
    if((machineCommands[k] == "JZERO " || machineCommands[k] == "JPOS ") && number > 0) {
      machineCommands[k] += s;
      number--;
    }
    if(number == 0) {
      break;
    }
  }
}

std::vector<std::string> Compiler::getCommands() {
  return machineCommands;
}

void Compiler::set_variable_initialization(const char *variable) {
  for(auto &init : initializationList) {
    if(std::string(init.first) == variable) {
      init.second = true;
      break;
    }
  }
}

bool Compiler::check_var_initialization(const char *variable) {
  for(auto &it : initializationList) {
    if(std::string(it.first) == variable) {
      return it.second;
    }
  }
  return false;
}

void Compiler::check_declaration(long long num, const char *var, const char *T) {
  if(strcmp(T, "") == 0) { // case single variable(x) and T[10]
    if(get_declaration(var) == -1) {
      // return yyerror((std::string("Uzycie niezadeklarowanej zmiennej ") + var).c_str());
    }
  } else { // T[a]
    int tab_declaration = get_declaration(T);
    if(tab_declaration == -1) {
      return;
      // return yyerror((std::string("Uzycie niezadeklarowanej zmiennej ") + T).c_str());
    }
    int tab_index_declaration = get_declaration(var);
    if(tab_index_declaration == -1) {
      return;
      // return yyerror((std::string("Uzycie niezadeklarowanej zmiennej ") + var).c_str());
    }
  }
}

std::string Compiler::check_var_declaration(const char *var, bool isTab) {
  if(!isTab) { // normal variable
    if(get_declaration(var) == -1) {
      return "ERR";
    }
    return "";
  } else {
    if(get_declaration(var) == -1) {
      return "ERR";
    }
    return "";
  }
}

void Compiler::clearCommands() {
  machineCommands.clear();
}

int Compiler::getProcedureIndex(const char *s) {
  int res = -1;
  for(auto i : procedures) {
    if(strcmp(i.first, s) == 0) {
      res = i.second[procedure_index].first;
      procedure_index++;
      if(procedure_index == i.second.size()) {
        procedure_index = 0;
      }
      break;
    }
  }
  return res;
}

bool Compiler::isAnArray(const char *s) {
  for(const auto& variable : variables) {
    if(strcmp(variable.first, s) == 0) {
      return variable.second;
    }
  }
  return false;
}

void Compiler::add_procedure(const char *s) {
  std::vector<std::pair<int, bool>> index;
  for(int i = 0; i < declarationList.size(); ++i) {
    std::cout << declarationList[i].second << " yyy" << std::endl;
    index.push_back(std::make_pair(declarationList[i].second, procedure_args[i]));
  }
  procedure_args.clear();
  procedures.push_back(std::make_pair(s, index));
}

std::vector<std::pair<int, bool>> Compiler::get_procedure_args(const char *s) {
  for(auto it : procedures) {
    if(strcmp(it.first, s) == 0) {
      return it.second;
    }
  }
  return std::vector<std::pair<int, bool>>();
}

void Compiler::add_beginning_procedure(const char *s, int i) {
  beginning_procedure.push_back(std::make_pair(s, i));
}

int Compiler::get_beginning_procedure(const char *s) {
  for(auto& entry : beginning_procedure) {
    if(strcmp(entry.first, s) == 0) {
      return entry.second;
    }
  }
  yyerror((std::string("Undefined procedure ") + s).c_str());
  return -1;
}

int Compiler::get_beginning_next_procedure(const char *s) {
  auto it = std::find_if(beginning_procedure.begin(), beginning_procedure.end(), [s](const auto &entry) {
    return strcmp(entry.first, s) == 0; });
  if(it != beginning_procedure.end() && std::next(it) != beginning_procedure.end()) {
    return std::next(it)->second;
  }
  return -1;
}

int Compiler::size_args_procedure(const char *s) {
  for(const auto& entry : procedures) {
    if(strcmp(entry.first, s) == 0) {
      return entry.second.size();
    }
  }
  return -1;
}

void Compiler::addCommandInside(const std::string s, int i) {
  for(auto &command : machineCommands) {
    if((command.substr(0, 4) == "JUMP" || command.substr(0, 4) == "JPOS") && command.size() > 5) {
      int liczba;
      std::istringstream(command.substr(5)) >> liczba;

      if(liczba > i + 1) {
        command = command.substr(0, 5) + std::to_string(liczba + 1);
      }
    } 
    else if(command.substr(0, 5) == "JZERO" && command.size() > 6) {
      int liczba;
      std::istringstream(command.substr(6)) >> liczba;
      if(liczba > i + 1) {
        command = command.substr(0, 6) + std::to_string(liczba + 1);
      }
    }
  }
  auto iterator = machineCommands.begin() + i; 
  machineCommands.insert(iterator, s);
}


