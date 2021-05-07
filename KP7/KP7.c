#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include <stdbool.h>

int main()
{
    char name[20];
    vector v;
    vector* a = &v;
    printf("Enter the file name\n");
    a = matrix_input(a);
    task_print(a);
    natural_print(a);
    function(a);
    return 0;
}
