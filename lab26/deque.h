#ifndef DEQUE
#define DEQUE

#include <stdio.h>

typedef struct _deque deque;

struct _deque
{
    int *elements;
    int capasity;
    int number_of_elements;
};

void deque_create(deque* a);
void push_front(deque* a, int b);
void push_back(deque* a, int b);
int first_front(deque* a);
int first_back(deque* a);
int empty(deque* a);
void pop_front(deque* a);
void pop_back(deque* a);
void resize(deque* a);
int size(deque* a);
int deque_size(deque* a);

deque* reverse(deque* a);
void merge(deque* res, deque* a, deque* b);
void merge_sort(deque* a);
#endif
