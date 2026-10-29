#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int mm, dd, yy;

    printf("Enter a data:\n");
    scanf("%d/%d/%d", &mm, &dd, &yy);

    if (mm < 10 && dd < 10) {
        printf("You entered the date %d0%d0%d", yy, mm, dd);
    }
    else if (mm < 10 && dd >= 10) printf("You entered the date %d0%d%d", yy, mm, dd);
    else if (mm >= 10 && dd < 10) printf("You entered the date %d%d0%d", yy, mm, dd);
    else printf("You entered the date %d%d%d", yy, mm, dd);

    return 0;
}
//简化算法：定义年为yyyy，月为mm，日为dd。输出时分别用%.4d/%.2d/%.2d精度（精度不仅可以表示小数点后，也可以表示前位补0）