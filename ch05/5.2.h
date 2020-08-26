#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/**
 *
 */
#define SIZE 5
void test(){
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++){
        printf("%d\n", array[n]);
    }
}

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, sign;

    c = getch();
    while (isspace(c))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-'){
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;
    if (c != EOF){
        ungetch(c);
    }
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}


/**
 * 练习5-1在上面的例子中，如果符号+或-的后面紧跟的不是数字，getint函数将把符号视为数字0的有效表达方式。修改该函数，将这种形式的+或-符号重新写回到输入流中。
 * TODO
 */

/**
 * 练习5-2模仿函数getint的实现方法，编写一个读取浮点数的函数getfloat。getfloat函数的返回值应该是什么类型？
 * TODO
 */