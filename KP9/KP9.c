#include <stdio.h>
#include <string.h>
#include "table.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Need exactly two arguments\n");
        exit(1);
    }
    if (!strcmp(argv[1], "-a")) {
        add_to_table_keys();
    } else if (!strcmp(argv[1], "-p")) {
        print_table_keys();
    } else if (!strcmp(argv[1], "-k")) {
        create_table_keys();
    } else if (!strcmp(argv[1], "-s")) {
        binary_insert_sort();
    } else if (!strcmp(argv[1], "-b")) {
        binary_search();
    } else if (!strcmp(argv[1], "-t")) {
        task();
    } else {
        printf("Unknown flag\n");
    }
    return 0;
}
