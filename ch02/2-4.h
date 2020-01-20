#include <stdio.h>
#include <limits.h>

void squeeze(char s[], int c);
void squeezeAll(char s1[], char s2[]);
void mystrcat(char s[], char t[]);

void testsqueeze() {
    char s1[] = "abcde";
    char s2[] = "abc";
    squeezeAll(s1, s2);
    printf("%s", s1);

}

void squeeze(char s[], int c) {
    int i, j;

    i = j = 0;

    for( ; s[i] != '\0'; i++){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}

/**
 * 练习 2-4
 * 重新编写函数 squeeze(s1,s2)，将字符串s1中任何与字符串s2中字符匹配的字符都删除。
 */
void squeezeAll(char s1[], char s2[]){
    int i, j, k;

    i = j = k = 0;

    for( ; s1[i] != '\0'; i++){
        for( ; s2[j] != '\0' && s1[i] != s2[j]; j++){
            ;
        }

        if (s2[j] == '\0'){
            s1[k++] = s1[i];
        }
    }

    s1[k] = '\0';
}

void mystrcat(char s[], char t[]){
    int i, j;

    i = j = 0;

    while (s[i] != '\0'){
        i++;
    }
    while (t[j] != '\0'){
        s[i++] = t[j++];
    }
}
