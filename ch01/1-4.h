#include <stdio.h>\

/**
 * 符号常量
 */
#define LOWER 0
#define UPPER 300
#define STEP 20

void calcTemperatureReverse() {
    int fahrenheit;

    for (fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit = fahrenheit - STEP) {
        printf("%3d\t%6.1f\n", fahrenheit, (5.0/9.0) * (fahrenheit - 32));
    }
}
