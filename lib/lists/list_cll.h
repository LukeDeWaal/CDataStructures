//
// Created by luker on 26/12/2022.
//

#ifndef DS_MAIN_LIST_CLL_H
#define DS_MAIN_LIST_CLL_H

#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../datatypes.h"
#include "node.h"
#include "list_helpers.h"

typedef struct CLL_t {
    uint64_t len;
    ListNode_d_t* head;
} CLL_t;


LIST_PRINT_DCL(CLL_t, print_cll);
LIST_APPLY_DCL(CLL_t, apply_cll);
LIST_GEN_DCL(CLL_t, create_cll);
LIST_DSTR_DCL(CLL_t, destroy_cll);
LIST_INDEX_DCL(CLL_t , index_cll, d);
LIST_POP_DCL(CLL_t, pop_cll, d);

LIST_APPEND_DCL(CLL_t , cll_append, void*,    ptr);
LIST_APPEND_DCL(CLL_t , cll_append, uint8_t,  u8);
LIST_APPEND_DCL(CLL_t , cll_append, int8_t,   i8);
LIST_APPEND_DCL(CLL_t , cll_append, uint16_t, u16);
LIST_APPEND_DCL(CLL_t , cll_append, int16_t,  i16);
LIST_APPEND_DCL(CLL_t , cll_append, uint32_t, u32);
LIST_APPEND_DCL(CLL_t , cll_append, int32_t,  i32);
LIST_APPEND_DCL(CLL_t , cll_append, uint64_t, u64);
LIST_APPEND_DCL(CLL_t , cll_append, int64_t,  i64);
LIST_APPEND_DCL(CLL_t , cll_append, float,    f32);
LIST_APPEND_DCL(CLL_t , cll_append, double,   f64);

LIST_INSERT_DCL(CLL_t , cll_insert, void*,    ptr);
LIST_INSERT_DCL(CLL_t , cll_insert, uint8_t,  u8);
LIST_INSERT_DCL(CLL_t , cll_insert, int8_t,   i8);
LIST_INSERT_DCL(CLL_t , cll_insert, uint16_t, u16);
LIST_INSERT_DCL(CLL_t , cll_insert, int16_t,  i16);
LIST_INSERT_DCL(CLL_t , cll_insert, uint32_t, u32);
LIST_INSERT_DCL(CLL_t , cll_insert, int32_t,  i32);
LIST_INSERT_DCL(CLL_t , cll_insert, uint64_t, u64);
LIST_INSERT_DCL(CLL_t , cll_insert, int64_t,  i64);
LIST_INSERT_DCL(CLL_t , cll_insert, float,    f32);
LIST_INSERT_DCL(CLL_t , cll_insert, double,   f64);


#endif //DS_MAIN_LIST_CLL_H
