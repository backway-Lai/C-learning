/*日历（Calendar Month）

编写程序显示单月的日历。用户指定这个月的天数和该月起始日是星期几。

输出范例：

Enter number of days in month : 31

Enter starting day of the week(1 = Sun, 7 = Sat) : 3

日	一	二	三	四	五	六
1	2	 3	 4	 5
6	 7	 8	 9	10	11	12
13	14	15	16	17	18	19
20	21	22	23	24	25	26
27	28	29	30	31*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	int const Days = 7;

	printf("Enter number of days in month:\n");
	scanf("%d", &a);
	printf("Enter starting day of the week(1=Sun, 7=Sat):\n");
	scanf("%d", &b);

	printf("日 一 二 三 四 五 六\n");

	for (int i = 1;i <= a - 1;i++) {
		printf(" ");
	}
	for (int i = 1;i <= Days - a + 1;i++) {
		printf("%d ", i);
	}
	return 0;
}