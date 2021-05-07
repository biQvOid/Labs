#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include <stdbool.h>

void vector_create(vector* v, int size)
{
    v->size = size;
    v->data = (int*)malloc(sizeof(int) * v->size);
    v->elements_count = 0;
}

int size(vector* v)
{
    return v->size;
}

bool empty(vector* v)
{
    return v->size == 0;
}

void size_pp(vector* v)
{
    v->size++;
    v->data = realloc(v->data, sizeof(int) * v->size);
}

void push_back(vector* v, int value)
{
    if (v->size == v->elements_count) {
        size_pp(v);
    }
    v->data[v->elements_count++] = value;
}

void destroy(vector* v)
{
    v->size = 0;
    v->elements_count = 0;
    free(v->data);
}
