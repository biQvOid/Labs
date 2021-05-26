#include "deque.h"
#include <stdlib.h>

void deque_create(deque *a)
{
    a->elements = malloc(sizeof(int));
    a->capasity = 1;
    a->number_of_elements = 0;
}

void push_front(deque *a, int b)
{ 
    if(a->number_of_elements == a->capasity) {
        resize(a);
    }
    int tmp1, tmp2;
    tmp1 = b;
    for(int i = 0; i < a->number_of_elements + 1; i++) {
        tmp2 = a->elements[i];
        a->elements[i] = tmp1;
        tmp1 = tmp2;
    }
    a->number_of_elements++;
}

void push_back(deque *a, int b)
{ 
    if (a->number_of_elements == deque_size(a)) {
        resize(a);
    }
    a->elements[a->number_of_elements] = b;
    a->number_of_elements++;
}

void pop_back(deque *a)
{
    if (a->number_of_elements > 0) {
        a->number_of_elements--;
    }
}

void pop_front(deque *a)
{
    if (a->number_of_elements > 0) {
        for(int i = 0; i < a->number_of_elements - 1; i++) {
            a->elements[i] = a->elements[i + 1];
        }
        a->number_of_elements--;
    }
}

int first_front(deque* a)
{
    return a->elements[0];
}

int first_back(deque* a)
{
    return a->elements[a->number_of_elements - 1];
}

int empty(deque *a)
{
    if (a->number_of_elements == 0) {
        return 1;
    } else {
        return 0;
    }
}

void resize(deque *a)
{
    a->capasity++;
    a->elements = realloc(a->elements, a->capasity * sizeof(int));
}

int size(deque* a)
{
    return a->number_of_elements;
}

int deque_size(deque *a)
{
    return a->capasity;
}

deque* reverse(deque* a)
{
    deque* b;
    deque_create(b);
    while (!empty(a)) {
        push_front(b, first_front(a));
        pop_front(a);
    }
    return b;
}

void merge(deque* res, deque* a, deque* b)
{
    deque c;
    deque_create(&c);
    while (!empty(a) && !empty(b)) {
        if (first_front(a) < first_front(b)) {
            push_back(&c, first_front(a));
            pop_front(a);
        } else {
            push_back(&c, first_front(b));
            pop_front(b);
        }
    }
    while (!empty(a)) {
        push_back(&c, first_front(a));
        pop_front(a);
    }
    while (!empty(b)) {
        push_back(&c, first_front(b));
        pop_front(b);
    }
    deque* new = reverse(&c);
    while (!empty(new)) {
        push_front(res, first_front(new));
        pop_front(new);
    }
}

void merge_sort(deque* a)
{
    if (size(a) > 1) {
        deque b, c;
        deque_create(&b);
        deque_create(&c);
        while (!empty(a)) {
            if (size(a) % 2 == 0) {
                push_front(&b, first_front(a));
                pop_front(a);
            } else {
                push_front(&c, first_front(a));
                pop_front(a);
            }
        }
        merge_sort(&b);
        merge_sort(&c);
        merge(a, &b, &c);
    }
}
