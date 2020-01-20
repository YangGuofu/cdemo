#include <stdio.h>

/**
 * 外部变量 extern
 */
#define MAX_LINE 1000

extern char _longest[MAX_LINE]; // 最长的行
extern char _line[MAX_LINE]; // 当前读取的行
extern int _max;

int getLine(int lim);
void copy();

void call() {
    int len; // 当前行的长度

    char _longest[MAX_LINE]; // 最长的行
    int _max; // 最长的行的长度

    _max = 0;

    while ((len = getLine(MAX_LINE)) > 0) {
        if (len > _max) {
            _max = len;
            copy();
        }
    }

    if (_max > 0) {
        printf("longest - %d - %s", _max, _longest);
    } else {
        printf("no line input");
    }

}

int getLine(int lim) {
    char _line[MAX_LINE]; // 当前读取的行
    int i;
    char c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        _line[i] = c;
    }
    if (c == '\n') {
        _line[i] = c;
        i++;
    }
    _line[i] = '\0';

    return i;
}

void copy() {
    char _line[MAX_LINE]; // 当前读取的行
    char _longest[MAX_LINE]; // 当前读取的行
    int i;

    i = 0;

    while ((_longest[i] = _line[i]) != '\0') {
        ++i;
    }
}

/**
 * 练习 1.20
 * 编写程序 detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定的，比如每隔 n 列就会出现一个制表符终止位。n 应该作为变量还是符号常量呢？
 */
#define TAB_INC 4
void detab() {
    int c, nb;

    nb = TAB_INC; // 到下个 tab 还需要多少个空格
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            while (nb > 0) {
                --nb;
                putchar('_');
            }
        } else if (c == '\n') {
            nb = TAB_INC;
            putchar(c);
        } else {
            --nb;
            putchar(c);
        }
        if (nb == 0) {
            nb = TAB_INC;
        }
    }
}

/**
 * 练习 1.21
 * 编写程序 entab，将空格串替换为最少数量的制表符和空格，但要保持单词间的间隔不变。假设制表符终止位的位置与练习 1.20 的 detab 程序的情况相同。当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪一种替换字符比较好？
 */
void entab() {
    int c, nb, nt, pos;

    nb = 0;
    nt = 0;

    for (pos = 1; (c = getchar() != EOF) ; ++pos) {
        if (c == ' ') {
            if (pos % TAB_INC == 0) {
                nb = 0;
                ++nt;
            } else {
                ++nb;
            }
        } else {
            while (nt > 0) {
                putchar('_');
                --nt;
            }
            if (c == '\t') {
                nb = 0;
            } else {
                while (nb > 0) {
                    putchar(' ');
                    --nb;
                }
            }
            //putchar(c);
            printf("%d", c);

            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                pos = pos + (TAB_INC - (pos - 1) % TAB_INC) - 1;
            }
        }
    }
}


/**
 * 练习 1.22
 * 编写一个程序，把较长的输入“折”成短一些的两行或多行，折行的位置在输入行的第 n 列之前的最后一个非空格之后。要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或制表符时的情况。
 */
#define MAX_COL 10
char line[MAX_COL];

void wrap() {
    int c, pos;
    pos = 0;

    while ((c = getchar()) != EOF) {
        ++pos;
        line[pos] = c;
        if (c == '\t') {

        } else if (c == '\n') {

        } else {

        }
    }
}

int expandTab(int pos) {

}

/**
 * 练习 1.23
 * 编写一个删除 C 语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在 C 语言中，注释不允许嵌套。
 */

/**
 * 练习 1.24
 * 编写一个程序，查找 C 语言程序中的基本语法错误，如圆括号、方括号、花括号不配对等。要正确处理引号（包括单引号和双引号）、转义字符序列与注释。
 */
