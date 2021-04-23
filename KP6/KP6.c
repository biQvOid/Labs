#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Need exactly two arguments\n");
        exit(1);
    }
    if (!strcmp(argv[1], "-a")) {
        add();
    } else if (!strcmp(argv[1], "-p")) {
        print();
    } else if (!strcmp(argv[1], "-d")) {
        delete();
    } else if (!strcmp(argv[1], "-k")) {
        create();
    } else if (!strcmp(argv[1], "-f")) {
        function();
    } else {
        printf("Unknown command\n");
    }
    return 0;
}
