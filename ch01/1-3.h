#include <stdio.h>\

/**
 * 练习 1-5
 * 修改温度转换程序，要求以逆序（即按照从 300 度到 0 度的顺序）打印温度转换表。
 */
void calcTemperatureReverse() {
    int fahrenheit;

    for (fahrenheit = 300; fahrenheit >= 0; fahrenheit = fahrenheit - 20) {
        printf("%3d\t%6.1f\n", fahrenheit, (5.0/9.0) * (fahrenheit - 32));
    }
}
