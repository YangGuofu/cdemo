#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void itoa2(long n, char s[]);
void itoa3(long n, char s[]);
void itob(long n, char s[], int b);
void itoa4(long n, char s[], int w);

void test() {
    char s1[20];
    itoa3(-123, s1);
    printf("%s\n", s1);

    char s2[20];
    itoa3(-pow(2, 31), s2);
    printf("%s\n", s2);

    char s3[20];
    itob(66, s3, 8);
    printf("%s\n", s3);

    char s4[20];
    itoa4(123, s4, 5);
    printf("%s\n", s4);
}

/**
 * itoa 函数是 atoi 函数的逆函数，它把数字转换为字符串。
 */
void itoa2(long int n, char s[]){
    int i, sign;
    i = 0;

    sign = n > 0 ? 1 : -1;
    if (n < 0){
        n = -n;
    }

    do {
        s[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    strrev(s);
}


/**
 * 练习3-4在数的对二的补码表示中,我们编写的itoa函数不能处理最大的负数,即n等于-2的情况。
 * 请解释其原因。修改该函数,使它在任何机器上运行时都能打印出正确的值。
 *
 * 原因：n = -n 溢出
 */

void itoa3(long int n, char s[]){
    int i, sign;
    i = 0;

    sign = n > 0 ? 1 : -1;
    do {
        s[i++] = abs(n % 10) + '0';
        n /= 10;
    } while (n != 0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';

    strrev(s);
}

/**
 * 练习3-5 编写函数itob(n,s,b),将整数n转换为以b为底的数,并将转换结果以字符的形式保存到字符串s中。
 * 例如,itob(n,s,16)把整数n格式化成十六进制整数保存在s中。
 */
void itob(long n, char s[], int b){
    int i, j, sign;
    i = 0;

    sign = n > 0 ? 1 : -1;
    if (n < 0){
        n = -n;
    }

    do {
        j = n % b;
        s[i++] = j <= 9 ? j + '0' : j - 10 + 'a';
        n /= b;
    } while (n > 0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    strrev(s);
}

/**
 * 练习3-6 修改itoa函数,使得该函数可以接收三个参数。其中,第三个参数为最小字段宽度。
 * 为了保证转换后所得的结果至少具有第三个参数指定的最小宽度,在必要时应在所得结果的左边填充一定的空格。
 */
void itoa4(long int n, char s[], int w){
    int i, sign;
    i = 0;

    sign = n > 0 ? 1 : -1;
    do {
        s[i++] = abs(n % 10) + '0';
        n /= 10;
    } while (n != 0);

    if (sign < 0){
        s[i++] = '-';
    }
    // 填充空格
    while (i < w){
        s[i++] = ' ';
    }
    s[i] = '\0';
    strrev(s);
}