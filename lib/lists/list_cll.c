//
// Created by luker on 26/12/2022.
//

#include "list_cll.h"


#define CLL_APPEND_SRC(fname, datatype, dtype_code) LIST_APPEND_DCL(CLL_t, fname, datatype, dtype_code){ \
    if((*list)->len == 0){                                                                                  \
       (*list)->head = create_node_d_##dtype_code (data);                                                \
       (*list)->head->next = (*list)->head;                                                              \
       (*list)->head->prev = (*list)->head;                                                             \
    } else {                                                                                             \
       ListNode_d_t* newnode = create_node_d_##dtype_code (data);                                         \
       newnode->next = (*list)->head;                                                                       \
       newnode->prev = (*list)->head->prev;                                                                 \
       (*list)->head->prev->next = newnode;                                                                                                                                                                   \
       (*list)->head->prev = newnode;                                                                       \
    }                                                                                                    \
    (*list)->len += 1;                                                                                      \
};

#define CLL_INSERT_SRC(fname, datatype, dtype_code) LIST_INSERT_DCL(CLL_t, fname, datatype, dtype_code){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                                                                \
    if(index == (*list)->len){                                                                                      \
        cll_append_##dtype_code (list, data);                                                                  \
        return; \
    }                                                                                                    \
    ListNode_d_t* curr = NULL;                                                                  \
    ListNode_d_t* prev = NULL;                                                                                                     \
    ListNode_d_t* newnode = create_node_d_##dtype_code (data);                                            \
    if(index == 0){                                                                                      \
        newnode->next = (*list)->head;                                                                   \
        newnode->prev = (*list)->head->prev;                                                                                                 \
        (*list)->head->prev->next = newnode;                                                             \
        (*list)->head->prev = newnode;                                                                                                 \
        (*list)->head = newnode;                                                                         \
    } else {                                                                                             \
        curr = (*list)->head; \
        if(index <= (*list)->len / 2){                                                                    \
            uint64_t count = 0;                                                                          \
            while(count != index){                                                                           \
                prev = curr;\
                curr = curr->next;                                                                           \
                count++;\
            }                                                                                                \
            newnode->next = curr;                                                                        \
            newnode->prev = prev;\
            curr->prev = newnode;\
            prev->next = newnode;                                                                            \
        } else {                                                                                         \
            curr = curr->prev; \
            uint64_t count = (*list)->len;                                                           \
            while(count != index){                                                                           \
                prev = curr;\
                curr = curr->prev;                                                                           \
                count--;                                                                                 \
            }                                                                                                \
            newnode->prev = curr;                                                                        \
            newnode->next = prev; \
            prev->prev = newnode;                                                                        \
            curr->next = newnode; \
        }                                                                                                 \
    }                                                                                                    \
    (*list)->len++;                                                          \
}

#define CLL_POP_SRC(fname) LIST_POP_DCL(CLL_t, fname, d){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                  \
    ListNode_d_t* curr = (*list)->head;                                                                  \
    ListNode_d_t* prev = NULL;                               \
                                                             \
    if(index == 0){                                          \
        (*list)->head = curr->next;                       \
        (*list)->head->prev = curr->prev;                                                     \
    } else {                                                 \
        uint64_t count = 0;                                                                              \
        while(count != index){                                                                           \
            prev = curr;\
            curr = curr->next;                                                                           \
            count++;\
        }                                                 \
        prev->next = curr->next;                          \
        prev->next->prev = prev;                                                  \
                                  \
    }                                                        \
    (*list)->len--;                                       \
    curr->next = NULL;                                    \
    curr->prev = NULL; \
    return curr;\
}

LIST_GEN_SRC(CLL_t, create_cll);
LIST_DSTR_SRC(CLL_t, d, destroy_cll);
LIST_PRINT_SRC(CLL_t, print_cll, d);
LIST_APPLY_SRC(CLL_t, apply_cll, d);
LIST_INDEX_SRC(CLL_t , index_cll, d);

CLL_POP_SRC(pop_cll);

CLL_APPEND_SRC(cll_append, void*,    ptr);
CLL_APPEND_SRC(cll_append, uint8_t,  u8);
CLL_APPEND_SRC(cll_append, int8_t,   i8);
CLL_APPEND_SRC(cll_append, uint16_t, u16);
CLL_APPEND_SRC(cll_append, int16_t,  i16);
CLL_APPEND_SRC(cll_append, uint32_t, u32);
CLL_APPEND_SRC(cll_append, int32_t,  i32);
CLL_APPEND_SRC(cll_append, uint64_t, u64);
CLL_APPEND_SRC(cll_append, int64_t,  i64);
CLL_APPEND_SRC(cll_append, float,    f32);
CLL_APPEND_SRC(cll_append, double,   f64);

CLL_INSERT_SRC(cll_insert, void*,    ptr);
CLL_INSERT_SRC(cll_insert, uint8_t,  u8);
CLL_INSERT_SRC(cll_insert, int8_t,   i8);
CLL_INSERT_SRC(cll_insert, uint16_t, u16);
CLL_INSERT_SRC(cll_insert, int16_t,  i16);
CLL_INSERT_SRC(cll_insert, uint32_t, u32);
CLL_INSERT_SRC(cll_insert, int32_t,  i32);
CLL_INSERT_SRC(cll_insert, uint64_t, u64);
CLL_INSERT_SRC(cll_insert, int64_t,  i64);
CLL_INSERT_SRC(cll_insert, float,    f32);
CLL_INSERT_SRC(cll_insert, double,   f64);