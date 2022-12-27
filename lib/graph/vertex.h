//
// Created by luker on 27/12/2022.
//

#ifndef DS_MAIN_VERTEX_H
#define DS_MAIN_VERTEX_H

#include <inttypes.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "defines.h"
#include "../datatypes.h"
#include "../lists/lists.h"


struct Edge_s {
    Vertex_t *v1;
    Vertex_t *v2;
    DataUnion_t weight;
    DATATYPE dtype;
};

struct DirectionalEdge_s{
    Vertex_t *source;
    Vertex_t *target;
};

struct Vertex_s {
    DataUnion_t data;
    DATATYPE dtype;
    SLL_t edges;
};



#endif //DS_MAIN_VERTEX_H
