#ifndef vector_h
#define vector_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _vector vector;

struct _vector
{
    int size;
    int* data;
    int elements_count;
};

void vector_create(vector* v, int size);
int size(vector* v);
bool is_empty(vector* v);
void resize(vector* v, int new_size);
void size_pp(vector* v);
void push_back(vector* v, int value);
void load(vector* v);
void destroy(vector* v);


#endif
