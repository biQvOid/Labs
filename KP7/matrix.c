#include "matrix.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int el_count(char name[20])
{
    int a = 0;
    int count = 0;
    FILE* f = fopen(name, "r");
    while(fscanf(f, "%d", &a) && !feof(f)) {
        count++;
    }
    fclose(f);
    return count;
}

int lines_count(char name[20])
{
    int count = 0;
    FILE* f = fopen(name, "r");
    while (!feof(f)) {
        if (fgetc(f) == '\n')
            count++;
    }
    fclose(f);
    return count;
}

vector* matrix_input(vector* v)
{
    int a;
    char name[20];
    vector_create(v, 1);
    int n, m;
    scanf("%s", name);
    FILE* f = fopen(name, "r");
    if (f == NULL) {
        printf("The file not exists\n");
        exit(1);
    }
    n = lines_count(name);
    m = el_count(name) / n;
    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &a);
            c[i][j] = a;
        }
    }
    int g = 0;
    for (int p = 0; p < n; p++) {
        int k = 0;
        for (int g = 0; g < m; g++) {
            if (c[p][g] != 0) {
                if (k == 0) {
                    //push_back(&v, p + 1);
                    push_back(v, p + 1);
                    k++;
                }
                push_back(v, g + 1);
                push_back(v, c[p][g]);
            }
        }
        if (k != 0) {
            push_back(v, 0);
        }
    }
    push_back(v, 0);
    push_back(v, n);
    push_back(v, m);
    fclose(f);
    return v;
}

void task_print(vector* v)
{
    if (v == NULL) {
        return;
    }
    printf("Matrix pattern placing\n");
    for (int i = 0; i < v->size - 2; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

void function1(vector* v)
{
    int count = 0;
    int column_count = 1;
    vector a;
    vector_create(&a, 0);
    for (int i = 0; i < v->size - 3; i++) {
        if (v->data[i] != 0 && (i + 1) % 2 == 0) {
            push_back(&a, v->data[i]);
            printf("%d ", v->data[i]);
        }
    }
    printf("\n");
    if (v->size == 0) {
        return;
    }
    int ind = 0;
    int e = 0;
    int max = 1;
    int old_max = max;
    for (int i = 0; i < a.size - 1; i++) {
        if (a.data[i] == a.data[i + 1]) {
            count++;
            e++;
        }
        if (count > max - 1) {
            max = count;
        }
        if (a.data[i] != a.data[i + 1]) {
            count = 0;
        }
    }
    if (e != 0) {
        max++;
    }
    printf("%d\n", max);
}

void function(vector* v)
{
    vector a;
    vector_create(&a, 0);
    for (int i = 0; i < v->size - 3; i++) {
        if (v->data[i] != 0 && (i + 1) % 2 == 0) {
            push_back(&a, v->data[i]);
        }
    }
    vector b;
    vector_create(&b, v->data[v->size - 1]);
    for (int i = 0; i < b.size; i++) {
        b.data[i] = 0;
    }
    for (int i = 0; i < a.size; i++) {
        b.data[a.data[i] - 1]++;
    }
    int max = b.data[0];
    for (int i = 0; i < b.size - 1; i++) {
        if (b.data[i + 1] > max) {
            max = b.data[i + 1];
        }
    }
    int alone_st = -1;   
    int back_second_st = -1;
    int k = 0;
    int ind;
    for (int i = b.size - 1; i >= 0; i--) {
        if (b.data[i] == max && k == 0) {
            alone_st = i + 1;
            k++;
        } else if (b.data[i] == max && k == 1) {
            back_second_st = i + 1;
            k++;
        }
    }
    if (back_second_st == -1) {
        ind = alone_st;
    } else {
        ind = back_second_st;
    }
    int p = 1;
    for (int i = 0; i < v->size - 3; i++) {
        if (v->data[i] != 0 && (i + 1) % 2 == 0 && v->data[i] == ind) {
            p = p * v->data[i + 1];
        }
    }
    printf("The elements composition of processed column: %d\n", p);
    printf("The index of processed column: %d\n", ind);
}   

void natural_print(vector* v)
{
    int n = v->data[v->size - 2];
    int m = v->data[v->size - 1];
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    if (v->size == 0) {
        return;
    }
    int l = 0;
    int k = 0;
    int count = 0;
    int value;
    for (int i = 0; i < v->size - 5;) {
        if (count == 0) {
            l = v->data[i] - 1;
            k = v->data[i + 1] - 1;
            value = v->data[i + 2];
            a[l][k] = value;
            count++;
            if (v->data[i + 3] == 0) {
                count--;
                i = i + 4;
            } else {
                i = i + 3;
            }
        } else {
            k = v->data[i] - 1;
            value = v->data[i + 1];
            a[l][k] = value;
            if (v->data[i + 2] == 0) {
                count--;
                i = i + 3;
            } else {
                i = i + 2;
            }
        }
    }
    printf("Natural form of matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
