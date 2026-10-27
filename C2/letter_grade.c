#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a;

    printf("Enter numerical grade:\n");
    if (scanf("%d", &a) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int b = a / 10;
    char letter_grade;

    if (a > 100 || a < 0) {
        printf("Error, grade must be between 0 and 100.\n");
        return 1;
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

    printf("Letter grade:%c\n", letter_grade);

    return 0;
}