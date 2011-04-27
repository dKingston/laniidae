// liblaniidae -- A PS1 emulator library.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#pragma once

#include "cpu_a.hpp"

class Interpreter : public CPU
{
 private:
     void op_lb(void);
     void op_lbu(void);
     void op_lh(void);
     void op_lhu(void);
     void op_lw(void);
     void op_lwl(void);
     void op_lwr(void);
     void op_sb(void);
     void op_sh(void);
     void op_sw(void);
     void op_swl(void);
     void op_swr(void);
     void op_addi(void);
     void op_addiu(void);
     void op_slti(void);
     void op_sltiu(void);
     void op_andi(void);
     void op_ori(void);
     void op_xori(void);
     void op_lui(void);
     void op_add(void);
     void op_addu(void);
     void op_sub(void);
     void op_subu(void);
     void op_slt(void);
     void op_sltu(void);
     void op_and(void);
     void op_or(void);
     void op_xor(void);
     void op_nor(void);
     void op_sll(void);
     void op_srl(void);
     void op_sra(void);
     void op_sllv(void);
     void op_srlv(void);
     void op_srav(void);
     void op_mult(void);
     void op_multu(void);
     void op_div(void);
     void op_divu(void);
     void op_mfhi(void);
     void op_mflo(void);
     void op_mthi(void);
     void op_mtlo(void);
     void op_j(void);
     void op_jal(void);
     void op_jr(void);
     void op_jalr(void);
     void op_beq(void);
     void op_bne(void);
     void op_blez(void);
     void op_bgtz(void);
     void op_bltz(void);
     void op_bgez(void);
     void op_bltzal(void);
     void op_bgezal(void);
     void op_syscall(void);
     void op_break(void);
     void op_cop0(void);
     void op_cop2(void);

 public:
    Interpreter(Memory* m);
    virtual ~Interpreter(void);
};
