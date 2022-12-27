//
// Created by luker on 26/12/2022.
//

#include "list_dll.h"

#define DLL_APPEND_SRC(fname, datatype, dtype_code) LIST_APPEND_DCL(DLL_t, fname, datatype, dtype_code){ \
    if((*list)->len == 0){                                                                                  \
       (*list)->head = create_node_d_##dtype_code (data);                                                  \
    } else if((*list)->len == 1){                                                                           \
       (*list)->tail = create_node_d_##dtype_code (data);                                                \
       (*list)->head->next = (*list)->tail;                                                       \
       (*list)->tail->prev = (*list)->head;                                                                    \
    } else {                                                                                             \
       (*list)->tail->next = create_node_d_##dtype_code (data);                                            \
       (*list)->tail->next->prev = (*list)->tail;                                                              \
       (*list)->tail = (*list)->tail->next;                                                                    \
    }                                                                                                    \
    (*list)->len += 1;                                                                                      \
};

#define DLL_INSERT_SRC(fname, datatype, dtype_code) LIST_INSERT_DCL(DLL_t, fname, datatype, dtype_code){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                                                                \
    if(index == (*list)->len){                                                                                      \
        dll_append_##dtype_code (list, data);                                                                  \
        return; \
    }                                                                                                    \
    ListNode_d_t* curr = NULL;                                                                  \
    ListNode_d_t* prev = NULL;                                                                                                     \
    ListNode_d_t* newnode = create_node_d_##dtype_code (data);                                            \
    if(index == 0){                                                                                      \
        newnode->next = (*list)->head;                                                                   \
        (*list)->head->prev = newnode; \
        (*list)->head = newnode;                                                                         \
    } else {                                                                                             \
        if(index <= (*list)->len / 2){                                                                    \
            uint64_t count = 0;                                                                          \
            curr = (*list)->head; \
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
            uint64_t count = (*list)->len;                                                           \
            curr = (*list)->tail; \
            while(count != index){                                                                           \
                prev = curr;\
                curr = curr->prev;                                                                           \
                count--;\
            }                                                                                                \
            newnode->prev = curr;                                                                        \
            newnode->next = prev; \
            prev->prev = newnode;                                                                        \
            curr->next = newnode; \
        }                                                                                                 \
    }                                                                                                    \
    (*list)->len++;                                                                                                         \
}

#define DLL_POP_SRC(fname) LIST_POP_DCL(DLL_t, fname, d){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                  \
    ListNode_d_t* curr = (*list)->head;                                                                  \
    ListNode_d_t* prev = NULL;                               \
                                                             \
    if(index == 0){                                          \
        (*list)->head = curr->next;                       \
        (*list)->head->prev = NULL;                                                     \
    } else {                                                 \
        uint64_t count = 0;                                                                              \
        while(count != index){                                                                           \
            prev = curr;\
            curr = curr->next;                                                                           \
            count++;\
        }                                                 \
        prev->next = curr->next;                          \
        prev->next->prev = prev;                                                  \
        if(index == (*list)->len - 1){                        \
           (*list)->tail = prev;                                                   \
        }                                                  \
                                  \
    }                                                        \
    (*list)->len--;                                       \
    curr->next = NULL;                                    \
    curr->prev = NULL; \
    return curr;\
}


LIST_GEN_SRC(DLL_t, create_dll);
LIST_DSTR_SRC(DLL_t, d, destroy_dll);
LIST_APPLY_SRC(DLL_t, apply_dll, d);
LIST_PRINT_SRC(DLL_t, print_dll, d);
LIST_INDEX_SRC(DLL_t , index_dll, d);

DLL_POP_SRC(pop_dll);

DLL_APPEND_SRC(dll_append, void*,    ptr);
DLL_APPEND_SRC(dll_append, uint8_t,  u8);
DLL_APPEND_SRC(dll_append, int8_t,   i8);
DLL_APPEND_SRC(dll_append, uint16_t, u16);
DLL_APPEND_SRC(dll_append, int16_t,  i16);
DLL_APPEND_SRC(dll_append, uint32_t, u32);
DLL_APPEND_SRC(dll_append, int32_t,  i32);
DLL_APPEND_SRC(dll_append, uint64_t, u64);
DLL_APPEND_SRC(dll_append, int64_t,  i64);
DLL_APPEND_SRC(dll_append, float,    f32);
DLL_APPEND_SRC(dll_append, double,   f64);

DLL_INSERT_SRC(dll_insert, void*,    ptr);
DLL_INSERT_SRC(dll_insert, uint8_t,  u8);
DLL_INSERT_SRC(dll_insert, int8_t,   i8);
DLL_INSERT_SRC(dll_insert, uint16_t, u16);
DLL_INSERT_SRC(dll_insert, int16_t,  i16);
DLL_INSERT_SRC(dll_insert, uint32_t, u32);
DLL_INSERT_SRC(dll_insert, int32_t,  i32);
DLL_INSERT_SRC(dll_insert, uint64_t, u64);
DLL_INSERT_SRC(dll_insert, int64_t,  i64);
DLL_INSERT_SRC(dll_insert, float,    f32);
DLL_INSERT_SRC(dll_insert, double,   f64);