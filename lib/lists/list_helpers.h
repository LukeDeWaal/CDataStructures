//
// Created by luker on 19/12/2022.
//

#ifndef DS_MAIN_LIST_HELPERS_H
#define DS_MAIN_LIST_HELPERS_H

#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../datatypes.h"
#include "node.h"

typedef enum list_types_t {
    sll_e, dll_e, cll_e, listtypeEND
} list_types_t;

typedef enum direction_t {
    headtotail, tailtohead, directionEND
} direction_t;

void trivial_destructor(void* arg);
void freeing_destructor(void* arg);

#define LIST_GEN_DCL(ltype, fname) ltype* fname ()

#define LIST_DSTR_DCL(ltype, fname) void fname (ltype** list, void (*destructor)(void* arg))

#define LIST_APPEND_DCL(ltype, fname, datatype, dtype_code) void fname##_##dtype_code (ltype** list, datatype data)

#define LIST_INSERT_DCL(ltype, fname, datatype, dtype_code) void fname##_##dtype_code (ltype** list, datatype data, uint64_t index)

#define LIST_PRINT_DCL(ltype, fname) void fname (ltype* list, char* sep)

#define LIST_APPLY_DCL(ltype, fname) void fname (ltype* list, void (*function)(DataUnion_t* arg, DATATYPE dtype))

#define LIST_INDEX_DCL(ltype, fname, ntag) ListNode_##ntag##_t* fname (ltype* list, uint64_t index)

#define LIST_POP_DCL(ltype, fname, ntag) ListNode_##ntag##_t* fname (ltype** list, uint64_t index)

#define LIST_GEN_SRC(ltype, fname) LIST_GEN_DCL(ltype, fname){ \
    ltype* result = (ltype*)malloc(sizeof(ltype));             \
    memset(result, 0, sizeof(ltype));                          \
    result->len = 0ull;                                        \
    return result;                                             \
};

#define LIST_DSTR_SRC(ltype, ntag, fname) LIST_DSTR_DCL(ltype, fname){ \
    ListNode_##ntag##_t* curr = (*list)->head;                                        \
    ListNode_##ntag##_t* next = NULL;                                                 \
    while((*list)->len != 0){                                                \
        next = curr->next;                                             \
        destroy_node_##ntag(&curr, destructor);                      \
        curr = next;                                                   \
        (*list)->len -= 1;                                              \
    }                                                                  \
    free(*list);\
};

#define LIST_PRINT_SRC(ltype, fname, ntag) LIST_PRINT_DCL(ltype, fname){ \
    uint64_t count = 0;                                            \
    ListNode_##ntag##_t* curr = list->head;                        \
    printf("[");                                                   \
    while(count < list->len){                                      \
        print_node_##ntag (curr);                                  \
        if(count != list->len - 1){                                \
           printf("%s", sep);                                      \
        } else {                                                   \
           printf("]");                                            \
        }                                                           \
        curr = curr->next;                                          \
        count++;                                                    \
    }                                                                    \
    \
};

#define LIST_APPLY_SRC(ltype, fname, ntag) LIST_APPLY_DCL(ltype, fname){ \
    uint64_t count = 0;                                                                     \
    ListNode_##ntag##_t* curr = list->head;                              \
    while(count < list->len){                                      \
        function(&curr->data, curr->dtype);                          \
        curr = curr->next;                                          \
        count++;                                                    \
    }                                                                    \
};

#define LIST_INDEX_SRC(ltype, fname, ntag) LIST_INDEX_DCL(ltype, fname, ntag){ \
    uint64_t count = 0;                                                                     \
    ListNode_##ntag##_t* curr = list->head;                              \
    while(count != index){                                      \
        curr = curr->next;                                          \
        count++;                                                    \
    }                                                                                  \
    return curr;                                                    \
}

#define LIST_BOUNDS_CHECK(list, index, errcode) \
    if(index > list->len){                                                                       \
        fprintf(stderr, "Index %llu is not in range [0 - %llu]\n", index, list->len);             \
        exit(errcode);                                                                                \
     };

#endif //DS_MAIN_LIST_HELPERS_H
