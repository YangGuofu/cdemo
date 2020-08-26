#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

void strcpyarr(char *s, char *t){
    int i;

    i = 0;
    while (t[i]){
        s[i] = t[i];
        i++;
    }
}

void strcpyp(char *s, char *t){
    while ((*s = *t) != '\0'){
        s++;
        t++;
    }
}

int strcmparr(char *s, char *t){
    int i;

    for (i = 0; s[i] == t[i]; i++){
        if (s[i] == '\0'){
            return 0;
        }
    }
    return s[i] - t[i];
}

int strcmpp(char *s, char *t){
    while (*s == *t){
        if (*s == '\0'){
            return 0;
        }
        s++;
        t++;
    }

    return *s - *t;
}

/**
 * 练习5-3 用指针方式实现第2章中的函数strcat。函数strcat(s,t)将t指向的字符串复制到s指向的字符串的尾部。
 */
void strcatp(char *s, char *t){
    while (*s){
        s++;
    }

    while (*t){
        *s = *t;
        s++;
        t++;
    }
}

/**
 * 练习5-4 编写函数strend(s,t)。如果字符串七出现在字符串s的尾部，该函数返回1;否则返回0。
 */
int strend(char *s, char *t){
    char *bs = s;
    char *bt = t;

    while (*s){
        s++;
    }
    while (*t){
        t++;
    }

    while (*s == *t){
        if (t == bt || s == bs){
            break;
        }
        s--;
        t--;
    }

    if (*s == *t && t == bt && *s){
        return 1;
    } else {
        return 0;
    }
}

/**
 * 练习5-5 实现库函数strncpy、strncat和strncmp,它们最多对参数字符串中的前n个字符进行操作。
 * 例如，函数strncpy(s,t,n)将t中最多前n个字符复制到s中。更详细的说明请参见附录B。
 */
void strncpyp(char *s, char *t, int n){
    while (*t && n > 0){
        *s = *t;
        s++;
        t++;
        n--;
    }
}
void strncatp(char *s, char *t, int n){
    while (*s){
        s++;
    }

    while (*t && n){
        *s = *t;
        s++;
        t++;
        n--;
    }
}
int strncmpp(char *s, char *t, int n){
    while (*s == *t && n > 0){
        if (*s == '\0'){
            return 0;
        }
        s++;
        t++;
        n--;
    }

    return *s - *t;
}





void test(){
    char t1[30] = "hello world";
    char s1[30] = "";
    strcpyp(s1, t1);
    printf("%s\n", s1);


    char t2[30] = "hello world";
    char s2[30] = "ha";
    printf("%d\n", strcmpp(s2, t2));

    char t3[30] = "hello";
    char s3[30] = "world";
    strcatp(t3, s3);
    printf("%s\n", t3);

    char t4[30] = "hello";
    char s4[30] = "lo";
    printf("%d\n", strend(t4, s4));


    char t5[30] = "hello world";
    char s5[30] = "";
    strncpyp(s5, t5, 15);
    printf("%s\n", s5);

    char t6[30] = "hello";
    char s6[30] = "world";
    strncatp(t6, s6, 2);
    printf("%s\n", t6);

    char t7[30] = "hello world";
    char s7[30] = "helle";
    printf("%d\n", strncmpp(s7, t7, 3));
}


