#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/**
 * 1. register 声明只适用于自动变量以及函数的形参
 * 2.
 */
void f(unsigned m, long n);
void test(){
    unsigned m = 0;
    long n = 0;
    f(m, n);
}


void f(register unsigned m, register long n){
    register int i;

    i = 1;
    printf("%d", i);

}