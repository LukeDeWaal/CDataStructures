//
// Created by luker on 26/12/2022.
//

#include "list_cll.h"


#define CLL_APPEND_GENERIC_SRC(fname)  LIST_APPEND_GENERIC_DCL(CLL_t, fname){ \
    if((*list)->len == 0){                                                                                  \
       (*list)->head = create_node_d (data);                                                \
       (*list)->head->next = (*list)->head;                                                              \
       (*list)->head->prev = (*list)->head;                                                             \
    } else {                                                                                             \
       ListNode_d_t* newnode = create_node_d (data);                                         \
       newnode->next = (*list)->head;                                                                       \
       newnode->prev = (*list)->head->prev;                                                                 \
       (*list)->head->prev->next = newnode;                                                                                                                                                                   \
       (*list)->head->prev = newnode;                                                                       \
    }                                                                                                    \
    (*list)->len += 1;                                                                                      \
};

#define CLL_INSERT_GENERIC_SRC(fname) LIST_INSERT_GENERIC_DCL(CLL_t, fname){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                                                                \
    if(index == (*list)->len){                                                                                      \
        cll_append (list, data);                                                                  \
        return; \
    }                                                                                                    \
    ListNode_d_t* curr = NULL;                                                                  \
    ListNode_d_t* prev = NULL;                                                                                                     \
    ListNode_d_t* newnode = create_node_d (data);                                            \
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
    Data_t result;                                                      \
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
    curr->prev = NULL;                                    \
    result.value = curr->data.value;                             \
    result.dtype = curr->data.dtype;\
    destroy_node_d(&curr, NULL);                                                      \
    return result;\
}

LIST_GEN_SRC(CLL_t, create_cll);
LIST_DSTR_SRC(CLL_t, d, destroy_cll);
LIST_PRINT_SRC(CLL_t, print_cll, d);
LIST_APPLY_SRC(CLL_t, apply_cll, d);
LIST_INDEX_SRC(CLL_t , index_cll, d);

CLL_POP_SRC(pop_cll);

CLL_APPEND_GENERIC_SRC(cll_append);
CLL_INSERT_GENERIC_SRC(cll_insert);

#define CLL_APPEND_SRC_GENERATOR(type, tag) \
    LIST_APPEND_SRC(CLL_t, cll_append, type, tag)

#define CLL_INSERT_SRC_GENERATOR(type, tag) \
    LIST_INSERT_SRC(CLL_t, cll_insert, type, tag)

MAP_TUPLES(CLL_APPEND_SRC_GENERATOR, PAIRS);
MAP_TUPLES(CLL_INSERT_SRC_GENERATOR, PAIRS);
