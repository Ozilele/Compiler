
#include "compiler.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

extern void yyerror(const char *s);

void Compiler::add_declaration(const char *s, int size) {
  int isVariableAlreadyDeclared = get_declaration(s);
  if(isVariableAlreadyDeclared != -1) {
    return yyerror((std::string("Druga deklaracja zmiennej ") + s).c_str());
  }
  std::cout << s << ", " << memoryCell << std::endl;
  declarationList.push_back(std::make_pair(s, memoryCell));
  initializationList.push_back(std::make_pair(s, false)); // zmienna zadeklarowana ale nie zainicjowana jeszcze
  memoryCell += size;
};

int Compiler::get_declaration(const char *s) { // Zwraca komorkę pamięci(p_i) gdzie zostala zadeklarowana zmienna, jezeli -1 to znaczy ze nie bylo deklaracji zmiennej - error
  for(const auto i : declarationList) {
    if(strcmp(i.first, s) == 0) {
      return i.second;
    }
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
  if(num == -1) { // case when access T[a]
    std::cout << str << ", " << str1 << std::endl;
    set_number(get_declaration(str), 1);
    for(auto arg : function_arguments) {
      if(arg.first <= get_declaration(str) && get_declaration(str) < arg.second) {
        add_machine_command("LOAD b");
        add_machine_command("PUT b");
        break;
      }
    }
    set_number(get_declaration(str1), 0);
    for(auto arg : function_arguments) {
      if(arg.first <= get_declaration(str1) && get_declaration(str1) < arg.second) {
        add_machine_command("LOAD a");
        break;
      }
    }
    add_machine_command("LOAD a");
    add_machine_command("ADD b");
    add_machine_command(std::string("PUT ") + registerList[registerNum]);
  }
  else { // case when access variable a,x or T[2] itd.
    // std::cout << get_declaration(str) << " xxzaza" << std::endl;
    set_number(get_declaration(str) + num, registerNum);
    for(auto arg : function_arguments) {
      if(arg.first <= get_declaration(str) && get_declaration(str) < arg.second) {
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
  
  std::cout << "Value to " << value << ", " << registers[r] << std::endl;

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
      registers[r] = tempRegisterValue; // new value of register
    }

    if(registers[r] == value) {
      break;
    }
    // if(value == 0) {
    //   break;
    // }

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
        commandsToDo.push_back("PUT g"); // r_g <- r_a
        commandsToDo.push_back("GET e"); // r_a <- r_e
        commandsToDo.push_back(std::string("ADD ") + registerList[r]); // r_a <- r_a + registerList[r]

        while(value > 0) {
          if(value == 1) { // Warunek stopu while
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
            commandsToDo.push_back("SHL f"); // r_f <- 2 * r_f
            tmp *= 2;
          }
          commandsToDo.push_back("ADD f");
          value -= tmp;
        }
        commandsToDo.push_back(std::string("PUT ") + registerList[r]); // r_b <- r_a
        commandsToDo.push_back("GET g"); // r_a <- r_g(saved value)
        break;
      } 
      else if(isNewRegisterApplied && decrement) {
        commandsToDo.push_back("PUT g");
        commandsToDo.push_back(std::string("GET ") + registerList[r]); 
        commandsToDo.push_back(std::string("SUB e")); 

        while((registers[r] - value) > 0) {
          if((registers[r] - value) == 1) { // Warunek stopu while
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
            commandsToDo.push_back("SHL f"); // r_f <- 2 * r_f
            tmp *= 2;
          }
          commandsToDo.push_back("SUB f");
          registers[r] -= tmp;
        }

        commandsToDo.push_back(std::string("PUT ") + registerList[r]); // r_b <- r_a
        commandsToDo.push_back("GET g"); // r_a <- r_g(saved value)
        break;
      }
      else if(!isNewRegisterApplied && !decrement) { // new register e not applied
        commandsToDo.push_back("PUT g"); // r_g <- r_a
        commandsToDo.push_back(std::string("GET ") + registerList[r]); // r_a <- r_b

        while(value > 0) {
          if(value == 1) { // Warunek stopu while
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
            commandsToDo.push_back("SHL f"); // r_f <- 2 * r_f
            tmp *= 2;
          }
          commandsToDo.push_back("ADD f"); // r_a += r_f
          value -= tmp;
        }
        commandsToDo.push_back(std::string("PUT ") + registerList[r]); // r_b <- r_a
        commandsToDo.push_back("GET g"); // r_a <- r_g
        break;
      }
      else if(!isNewRegisterApplied && decrement) {
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
            commandsToDo.push_back("SHL f"); // r_f <- 2 * r_f
            tmp *= 2;
          }
          commandsToDo.push_back("SUB f");
          registers[r] -= tmp;
        }
        break;
      }
    }
  }
  
  std::cout << " Wyjście z pętli while " << std::endl;
  for(auto command : commandsToDo) {
    add_machine_command(command);
  }
}

void Compiler::add_machine_command(std::string wholeCommand) { // Command like LOAD b, STORE b
  int spaceIndex = wholeCommand.find(" ");
  std::string command = wholeCommand.substr(0, spaceIndex);
  std::string reg = wholeCommand.substr(spaceIndex + 1, wholeCommand.size());

  if(command == "READ") {
    registers[0] = -1;
  } else if(command == "WRITE") {

  } else if(command == "STORE") {

  } else if(command == "LOAD") {
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
  else if(command == "GET") {
    registers[0] = registers[registerList.find(reg)];
  }
  else if(command == "PUT") {
    registers[registerList.find(reg)] = registers[0]; 
  }
  else if(command == "RST") {
    registers[registerList.find(reg)] = 0;
  }
  else if(command == "INC") {
    registers[registerList.find(reg)] += 1;
  } 
  else if(command == "DEC") {
    registers[registerList.find(reg)] -= 1;
  }
  else if(command == "SHL") { // 2*
    registers[registerList.find(reg)] *= 2;
  } 
  else if(command == "SHR") { // /2
    if(registers[registerList.find(reg)] == -1) {
      registers[registerList.find(reg)] = -1;
    } else {
      registers[registerList.find(reg)] /= 2;
    }
  } else if(command == "JPOS") {
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
  else if(command == "HALT") {
    // Zakończenie programu
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

// 22, 9, 1 // 128, 37, 1, (151, 0, 1)
void Compiler::change_command(std::string s, int i, int number) {
  if(machineCommands[i] == "JUMP " || machineCommands[i] == "JPOS " || machineCommands[i] == "JZERO " || machineCommands[i] == "JUMPR ") {
    machineCommands[i] += s; // dodanie miejsca skoku, np. JPOS 14
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

void Compiler::check_declaration(long long num, const char *var, const char *T) {
  if(strcmp(T, "") == 0) { // case single variable(x) and T[10]
    int var_declaration = get_declaration(var);
    if(var_declaration == -1) {
      return yyerror((std::string("Uzycie niezadeklarowanej zmiennej ") + var).c_str());
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
      return "Błąd: uzycie niezadeklarowanej zmiennej";
      // return (std::to_string("Błąd: uzycie niezadeklarowanej zmiennej ") + var).c_str();
    }
    return "";
  } else {
    if(get_declaration(var) == -1) {
      return "";
      // return "Błąd: uzycie niezadeklarowanej tablicy";
      // return (std::to_string("Błąd: uzycie niezadeklarowanej tablicy ") + var).c_str();
    }
    return "";
  }
}

void Compiler::check_var_initialization(long long num, const char *var, const char *T) {

}

void Compiler::clearCommands() {
  machineCommands.clear();
}

int Compiler::getIndex(const char *s) {
  int res = -1;
  for(auto i : procedures) {
    if(strcmp(i.first, s) == 0) {
      res = i.second[procedure_index].first; // 
      std::cout << "Index of var " << s << " to " << res << std::endl;
      procedure_index++;
      if(procedure_index == i.second.size()) {
        procedure_index = 0;
      }
      break;
    }
  }
  return res;
}

void Compiler::add_procedure(const char *s) {
  std::vector<std::pair<int, bool>> index;
  for(int i = 0; i < declarationList.size(); ++i) {
    std::cout << declarationList[i].second << " yyy" << std::endl;
    index.push_back(std::make_pair(declarationList[i].second, procedure_args[i])); // dodanie adresu w pamięci do vectora oraz tego czy zadeklarowana zmienna jest tablicą, czy nie 
  }
  procedure_args.clear();
  procedures.push_back(std::make_pair(s, index)); // dodanie do listy procedur nazwy procedury oraz informacji o parametrach procedury(isTab, komórka pamięci)
}

std::vector<std::pair<int, bool>> Compiler::get_procedure_args(const char *s) {
  for(auto i : procedures) {
    if(strcmp(i.first, s) == 0) {
      return i.second;
    }
  }
  yyerror((std::string("Undefined procedure ") + s).c_str());
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

int Compiler::get_beginning_next_procedure(const char *s) { // poczatek kolejnej procedury
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
  yyerror((std::string("Undefined procedure ") + s).c_str());
  return -1;
}

bool Compiler::is_Tab(const char *s) {
  std::cout << " ssik " << s << std::endl;
  size_t len = strlen(s);
  std::cout << len << " len" << std::endl;
  if(len > 2 && s[len - 2] == '[' && s[len - 1] == ']') { // Ostatnie dwa znaki to nawiasy kwadratowe, co sugeruje tablicę.
    return true;
  }
  return false;
}

// JUMP 32, 24
void Compiler::add_commands_inside(const std::string s, int i) {
  for(auto &command : machineCommands) { // Aktualizacja wartosci skoków
    if((command.substr(0, 4) == "JUMP" || command.substr(0, 4) == "JPOS") && command.size() > 5) {
      int liczba;
      std::istringstream(command.substr(5)) >> liczba;

      if(liczba > i + 1) {
        command = command.substr(0, 5) + std::to_string(liczba + 1);
      }
    } 
    else if(command.substr(0, 5) == "JZERO" && command.size() > 6) { // 
      int liczba;
      std::istringstream(command.substr(6)) >> liczba;
      if(liczba > i + 1) { // 25 > 24 + 1
        command = command.substr(0, 6) + std::to_string(liczba + 1);
      }
    }
  }
  auto it = machineCommands.begin() + i; 
  machineCommands.insert(it, s); // insert new command at position
}


