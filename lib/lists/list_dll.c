//
// Created by luker on 26/12/2022.
//

#include "list_dll.h"

#define DLL_APPEND_GENERIC_SRC(fname) LIST_APPEND_GENERIC_DCL(DLL_t, fname){ \
    if((*list)->len == 0){                                                                                  \
       (*list)->head = create_node_d (data);                                                  \
    } else if((*list)->len == 1){                                                                           \
       (*list)->tail = create_node_d (data);                                                \
       (*list)->head->next = (*list)->tail;                                                       \
       (*list)->tail->prev = (*list)->head;                                                                    \
    } else {                                                                                             \
       (*list)->tail->next = create_node_d (data);                                            \
       (*list)->tail->next->prev = (*list)->tail;                                                              \
       (*list)->tail = (*list)->tail->next;                                                                    \
    }                                                                                                    \
    (*list)->len += 1;                                                                                                                                                               \
}

#define DLL_INSERT_GENERIC_SRC(fname) LIST_INSERT_GENERIC_DCL(DLL_t, fname){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                                                                \
    if(index == (*list)->len){                                                                                      \
        dll_append (list, data);                                                                  \
        return; \
    }                                                                                                    \
    ListNode_d_t* curr = NULL;                                                                  \
    ListNode_d_t* prev = NULL;                                                                                                     \
    ListNode_d_t* newnode = create_node_d (data);                                            \
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
    Data_t result;                                                          \
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
    curr->prev = NULL;                                    \
    result.value = curr->data.value;                             \
    result.dtype = curr->data.dtype;\
    destroy_node_d(&curr, NULL);                                                    \
    return result;\
}


LIST_GEN_SRC(DLL_t, create_dll);
LIST_DSTR_SRC(DLL_t, d, destroy_dll);
LIST_APPLY_SRC(DLL_t, apply_dll, d);
LIST_PRINT_SRC(DLL_t, print_dll, d);
LIST_INDEX_SRC(DLL_t , index_dll, d);
DLL_APPEND_GENERIC_SRC(dll_append)
DLL_INSERT_GENERIC_SRC(dll_insert)
DLL_POP_SRC(pop_dll);

#define DLL_APPEND_SRC_GENERATOR(type, tag) \
    LIST_APPEND_SRC(DLL_t, dll_append, type, tag)

#define DLL_INSERT_SRC_GENERATOR(type, tag) \
    LIST_INSERT_SRC(DLL_t, dll_insert, type, tag)

MAP_TUPLES(DLL_APPEND_SRC_GENERATOR, PAIRS);
MAP_TUPLES(DLL_INSERT_SRC_GENERATOR, PAIRS);
