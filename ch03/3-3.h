#include <stdio.h>
#include <limits.h>

void test33();
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

void test33() {
    int v[] = {1, 2, 3, 4, 6, 10};
    printf("%d\n",  binsearch(1, v, 6));
    printf("%d\n",  binsearch2(1, v, 6));
}

/**
 * 该函数用于判定已排序的数组v中是否存在某个特定的值ⅹ。数组ⅴ的元素必须以升序排列。如果v中包含x,则该函数返回x在v中的位置(介于0~n-1之间的一个整数);否则,该函数返回-1。
 */
int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high){
        mid = (low + high) / 2;

        if (x < v[mid]){
            high = mid - 1;
        } else if (x > v[mid]){
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

/**
 * 练习3-1 在上面有关折半查找的例子中, while循环语句内共执行了两次测试,其实只要一次就足够(代价是将更多的测试在循环外执行)。重写该函数,使得在循环内部只执行次测试。比较两种版本函数的运行时间。
 */
int binsearch2(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]){
        if (x < v[mid]){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == v[mid]){
        return mid;
    }

    return -1;
}