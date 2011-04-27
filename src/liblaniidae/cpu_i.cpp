// liblaniidae -- A PS1 emulator library.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#include "cpu_a.hpp"
#include "cpu_i.hpp"
#include "mem.hpp"

// CLASS METHOD: Interpreter::Interpreter()
// PURPOSE:      CPU interpreter constructor.
// ARGUMENTS:    Memory instance.
// RETURNS:      None.
Interpreter::Interpreter(Memory *m)
{
    mem = m;
}

// CLASS METHOD: Interpreter::~Interpreter()
// PURPOSE:      CPU interpreter destructor.
// ARGUMENTS:    None.
// RETURNS:      None.
Interpreter::~Interpreter(void)
{ }

// CLASS METHOD: Interpreter::exec_load_store_instr()
// PURPOSE:      Load/store instructions move data between memory and the
//               general registers.  They are all encoded as "I-Type"
//               instructions, and the only addressing mode implemented is base
//               register plus signed, immediate offset.  This directly enables
//               the use of three distinct addressing modes: register plus
//               offset; register direct; and immediate.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::exec_load_store_instr(void)
{
    Word vaddr, paddr;

    switch (op(curr_instr))
    {
        // LB -- Load Byte
        // 
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Sign-extend contents of addressed byte and load into
        // `rt`.
        case LB:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), sign_ext_byte(mem->read(vaddr, paddr), bytepos(vaddr)));
            break;

        // LBU -- Load Byte Unsigned
        //
        // Sign-extend 16-bit `offse` and add to contents of register `base` to
        // form address.  Zero-extend contents of addressed byte and load into
        // `rt`.
        case LBU:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), zero_ext_byte(mem->read(vaddr, paddr), bytepos(vaddr)));
            break;

        // LH -- Load Halfword
        //
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Sign-extend contents of addressed byte and load into
        // `rt`.
        case LH:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), sign_ext_hword(mem->read(vaddr, paddr), hwordpos(vaddr)));
            break;

        // LHU -- Load Halfword Unsigned
        //
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Zero-extend contents of addressed byte and load into
        // `rt`.
        case LHU:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), zero_ext_hword(mem->read(vaddr, paddr), hwordpos(vaddr)));
            break;

        // LW -- Load Word
        //
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Load contents of addressed word into register `rt`.
        case LW:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), mem->read(vaddr, paddr));
            break;

        // LWL -- Load Word Left
        //
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Shift addressed word left so that addressed byte is
        // leftmost byte of a word.  Merge bytes from memory with contents of
        // register `rt` and load result into register `rt`.
        case LWL:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), merge(gpr[rt(curr_instr)], mem->read(vaddr, paddr), bytepos(vaddr), true));
            break;

        // LWR -- Load Word Right
        //
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Shfit addressed word right so that addressed byte is
        // rightmost byte of a word.  Merge bytes from memory with contents of
        // register `rt` and load result into register `rt`.
        case LWR:
            vaddr = gpr[base(curr_instr)] + sign_ext(curr_instr);
            paddr = translate_address(align(vaddr));

            do_load(LOADREG, rt(curr_instr), merge(gpr[rt(curr_instr)], mem->read(vaddr, paddr), bytepos(vaddr), false));
            break;

        // SB -- Store Byte
        //
        // Sign-extend 16-bit `offset` and add to contents of register `base` to
        // form address.  Store least significant byte of register `rt` at
        // addressed location.
    }
}
