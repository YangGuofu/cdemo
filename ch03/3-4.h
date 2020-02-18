#include <stdio.h>
#include <limits.h>

void test34();
void countDigitAndWhiteSpace();
void escape();
void unescape();

void test34() {
    char s[20];

    char t[] = "dddqdq\tffwe\ne\n";
    escape(s, t);
    printf("%s\n", s);
    unescape(s, t);
    printf("%s\n", s);
    printf("%s\n", t);
}

/**
 * 数组
 * 统计各个数字、空白符出现的次数 switch版本
 */
void countDigitAndWhiteSpace() {
    int c, i, nWhite, nOther, nDigit[10];
    nWhite = nOther = 0;

    for (i = 0; i < 10; ++i) {
        nDigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        switch (c){
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ++nDigit[c - '0'];
                break;
            case ' ':
            case '\t':
            case '\n':
                ++nWhite;
                break;
            default:
                ++nOther;
                break;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", nDigit[i]);
    }
    printf(", white space = %d, other = %d\n", nWhite, nOther);
}

void escape(char s[], char t[]){
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]){
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] != '\\'){
            s[j++] = t[i];
        } else {
            switch (t[++i]){
                case 'n':
                    s[j++] = '\n';
                    break;
                case '\t':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        }

    }
    s[j] = '\0';
}