//
// Created by luker on 26/12/2022.
//

#ifndef DS_MAIN_DATATYPES_H
#define DS_MAIN_DATATYPES_H

#include <stdint.h>

#define ASSIGN_DATA(var, data, dtype_code) \
    Data_t var;                                                                                          \
    var.value.dtype_code = data;                                                                         \
    var.dtype = dtype_code;

typedef enum DATATYPE {
    ptr,
    u8,
    i8,
    u16,
    i16,
    u32,
    i32,
    u64,
    i64,
    f32,
    f64,
    datatypeEND
} DATATYPE;

typedef union {
    void*       ptr;
    uint8_t     u8;
    int8_t      i8;
    uint16_t    u16;
    int16_t     i16;
    uint32_t    u32;
    int32_t     i32;
    uint64_t    u64;
    int64_t     i64;
    float       f32;
    double      f64;
} DataUnion_t;

typedef struct Data_s {
    DataUnion_t value;
    DATATYPE dtype;
} Data_t;

#define PAIRS       \
(void*, ptr),       \
(uint8_t, u8),      \
(int8_t, i8),       \
(uint16_t, u16),    \
(int16_t, i16),     \
(uint32_t, u32),    \
(int32_t, i32),     \
(uint64_t, u64),    \
(int64_t, i64),     \
(float, f32),       \
(double, f64)

#endif //DS_MAIN_DATATYPES_H
