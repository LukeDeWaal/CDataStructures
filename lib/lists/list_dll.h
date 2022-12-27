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

#include "../map.h"
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

LIST_APPEND_GENERIC_DCL(DLL_t , dll_append);
LIST_INSERT_GENERIC_DCL(DLL_t , dll_insert);

#define DLL_APPEND_DCL_GENERATOR(type, tag) \
    LIST_APPEND_DCL(DLL_t, dll_append, type, tag);

#define DLL_INSERT_DCL_GENERATOR(type, tag) \
    LIST_INSERT_DCL(DLL_t, dll_insert, type, tag);

MAP_TUPLES(DLL_APPEND_DCL_GENERATOR, PAIRS);
MAP_TUPLES(DLL_INSERT_DCL_GENERATOR, PAIRS);

#endif //DS_MAIN_LIST_DLL_H
