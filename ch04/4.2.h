#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double atof2(char s[]);
double atof3(char s[]);

void test() {
    char s1[] = "123456.78";
    char s2[] = "123456.78e2";
    char s3[] = "123456.78e-2";
    printf("%f\n", atof2(s1));
    printf("%f\n", atof3(s2));
    printf("%f\n", atof3(s3));
}


double atof2(char s[]){
    double val, power;
    int i, sign;

    // 过滤空格
    for (i = 0; isspace(s[i]); i++)
        ;

    // 过滤符号
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+'){
        i++;
    }

    // 处理整数
    for (val = 0.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
    }

    // 处理小数点
    if (s[i] == '.'){
        i++;
    }

    // 处理小数
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;

}

/**
 * 练习4-2 对atof函数进行扩充,使它可以处理形如 123.45e-6 的科学表示法,其中,浮点数后面可能会紧跟一个e或E以及一个指数(可能有正负号)。
 */
double atof3(char s[]){
    double val, power;
    int i, sign, exp, esign;

    // 过滤空格
    for (i = 0; isspace(s[i]); i++)
        ;

    // 过滤符号
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+'){
        i++;
    }

    // 处理整数
    for (val = 0.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
    }

    // 处理小数点
    if (s[i] == '.'){
        i++;
    }

    // 处理小数
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    val = sign * val / power;

    // 处理e
    if (s[i] == 'e' || s[i] == 'E'){
        i++;

        // e后面的符号
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+'){
            i++;
        }

        // 处理指数位
        for (exp = 0; isdigit(s[i]); i++){
            exp = 10 * exp + (s[i] - '0');
        }

        if (esign == 1){
            while (exp-- > 0){
                val *= 10;
            }
        } else {
            while (exp-- > 0){
                val /= 10;
            }
        }
    }

    return val;
}
