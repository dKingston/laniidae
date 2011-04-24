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

// CLASS METHOD: Interpreter::op_lb()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Sign-extend contents of addressed byte
//               and load into `rt`.
//
// ARGUMENTS:    None.
// RETURNS:      None.
void
Interpreter::op_lb(void)
{
    Byte vaddr = gpr[base] + sign_ext;
    Byte paddr = translate_address(vaddr);
}

// CLASS METHOD: Interpreter::op_lbu()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Zero-extend contents of addressed byte
//               and load into `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_lbu(void)
{
    Byte vaddr = gpr[base] + sign_ext;
    Byte paddr = translate_address(vaddr);
}

// CLASS METHOD: Interpreter::op_lh()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Sign-extend contents of addressed byte
//               and load into `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_lh(void)
{
    HWord vaddr = gpr[base] + sign_ext;
    HWord paddr = translate_address(vaddr);
}

// CLASS METHOD: Interpreter::op_lhu()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Zero-extend contents of addressed byte
//               and load into `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_lhu(void)
{
    HWord vaddr = gpr[base] + sign_ext;
    HWord paddr = translate_address(vaddr);
}

// CLASS METHOD: Interpreter::op_lw()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Load contents of addressed word into
//               register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_lw(void)
{
    Word vaddr = gpr[base] + sign_ext;
    Word paddr = translate_address(vaddr);
}

// CLASS METHOD: Intepreter::op_lwl()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Shift addressed word left so that
//               addressed byte is leftmost byte of a word.  Merge bytes from
//               memory with contents of register `rt` and load result into
//               register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Intepreter::op_lwl(void)
{
    Word vaddr = gpr[base] + sign_ext;
    Word paddr = translate_address(vaddr);
}

// CLASS METHOD: Interpreter::op_lwr()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Shift addressed word right so that
//               addressed byte is rightmost byte of a word.  Merge bytes from
//               memory with contents of register `rt` and load result into
//               register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_lwr(void)
{
    Word vaddr = gpr[base] + sign_ext;
    Word paddr = translate_address(vaddr);
}

// CLASS METHOD: Interpreter::op_sb()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Store least significant byte of
//               register `rt` at addressed location.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_sb(void)
{ }

// CLASS METHOD: Interpreter::op_sh()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Store least significant halfword of
//               register `rt` at addressed location.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_sh(void)
{ }

// CLASS METHOD: Interpreter::op_sw()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Store least significant word of
//               register `rt` at addressed location.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_sw(void)
{ }

// CLASS METHOD: Interpreter::op_swl()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Shift contents of register `rt` right
//               so that leftmost byte of the word is in position of addressed
//               byte.  Store bytes containing original data into corresponding
//               bytes at addressed byte.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_swl(void)
{ }

// CLASS METHOD: Interpreter::op_swr()
// PURPOSE:      Sign-extend 16-bit `offset` and add to contents of register
//               `base` to form address.  Shift contents of register `rt` left
//               so that rightmost byte of the word is in position of addressed
//               byte.  Store bytes containing original data into corresponding
//               bytes at addressed byte.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_swr(void)
{ }

// CLASS METHOD: Interpreter::op_addi()
// PURPOSE:      Add 16-bit sign-extended `immediate` to register `rs` and place
//               32-bit result in register `rt`.  Trap on two's complement
//               overflow.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_addi(void)
{
    Word temp = gpr[rs] + sign_ext(immediate);

    if (arithmetic_overflow(temp))
    {
        signal_exc(Ovf);
        return;
    }

    gpr[rt] = temp;
}

// CLASS METHOD: Interpreter::op_addiu()
// PURPOSE:      Add 16-bit sign-extended immediate to register `rs` and place
//               32-bit result in register `rt`.  Do not trap on overflow.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_addiu(void)
{
    gpr[rt] = gpr[rs] + sign_ext(immediate);
}

// CLASS METHOD: Interpreter::op_slti()
// PURPOSE:      Compare 16-bit sign-extended `immediate` with register `rs` as
//               signed 32-bit integers.  Result = 1 if `rs` is less than
//               `immediate`; otherwise result = 0.  Place result in register
//               `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_slti(void)
{
    gpr[rt] = (gpr[rs] < sign_ext(immediate)) ? 1 : 0;
}

// CLASS METHOD: Interpreter::op_sltiu()
// PURPOSE:      Compare 16-bit sign-extended `immediate` with register `rs` as
//               unsigned 32-bit integers.  Result = 1 if `rs` is less than
//               `immediate`; otherwise result = 0.  Place result in register
//               `rt`.  Do not trap on overflow.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_sltiu(void)
{
    gpr[rt] = (static_cast<UWord*>(gpr[rs]) < static_cast<UWord*>(sign_ext(immediate))) ? 1 : 0;
}

// CLASS METHOD: Interpreter::op_andi()
// PURPOSE:      Zero-extend 16-bit `immediate`, AND with the contents of
//               register `rs` and place result in register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_andi(void)
{
    gpr[rt] = zero_ext(immediate) & gpr[rs];
}

// CLASS METHOD: Interpreter::op_ori()
// PURPOSE:      Zero-extend 16-bit `immediate`, OR with contents of register
//               `rs` and place result in register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_ori(void)
{
    gpr[rt] = zero_ext(immediate) | gpr[rs];
}

// CLASS METHOD: Interpreter::op_xori()
// PURPOSE:      Zero-extend 16-bit `immediate`, exclusive OR with contents of
//               register `rs` and place result in register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_xori(void)
{
    gpr[rt] = ~(zero_ext(immediate) | gpr[rs]);
}

// CLASS METHOD: Interpreter::op_lui()
// PURPOSE:      Shift 16-bit `immediate` left 16 bits.  Set least significant
//               16 bits of word to zeros.  Store result in register `rt`.
//
// ARGUMENTS: None.
// RETURNS:   None.
void
Interpreter::op_lui(void)
{
    gpr[rt] = immediate << 16;
}
