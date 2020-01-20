#include <stdio.h>\

/**
 * 当 fahrenheit = 0,20,...,300 时，分别打印华氏温度和摄氏温度对照表
 * 整数版本
 */
void calcTemperatureInt() {
    int fahrenheit, celsius;
    int lower, upper, step;

    lower = 0; // 温度表下限
    upper = 300; // 温度表上限
    step = 20; // 打印的步长

    fahrenheit = lower;

    while (fahrenheit <= upper) {
        celsius = 5 * (fahrenheit - 32) / 9; // 整数相除舍位取整 不可先除
        printf("%3d\t%6d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}

/**
 * 练习 1-3
 * 修改温度转换程序，使之能在转换表的顶部打印一个标题。
 */
void calcTemperatureFloatWithTitle() {
    float fahrenheit, celsius;
    float lower, upper, step;

    lower = 0; // 温度表下限
    upper = 300; // 温度表上限
    step = 20; // 打印的步长

    fahrenheit = lower;

    printf("%s\t%s\n", "fahr", "celsius"); // 添加标题

    while (fahrenheit <= upper) {
        celsius = (5.0/9.0) * (fahrenheit - 32); // 浮点数相除不舍位 可先除
        printf("%.0f\t%.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}

/**
 * 练习 1-4
 * 编写一个程序打印摄氏温度转换为相应华氏温度的转换表。
 */
void calcTemperatureFloat() {
    float fahrenheit, celsius;
    float lower, upper, step;

    lower = 0; // 温度表下限
    upper = 300; // 温度表上限
    step = 20; // 打印的步长

    fahrenheit = lower;

    while (fahrenheit <= upper) {
        celsius = (5.0/9.0) * (fahrenheit - 32); // 浮点数相除不舍位 可先除
        printf("%3.0f\t%6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}