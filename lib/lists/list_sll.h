//
// Created by luker on 26/12/2022.
//

#ifndef DS_MAIN_LIST_SLL_H
#define DS_MAIN_LIST_SLL_H

#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../datatypes.h"
#include "node.h"
#include "list_helpers.h"

typedef struct SLL_t {
    uint64_t len;
    ListNode_s_t* head;
    ListNode_s_t* tail;
} SLL_t ;

LIST_GEN_DCL(SLL_t, create_sll);
LIST_DSTR_DCL(SLL_t, destroy_sll);
LIST_PRINT_DCL(SLL_t, print_sll);
LIST_APPLY_DCL(SLL_t, apply_sll);
LIST_INDEX_DCL(SLL_t, index_sll, s);
LIST_POP_DCL(SLL_t, pop_sll, s);

LIST_APPEND_DCL(SLL_t , sll_append, void*,    ptr);
LIST_APPEND_DCL(SLL_t , sll_append, uint8_t,  u8);
LIST_APPEND_DCL(SLL_t , sll_append, int8_t,   i8);
LIST_APPEND_DCL(SLL_t , sll_append, uint16_t, u16);
LIST_APPEND_DCL(SLL_t , sll_append, int16_t,  i16);
LIST_APPEND_DCL(SLL_t , sll_append, uint32_t, u32);
LIST_APPEND_DCL(SLL_t , sll_append, int32_t,  i32);
LIST_APPEND_DCL(SLL_t , sll_append, uint64_t, u64);
LIST_APPEND_DCL(SLL_t , sll_append, int64_t,  i64);
LIST_APPEND_DCL(SLL_t , sll_append, float,    f32);
LIST_APPEND_DCL(SLL_t , sll_append, double,   f64);

LIST_INSERT_DCL(SLL_t , sll_insert, void*,    ptr);
LIST_INSERT_DCL(SLL_t , sll_insert, uint8_t,  u8);
LIST_INSERT_DCL(SLL_t , sll_insert, int8_t,   i8);
LIST_INSERT_DCL(SLL_t , sll_insert, uint16_t, u16);
LIST_INSERT_DCL(SLL_t , sll_insert, int16_t,  i16);
LIST_INSERT_DCL(SLL_t , sll_insert, uint32_t, u32);
LIST_INSERT_DCL(SLL_t , sll_insert, int32_t,  i32);
LIST_INSERT_DCL(SLL_t , sll_insert, uint64_t, u64);
LIST_INSERT_DCL(SLL_t , sll_insert, int64_t,  i64);
LIST_INSERT_DCL(SLL_t , sll_insert, float,    f32);
LIST_INSERT_DCL(SLL_t , sll_insert, double,   f64);


#endif //DS_MAIN_LIST_SLL_H
