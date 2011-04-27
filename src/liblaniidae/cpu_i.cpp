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
virtual
Interpreter::~Interpreter(void)
{ }
