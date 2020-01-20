#include <stdio.h>
#include <limits.h>

/**
 * 练习 2.2
 * 在不使用运算符 && 或 || 的条件下编写一个与上面的 for 循环语句等价的循环语句。
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c
 */
int strlen2(char s[]);

enum LOOP { NO, YES };
enum LOOP okloop = YES;

void change() {
    while (okloop){
        if (i<lim-1){
            okloop = NO;
        } else if ((c = getchar()) != '\n'){
            okloop = NO;
        } else if (c != EOF){
            okloop = NO;
        } else {
            s[i] = c;
            ++i;
        }
    }
}

