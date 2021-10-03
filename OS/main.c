#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void Reverse(char name[])
{
    char tmp;
    int len = strlen(name);
    for(int i = 0; i < len; i++)
    {
        tmp = name[len - 1];
        name[len - 1] = name[i];
        name[i] = tmp;
        len--;
    }
}

int main()
{
    char name[100];
    int fd1[2];
    int fd2[2];
    scanf("%s", name);
    int f1 = open(name, O_RDWR | O_CREAT, 0777);
    scanf("%s", name);
    int f2 = open(name, O_RDWR | O_CREAT, 0777);

    if (f1 < 0 || f2 < 0) {
        printf("Error during opening one of the files\n");
        exit(1);
    }
    if (pipe(fd1) == -1) {
        printf("Error with creating pipe\n");
        exit(2);
    }
    if (pipe(fd2) == -1) {
        printf("Error with creating pipe\n");
        exit(2);
    }
    pid_t p1 = fork();
    if (p1 == -1) {
        printf("Error with fork(); call\n");
        exit(3);
    } 
    if (p1 == 0) {
        pid_t p2 = fork();
        if (p2 == -1) {
            printf("Error with fork(); call");
            exit(3);
        }
        if (p2 == 0) {
            while(1) {
                int m1; 
                char string1[m1];
                read(fd2[0], &m1, sizeof(int));
                read(fd2[0], string1, sizeof(char) * m1);
                string1[m1] = '\0';
                printf("%s 2!\n", string1);
                Reverse(string1);
                write(f1, string1, sizeof(char) * m1);
                write(f1, "\n", sizeof(char));
            }
        } else {
            while(1) {
                int m2;
                char string2[m2];
                read(fd1[0], &m2, sizeof(int));
                read(fd1[0], string2, sizeof(char) * m2);
                string2[m2] = '\0';
                printf("%s 1!\n", string2);
                Reverse(string2);
                write(f2, string2, sizeof(char) * m2);
                write(f2, "\n", sizeof(char));
            }
        }
    } else {
        while (1) {
            char string[100];
            scanf("%s", string);
            int n = strlen(string);
            if (strlen(string) > 10) {
                int n1 = strlen(string);
                write(fd2[1], &n1, sizeof(int));
                write(fd2[1], string, sizeof(char) * n);
            } else {
                int n2 = strlen(string);
                write(fd1[1], &n2, sizeof(int));
                write(fd1[1], string, sizeof(char) * n);
            }
        }
        close(fd1[0]); close(fd2[0]);
        close(fd1[1]); close(fd2[1]);
        close(f1); close(f2);
    }
    return 0;
}
