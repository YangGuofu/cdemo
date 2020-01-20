#include <stdio.h>\

/**
 * 将输入输出
 */
void copyInputToOutput() {
    int c;
    c = getchar();

    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

/**
 * 将输入输出
 * 紧凑风格
 */
void copyInputToOutputCompact() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

/**
 * 练习 1-6
 * 验证表达式 getchar() != EOF 的值是 0 还是 1。
 */
void checkGetcharNotEqualEOF() {
    int c;

    c = getchar() != EOF;

    while (c) {
        printf("%d\n", c);
        c = getchar() != EOF;
    }
}

/**
 * 练习 1-7
 * 编写一个打印 EOF 值的程序
 */
void printEOF() {
    printf("EOF is %d\n", EOF);
}

/**
 * 字符计数
 */
void countInput() {
    long length;

    length = 0;

    while (getchar() != EOF) {
        ++length;
    }
    printf("%ld\n", length);
}

/**
 * 行计数
 */
void countLine() {
    int c;
    long length;

    length = 0;

    while ( (c = getchar()) != EOF) {
        if (c == '\n') {
            ++length;
        }
    }
    printf("%ld\n", length);
}

/**
 * 练习 1-8
 * 编写一个统计空格、制表符与换行符个数的程序。
 */
void countSpaceTapAndLine() {
    int c, nl, nt, nb;

    nl = nt = nb = 0;

    while ( (c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        } else if (c == '\t'){
            ++nt;
        } else if (c == ' ') {
            ++nb;
        }
    }
    printf("line - %d\nblank - %d\ntab - %d\n", nl, nb, nt);
}

/**
 * 练习 1-9
 * 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替。
 */
#define NON_BLANK 'a'
void copyInputToOutputReplaceBlank() {
    int c, lastChar;

    lastChar = NON_BLANK;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else {
            if (lastChar != ' ') {
                putchar(c);
            }
        }
        lastChar = c;
    }
}

/**
 * 练习 1-9
 * 编写一个将输入复制到输出的程序，并将其中的制表符替换为 \t，把回退符替换为 \b，把反斜杠替换为 \\。这样可以将制表符和回退符以可见的方式显示出来。
 */
void copyInputToOutputShowEscape() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t'){
            printf("\\t");
        } else if (c == '\b'){
            printf("\\b");
        } else if (c == '\\'){
            printf("\\\\");
        } else {
            printf("%c", c);
        }
    }
}

/**
 * 单词计数
 * 统计行数、单词数与字符数
 */
#define IN 1 // 在单词中
#define OUT 0 // 不在单词中
void countWord() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n'){
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("line - %d\nword - %d\nchar - %d\n", nl, nw, nc);
}

/**
 * 练习 1-12
 * 编写一个程序，以每行一个单词的形式打印其输入。
 */
#define IN 1 // 在单词中
#define OUT 0 // 不在单词中
void wordNewLine() {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            if (state == IN) {
                putchar('\n');
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        } else {
            putchar(c);
        }
    }
}