#include <stdio.h>
#include <ctype.h>

/**
 * 数组
 * 统计各个数字、空白符出现的次数
 */
void countDigitAndWhiteSpace() {
    int c, i, nWhite, nOther, nDigit[10];
    nWhite = nOther = 0;

    for (i = 0; i < 10; ++i) {
        nDigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++nDigit[c - '0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nWhite;
        } else {
            ++nOther;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", nDigit[i]);
    }
    printf(", white space = %d, other = %d\n", nWhite, nOther);
}


/**
 * 练习 1-13
 * 编写一个程序，打印输入中单词长度的直方图。
 */
#define IN 1 // 在单词中
#define OUT 0 // 不在单词中
#define MAX_WORD 20 // 最长单词
void printWordLength() {
    int c, i, state, nc, len, wl[MAX_WORD];

    state = OUT;
    nc = 0;

    for (i = 0; i < MAX_WORD; ++i) {
        wl[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            if (state == IN) {
                ++wl[nc];
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        } else {
            ++nc;
        }
    }

    for (i = 1; i < MAX_WORD; ++i) {
        printf("%2d - %2d : ", i, wl[i]);
        len = wl[i];
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
}

/**
 * 练习 1-14
 * 编写一个程序，打印输入中各个字符出现频度的直方图
 */
#define MAX_CHAR 128
void printCharHz() {
    int c, i, len, charHz[MAX_CHAR];

    for (i = 0; i < MAX_CHAR; ++i) {
        charHz[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c < MAX_CHAR) {
            ++charHz[c];
        }
    }

    for (i = 1; i < MAX_CHAR; ++i) {
        if (isprint(i)){
            printf("%3d( %c ) - %4d : ", i, i, charHz[i]);
        } else {
            printf("%3d(   ) - %4d : ", i, charHz[i]);
        }

        len = charHz[i];
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
}