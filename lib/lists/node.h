//
// Created by luker on 26/12/2022.
//

#ifndef DS_MAIN_NODE_H
#define DS_MAIN_NODE_H

#include <inttypes.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../map.h"
#include "defines.h"
#include "../datatypes.h"

struct ListNode_single_s {
    Data_t data;
    ListNode_s_t* next;
};

struct ListNode_double_s {
    Data_t data;
    ListNode_d_t* prev;
    ListNode_d_t* next;
};

#define NODE_GEN_DCL_GENERIC(ntype, fname) ntype* fname (Data_t data)

#define NODE_GEN_DCL(ntype, datatype, dtype_code, fname) ntype* fname##_##dtype_code (datatype data)

#define NODE_DSTR_DCL(ntype, fname) void fname (ntype** node, void (*destructor)(void* arg))

#define NODE_PRINT_DCL(ntype, fname) void fname (ntype* node)

NODE_GEN_DCL_GENERIC(ListNode_s_t, create_node_s);
NODE_GEN_DCL_GENERIC(ListNode_d_t, create_node_d);

#define SNODE_GEN_DCL_GENERATOR(type, tag) \
    NODE_GEN_DCL(ListNode_s_t, type, tag, create_node_s);

#define DNODE_GEN_DCL_GENERATOR(type, tag) \
    NODE_GEN_DCL(ListNode_d_t, type, tag, create_node_d);

MAP_TUPLES(SNODE_GEN_DCL_GENERATOR, PAIRS);
MAP_TUPLES(DNODE_GEN_DCL_GENERATOR, PAIRS);

NODE_DSTR_DCL(ListNode_s_t, destroy_node_s);
NODE_DSTR_DCL(ListNode_d_t, destroy_node_d);

NODE_PRINT_DCL(ListNode_s_t, print_node_s);
NODE_PRINT_DCL(ListNode_d_t, print_node_d);

#endif //DS_MAIN_NODE_H
