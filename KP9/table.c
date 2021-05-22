#include <stdio.h>
#include <stdlib.h>
#include "table.h"

void create_table()
{
    char name[20];
    FILE* set;
    printf("Enter file name to create file with data\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (set != NULL) {
        printf("Such file already exists\n");
        create_table();
    } else {
        set = fopen(name, "a");
    }
    fclose(set);
}

void create_keys()
{
    char name[20];
    FILE* set;
    printf("Enter file name to create file with keys\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (set != NULL) {
        printf("Such file already exists\n");
        create_keys();
    } else {
        set = fopen(name, "a");
    }
    fclose(set);
}

void create_table_keys()
{
    create_table();
    create_keys();
}

void add_to_table(int k)
{
    char name[20];
    FILE* set;
    char c;
    Data data;
    printf("Enter file name to open file with data\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (!set) {
        printf("such file not exists\n");
        add_to_table(k);
    } else {
        set = fopen(name, "a");
        printf("Enter the data: integer\n");
        for (int i = 0; i < k; i++) {
            scanf("%d", &data.INTEGER);
            fwrite(&data, sizeof(Data), 1, set);
        }
    }
    fclose(set);

}

void add_to_keys(int k)
{
    char name[20];
    FILE* set;
    char c;
    Key key;
    printf("Enter file name to open file with keys\n");
    scanf("%s", name);
    set = fopen(name, "rb");
    if (!set) {
        printf("such file not exists\n");
        add_to_keys(k);
    } else {
        set = fopen(name, "a");
        printf("Enter the key: integer and char\n");
        for (int i = 0; i < k; i++) {
            scanf("%d", &key.INTEGER);
            scanf("%c", &c);
            scanf("%c", &key.CHAR);
            scanf("%c", &c);
            fwrite(&key, sizeof(Key), 1, set);
        }
    }
    fclose(set);
}

void add_to_table_keys()
{
    int k;
    printf("How many records do you want to add to the table ?\n");
    scanf("%d", &k);
    add_to_table(k);
    add_to_keys(k);
}

void print_table_keys()
{
    FILE* t;
    FILE* k;
    Key ke;
    Data te;
    char name[20];
    printf("Enter file with data name\n");
    scanf("%s", name);
    t = fopen(name, "rb");
    if (!t) {
        printf("Such file not exists\n");
    } else {
        printf("Enter file with keys name\n");
        scanf("%s", name);
        k = fopen(name, "rb");
        if (!k) {
            printf("The file not exists\n");
        } else {
            while ((fread(&te, sizeof(Data), 1, t) != EOF && !feof(t)) && (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k))) {
                printf("Key: %4d %c|Data: %4d", ke.INTEGER, ke.CHAR, te.INTEGER);
                printf("\n");
            }
        }
    }
}

void binary_insert_sort()
{
    FILE* t;
    FILE* k;
    Table tab;
    int count = 0;
    Key ke;
    Data te;
    char data_name[20];
    char keys_name[20];
    printf("Enter file with data name\n");
    scanf("%s", data_name);
    t = fopen(data_name, "rb");
    if (!t) {
        printf("Such file not exists\n");
    } else {
        printf("Enter file with keys name\n");
        scanf("%s", keys_name);
        k = fopen(keys_name, "rb");
        if (!k) {
            printf("The file not exists\n");
        } else {
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                count++;
            }
            fclose(k);
            k = fopen(keys_name, "rb");
            tab.node = (Node*)malloc(sizeof(Node) * count);
            int i = 0;
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                tab.node[i].key.INTEGER = ke.INTEGER;
                tab.node[i].key.CHAR = ke.CHAR;
                i++;
            }
            i = 0;
            while (fread(&te, sizeof(Data), 1, t) != EOF && !feof(t)) {
                tab.node[i].data.INTEGER = te.INTEGER;
                i++;
            }
            for (int j = 1; j < count; j++) {
                int l = 0;
                int r = j;
                int x = tab.node[j].key.INTEGER;
                char c  = tab.node[j].key.CHAR;
                int mid;
                while (l < r) {
                    mid = (l + r) / 2;
                    if ((tab.node[mid].key.INTEGER < x) || (tab.node[mid].key.INTEGER == x && tab.node[mid].key.CHAR < c)) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                for (int p = j; p != r; p--) {
                    int tmp = tab.node[p - 1].data.INTEGER;
                    int Int = tab.node[p - 1].key.INTEGER;
                    char d = tab.node[p - 1].key.CHAR;
                    tab.node[p - 1].data.INTEGER = tab.node[p].data.INTEGER;
                    tab.node[p - 1].key.INTEGER = tab.node[p].key.INTEGER;
                    tab.node[p - 1].key.CHAR = tab.node[p].key.CHAR;
                    tab.node[p].data.INTEGER = tmp;
                    tab.node[p].key.INTEGER = Int;
                    tab.node[p].key.CHAR = d;
                }
            }
            t = fopen(data_name, "wb");
            k = fopen(keys_name, "wb");
            for (int g = 0; g < count; g++) {
                fwrite(&tab.node[g].data, sizeof(Data), 1, t);
                fwrite(&tab.node[g].key, sizeof(Key), 1, k);
            }
            fclose(t);
            fclose(k);
        }
    }
}

void binary_search()
{
    FILE* t;
    FILE* k;
    Table tab;
    int count = 0;
    Key ke;
    Data te;
    char data_name[20];
    char keys_name[20];
    printf("Enter file with data name\n");
    scanf("%s", data_name);
    t = fopen(data_name, "rb");
    if (!t) {
        printf("Such file not exists\n");
    } else {
        printf("Enter file with keys name\n");
        scanf("%s", keys_name);
        k = fopen(keys_name, "rb");
        if (!k) {
            printf("The file not exists\n");
        } else {
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                count++;
            }
            fclose(k);
            k = fopen(keys_name, "rb");
            tab.node = (Node*)malloc(sizeof(Node) * count);
            int i = 0;
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                tab.node[i].key.INTEGER = ke.INTEGER;
                tab.node[i].key.CHAR = ke.CHAR;
                i++;
            }
            i = 0;
            while (fread(&te, sizeof(Data), 1, t) != EOF && !feof(t)) {
                tab.node[i].data.INTEGER = te.INTEGER;
                i++;
            }
            int l = 0;
            int r = count;
            int mid;
            int x, d;
            char c;
            char k;
            printf("Enter the key: integer and char\n");
            scanf("%d", &d);
            scanf("%c", &c);
            scanf("%c", &k);
            scanf("%c", &c);
            while (l < r) {
                mid = (l + r) / 2;
                if (tab.node[mid].key.INTEGER == d && tab.node[mid].key.CHAR == k) {
                    printf("Data: %d\n", tab.node[mid].data.INTEGER);
                    break;
                }
                if ((tab.node[mid].key.INTEGER < d) || (tab.node[mid].key.INTEGER == d && tab.node[mid].key.CHAR < k)) {
                        l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
    }
}

void print_table_keys_par(char data_name[20], char keys_name[20])
{
    FILE* t;
    FILE* k;
    Key ke;
    Data te;
    t = fopen(data_name, "rb");
    if (!t) {
        printf("File with data not exists\n");
    } else {
        k = fopen(keys_name, "rb");
        if (!k) {
            printf("File with keys not exists\n");
        } else {
            while ((fread(&te, sizeof(Data), 1, t) != EOF && !feof(t)) && (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k))) {
            printf("Keys: %4d %c|Data: %4d", ke.INTEGER, ke.CHAR, te.INTEGER);
            printf("\n");
        }
        }
    }
}

void binary_insert_sort_par(char data_name[20], char keys_name[20])
{
    FILE* t;
    FILE* k;
    Table tab;
    int count = 0;
    Key ke;
    Data te;
    t = fopen(data_name, "rb");
    if (!t) {
        printf("File with data not exists\n");
    } else {
        k = fopen(keys_name, "rb");
        if (!k) {
            printf("File with keys not exists\n");
        } else {
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                count++;
            }
            fclose(k);
            k = fopen(keys_name, "rb");
            tab.node = (Node*)malloc(sizeof(Node) * count);
            int i = 0;
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                tab.node[i].key.INTEGER = ke.INTEGER;
                tab.node[i].key.CHAR = ke.CHAR;
                i++;
            }
            i = 0;
            while (fread(&te, sizeof(Data), 1, t) != EOF && !feof(t)) {
                tab.node[i].data.INTEGER = te.INTEGER;
                i++;
            }
            for (int j = 1; j < count; j++) {
                int l = 0;
                int r = j;
                int x = tab.node[j].key.INTEGER;
                char c  = tab.node[j].key.CHAR;
                int mid;
                while (l < r) {
                    mid = (l + r) / 2;
                    if ((tab.node[mid].key.INTEGER < x) || (tab.node[mid].key.INTEGER == x && tab.node[mid].key.CHAR < c)) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                for (int p = j; p != r; p--) {
                    int tmp = tab.node[p - 1].data.INTEGER;
                    int Int = tab.node[p - 1].key.INTEGER;
                    char d = tab.node[p - 1].key.CHAR;
                    tab.node[p - 1].data.INTEGER = tab.node[p].data.INTEGER;
                    tab.node[p - 1].key.INTEGER = tab.node[p].key.INTEGER;
                    tab.node[p - 1].key.CHAR = tab.node[p].key.CHAR;
                    tab.node[p].data.INTEGER = tmp;
                    tab.node[p].key.INTEGER = Int;
                    tab.node[p].key.CHAR = d;
                }
            }
            t = fopen(data_name, "wb");
            k = fopen(keys_name, "wb");
            for (int g = 0; g < count; g++) {
                fwrite(&tab.node[g].data, sizeof(Data), 1, t);
                fwrite(&tab.node[g].key, sizeof(Key), 1, k);
            }
            fclose(t);
            fclose(k);
        }
    }
}

void binary_search_par(char data_name[20], char keys_name[20], int counter)
{
    FILE* t;
    FILE* k;
    Table tab;
    int count = 0;
    Key ke;
    Data te;
    t = fopen(data_name, "rb");
    if (!t) {
        printf("File with data not exists\n");
    } else {
        k = fopen(keys_name, "rb");
        if (!k) {
            printf("File with keys not exists\n");
        } else {
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                count++;
            }
            fclose(k);
            k = fopen(keys_name, "rb");
            tab.node = (Node*)malloc(sizeof(Node) * count);
            int i = 0;
            while (fread(&ke, sizeof(Key), 1, k) != EOF && !feof(k)) {
                tab.node[i].key.INTEGER = ke.INTEGER;
                tab.node[i].key.CHAR = ke.CHAR;
                i++;
            }
            i = 0;
            while (fread(&te, sizeof(Data), 1, t) != EOF && !feof(t)) {
                tab.node[i].data.INTEGER = te.INTEGER;
                i++;
            }
            for (int i = 0; i < counter; i++) {
                int l = 0;
                int r = count;
                int mid;
                int x, d;
                char c;
                char k;
                printf("Enter the key: integer and char\n");
                scanf("%d", &d);
                scanf("%c", &c);
                scanf("%c", &k);
                scanf("%c", &c);
                while (l < r) {
                    mid = (l + r) / 2;
                    if (tab.node[mid].key.INTEGER == d && tab.node[mid].key.CHAR == k) {
                        printf("Data: %d\n", tab.node[mid].data.INTEGER);
                        break;
                    }
                    if ((tab.node[mid].key.INTEGER < d) || (tab.node[mid].key.INTEGER == d && tab.node[mid].key.CHAR < k)) {
                            l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
            }
        }
    }
}

void task()
{
    char data_name[20];
    char keys_name[20];
    int a;
    printf("Enter file with data:\n");
    scanf("%s", data_name);
    printf("Enter file with keys:\n");
    scanf("%s", keys_name);
    printf("The table before sorting\n");
    print_table_keys_par(data_name, keys_name);
    binary_insert_sort_par(data_name, keys_name);
    printf("\n");
    printf("The table after sorting\n");
    print_table_keys_par(data_name, keys_name);
    printf("Enter the count of keys to search data in the table:\n");
    scanf("%d", &a);
    binary_search_par(data_name, keys_name, a);
}
