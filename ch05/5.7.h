#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/**
 * 练习5-8 函数day_of_year和month_day中没有进行错误检查，请解决该问题。
 */
int day_of_year(int year, int month, int day){
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

    if (month < 1 || month > 12){
        return -1;
    }
    if (day < 1 || day > daytab[leap][month]){
        return -1;
    }

    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    if (year < 1){
        *pmonth = -1;
        *pday = -1;
    }
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++){
        yearday -= daytab[leap][i];
    }

    // 循环结束时，如果i=13且yearday大于该年度最后月份的天数
    if (i > 12 && yearday > daytab[leap][12]){
        *pmonth = -1;
        *pday = -1;
    } else {
        *pmonth = i;
        *pday = yearday;
    }

}



void test() {
    printf("%d\n", day_of_year(1994, 3, 3));

    int pmonth = 0;
    int pday = 0;
    month_day(1994, 100, &pmonth, &pday);
    printf("%d month %d day\n", pmonth, pday);

}


