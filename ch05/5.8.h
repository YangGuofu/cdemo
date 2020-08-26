#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


char *month_name(int n){
    static char *name[] = {
            "Illegal month",
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

void test() {
    char *name = month_name(1);
    printf("%s", name);
}


