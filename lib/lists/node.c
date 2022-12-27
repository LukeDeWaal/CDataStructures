//
// Created by luker on 26/12/2022.
//

#include "node.h"

#define NODE_GEN_SC_GENERIC(ntype, fname) NODE_GEN_DCL_GENERIC(ntype, fname){ \
   ntype* result = (ntype*)malloc(sizeof(ntype));                                                    \
   memset(result, 0, sizeof(ntype));                                                                 \
   result->data.value = data.value;                                           \
   result->data.dtype = data.dtype;\
   return result;                                                                                    \
}

#define NODE_GEN_SRC(ntype, datatype, dtype_code, fname) NODE_GEN_DCL(ntype, datatype, dtype_code, fname){       \
   Data_t arg;                                                                                                   \
   arg.value.dtype_code = data;                                                                                  \
   arg.dtype = dtype_code;\
   return fname (arg);                                                                                    \
};


#define NODE_DSTR_SRC(ntype, fname) NODE_DSTR_DCL(ntype, fname){    \
   if(destructor != NULL && (*node)->data.dtype == ptr){                 \
      destructor(&((*node)->data.value.ptr));                                 \
   }                                                                \
   free(*node);                                                     \
};

#define NODE_PRINT_SRC(ntype, fname) NODE_PRINT_DCL(ntype, fname){ \
    switch(node->data.dtype){       \
        case ptr:                                                  \
            printf("%p", node->data.value.ptr);                                   \
            break;  \
        case u8:                                                   \
            printf("%"PRIu8"", node->data.value.u8);                                                       \
            break;  \
        case i8:                                                   \
            printf("%"PRIi8"", node->data.value.i8);                                                         \
            break;  \
        case u16:                                                  \
            printf("%"PRIu16"", node->data.value.u16);                                \
            break;  \
        case i16:   \
            printf("%"PRIi16"", node->data.value.i16);                                                        \
            break;  \
        case u32:                                                  \
            printf("%"PRIu32"", node->data.value.u32);                                \
            break;  \
        case i32:                                                  \
            printf("%"PRIi32"", node->data.value.i8);                                                        \
            break;  \
        case u64:                                                  \
            printf("%"PRIu64, node->data.value.u64);                                                       \
            break;  \
        case i64:                                                  \
            printf("%"PRIi64"", node->data.value.i64);                                                       \
            break;  \
        case f32:                                                  \
            printf("%f", node->data.value.f32);\
            break;  \
        case f64:                                                  \
            printf("%lf", node->data.value.f64);                                                        \
            break;                                                 \
        case datatypeEND:  \
        default:                                                   \
            printf("ERR");\
            break;  \
        }                                                          \
                                                                     \
};

NODE_GEN_SC_GENERIC(ListNode_s_t, create_node_s);
NODE_GEN_SC_GENERIC(ListNode_d_t, create_node_d);

NODE_GEN_SRC(ListNode_s_t, void*,       ptr,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, uint8_t,     u8,     create_node_s);
NODE_GEN_SRC(ListNode_s_t, int8_t,      i8,     create_node_s);
NODE_GEN_SRC(ListNode_s_t, uint16_t,    i16,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, int16_t,     u16,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, uint32_t,    u32,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, int32_t,     i32,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, uint64_t,    u64,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, int64_t,     i64,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, float,       f32,    create_node_s);
NODE_GEN_SRC(ListNode_s_t, double,      f64,    create_node_s);

NODE_GEN_SRC(ListNode_d_t, void*,       ptr,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, uint8_t,     u8,     create_node_d);
NODE_GEN_SRC(ListNode_d_t, int8_t,      i8,     create_node_d);
NODE_GEN_SRC(ListNode_d_t, uint16_t,    i16,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, int16_t,     u16,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, uint32_t,    u32,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, int32_t,     i32,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, uint64_t,    u64,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, int64_t,     i64,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, float,       f32,    create_node_d);
NODE_GEN_SRC(ListNode_d_t, double,      f64,    create_node_d);

NODE_DSTR_SRC(ListNode_s_t, destroy_node_s);
NODE_DSTR_SRC(ListNode_d_t, destroy_node_d);

NODE_PRINT_SRC(ListNode_s_t, print_node_s);
NODE_PRINT_SRC(ListNode_d_t, print_node_d);