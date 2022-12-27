//
// Created by luker on 26/12/2022.
//

#include "list_sll.h"

#define SLL_APPEND_SRC(fname, datatype, dtype_code) LIST_APPEND_DCL(SLL_t, fname, datatype, dtype_code){ \
    if((*list)->len == 0){                                                                                  \
       (*list)->head = create_node_s_##dtype_code (data);                                                  \
       (*list)->head->next = (*list)->tail;                                                                    \
    } else if((*list)->len == 1){                                                                           \
       (*list)->tail = create_node_s_##dtype_code (data);                                                \
       (*list)->head->next = (*list)->tail;                                                                                                      \
    } else {                                                                                             \
       (*list)->tail->next = create_node_s_##dtype_code (data);                                            \
       (*list)->tail = (*list)->tail->next;                                                                    \
    }                                                                                                    \
    (*list)->len += 1;                                                                                      \
};

#define SLL_INSERT_SRC(fname, datatype, dtype_code) LIST_INSERT_DCL(SLL_t, fname, datatype, dtype_code){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                                                                \
    if(index == (*list)->len){                                                                                      \
        sll_append_##dtype_code (list, data);                                                                  \
        return; \
    }                                                                                                    \
    ListNode_s_t* curr = (*list)->head;                                                                  \
    ListNode_s_t* prev = NULL;                                                                                                     \
    ListNode_s_t* newnode = create_node_s_##dtype_code (data);                                            \
    if(index == 0){                                                                                      \
        newnode->next = (*list)->head;                                                                   \
        (*list)->head = newnode;                                                                         \
    } else {                                                                                             \
        uint64_t count = 0;                                                                              \
        while(count != index){                                                                           \
            prev = curr;\
            curr = curr->next;                                                                           \
            count++;\
        }                                                                                                \
        newnode->next = curr;                                                                            \
        prev->next = newnode;                                                                            \
    }                                                                                                    \
    (*list)->len++;                                                                                                         \
}

#define SLL_POP_SRC(fname) LIST_POP_DCL(SLL_t, fname, s){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                  \
    ListNode_s_t* curr = (*list)->head;                                                                  \
    ListNode_s_t* prev = NULL;                               \
                                                             \
    if(index == 0){                                          \
        (*list)->head = curr->next;                          \
    } else {                                                 \
        uint64_t count = 0;                                                                              \
        while(count != index){                                                                           \
            prev = curr;\
            curr = curr->next;                                                                           \
            count++;\
        }                                                 \
        prev->next = curr->next;                          \
        if(index == (*list)->len - 1){                        \
            (*list)->tail = prev;                                                  \
        }                                                  \
    }                                                        \
    (*list)->len--;                                       \
    curr->next = NULL;                                                      \
    return curr;\
}

LIST_GEN_SRC(SLL_t, create_sll);
LIST_DSTR_SRC(SLL_t, s, destroy_sll);
LIST_PRINT_SRC(SLL_t, print_sll, s);
LIST_APPLY_SRC(SLL_t, apply_sll, s);
LIST_INDEX_SRC(SLL_t , index_sll, s);
LIST_POP_DCL(SLL_t, pop_sll, s);

SLL_POP_SRC(pop_sll);

SLL_APPEND_SRC(sll_append, void*,    ptr);
SLL_APPEND_SRC(sll_append, uint8_t,  u8);
SLL_APPEND_SRC(sll_append, int8_t,   i8);
SLL_APPEND_SRC(sll_append, uint16_t, u16);
SLL_APPEND_SRC(sll_append, int16_t,  i16);
SLL_APPEND_SRC(sll_append, uint32_t, u32);
SLL_APPEND_SRC(sll_append, int32_t,  i32);
SLL_APPEND_SRC(sll_append, uint64_t, u64);
SLL_APPEND_SRC(sll_append, int64_t,  i64);
SLL_APPEND_SRC(sll_append, float,    f32);
SLL_APPEND_SRC(sll_append, double,   f64);

SLL_INSERT_SRC(sll_insert, void*,    ptr);
SLL_INSERT_SRC(sll_insert, uint8_t,  u8);
SLL_INSERT_SRC(sll_insert, int8_t,   i8);
SLL_INSERT_SRC(sll_insert, uint16_t, u16);
SLL_INSERT_SRC(sll_insert, int16_t,  i16);
SLL_INSERT_SRC(sll_insert, uint32_t, u32);
SLL_INSERT_SRC(sll_insert, int32_t,  i32);
SLL_INSERT_SRC(sll_insert, uint64_t, u64);
SLL_INSERT_SRC(sll_insert, int64_t,  i64);
SLL_INSERT_SRC(sll_insert, float,    f32);
SLL_INSERT_SRC(sll_insert, double,   f64);


