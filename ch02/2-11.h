#include <stdio.h>
#include <limits.h>

void test29();
unsigned printarray(char a[]);
unsigned bitcount2(unsigned x);

void test211() {
    printf("%d\n", bitcount2(170));
    char a[] = "123456789123456789123456789123";
    printarray(a);
}


/**
 * 函数 bitcount统计其整型参数的值为1的二进制位的个数
 */
unsigned printarray(char a[]){
    int i;
    int n = 30;

    for (i = 0; i < n; i++) {
        printf("%c%c", a[i], i%9==8 || i==n-1 ? '\n' : ' ');
    }
}

/**
 * 练习2-10 重新编写将大写字母转换为小写字母的函数lower,并用条件表达式替代其中的if-ese结构。
 */
int lower(int c){
    return c >= 'A' & c <= 'Z' ? c + 'a' - 'A' : c;
}
