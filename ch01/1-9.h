#include <stdio.h>

/**
 * 字符数组
 */
int getLine(char s[], int lim);

void copy(char to[], char from[]);

int trim(char s[]);
void reverse(char s[]);

int getLine(char s[], int lim) {
    int i;
    char c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

int trim(char s[]) {
    int i;

    i = 0;

    // 找出 \n 位置
    while (s[i] != '\n') {
        ++i;
    }

    // 倒退一格 到 \n 前面
    --i;

    // 找出最后一个非空格或制表符位置
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }

    // 补上 \n \0
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }

    return i;
}

void reverse(char s[]) {
    int i, j;
    char temp;

    i = j = 0;

    // 找出 \n 位置
    while (s[i] != '\n') {
        ++i;
    }

    // 倒退一格 到 \n 前面
    --i;

    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        ++j;
        --i;
    }
}

#define MAX_LINE 1000

void call() {
    char line[MAX_LINE]; // 当前读取的行
    int len; // 当前行的长度

    char longest[MAX_LINE]; // 最长的行
    int max; // 最长的行的长度

    max = 0;

    while ((len = getLine(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("longest - %d - %s", max, longest);
    } else {
        printf("no line input");
    }

}

/**
 * 练习 1.16
 * 修改打印最长文本行的程序的主程序 main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本
 */
void printLen() {
    char line[MAX_LINE]; // 当前读取的行
    int len; // 当前行的长度

    char longest[MAX_LINE]; // 最长的行
    int max; // 最长的行的长度

    max = 0;

    while ((len = getLine(line, MAX_LINE)) > 0) {
        printf("%d - %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("longest - %d - %s", max, longest);
    } else {
        printf("no line input");
    }
}

/**
 * 练习 1.17
 * 编写一个程序，打印长度大于 80 个字符的所有输入行
 */
#define LONG_LINE 10

void printGreaterThan() {
    char line[MAX_LINE]; // 当前读取的行
    int len; // 当前行的长度

    while ((len = getLine(line, MAX_LINE)) > 0) {
        if (len > LONG_LINE) {
            printf("%d - %s", len, line);
        }
    }
}

/**
 * 练习 1.18
 * 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行
 */
void printTrim() {
    char line[MAX_LINE]; // 当前读取的行
    int len; // 当前行的长度

    while (getLine(line, MAX_LINE) > 0) {
        len = trim(line);

        if (trim(line) > 0) {
            printf("%d - %s", len, line);
        }
    }
}

/**
 * 练习 1.19
 * 编写函数 reverse(s) ，将字符串 s 中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。
 */
 void printReverse() {
    char line[MAX_LINE]; // 当前读取的行
    int len; // 当前行的长度

    while ((len = getLine(line, MAX_LINE)) > 0) {
        reverse(line);
        printf("%d - %s", len, line);
    }
 }

