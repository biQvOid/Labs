#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main()
{
    char s[10];
    int k;
    char c;
    char h = 0;
    list* l;
    printf("Набор команд:\n");
    printf("create - создать список\n");
    printf("addf - добавить элемент в начало списка(необходимо ввести значение элемента-любой символ)\n");
    printf("addb - добавить элемент в конец списка(необходимо ввести значение элемента-любой символ)\n");
    printf("delete - удалить элемент списка(необходимо ввести индекс элемента, начиная с 0)\n");
    printf("func - добавить k экземпляров последнего элемента списка в его начало(необходимо ввести целое число k)\n");
    printf("print - распечатать список\n");
    printf("count - количество элементов в списке\n");
    printf("destroy - уничтожение списка\n");
    scanf("%s%c", s, &c);
    while(1) {
        if (!strcmp(s, "create") && h == 0) {
            l = list_create();
            h++;
        } else if (!strcmp(s, "create") && h != 0) {
            printf("The list already exists\n");
        } else if (!strcmp(s, "addf") && h != 0) {
            scanf("%c", &c);
            front_insert(l, c);
        } else if (!strcmp(s, "addf") && h == 0) {
            printf("The list not exists\n");
        } else if (!strcmp(s, "addb") && h != 0) {
            scanf("%c", &c);
            back_insert(l, c);
        } else if (!strcmp(s, "addb") && h == 0) {
            printf("The list not exists\n");
        } else if (!strcmp(s, "print") && h != 0 && count(l) != 0) {
            print(l);
        } else if (!strcmp(s, "print") && h == 0) {
            printf("The list not exists\n");
        } else if (!strcmp(s, "print") && count(l) == 0) {
            printf("The list is empty\n");
        } else if (!strcmp(s, "delete") && h != 0 && count(l) != 0) {
            scanf("%d", &k);
            delete(l, k);
        } else if (!strcmp(s, "delete") && h == 0) {
            printf("The list not exists\n");
        } else if (!strcmp(s, "delete") && count(l) == 0) {
            printf("The list is empty\n");
        } else if (!strcmp(s, "func") && h != 0 && count(l) != 0) {
            scanf("%d", &k);
            function(l, k);
        } else if (!strcmp(s, "func") && h == 0) {
            printf("The list not exists\n");
        } else if (!strcmp(s, "func") && count(l) == 0) {
            printf("The list is empty\n");
        } else if (!strcmp(s, "count") && h != 0) {
            printf("%d\n", count(l));
        } else if (!strcmp(s, "count") && h == 0) {
            printf("The list not exists\n");
        } else if (!strcmp(s, "destroy") && h != 0) {
            destroy(l);
            h--;
        } else if (!strcmp(s, "destroy") && h == 0) {
            printf("The list not exists\n");
        }
        scanf("%s%c", s, &c);
    }
    return 0;
}
