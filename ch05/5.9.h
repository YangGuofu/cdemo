#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * 练习5-9 用指针方式代替数组下标方式改写函数day_of_year和month_day。
 */
static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
    int i, leap;
    char *p;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = daytab[leap];

    while (--month){
        day += *++p;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;
    char *p;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = daytab[leap];

    while (yearday > *++p){
        yearday -= *p;
    }

    *pmonth = p - *(daytab + leap);
    *pday = yearday;

}



void test() {
    printf("%d\n", day_of_year(1994, 3, 3));

    int pmonth = 0;
    int pday = 0;
    month_day(1994, 100, &pmonth, &pday);
    printf("%d month %d day\n", pmonth, pday);

}


