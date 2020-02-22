#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int strindex(char s1[], char s2[]);
int strrindex(char s1[], char s2[]);

void test() {
    char s1[] = "12345656";
    char s2[] = "56";
    char s3[] = "7";

    printf("%d\n", strindex(s1, s2));
    printf("%d\n", strindex(s1, s3));

    printf("%d\n", strrindex(s1, s2));
    printf("%d\n", strrindex(s1, s3));
}


int strindex(char s1[], char s2[]){
    int i, j, k;

    for (i = 0; s1[i] != '\0';i++){
        for (j = i, k = 0; s2[k] != '\0' && s1[j] == s2[k]; j++, k++)
            ;
        if (k > 0 && s2[k] == '\0'){
            return i;
        }
    }

    return -1;
}

/**
 * 练习4-1 编写函数 strindex(s,t),它返回字符串t在s中最右边出现的位置如果s中不包含t,则返回-1
 */
int strrindex(char s1[], char s2[]){
    int i, j, k;

    for (i = strlen(s1) - strlen(s2); i >= 0; i--){
        for (j = i, k = 0; s2[k] != '\0' && s1[j] == s2[k]; j++, k++)
            ;
        if (k > 0 && s2[k] == '\0'){
            return i;
        }
    }

    return -1;
}

