// liblaniidae -- A PS1 emulator library.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#pragma once

#include "cpu_a.hpp"

class Interpreter : public CPU
{
 private:
    void exec_load_store_instr(void);
    void exec_computational_instr(void);
    void exec_jump_branch_instr(void);
    void exec_coprocessor_instr(void);
    void exec_special_instr(void);

 public:
    Interpreter(Memory* m);
    virtual ~Interpreter(void);
};
