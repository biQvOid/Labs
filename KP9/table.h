#ifndef _TABLE_H_
#define _TABLE_H_

#include <stdio.h>

typedef struct _data Data;
typedef struct _key Key;
typedef struct _table Table;
typedef struct _node Node;

struct _data
{
    int INTEGER;
};

struct _key
{
    int INTEGER;
    char CHAR;
};

struct _node
{
    Key key;
    Data data;
};

struct _table
{
    Node* node;
    int size;
};

void create_table_keys();
void add_to_table_keys();
void print_table_keys();
void table_sort();
void binary_insert_sort();
void binary_search();
void task(); 

void print_table_keys_par(char data_name[20], char keys_name[20]);
void binary_insert_sort_par(char data_name[20], char keys_name[20]);
void binary_search_par(char data_name[20], char keys_name[20], int count);

#endif
