#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void printd(int n);
void quicksort(int v[], int left, int right);
void itoa2(int n, char s[]);
void reverse(char s[]);

void test(){
    char s1[20];
    itoa2(123, s1);
    printf("%s\n", s1);

    char s2[] = "hello";
    reverse(s2);
    printf("%s\n", s2);
}

/**
 * 函数printd首先调用它自身打印前面的（高位）数字，然后再打印后面的数字。这里编写的函数不能处理最大的负数。
 * @param n
 */
void printd(int n){
    if (n < 0){
        n = -n;
        putchar('-');
    }

    if (n / 10){
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}


void quicksort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last-1);
    quicksort(v, last+1, right);
}

void swap(int v[], int i, int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/**
 * 练习4-12运用printd函数的设计思想编写一个递归版本的itoa函数，即通过递归调用把整数转换为字符串。
 */
void itoa2(int n, char s[]){
    static int i = 0;
    if (n < 0){
        n = -n;
        s[i++] = '-';
    }

    if (n / 10){
        itoa2(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

/**
 * 练习4-13编写一个递归版本的reverse(s)函数，以将字符串s倒置。
 */
void reverse(char s[]){
    void reverserecursive(char s[], int i, int len);

    reverserecursive(s, 0, strlen(s));
}

void reverserecursive(char s[], int i, int len){
    int c, j;

    j = len - i - 1;
    if (i < j){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverserecursive(s, ++i, len);
    }
}