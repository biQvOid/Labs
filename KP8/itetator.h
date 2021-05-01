#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "list.h"
#include <stdio.h>

typedef struct _iterator iterator;

struct _iterator
{
    node* nod;
};

iterator* iterator_create(list* lst);
void iterator_next(iterator* it);
void iterator_prev(iterator* it);
node* iterator_get(iterator* it);
void iterator_destroy(iterator* it);

#endif