#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

void shellsort(int v[], int n);
void reverse(char s[]);
void expand(char s1[], char s2[]);

void test() {


    int v[] = {5, 3, 9, 4, 6, 2, 7, 1, 0, 8};
    shellsort(v, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");

    char s[] = "123456789";
    reverse(s);
    printf("%s\n", s);

    char s1[] = "-c-e";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);

}

/**
 * 作为一个较大的例子,我们来重新编写将字符串转换为对应数值的函数atoi。这里编写的函数比第2章中的atoi函数更通用,
 * 它可以处理可选的前导空白符以及一个可选的加(+)或减(-)号。(第4章将介绍函数atof,它用于对浮点数执行同样的转换。)
 */
int atoi(char s[]) {
    int i, n, sign;

    n = i = 0;

    while (isspace(s[i])){
        i++;
    }

    for (i=0; isdigit(s[i]); i++){
        n = 10 * n + (s[i] - '0');
    }

    sign = s[i] == '-' ? -1 : 1;

    if (s[i] == '-' || s[i] == '+'){
        i++;
    }

    return n & sign;
}

/**
 * Shell排序算法是D.L.Shel于1959年发明的,其基本思想是:先比较距离远的元素,而不是像简单交换排序算法那样先比较相邻的元素。
 * 这样可以快速减少大量的无序情况,从而减轻后续的工作。被比较的元素之间的距离逐步减少,直到减少为1,这时排序变成了相邻元素的互换
 */
void shellsort(int v[], int n){
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

/**
 * 该函数用于倒置字符串s中各个字符的位置。
 */
void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/**
 * 练习3-3 编写函数 expand(s1,s2)，将字符串s1中类似于 a-z 一类的速记符号在字符串 s2 中扩展为等价的完整列表 abc…,xyz。
 * 该函数可以处理大小写字母和数字，并可以处理 a-b-c、a-z0-9 与 -a-z 等类似的情况。作为前导和尾随的 - 字符原样排印。
 */
void expand(char s1[], char s2[]){
    char c;
    int i, j;
    i = j = 0;

    while ((c = s1[i++]) != '\0'){
        if (s1[i] == '-' && s1[i+1] >= c){
            i++;
            while (c < s1[i]){
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}