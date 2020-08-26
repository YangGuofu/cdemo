#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXLINE 1000

int mygetline(char s[], int lim){
    int c, i;

    i = 0;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }

    if (c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

void find(int argc, char *argv[]) {
    printf("%d\n", argc);

    int except = 0, number = 0, found = 0;
    char c;
    long lineno = 0;
    char line[MAXLINE];

    while (--argc > 0 && (*++argv)[0] == '-'){
        while (c = *++argv[0]){
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (mygetline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number){
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
        }

    printf("%d\n", found);
}

#define MAXVAL 100
#define NUMBER '0'

int getop(char []);
void ungets(char s[]);
double pop(void);
void push(double f);

/**
 * 练习5-10编写程序expr,以计算从命令行输入的逆波兰表达式的值，其中每个运算符或操作数用一个单独的参数表示。
 * 例如，命令 （expr 2 3 4 + *） 将计算表达式 2×(3+4) 的值。
 *
 */
//void expr(int argc, char *argv[]){
//    char s[MAXVAL];
//    double op2;
//    char c;
//    while (--argc > 0){
//        ungets(" ");
//        ungets(*++argv);
//        switch (getop(s)){
//            case NUMBER:
//                push(atof(s));
//                break;
//            case '+':
//                push(pop() + pop());
//                break;
//            case '-':
//                op2 = pop();
//                push(pop() - op2);
//                break;
//            case '*':
//                push(pop() * pop());
//                break;
//            case '/':
//                op2 = pop();
//                if (op2 != 0.0){
//                    push(pop() / op2);
//                } else {
//                    printf("error");
//                }
//
//                break;
//            default:
//                printf("opt error");
//                break;
//        }
//    }
//    printf("\t%.8g\n", pop());
//}
#define LINES 100
void tail(int argc, char *argv[]){
    char line[MAXLINE];
    char *lineptr[LINES];
    int last = 0;

    while (mygetline(line, MAXLINE) > 0){
        printf("%s\n", line);
        strcpy(lineptr[last], line);
        last++;
    }

    /*while (--last > 0){
        printf("%d\n", last);
        printf("%s\n", lineptr[last]);
    }*/

}

void test(int argc, char *argv[]) {
    tail(argc, argv);
}




