//将百分制转换为等级制（Centesimal - grade to Letter - grade）
//
//利用switch语句编写一个程序，把用数字表示的成绩转化为字母表示的等级。
//
//使用下面的等级评定规则：A为90~100，B为80~89，C为70~79，D为60~69，F为0~59。如果成绩大于100或小于0显示出错信息。
//
//输出范例：
//Enter numerical grade : 84
//Letter grade : B
//
//Enter numerical grade : -1
//Error, grade must be between 0 and 100.
//
//提示：把成绩拆分成 2 个数字，然后使用 switch 语句判定十位上的数字。
//
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a;


    if (scanf("%d", &a) != 1) {

        return 1;
    }

    int b = a / 10;
    char letter_grade;

    if (a > 100 || a < 0) {
        printf("Error, grade must be between 0 and 100.");
        return 0;
    }

    switch (b) {
    case 10: case 9:
        letter_grade = 'A';
        break;
    case 8:
        letter_grade = 'B';
        break;
    case 7:
        letter_grade = 'C';
        break;
    case 6:
        letter_grade = 'D';
        break;
    default:
        letter_grade = 'F';
        break;
    }

    printf("Letter grade : %c\n", letter_grade);

    return 0;
}