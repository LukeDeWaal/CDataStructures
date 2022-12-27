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

#include "../map.h"
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

LIST_APPEND_GENERIC_DCL(SLL_t , sll_append);
LIST_INSERT_GENERIC_DCL(SLL_t , sll_insert);

#define SLL_APPEND_DCL_GENERATOR(type, tag) \
    LIST_APPEND_DCL(SLL_t, sll_append, type, tag);

#define SLL_INSERT_DCL_GENERATOR(type, tag) \
    LIST_INSERT_DCL(SLL_t, sll_insert, type, tag);

MAP_TUPLES(SLL_APPEND_DCL_GENERATOR, PAIRS);
MAP_TUPLES(SLL_INSERT_DCL_GENERATOR, PAIRS);




#endif //DS_MAIN_LIST_SLL_H
