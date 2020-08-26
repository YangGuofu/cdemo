#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

int mystrlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

void test(){
    int *pa;
    int *pa1;
    int x;
    int a[SIZE];
    char arr[100];
    char start = 'a';

    for (int i = 0; i < SIZE; ++i) {
        a[i] = start;
        start++;
    }

    for (int i = 0; i < SIZE; ++i) {
        printf("%c", a[i]);
    }
    printf("\n");

    pa = a;
    x = *pa;

    printf("%c\n", x);
    printf("%c\n", *pa);
    printf("%d\n", mystrlen(arr));

}

