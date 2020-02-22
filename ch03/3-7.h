#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int trim(char s[]);

void test() {
    char s[] = "hello   ";
    trim(s);
    printf("%s", s);
}


int trim(char s[]){
    int n;

    for (n = strlen(s) - 1; n >= 0; n--){
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n'){
            break;
        }
    }
    s[n+1] = '\0';

    return n;
}

