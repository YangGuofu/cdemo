#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define FOREVER for(int i = 0; i < 10; i++)
#define MAX(A, B) (A > B) ? A : B
#define SQUARE(X) X * X

#define printf(x) x
#undef printf

#define dprint(expr) printf(#expr " = %g\n", expr)

#define PASTE(FRONT, BACK) FRONT ## BACK

/**
 * 练习4-14定义宏swap(t,x,y)以交换t类型的两个参数。（使用程序块结构会对你有所帮助。）
 */
#define swap(t,x,y) { \
    t _z; \
    _z = y; \
    y = x; \
    x = _z; \
}

#if !defined(HDR)
#define HDR hdr
#endif

#ifndef HDR
#define HRD hdr
#endif

/**
 *
 */
void test(){
    FOREVER{
        printf("%d", i);
    };
    printf("\n");

    printf("%d\n", MAX(3, 5));

    // x + 1 * x + 1
    int x = 3;
    printf("%d\n", SQUARE(x+1));

    dprint(3.0 / 2.0);


    char ab[] = "ab";
    char a[] = "a";
    char b[] = "b";
    printf("%s\n", PASTE(a, b));

    int swapx = 'x';
    int swapy = 'y';
    swap(int, swapx, swapy);
    printf("%c%c", swapx, swapy);

}