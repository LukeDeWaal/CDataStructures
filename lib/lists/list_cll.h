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

#include "../map.h"
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

LIST_APPEND_GENERIC_DCL(CLL_t , cll_append);
LIST_INSERT_GENERIC_DCL(CLL_t , cll_insert);

#define CLL_APPEND_DCL_GENERATOR(type, tag) \
    LIST_APPEND_DCL(CLL_t, cll_append, type, tag);

#define CLL_INSERT_DCL_GENERATOR(type, tag) \
    LIST_INSERT_DCL(CLL_t, cll_insert, type, tag);

MAP_TUPLES(CLL_APPEND_DCL_GENERATOR, PAIRS);
MAP_TUPLES(CLL_INSERT_DCL_GENERATOR, PAIRS);

#endif //DS_MAIN_LIST_CLL_H
