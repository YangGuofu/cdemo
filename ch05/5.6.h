#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void myqsort(char *v[], int left, int right){
    int i, last;

    if (left >= right){
        return;
    }

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++){
        if (strcmp(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    myqsort(v, left, last-1);
    myqsort(v, last+1, right);
}



void test(){
    int len = 5;
    char *s[] = {
            "a", "d", "b", "c", "e"
    };
    myqsort(s, 0, len-1);

    int i;
    for (i = 0; i < len; i++){
        printf("%s", s[i]);
    }
    printf("\n");
}


