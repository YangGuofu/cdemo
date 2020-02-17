#include <stdio.h>
#include <limits.h>

void test29();
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned rightrot2(unsigned x, int n);
unsigned rightrot3(unsigned x, int n);
int wordlength(void);

void test29() {
    printf("%d\n", getbits(0xef, 4, 3));
    printf("%d\n", setbits(239, 4, 3, 170));
    printf("%d\n", invert(170, 4, 3));
    unsigned x = 170;
    printf("%d\n", rightrot(x, 135));
    printf("%d\n", rightrot2(x, 135));
    printf("%d\n", rightrot3(x, 135));

}


/**
 * 函数 gerrits(x,p,n),它返回x中从右边数第p位开始向右数n位的字段。这里假定最右边的一位是第0位,n与p都是合理的正值。例如, gethits(x,4,3)返回x中第4、3、2三位的值
 *
 * 将 11101111 从右边数第4位的后3移到最右边 11101111 -> 00111011 (x >> (p - n + 1))
 * 将 00111011 除后n位外置0 00111011和屏蔽码相与 00111011&00000111 = 00000011
 * 屏蔽码 00000111 = ~11111000 = ~(11111111 << 3) = ~(~0 << 3)
 */
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p - n + 1)) & ~(~0 << n);
}

/**
 * 练习2-6 编写一个函数 setbits(x,p,n,y),该函数返回对x执行下列操作后的结果值:将x中从第p位开始的n个(二进制)位设置为y中最右边n位的值,x的其余各位保持不变。
 * @return
 */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // 11101111    10101010   1110 1011
    // 4 3
    unsigned xmask = ~(~0 << n) << (p - n + 1);
    unsigned ymask = ~(~0 << n);
    return (x & ~xmask) | (y & ymask << (p - n + 1)); // y先屏蔽再左移
}

/**
 * 练习2-7 编写一个函数 invert(x,p,n),该函数返回对x执行下列操作后的结果值:将x中从第p位开始的n个(二进制)位求反(即,1变成0,0变成1),x的其余各位保持不变。
 * @return
 */
unsigned invert(unsigned x, int p, int n){
    // 1010 1010 4 3     10110110
    // 1010 1010 ^ 0001 1100
    return x ^ (~(~0 << n) << (p - n + 1));
}

/**
 * 练习2-8 编写一个函数 rightrot(x,n),该函数返回将x循环右移(即从最右端移出的位将从最左端移入)n(二进制)位后所得到的值。
 * @return
 */
unsigned rightrot(unsigned x, int n){
    // 1010 1010  3   01010101
    // 000x xxxx
    // xxx0 0000    1110 0000 & xxxx xxxx
    // 1110 0000   0000 0111
    int rbit;
    while (n-- > 0){
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }

    return x;
}

unsigned rightrot2(unsigned x, int n){
    n = n % wordlength();
    return (x >> n) | ((x & (~(~0 << n))) << (wordlength() - n));
}

unsigned rightrot3(unsigned x, int n){
    n = n % wordlength();
    return (x >> n) | (x << (wordlength() - n));
}

int wordlength(void){
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 0; v > 0; i++) {
        v = v >> 1;
    }
    return i;
}