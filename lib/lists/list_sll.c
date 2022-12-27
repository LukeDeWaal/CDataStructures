//
// Created by luker on 26/12/2022.
//

#include "list_sll.h"

#define SLL_APPEND_GENERIC_SRC(fname) LIST_APPEND_GENERIC_DCL(SLL_t, fname){ \
    if((*list)->len == 0){                                                                                  \
       (*list)->head = create_node_s(data);                                                  \
       (*list)->head->next = (*list)->tail;                                                                    \
    } else if((*list)->len == 1){                                                                           \
       (*list)->tail = create_node_s(data);                                                \
       (*list)->head->next = (*list)->tail;                                                                                                      \
    } else {                                                                                             \
       (*list)->tail->next = create_node_s(data);                                            \
       (*list)->tail = (*list)->tail->next;                                                                    \
    }                                                                                                    \
    (*list)->len += 1;                                                                                       \
}



#define SLL_INSERT_GENERIC_SRC(fname) LIST_INSERT_GENERIC_DCL(SLL_t, fname){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                                                                \
    if(index == (*list)->len){                                                                                      \
        sll_append (list, data);                                                                  \
        return; \
    }                                                                                                    \
    ListNode_s_t* curr = (*list)->head;                                                                  \
    ListNode_s_t* prev = NULL;                                                                                                     \
    ListNode_s_t* newnode = create_node_s (data);                                            \
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
    (*list)->len++;                                                                                      \
}

#define SLL_POP_SRC(fname) LIST_POP_DCL(SLL_t, fname, s){ \
    LIST_BOUNDS_CHECK((*list), index, 255);                  \
    Data_t result;                                                      \
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
    curr->next = NULL;                                    \
    result.value = curr->data.value;                             \
    result.dtype = curr->data.dtype;\
    destroy_node_s(&curr, NULL);\
    return result;\
}

LIST_GEN_SRC(SLL_t, create_sll);
LIST_DSTR_SRC(SLL_t, s, destroy_sll);
LIST_PRINT_SRC(SLL_t, print_sll, s);
LIST_APPLY_SRC(SLL_t, apply_sll, s);
LIST_INDEX_SRC(SLL_t , index_sll, s);
LIST_POP_DCL(SLL_t, pop_sll, s);
SLL_POP_SRC(pop_sll);

SLL_APPEND_GENERIC_SRC(sll_append);
SLL_INSERT_GENERIC_SRC(sll_insert);

#define SLL_APPEND_SRC_GENERATOR(type, tag) \
    LIST_APPEND_SRC(SLL_t, sll_append, type, tag)

#define SLL_INSERT_SRC_GENERATOR(type, tag) \
    LIST_INSERT_SRC(SLL_t, sll_insert, type, tag)

MAP_TUPLES(SLL_APPEND_SRC_GENERATOR, PAIRS);
MAP_TUPLES(SLL_INSERT_SRC_GENERATOR, PAIRS);






