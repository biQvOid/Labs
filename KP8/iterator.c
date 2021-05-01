#include <stdio.h>
#include "list.h"
#include "itetator.h"
#include <stdlib.h>

iterator* iterator_create(list* lst)
{
    iterator* it = (iterator*)malloc(sizeof(iterator));
    it->nod = lst->head;
    return it;
}

void iterator_next(iterator* it)
{
    if (it != NULL) {
        it->nod = it->nod->next;
    }
}

void iterator_prev(iterator* it)
{
    if (it != NULL) {
        it->nod = it->nod->prev;
    }
}

node* iterator_get(iterator* it)
{
    return it->nod;
}