#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include<string>

class Assembler {
  public:
    typedef enum {
      ASM_INSTR_READ,
      ASM_INSTR_WRITE,
      ASM_INSTR_LOAD,
      ASM_INSTR_STORE,
      ASM_INSTR_GET,
      ASM_INSTR_PUT,
      ASM_INSTR_ADD,
      ASM_INSTR_SUB,
      ASM_INSTR_RST,
      ASM_INSTR_INC,
      ASM_INSTR_DEC,
      ASM_INSTR_SHL,
      ASM_INSTR_SHR,
      ASM_INSTR_JUMP,
      ASM_INSTR_JPOS,
      ASM_INSTR_JZERO,
      ASM_INSTR_STRK,
      ASM_INSTR_JUMPR,
      ASM_INSTR_HALT,
    } asm_instruction;

    std::string instructions_str[19];

    std::string& instr_read() { return instructions_str[ASM_INSTR_GET]; }
    std::string& instr_write() { return instructions_str[ASM_INSTR_WRITE]; }
    std::string& instr_load() { return instructions_str[ASM_INSTR_LOAD]; }
    std::string& instr_store() { return instructions_str[ASM_INSTR_STORE]; }
    std::string& instr_get() { return instructions_str[ASM_INSTR_GET]; }
    std::string& instr_put() { return instructions_str[ASM_INSTR_PUT]; }
    std::string& instr_add() { return instructions_str[ASM_INSTR_ADD]; }
    std::string& instr_sub() { return instructions_str[ASM_INSTR_SUB]; }
    std::string& instr_rst() { return instructions_str[ASM_INSTR_RST]; }
    std::string& instr_inc() { return instructions_str[ASM_INSTR_INC]; }
    std::string& instr_dec() { return instructions_str[ASM_INSTR_DEC]; }
    std::string& instr_shl() { return instructions_str[ASM_INSTR_SHL]; }
    std::string& instr_shr() { return instructions_str[ASM_INSTR_SHR]; }
    std::string& instr_jump() { return instructions_str[ASM_INSTR_JUMP]; }
    std::string& instr_jpos() { return instructions_str[ASM_INSTR_JPOS]; }
    std::string& instr_jzero() { return instructions_str[ASM_INSTR_JZERO]; }
    std::string& instr_strk() { return instructions_str[ASM_INSTR_STRK]; }
    std::string& instr_jumpr() { return instructions_str[ASM_INSTR_JUMPR]; }
    std::string& instr_halt() { return instructions_str[ASM_INSTR_HALT]; }
};

#endif