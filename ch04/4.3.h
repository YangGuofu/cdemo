#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

int getop(char []);
void push(double);
double pop(void);
void clear();

/**
 * 练习4-3 在有了基本框架后,对计算器程序进行扩充就比较简单了。在该程序中加入取模(号)运算符,并注意考虑负数的情况
 */
/**
 * 练习4-4 在栈操作中添加几个命令,分别用于在不弹出元素的情况下打印栈顶元素复制栈顶元素;交换栈顶两个元素的值。另外增加一个命令用于清空栈。
 */
/**
 * 练习4-5 给计算器程序增加访问sin、exp与pow等库函数的操作。有关这些库函数的详细信息,参见附录B4节中的头文件<math.h>
 */
void test() {
    int i, type, var = 0;
    double op1, op2, v;
    char s[MAXOP];

    double variable[26];
    for (i = 0; i < 26; ++i) {
        variable[i] = 0.0;
    }

    while ((type = getop(s)) != EOF){
        printf("type is %c\n", type);
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                printf("get name %s\n", s);
                if (strcmp(s, "sin") == 0){
                    push(sin(pop()));
                } else if (strcmp(s, "cos") == 0){
                    push(cos(pop()));
                } else if (strcmp(s, "exp") == 0){
                    push(exp(pop()));
                } else if (strcmp(s, "pow") == 0){
                    op2 = pop();
                    printf("op2 is %lg \n", op2);
                    push(pow(pop(), op2));
                } else {
                    printf("error: %s not supported\n", s);
                }
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0){
                    push(pop() / op2);
                } else {
                    printf("erro: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0){
                    push(fmod(pop(), op2));
                } else {
                    printf("erro: zero divisor\n");
                }
                break;
            case '?': // 打印栈顶元素
                op2 = pop();
                printf("top is %.8g\n", op2);
                push(op2);
                break;
            case 'd': // 复制栈顶元素
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's': // 交换栈顶两个元素
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c': // 清空栈
                clear();
                break;
            case '=':
                pop();
                variable[var - 'A'] = pop();
                break;
            case '\n':
                v = pop();
                printf("result is %.8g\n", v);
                break;
            default:
                printf("type is %c\n", type);
                if (type >= 'A' && type <= 'Z'){
                    push(variable[type - 'A']);
                } else if (type == 'v'){
                    push(v);
                } else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        var = type;
    }
}


#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
    } else {
        printf("error: stack full, cant push %g\n", f);
    }
}

double pop(){
    if (sp > 0){
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(){
    sp = 0;
}


char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]){
    int len = strlen(s);

    while (len > 0){
        ungetch(s[--len]);
    }
}

int getop(char s[]){
    int i, c;

    // 处理空格
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;

    // 处理小写字母
    if (islower(c)){
        printf("islower %c\n", c);
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF){
            ungetch(c);
        }
        printf("strlen %d\n", strlen(s));
        printf("islower %c\n", c);
        if (strlen(s) > 1){
            return NAME;
        }else {
            return c;
        }
    }

    // 处理非 数字、小数点、减号
    if (!isdigit(c) && c != '.' && c != '-'){
        return c;
    }

    // 处理减号 负或者减号
    if (c == '-'){
        if (isdigit(c = getch()) || c == '.'){
            s[++i] = c;
        } else {
            if (c != EOF){
                ungetch(c);
            }
            return '-';
        }
    }

    if (isdigit(c)){
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.'){
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';

    if (c != EOF){
        ungetch(c);
    }

    return NUMBER;
}

