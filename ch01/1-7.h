#include <stdio.h>

/**
 * 整数求幂函数
 */
int power(int base, int n) {
    int i, result;
    result = 1;
    for (i = 0; i < n; ++i) {
        result = result * base;
    }
    return result;
}

/**
 * C最初定义的函数格式
 */
int powerOldVersion(base,n)
int base, n;
{
    int i, result;
    result = 1;
    for (i = 0; i < n; ++i) {
        result = result * base;
    }
    return result;
}

/**
 * 练习 1-15
 * 重新编写 1.2 节中的温度转换程序，使用函数实现温度转换计算。
 */
float celsiusByFahrenheit(float fahrenheit);

void calcTemperatureFloat() {
    float fahrenheit, celsius;
    float lower, upper, step;

    lower = 0; // 温度表下限
    upper = 300; // 温度表上限
    step = 20; // 打印的步长

    fahrenheit = lower;

    while (fahrenheit <= upper) {
        celsius = celsiusByFahrenheit(fahrenheit); // 浮点数相除不舍位 可先除
        printf("%3.0f\t%6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}

float celsiusByFahrenheit(float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}