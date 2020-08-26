#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

int mystrlen(char *s){
    char *p = s;
    while (*p != '\0'){
        p++;
    }
    return p - s;
}


void test(){
    char s1[10];
    char s2[10];

    if (s1 > s2){
        printf("true");
    } else {
        printf("false");
    }

}


#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allop = allocbuf;

char *alloc(int n){
    if (allop - allocbuf + n <= ALLOCSIZE){
        allop += n;
        return allop - n;
    } else {
        return 0;
    }
}

void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE){
        allop = p;
    }
}