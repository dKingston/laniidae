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
typedef Word   int32_t;
typedef UWord  uint32_t;
typedef HWord  int16_t;
typedef UHWord uint16_t;
typedef Byte   int8_t;
typedef UByte  uint8_t;

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
