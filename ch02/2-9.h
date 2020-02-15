#include <stdio.h>
#include <limits.h>

void testgetbits();
unsigned getbits(unsigned x, int p, int n);

void testgetbits() {
    printf("%d", getbits(0xef, 4, 3));
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

