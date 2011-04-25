// liblaniidae -- A PS1 emulator library.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#pragma once

#include "cpu_a.hpp"

// Primitive commands.
const Word Nop       = 0x01;
const Word Setloc    = 0x02;
const Word Play      = 0x03;
const Word Forward   = 0x04;
const Word Backward  = 0x05;
const Word ReadN     = 0x06;
const Word Standby   = 0x07;
const Word Stop      = 0x08;
const Word Pause     = 0x09;
const Word Mute      = 0x0b;
const Word Demute    = 0x0c;
const Word Setfilter = 0x0d;
const Word Setmode   = 0x0e;
const Word GetlocL   = 0x10;
const Word GetlocP   = 0x11;
const Word Getparam  = 0x0f;
const Word SeekL     = 0x15;
const Word SeekP     = 0x16;
const Word ReadS     = 0x1b;
