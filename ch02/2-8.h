#include <stdio.h>
#include <limits.h>

void squeeze(char s[], int c);
void squeezeAll(char s1[], char s2[]);
void mystrcat(char s[], char t[]);
int any(char s1[], char s2[]);


void testsqueeze() {
    char s1[] = "abcde";
    char s2[] = "abc";
    squeezeAll(s1, s2);
    printf("%s", s1);
}

void testany() {
    char s1[] = "abcde";
    char s2[] = "dce";
    printf("%d", any(s1, s2));
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


/**
 * 练习 2-5
 * 编写函数 any(s1,s2)，将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。如果 s1 中不包含 s2 中的字符，则返回 -1。(标准库函数 strpbrk 具有同样的功能，但它返回的是指向该位置的指针。)
 */
int any(char s1[], char s2[]){
    int i, j;

    for(i = 0 ; s1[i] != '\0'; i++){
        for(j = 0 ; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                return i;
            }
        }
    }

    return -1;
}

