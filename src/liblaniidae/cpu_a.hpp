// liblaniidae -- A PS1 emulator library.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#pragma once

// The following notice will appear in "cpu_a.cpp" as well:
//
// ****************************************************************************
//                             *** NOTICE ***
// ****************************************************************************
//
// To build a CPU interpreter/bytecode evaluator, whatever you want to call it,
// or a dynamic recompilator, you *MUST* use this file.  Patches will not be
// taken without it.  This is an abstraction layer that does most of the hard
// work for you, making life easier.  The abstractions can easily be overridden
// to do what you want it to do if it does not suffice for you, though you
// shouldn't have to. --dKingston

#include <stdint.h> // C++0x, GET DONE FASTER!

// I know these are typedefs to other typedefs, but they make debugging a bit
// easier to read.  Plus, they sound better, considering this is an emulator.
// --dKingston
typedef int32_t  Word;
typedef uint32_t UWord;
typedef int16_t  HWord;
typedef uint16_t UHWord;
typedef int8_t   Byte;
typedef uint8_t  UByte;

// CP0 special registers.
const Word Index    = 0;  // Programmable pointer into on-chip TLB array
const Word Random   = 1;  // Pseudo-random pointer into on-chip TLB array (read only)
const Word EntryLo  = 2;  // Low-half of TLB entry.
const Word Context  = 4;  // Pointer to kernel virtual Page Table Entry Table
const Word BadVAddr = 8;  // Bad virtual address
const Word EntryHi  = 10; // High-half of TLB entry
const Word SR       = 12; // Status Register
const Word Cause    = 13; // Cause of last exception
const Word EPC      = 14; // Exception Program Counter
const Word PRId     = 15; // Processor Revision Identifier

// PRId register value.
const Word prid_regval = 0x00000230;

class CPU
{
 protected:
    Word curr_pc;
    Word next_pc;
    Word succ_pc;
    Word prev_pc;
    Word curr_instr;
    Word prev_instr;
    Word next_instr;
    Word num_cycles;
    Word gpr[32];
    Word cp0_cpr[32];
    Word cp2_cpr[32];
    Word cp2_ccr[32];
    virtual void exec_instr(Word instr);

 public:
    CPU(Memory *m);
    virtual ~CPU(void);
    virtual void set_cp0_cpr(Word reg, Word val);
    virtual Word get_cp0_cpr(Word reg);
    virtual void set_cp2_cpr(Word reg, Word val);
    virtual Word get_cp2_cpr(Word reg);
    virtual void set_cp2_ccr(Word reg, Word val);
    virtual Word get_cp2_ccr(Word reg);
    virtual void set_gpr(Word reg, Word val);
    virtual Word get_gpr(Word reg);
    virtual void cycle(void);
    virtual void signal_exc(Word exc);
    virtual void branch(const Word address, const Word num_instrs);
    virtual Word translate_address(Word addr);
};
