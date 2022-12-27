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

#include "../datatypes.h"

typedef struct ListNode_single_s ListNode_s_t;
typedef struct ListNode_double_s ListNode_d_t;

struct ListNode_single_s {
    DataUnion_t data;
    DATATYPE dtype;
    ListNode_s_t* next;
};

struct ListNode_double_s {
    DataUnion_t data;
    DATATYPE dtype;
    ListNode_d_t* prev;
    ListNode_d_t* next;
};

#define NODE_GEN_DCL(ntype, datatype, dtype_code, fname) ntype* fname##_##dtype_code (datatype data)

#define NODE_DSTR_DCL(ntype, fname) void fname (ntype** node, void (*destructor)(void* arg))

#define NODE_PRINT_DCL(ntype, fname) void fname (ntype* node)

NODE_GEN_DCL(ListNode_s_t, void*,       ptr,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, uint8_t,     u8,     create_node_s);
NODE_GEN_DCL(ListNode_s_t, int8_t,      i8,     create_node_s);
NODE_GEN_DCL(ListNode_s_t, uint16_t,    i16,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, int16_t,     u16,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, uint32_t,    u32,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, int32_t,     i32,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, uint64_t,    u64,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, int64_t,     i64,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, float,       f32,    create_node_s);
NODE_GEN_DCL(ListNode_s_t, double,      f64,    create_node_s);

NODE_GEN_DCL(ListNode_d_t, void*,       ptr,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, uint8_t,     u8,     create_node_d);
NODE_GEN_DCL(ListNode_d_t, int8_t,      i8,     create_node_d);
NODE_GEN_DCL(ListNode_d_t, uint16_t,    i16,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, int16_t,     u16,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, uint32_t,    u32,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, int32_t,     i32,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, uint64_t,    u64,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, int64_t,     i64,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, float,       f32,    create_node_d);
NODE_GEN_DCL(ListNode_d_t, double,      f64,    create_node_d);

NODE_DSTR_DCL(ListNode_s_t, destroy_node_s);
NODE_DSTR_DCL(ListNode_d_t, destroy_node_d);

NODE_PRINT_DCL(ListNode_s_t, print_node_s);
NODE_PRINT_DCL(ListNode_d_t, print_node_d);

#endif //DS_MAIN_NODE_H
