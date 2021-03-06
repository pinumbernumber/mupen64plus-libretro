/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Mupen64plus-rsp-hle - hle.h                                           *
 *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
 *   Copyright (C) 2002 Hacktarux                                          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HLE_H
#define HLE_H

#define M64P_PLUGIN_PROTOTYPES 1
#include "m64p_plugin.h"

#define RSP_HLE_VERSION        0x016305
#define RSP_PLUGIN_API_VERSION 0x020000

#ifdef M64P_BIG_ENDIAN
#define S 0
#define S16 0
#define S8 0
#else
#define S 1
#define S16 2
#define S8 3
#endif

// types
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long long    s64;

extern RSP_INFO rspInfo;

typedef struct
{
    unsigned int type;
    unsigned int flags;

    unsigned int ucode_boot;
    unsigned int ucode_boot_size;

    unsigned int ucode;
    unsigned int ucode_size;

    unsigned int ucode_data;
    unsigned int ucode_data_size;

    unsigned int dram_stack;
    unsigned int dram_stack_size;

    unsigned int output_buff;
    unsigned int output_buff_size;

    unsigned int data_ptr;
    unsigned int data_size;

    unsigned int yield_data_ptr;
    unsigned int yield_data_size;
} OSTask_t;

static inline const OSTask_t * const get_task()
{
    return (OSTask_t*)(rspInfo.DMEM + 0xfc0);
}

void rspDebugMessage(int level, const char *message, ...);

#endif

