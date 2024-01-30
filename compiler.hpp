#ifndef COMPILER_HPP
#define COMPILER_HPP

#include<string>
#include<vector>
#include<utility>

// #include<string>
// #include<vector>
// #include<cstring>

class Compiler {
  private:
    int memoryCell;
    int procedure_index = 0;
    std::vector<std::pair<const char *, int>> declarationList;
    std::vector<std::pair<const char *, bool>> initializationList;
    std::vector<std::string> machineCommands;
    std::vector<std::pair<const char *, std::vector<std::pair<int, bool>>>> procedures;
    std::vector<std::pair<const char *, int>> beginning_procedure;

  public:
    std::vector<int> registers = { -1, -1, -1, -1, -1, -1, -1, -1 };
    std::vector<bool> storageRegisters = { false, false, false, false, false, false, false, false };
    std::string registerList = "abcdefgh";
    std::vector<const char *> arguments;
    std::vector<std::pair<const char*, bool>> variables;
    std::vector<std::pair<int, int>> function_arguments;
    std::vector<bool> procedure_args;

    void add_declaration(const char *s, int size);
    int get_declaration(const char *s);
    int get_next_declaration(const char *s);
    int get_first_declaration();
    void check_declaration(long long num, const char *var, const char *T);
    std::string check_var_declaration(const char *var, bool isTab);
    void clear_declaration();
    void set_variable_initialization(const char *var);

    void set_number(long long value, int r);
    void add_machine_command(std::string s);
    void change_command(std::string s, int i, int number);
    void get_register_value(int num, const char *str, const char *str1, int registerNum);
    void clear_register_value();
    void addCommandInside(const std::string s, int position);

    int getCommandsNumber();
    std::vector<std::string> getCommands();
    void clearCommands();
  
    bool check_var_initialization(const char *variable);
    bool isAnArray(const char *s);

    void add_procedure(const char *s);
    std::vector<std::pair<int, bool>> get_procedure_args(const char *s);
    bool check_procedure_params(const char *s);
    int getProcedureIndex(const char *s);
    void add_beginning_procedure(const char *s, int i);
    int get_beginning_procedure(const char *s);
    int get_beginning_next_procedure(const char *s); 
    int size_args_procedure(const char *s);
    bool checkLastCommand(std::string s);
};  


#endif
