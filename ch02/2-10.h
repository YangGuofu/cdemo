#include <stdio.h>
#include <limits.h>

void test29();
unsigned bitcount(unsigned x);
unsigned bitcount2(unsigned x);

void test210() {
    printf("%d\n", bitcount(170));
    printf("%d\n", bitcount2(170));


}


/**
 * 函数 bitcount统计其整型参数的值为1的二进制位的个数
 */
unsigned bitcount(unsigned x){
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01){
            b++;
        }
    }
    return b;
}

/**
 * 练习2.9 在求对二的补码时,表达式x&=(x-1)可以删除x中最右边值为1的个二进制位。请解释这样做的道理。用这一方法重写 bitcount函数,以加快其执行速度。
 */
unsigned bitcount2(unsigned x){
    int b;

    for (b = 0; x != 0; x &= x - 1) {
        b++;
    }
    return b;
}
