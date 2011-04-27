// liblaniidae -- A PS1 emulator library.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#pragma once

#include "cpu_a.hpp"

// Packet commands.
const Word GPU_CLEAR_CACHE       = 0x01;
const Word GPU_FB_RECT           = 0x02;
const Word GPU_MONO_3P_POLY      = 0x20;
const Word GPU_TEXT_3P_POLY      = 0x24;
const Word GPU_MONO_4P_POLY      = 0x28;
const Word GPU_TEXT_4P_POLY      = 0x2c;
const Word GPU_GRAD_3P_POLY      = 0x30;
const Word GPU_GRAD_TEXT_3P_POLY = 0x34;
const Word GPU_GRAD_4P_POLY      = 0x38;
const Word GPU_GRAD_TEXT_4P_POLY = 0x3c;
const Word GPU_MONO_LINE         = 0x40;
const Word GPU_MONO_PLINE        = 0x48;
const Word GPU_GRAD_LINE         = 0x50;
const Word GPU_GRAD_PLINE        = 0x58;
const Word GPU_RECT              = 0x60;
const Word GPU_SPRITE            = 0x64;
const Word GPU_DOT               = 0x68;
const Word GPU_EBE_RECT          = 0x70;
const Word GPU_EBE_SPRITE        = 0x74;
const Word GPU_SBS_RECT          = 0x78;
const Word GPU_SBS_SPRITE        = 0x7c;
const Word GPU_MI_FB             = 0x80;
const Word GPU_SEND_IMAGE_FB     = 0xa0;
const Word GPU_COPY_IMAGE_FB     = 0xc0;
const Word GPU_DRAW_MODE         = 0xe1;
const Word GPU_TEXT_WIN          = 0xe2;
const Word GPU_SET_DR_TL         = 0xe3;
const Word GPU_SET_DR_BR         = 0xe4;
const Word GPU_DRAW_OFFSET       = 0xe5;
const Word GPU_MASK_SETTING      = 0xe6;
