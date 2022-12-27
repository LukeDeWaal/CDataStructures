//
// Created by luker on 26/12/2022.
//

#ifndef DS_MAIN_LIST_DLL_H
#define DS_MAIN_LIST_DLL_H

#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../datatypes.h"
#include "node.h"
#include "list_helpers.h"

typedef struct DLL_t {
    uint64_t len;
    ListNode_d_t* head;
    ListNode_d_t* tail;
} DLL_t;

LIST_GEN_DCL(DLL_t, create_dll);
LIST_DSTR_DCL(DLL_t, destroy_dll);
LIST_PRINT_DCL(DLL_t, print_dll);
LIST_APPLY_DCL(DLL_t, apply_dll);
LIST_INDEX_DCL(DLL_t , index_dll, d);
LIST_POP_DCL(DLL_t, pop_dll, d);

LIST_APPEND_DCL(DLL_t , dll_append, void*,    ptr);
LIST_APPEND_DCL(DLL_t , dll_append, uint8_t,  u8);
LIST_APPEND_DCL(DLL_t , dll_append, int8_t,   i8);
LIST_APPEND_DCL(DLL_t , dll_append, uint16_t, u16);
LIST_APPEND_DCL(DLL_t , dll_append, int16_t,  i16);
LIST_APPEND_DCL(DLL_t , dll_append, uint32_t, u32);
LIST_APPEND_DCL(DLL_t , dll_append, int32_t,  i32);
LIST_APPEND_DCL(DLL_t , dll_append, uint64_t, u64);
LIST_APPEND_DCL(DLL_t , dll_append, int64_t,  i64);
LIST_APPEND_DCL(DLL_t , dll_append, float,    f32);
LIST_APPEND_DCL(DLL_t , dll_append, double,   f64);

LIST_INSERT_DCL(DLL_t , dll_insert, void*,    ptr);
LIST_INSERT_DCL(DLL_t , dll_insert, uint8_t,  u8);
LIST_INSERT_DCL(DLL_t , dll_insert, int8_t,   i8);
LIST_INSERT_DCL(DLL_t , dll_insert, uint16_t, u16);
LIST_INSERT_DCL(DLL_t , dll_insert, int16_t,  i16);
LIST_INSERT_DCL(DLL_t , dll_insert, uint32_t, u32);
LIST_INSERT_DCL(DLL_t , dll_insert, int32_t,  i32);
LIST_INSERT_DCL(DLL_t , dll_insert, uint64_t, u64);
LIST_INSERT_DCL(DLL_t , dll_insert, int64_t,  i64);
LIST_INSERT_DCL(DLL_t , dll_insert, float,    f32);
LIST_INSERT_DCL(DLL_t , dll_insert, double,   f64);


#endif //DS_MAIN_LIST_DLL_H
