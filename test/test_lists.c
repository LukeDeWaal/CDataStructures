
#include <assert.h>
#include <sys/time.h>
#include "../lib/library.h"

SLL_t* test_sll;
DLL_t* test_dll;
CLL_t* test_cll;

#define STRINGIFY(ARG) #ARG

#define PRINTTIME(name, testname, tv1, tv2)                      \
    printf ("%s %s tests passed in %.3f ms\n", name, testname,           \
    ((double) (tv2.tv_usec - tv1.tv_usec) / 1000 + (double) (tv2.tv_sec - tv1.tv_sec) * 1000));

#define LIST_TESTCASE(LTAG, NTAG, REPEATS)                                           \
    {                                                                           \
        const char* name = #LTAG"ll";                                           \
        test_##LTAG##ll = create_##LTAG##ll();                                  \
        ListNode_##NTAG##_t* elem = NULL;                                            \
        Data_t value;                                                                             \
        uint64_t idx = 0;\
                                                                                \
        struct timeval  tv1, tv2;                                               \
                                                                                \
        gettimeofday(&tv1, NULL);                                               \
        for(uint64_t i = 0; i < REPEATS; i++){                                  \
            LTAG##ll_append_u64 (&test_##LTAG##ll, i);                               \
            elem = index_##LTAG##ll(test_##LTAG##ll, i);                             \
            assert(elem->data.value.u64 == i);\
        }                                                                       \
        gettimeofday(&tv2, NULL);                                               \
                                                                                \
        PRINTTIME(name, "append", tv1, tv2);                           \
                                                                                \
        gettimeofday(&tv1, NULL);                                               \
        for(uint64_t i = 0; i < REPEATS; i++){                                       \
            idx =  test_##LTAG##ll->len / 2;                                    \
            LTAG##ll_insert_u64 (&test_##LTAG##ll, i, idx);\
            elem = index_##LTAG##ll(test_##LTAG##ll, idx);                             \
            assert(elem->data.value.u64 == i);                                                                             \
        }                                                                       \
        gettimeofday(&tv2, NULL);                                               \
                                                                                \
        PRINTTIME(name, "insert", tv1, tv2);                           \
                                                                                \
        gettimeofday(&tv1, NULL);                                               \
        for(uint64_t i = 0; i < REPEATS; i++){                                  \
            apply_##LTAG##ll (test_##LTAG##ll, &apply);                         \
        }                                                                       \
        gettimeofday(&tv2, NULL);                                               \
                                                                                \
        PRINTTIME(name, "apply", tv1, tv2);                    \
        gettimeofday(&tv1, NULL);                                               \
        for(uint64_t i = 0; i < REPEATS; i++){                                  \
            elem = index_##LTAG##ll (test_##LTAG##ll, i);                            \
            assert(elem->data.value.u64 >= REPEATS);                                                                         \
        }                                                                       \
        gettimeofday(&tv2, NULL);                                                    \
                                                                                     \
        PRINTTIME(name, "index", tv1, tv2);                                 \
                                                                                     \
        gettimeofday(&tv1, NULL);                                                    \
        for(uint64_t i = 0; i < REPEATS; i++){                                       \
            value = pop_##LTAG##ll (&test_##LTAG##ll, REPEATS - i);                   \
        }                                                                            \
        gettimeofday(&tv2, NULL);                                                    \
                                                                                     \
        PRINTTIME(name, "pop", tv1, tv2);                                   \
                                                                                     \
        destroy_##LTAG##ll (&test_##LTAG##ll, NULL);                                  \
        \
    }

void apply(Data_t* arg){
    switch (arg->dtype) {
        case u64:
            (*arg).value.u64++;
            break;
        default:
            break;
    }
}

int main(int argc, char** argv){

    LIST_TESTCASE(s, s, 10000);
    printf("=======================================\n");
    LIST_TESTCASE(d, d, 10000);
    printf("=======================================\n");
    LIST_TESTCASE(c, d, 10000);

    return 0;
}