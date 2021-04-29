#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list* list_create()
{
    list* lst = (list*)malloc(sizeof(list));
    lst->head = lst->tail = NULL;
}

void back_insert(list* lst, char c)
{
    if (lst == NULL) {
        printf("The list not exists\n");
        return;
    }
    node* new = (node*)malloc(sizeof(node));
    if (lst->head == NULL) {
        lst->head = new;
        lst->head->data = c;
        lst->tail = lst->head;
        lst->head->next = lst->head->prev = lst->tail;
    } else {     
        lst->tail->next = new;
        new->prev = lst->tail;
        new->next = lst->head;
        lst->tail = new;
        lst->tail->data = c;
        lst->head->prev = lst->tail;
    }
}

void print(list* lst)
{
    if (lst == NULL) {
        return;
    }
    node* first = lst->head->next;
    if (lst->head != NULL) {
        printf("[%c] ", lst->head->data);
    }
    while (first != lst->head) {
        printf("[%c] ", first->data);
        first = first->next;
    }
    printf("\n");
}

void front_insert(list* lst, char c)
{
    if (lst == NULL) {
        printf("The list not exists\n");
        return;
    }
    node* new = (node*)malloc(sizeof(node));
    if (lst->head == NULL) {
        lst->head = new;
        lst->head->data = c;
        lst->tail = lst->head;
        lst->head->next = lst->head->prev = lst->tail;
    } else {
        new->data = c;
        lst->head->prev = new;
        new->next = lst->head;
        lst->tail->next = new;
        lst->head = new;
        lst->head->prev = lst->tail;
    }
}

void delete(list* lst, int k)
{
    if (lst == NULL) {
        printf("The list not exists\n");
        return;
    }
    node* first = lst->head;
    for (int i = 0; i < k; i++) {
        first = first->next;
    }
    if (first != lst->head && first != lst->tail) {
        first->prev->next = first->next;
        first->next->prev = first->prev;
        free(first);
    } else if (first == lst->head) {
        lst->head = first->next;
        lst->tail->next = lst->head;
        first->next->prev = lst->tail;
        free(first);
    } else if (first == lst->tail) {
        lst->tail = first->prev;
        lst->head->prev = lst->tail;
        first->prev->next = lst->head;
        free(first);
    }
}

void function(list* lst, int k)
{
    if (lst == NULL) {
        return;
    }
    if (lst->tail == NULL) {
        return;
    }
    for (int i = 0; i < k; i++) {
        front_insert(lst, lst->tail->data);
    }
}

int count(list* lst)
{
    if (lst == NULL || lst->head == NULL) {
        return 0;
    }
    int k = 0;
    node* first = lst->head->next;
    if (lst->head != NULL) {
        k++;
    }
    while (first != lst->head) {
        k++;
        first = first->next;
    }
    return k;
}

void destroy(list* lst)
{
    int k = count(lst);
    for (int i = 0; i < k; i++) {
        delete(lst, i);
    }
}
