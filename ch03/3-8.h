#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int find(char s1[], char s2[]);

void test() {
    char s1[] = "hello";
    char s2[] = "world";
    char s3[] = "cpt";
    printf("%d\n", find(s1, s2));
    printf("%d\n", find(s1, s3));
}


int find(char s1[], char s2[]){
    int i, j, n, m;

    for (i = 0, n = strlen(s1) - 1; i <= n; i++){
        for (j = 0, m = strlen(s2) - 1; j <= m; j++){
            if (s1[i] == s2[j]){
                goto found;
            }
        }
    }

    return -1;

    found: return 1;
}

