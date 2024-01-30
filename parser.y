%{
  #include <iostream>
  #include <fstream>
  #include <vector>
  #include <string>
  #include <cstdio>
  #include <cstring>
  #include "assembler_generator.hpp"
  #include "conditioner.hpp"

  extern int yylex();
  extern int yyparse();
  void yyerror(const char* const message);

  extern FILE *yyin;
  extern int yylineno;
  
  Compiler compiler;
  AssemblerGenerator asmGenerator(&compiler);
  Conditioner conditioner(&compiler);
%}

%code requires {

  struct Value {
    long long num;
    char *str;
    char *str1;
    bool isArray;
  };

}

%union {
  Value value;
  char *str;
  long long num;
}

%token T_PROGRAM T_IS T_IN T_END
%token T_PROCEDURE
%token T_SEMICOLON T_COMMA
%token T_EQ T_NEQ T_LT T_GT T_LTEQ T_GTEQ
%token T_ADD T_SUB T_DIV T_MOD T_MUL
%token T_ASSIGN

%token T_READ T_WRITE
%token T_REPEAT T_UNTIL
%token T_WHILE T_DO T_ENDWHILE
%token T_IF T_THEN T_ELSE T_ENDIF
%token T_LEFTPARENTHESIS T_RIGHTPARENTHESIS
%token T_LEFT_BRACKET T_RIGHT_BRACKET
%token T_ERROR
%token T
%token <str> T_IDENTIFIER
%token <num> T_NUM

%start program_all

%type <num> condition
%type <num> commands
%type <num> command
%type <num> start

%type <value> identifier
%type <value> value
%type <value> expression


%%

program_all:
      procedures start_main main {
        compiler.add_machine_command("HALT");
      }
;

start_main:
  {
    compiler.add_beginning_procedure("", compiler.getCommandsNumber());
    if(compiler.getCommandsNumber() == 1) {
      compiler.clearCommands();
    } else {
      // std::cout << " Change command " << compiler.getCommandsNumber() << " " << std::endl;
      compiler.change_command(std::to_string(compiler.getCommandsNumber()), 0, 1); // Add jump to the block PROGRAM IS
    }
  }

procedures:
      procedures T_PROCEDURE proc_head T_IS declarations T_IN commands T_END {
        std::cout << "Procedure decl RETURN " << compiler.get_declaration(" RETURN") << std::endl;
        compiler.set_number(compiler.get_declaration(" RETURN"), 1); // r_b <- r_a
        compiler.add_machine_command("LOAD b"); // r_a <- p_rb
        compiler.clear_declaration();
        compiler.add_machine_command("JUMPR a"); // k <- r_a
        compiler.clear_register_value();
      }
      | procedures T_PROCEDURE proc_head T_IS T_IN commands T_END {
        compiler.set_number(compiler.get_declaration(" RETURN"), 1);
        compiler.add_machine_command("LOAD b");
        compiler.clear_declaration();
        compiler.add_machine_command("JUMPR a");
        compiler.clear_register_value();
      }
      | {
        compiler.add_machine_command("JUMP ");
      }
;

main:
    T_PROGRAM T_IS declarations T_IN commands T_END {
      // Finish compilation
    }
    | T_PROGRAM T_IS T_IN commands T_END {
      // Finish compilation
    }
;

commands: 
      commands command    {
        if($1 > $2) {
          $$ = $1;
        } else {
          $$ = $2;
        }
      }
      | command {
        $$ = $1;
      }
;

command:
      identifier T_ASSIGN expression T_SEMICOLON {
        if(compiler.isAnArray($1.str)) {
          if(!$1.isArray) { // single arr variable c(not valid)
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Niewłaściwe użycie tablicy " + $1.str).c_str());
          }
        }
        bool whether = false;
        for(auto i : compiler.function_arguments) {
          if((i.first <= compiler.get_declaration($1.str) && compiler.get_declaration($1.str) < i.second) || (i.first <= compiler.get_declaration($1.str1) && compiler.get_declaration($1.str1) < i.second)) {
            compiler.add_machine_command("PUT h");
            whether = true;
            break;
          }
        }

        if(whether == false && $1.num == -1) { // case T[a] := ...
          compiler.add_machine_command("PUT h");
          whether = true;
        }

        compiler.check_declaration($1.num, $1.str, $1.str1); // check if variable was declared
        compiler.get_register_value($1.num, $1.str, $1.str1, 1);

        if(whether) {
          compiler.add_machine_command("PUT b");
          compiler.add_machine_command("GET h"); 
        }
        compiler.add_machine_command("STORE b");
        compiler.add_machine_command("RST b");
        compiler.add_machine_command("RST a");
        compiler.set_variable_initialization($1.str);
        $$ = compiler.getCommandsNumber();
      }
      | start T_IF condition T_THEN commands start T_ELSE commands T_ENDIF {
        std::cout << $5 << ", if scope" << std::endl;
        std::cout << $3  << ", cond scope " << std::endl;
        std::cout << $8 << ", else scope" << std::endl;
        compiler.change_command(std::to_string($5 + 1), $3, 1); // albo $3 -1
        compiler.add_commands_inside("JUMP " + std::to_string($8 + 1), $5); // method which adds jump when the if ends so that else block will not be completedx
        $$ = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
      | start T_IF condition T_THEN commands T_ENDIF { 
        // $5 is the number of line where the scope of this if ends, $3 is the number of line where the condition of if ends
        std::cout << $5 << ", ifik" << std::endl;
        std::cout << $3 << ", cond" << std::endl;
        compiler.change_command(std::to_string($5), $3 - 1, 1); // -1 because of index, last command of condition is always a jump
        $$ = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
      | start T_WHILE condition T_DO commands T_ENDWHILE {
        std::cout << $3 << ", cond while" << std::endl;
        // $3 to koniec warunku condition, $1 to numer linii od ktorej zaczyna sie petla while
        compiler.change_command(std::to_string(compiler.getCommandsNumber() + 1), $3, 1); // dodanie wartosci jumpa w przypadku niespelnienia condition
        compiler.add_machine_command("JUMP " + std::to_string($1)); // dodanie jumpa do startu pętli
        $$ = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
      | start T_REPEAT commands T_UNTIL condition T_SEMICOLON {
        std::cout << $1 << ", " << $5 << ", " << std::endl;
        compiler.change_command(std::to_string($1), $5 - 1, 1); // Jump to the start of repeat loop after condition is checked
        $$ = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
      | proc_call T_SEMICOLON {
        $$ = compiler.getCommandsNumber();
      }
      | T_READ identifier T_SEMICOLON {
        if(compiler.isAnArray($2.str)) {
          if(!$2.isArray) { // single arr variable c(not valid)
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Niewłaściwe użycie tablicy " + $2.str).c_str());
          }
        }
        compiler.add_machine_command("READ");
        compiler.get_register_value($2.num, $2.str, $2.str1, 1);
        compiler.add_machine_command("STORE b"); // p_rb <- ra
        compiler.set_variable_initialization($2.str);
        $$ = compiler.getCommandsNumber();
      }
      | T_WRITE value T_SEMICOLON {
        if(strcmp($2.str, "") == 0) {
          compiler.set_number($2.num, 0);
        } else {
          compiler.get_register_value($2.num, $2.str, $2.str1, 1);
          if(!compiler.checkLastCommand("STORE b")) {
            if(compiler.checkLastCommand("LOAD b")) {
              compiler.add_machine_command("LOAD a");
            } else {
              compiler.add_machine_command("LOAD b");
            }
          }
        }
        compiler.add_machine_command("WRITE");
        $$ = compiler.getCommandsNumber();
      }
;

start:
    {
      $$ = compiler.getCommandsNumber();
      compiler.clear_register_value();
    }
;

proc_head:
      T_IDENTIFIER T_LEFTPARENTHESIS args_decl T_RIGHTPARENTHESIS {
        std::cout << "Procedure name: " << $1 << std::endl;
        compiler.add_beginning_procedure($1, compiler.getCommandsNumber());
        compiler.add_declaration(" RETURN", 1);
        compiler.add_procedure($1);
        int min = compiler.get_first_declaration();
        int max = compiler.get_declaration(" RETURN"); // zakres komorek pamieci ktore sa zarezerwowane dla procedury
        std::cout << "func args " << min << ", " << max << std::endl;
        compiler.function_arguments.push_back(std::make_pair(min, max)); // zakres argumentów procedury
      }
;

proc_call:
      T_IDENTIFIER T_LEFTPARENTHESIS args T_RIGHTPARENTHESIS {
        if(compiler.size_args_procedure($1) == -1) {
          yyerror((std::string("Line ") + std::to_string(yylineno) + ": Niezdefiniowana procedura " + $1).c_str());
        }
        if(compiler.getCommandsNumber() < compiler.get_beginning_next_procedure($1) || compiler.get_beginning_next_procedure($1) == -1) {
          yyerror((std::string("Line ") + std::to_string(yylineno) + ": Niewłaściwe użycie procedury " + $1).c_str());
        }
        std::vector<std::pair<int, bool>> args = compiler.get_procedure_args($1);
        for(size_t i = 0; i < compiler.arguments.size(); ++i) { // procedure call arg. size
          compiler.set_variable_initialization(compiler.arguments[i]);
          std::cout << "Param to procedure " << compiler.arguments[i] << std::endl;
          if(args[i].second) { // procedure param is an array
            if(!compiler.isAnArray(compiler.arguments[i])) {
              yyerror((std::string("Line ") + std::to_string(yylineno) + ": Niewłaściwe parametry procedury " + $1).c_str());
            }
          }
          compiler.get_register_value(0, compiler.arguments[i], nullptr, 0);
          compiler.add_machine_command("RST b");
          compiler.set_number(compiler.getIndex($1), 1); 
          compiler.add_machine_command("STORE b"); 
          compiler.add_machine_command("RST a");
        }

        compiler.set_number(compiler.getIndex($1), 1); // set return()
        compiler.add_machine_command("RST a");
        compiler.add_machine_command("INC a");
        compiler.add_machine_command("SHL a");
        compiler.add_machine_command("SHL a");
        compiler.add_machine_command("STRK c"); // r_c <- k(command Number)
        compiler.add_machine_command("ADD c"); // r_a + r_c
        compiler.add_machine_command("STORE b"); // p_rb <- r_a(zapisanie do returna adresu powrotu z procedury)
        compiler.add_machine_command("JUMP " + std::to_string(compiler.get_beginning_procedure($1))); // jump to the line in which procedure starts
        compiler.arguments.clear();
      }
;

declarations:
      declarations T_COMMA T_IDENTIFIER {
        if(compiler.get_declaration($3) != -1) {
          yyerror((std::string("Line ") + std::to_string(yylineno - 2) + ": Powtórne użycie identyfikatora " + $3).c_str());
        }
        compiler.variables.push_back(std::make_pair($3, false));
        compiler.add_declaration($3, 1); // memory Cell to 1
      }
      | declarations T_COMMA T_IDENTIFIER T_LEFT_BRACKET T_NUM T_RIGHT_BRACKET {
        if(compiler.get_declaration($3) != -1) {
          yyerror((std::string("Line ") + std::to_string(yylineno - 2) + ": Powtórne użycie identyfikatora " + $3).c_str());
        }
        compiler.variables.push_back(std::make_pair($3, true));
        compiler.add_declaration($3, $5);
      }
      | T_IDENTIFIER {
        if(compiler.get_declaration($1) != -1) {
          yyerror((std::string("Line ") + std::to_string(yylineno - 2) + ": Powtórne użycie identyfikatora " + $1).c_str());
        }
        compiler.variables.push_back(std::make_pair($1, false));
        compiler.add_declaration($1, 1);
      }
      | T_IDENTIFIER T_LEFT_BRACKET T_NUM T_RIGHT_BRACKET { // sito[100]
        if(compiler.get_declaration($1) != -1) {
          yyerror((std::string("Line ") + std::to_string(yylineno - 2) + ": Powtórne użycie identyfikatora " + $1).c_str());
        }
        compiler.variables.push_back(std::make_pair($1, true));
        compiler.add_declaration($1, $3);
      }
;

args_decl:
      args_decl T_COMMA T_IDENTIFIER {
        // parametry definiowane w deklaracji procedury proc_name(a, b, c)
        compiler.procedure_args.push_back(false);
        compiler.add_declaration($3, 1);
        compiler.set_variable_initialization($3);
      }
      | args_decl T_COMMA T T_IDENTIFIER { // args_decl, T x
        compiler.procedure_args.push_back(true);
        compiler.add_declaration($4, 1);
        compiler.set_variable_initialization($4);
      }
      | T_IDENTIFIER { // variable
        compiler.procedure_args.push_back(false);
        compiler.add_declaration($1, 1);
        compiler.set_variable_initialization($1);
      }
      | T T_IDENTIFIER { // T a
        compiler.procedure_args.push_back(true);
        compiler.add_declaration($2, 1);
        compiler.set_variable_initialization($2);
      }
;

args:
    args T_COMMA T_IDENTIFIER {
      // procedure call gcd(a, b, c)
      compiler.arguments.push_back($3);
    }
    | T_IDENTIFIER {
      compiler.arguments.push_back($1);
    }
;

expression:
      value {
        if(strcmp($1.str, "") != 0 && strcmp($1.str1, "") == 0) {
          if(!compiler.check_var_initialization($1.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str).c_str());
          }
        }
        else if($1.num == -1) {
          if(!compiler.check_var_initialization($1.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str1).c_str());
          }
        }
        asmGenerator.get_number($1.num, $1.str, $1.str1);
      }
      | value T_ADD value {
        if(strcmp($1.str, "") != 0 && strcmp($1.str1, "") == 0) { // variable, x[2]
          if(!compiler.check_var_initialization($1.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str).c_str());
          }
        } 
        else if($1.num == -1) {
          if(!compiler.check_var_initialization($1.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str1).c_str());
          }
        }
        if(strcmp($3.str, "") != 0 && strcmp($3.str1, "") == 0) {
          if(!compiler.check_var_initialization($3.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str).c_str());
          }
        }
        else if($3.num == -1) {
          if(!compiler.check_var_initialization($3.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str1).c_str());
          }
        }
        asmGenerator.add($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
      }
      | value T_SUB value {
        if(strcmp($1.str, "") != 0 && strcmp($1.str1, "") == 0) { // variable, x[2]
          if(!compiler.check_var_initialization($1.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str).c_str());
          }
        } 
        else if($1.num == -1) {
          if(!compiler.check_var_initialization($1.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str1).c_str());
          }
        }
        if(strcmp($3.str, "") != 0 && strcmp($3.str1, "") == 0) {
          if(!compiler.check_var_initialization($3.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str).c_str());
          }
        }
        else if($3.num == -1) {
          if(!compiler.check_var_initialization($3.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str1).c_str());
          }
        }
        asmGenerator.subtract($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
      }
      | value T_MUL value {
        if(strcmp($1.str, "") != 0 && strcmp($1.str1, "") == 0) { // variable, x[2]
          if(!compiler.check_var_initialization($1.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str).c_str());
          }
        }
        else if($1.num == -1) {
          if(!compiler.check_var_initialization($1.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str1).c_str());
          }
        }
        if(strcmp($3.str, "") != 0 && strcmp($3.str1, "") == 0) {
          if(!compiler.check_var_initialization($3.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str).c_str());
          }
        }
        else if($3.num == -1) {
          if(!compiler.check_var_initialization($3.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str1).c_str());
          }
        }
        asmGenerator.multiply($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
      }
      | value T_DIV value {
        if(strcmp($1.str, "") != 0 && strcmp($1.str1, "") == 0) { // variable, x[2]
          if(!compiler.check_var_initialization($1.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str).c_str());
          }
        }
        else if($1.num == -1) {
          if(!compiler.check_var_initialization($1.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str1).c_str());
          }
        }
        if(strcmp($3.str, "") != 0 && strcmp($3.str1, "") == 0) {
          if(!compiler.check_var_initialization($3.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str).c_str());
          }
        }
        else if($3.num == -1) {
          if(!compiler.check_var_initialization($3.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str1).c_str());
          }
        }
        asmGenerator.divide($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
      }
      | value T_MOD value {
        if(strcmp($1.str, "") != 0 && strcmp($1.str1, "") == 0) { // variable, x[2]
          if(!compiler.check_var_initialization($1.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str).c_str());
          }
        }
        else if($1.num == -1) {
          if(!compiler.check_var_initialization($1.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $1.str1).c_str());
          }
        }
        if(strcmp($3.str, "") != 0 && strcmp($3.str1, "") == 0) {
          if(!compiler.check_var_initialization($3.str)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str).c_str());
          }
        }
        else if($3.num == -1) {
          if(!compiler.check_var_initialization($3.str1)) {
            yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3.str1).c_str());
          }
        }
        asmGenerator.modulo($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
      }
;

condition:
      value T_EQ value {
        conditioner.equal($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
        $$ = compiler.getCommandsNumber();
      }
      | value T_NEQ value {
        conditioner.not_equal($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
        $$ = compiler.getCommandsNumber();
      }
      | value T_GT value {
        conditioner.greater($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
        $$ = compiler.getCommandsNumber();
      }
      | value T_LT value {
        conditioner.less($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
        $$ = compiler.getCommandsNumber();
      }
      | value T_GTEQ value {
        conditioner.greater_equal($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
        $$ = compiler.getCommandsNumber();
      }
      | value T_LTEQ value {
        conditioner.less_equal($1.num, $1.str, $1.str1, $3.num, $3.str, $3.str1);
        $$ = compiler.getCommandsNumber();
      }
;

value:
    T_NUM {
      $$.num = $1;
      $$.str = new char[1];
      $$.str1 = new char[1];
      $$.str[0] = '\0';
      $$.str1[0] = '\0';
      $$.isArray = false;
    }
    | identifier {
      $$.num = $1.num;
      $$.str = $1.str;
      $$.str1 = $1.str1;
      $$.isArray = $1.isArray;
    }
;

identifier:
      T_IDENTIFIER {
        std::string check = compiler.check_var_declaration($1, false);
        if(check != "") {
          yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezadeklarowanej zmiennej " + $1).c_str());
        }
        compiler.variables.push_back(std::make_pair($1, false));
        $$.num = 0;
        $$.str = $1; // nazwa zmiennej
        $$.str1 = new char[1];
        $$.str1[0] = '\0';
        $$.isArray = false;
      }
      | T_IDENTIFIER T_LEFT_BRACKET T_NUM T_RIGHT_BRACKET { // sito[10]
        std::string check = compiler.check_var_declaration($1, true);
        if(check != "") {
          yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezadeklarowanej zmiennej " + $1).c_str());
        }
        compiler.variables.push_back(std::make_pair($1, true));
        $$.num = $3; // numer indeksu w tablicy
        $$.str = $1; // nazwa tablicy(zmiennej)
        $$.str1 = new char[1];
        $$.str1[0] = '\0';
        $$.isArray = true;
      }
      | T_IDENTIFIER T_LEFT_BRACKET T_IDENTIFIER T_RIGHT_BRACKET { // sito[a]
        std::string check = compiler.check_var_declaration($1, true); // sprawdzenie deklaracji tablicy
        if(check != "") {
          yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezadeklarowanej zmiennej " + $1).c_str());
        }
        if(!compiler.check_var_initialization($3)) {
          yyerror((std::string("Line ") + std::to_string(yylineno) + ": Uzycie niezainicjowanej zmiennej " + $3).c_str());
        }
        compiler.variables.push_back(std::make_pair($1, true));
        $$.num = -1; // -1 bo indeks nie jest cyfra tylko zmienna
        $$.str = $1;
        $$.str1 = $3; // indeks w tablicy to zmienna
        $$.isArray = true;
      }
;

%%

void yyerror(const char* const message) {
  std::cout << "Error: " <<  message << std::endl;
  exit(1);
}

int execute(const char* input_file, const char* output_file) {
  // kompilator <nazwa input file> <nazwa_output_file>
  yyin = fopen(input_file, "r");

  std::ofstream outputStream;
  outputStream.open(output_file);

  yyparse();

  for(const auto &code : compiler.getCommands()) {
    outputStream << code << std::endl;
  }

  fclose(yyin);

  return 0;
}