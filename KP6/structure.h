#ifndef structure_h
#define structure_h

#include <stdio.h>
#include <stdlib.h>

struct student_progress
{
    char surname[50];
    char initials[10];
    char gender[10];
    int group_number;
    int sociology_mark;
    int history_mark;
    int english_mark;
    int informatics_mark;
    int math_analys_mark;
    int linear_algebra_mark;
    int discrete_math_mark;
};

typedef struct student_progress Study;

void create()
{
    char name[20];
    FILE* set;
    printf("Enter file name to create\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (set != NULL) {
        printf("Such file already exists\n");
    } else {
        set = fopen(name, "a");
    }
    fclose(set);
}

void add()
{
    int count;
    char name[20];
    FILE* set;
    Study adder;
    printf("Enter file name\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (!set) {
        printf("such file not exists\n");
    } else {
        set = fopen(name, "a");
        printf("Enter how many records do you want to add\n");
        scanf("%d", &count);
        for (int i = 0; i < count; i++) {
            printf("Enter student surname\n");
            scanf("%s", adder.surname);
            printf("Enter student initials\n");
            scanf("%s", adder.initials);
            printf("Enter student gender\n");
            scanf("%s", adder.gender); 
            printf("Enter group number\n");
            scanf("%d", &adder.group_number);
            printf("Enter sociology mark\n");
            scanf("%d", &adder.sociology_mark);
            printf("Enter english mark\n");
            scanf("%d", &adder.english_mark);
            printf("Enter informatics mark\n");
            scanf("%d", &adder.informatics_mark);
            printf("Enter discrete math mark\n");
            scanf("%d", &adder.discrete_math_mark);
            printf("Enter math analys mark\n");
            scanf("%d", &adder.math_analys_mark);
            printf("Enter linear algebra mark\n");
            scanf("%d", &adder.linear_algebra_mark);
            printf("Enter history mark\n");
            scanf("%d", &adder.history_mark);
            fwrite(&adder, sizeof(Study), 1, set);
        }
        fclose(set);
    }
}

void print()
{
    FILE* set;
    Study reader;
    char name[20];
    printf("Enter file name\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (!set) {
        printf("Such file not exists\n");
    } else {
        printf("|  Student surname|Initials|Gender|Group number|Sociology|History|English|Informatics|Discrete math|Math analys|Linear algebra|\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&reader, sizeof(Study), 1, set) != EOF && !feof(set)) {
            printf("|%17s|%8s|%6s|%12d|%9d|%7d|%7d|%11d|%13d|%11d|%14d|\n", reader.surname, reader.initials, reader.gender, reader.group_number,
                reader.sociology_mark, reader.history_mark, reader.english_mark, reader.informatics_mark, reader.discrete_math_mark,
                reader.math_analys_mark, reader.linear_algebra_mark);
        }
        fclose(set);
    }
}

void delete()
{
    FILE* set;
    char name[20];
    printf("Enter file name\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (!set) {
        printf("Such file not exists\n");
    } else {
        remove(name);
        printf("The file was deleted\n");
        fclose(set);
    }
}

void function()
{
    Study finder;
    char name[20];
    FILE* set;
    int p;
    int k = 0;
    printf("Enter file name\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (set == NULL) {
        printf("Such file not exists\n");
    } else {
        printf("Enter group number\n");
        scanf("%d", &p);
        set = fopen(name, "rb");
        while(fread(&finder, sizeof(Study), 1, set) != EOF && !feof(set)) {
            int count = 0;
            if (finder.group_number != p) {
                continue;
            } else {
                if (finder.sociology_mark == 3) count++;
                if (finder.discrete_math_mark == 3) count++;
                if (finder.history_mark == 3) count++;
                if (finder.english_mark == 3) count++;
                if (finder.informatics_mark == 3) count++;
                if (finder.linear_algebra_mark == 3) count++;
                if (finder.math_analys_mark == 3) count++;
                if (count > 2) k++;
            }
        }
        if (k == 0) {
            printf("Nobody in %d group has more than 2 three!\n", p);
        } else {
            printf("The count of students, who have more than 2 three in %d group: %d\n",p, k);
        }
        fclose(set);
    }
}
#endif
