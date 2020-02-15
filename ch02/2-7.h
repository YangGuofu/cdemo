#include <stdio.h>
#include <limits.h>

/**
 * 练习 2.3
 * 编写函数htoi(s),把由十六进制数字组成的字符串(包含可选的前缀0x或0x)转换为与之等价的整型值。字符串中允许包含的数字包括:0~9、a~f以及A~F
 */
enum BOOL {NO, YES};
int htoi(char s[]);

void testhtoi() {
    printf("%d", htoi("0x16"));
}

int htoi(char s[]) {
    int hexdigit, i, inhex, n;

    /* 包含可选的前缀0x或0x) */
    i = 0;
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X') {
            ++i;
        }
    }

    n = 0;
    hexdigit = 0;
    inhex = YES;
    for ( ; inhex == YES ; ++i) {
        if (s[i] >= '0' && s[i] <= '9'){
            hexdigit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f'){
            hexdigit = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F'){
            hexdigit = s[i] - 'A' + 10;
        } else {
            inhex = NO;
        }

        if (inhex == YES){
            n = 16 * n + hexdigit;
        }
    }

    return n;
}


int atoi2(char s[]){
    int i,n;

    n = 0;

    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++){
        n = 10 * n + (s[i] - '0');
    }

    return n;
}

