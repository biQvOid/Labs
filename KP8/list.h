#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct _list_node node;
typedef struct _list list;

struct _list_node
{
    char data;
    node* next;
    node* prev;
};

struct _list
{
    node* head;
    node* tail;
};

list* list_create();

void back_insert(list* lst, char value);
void front_insert(list* lst, char value);
void delete(list* lst, int k);
void print(list* lst);
void function(list* lst, int k);
int count(list* lst);
void destroy(list* lst);

#endif
