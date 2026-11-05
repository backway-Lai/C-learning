//翻译（Translation）
//
//编写程序可以把字母格式的电话号码翻译成数值格式：
//
//Enter phone number : CALLATT
//
//2255288
//
//如果没有电话在身边, 参考这里给出的字母在键盘上的对应关系：（2 = ABC，3 = DEF，4 = GHI，5 = JKL，6 = MNO，7 = PQRS，8 = TUV，9 = WXYZ）原始电话号码中的非字母字符（例如数字或标点符号）保持不变：
//
//Enter phone number : 1 - 800 - COL - LECT1 - 800 - 265 - 5328
//
//可以假设任何用户输入的字母都是大写字母。
//
//输出范例：
//
//Enter phone number : 1 - DCKS - A2D - OLED
//
//1 - 3257 - 223 - 6533

#include <stdio.h>
#include <string.h>

int main() {
	char str[100];
	int len;

	printf("Enter phone number:\n");
	fgets(str, sizeof(str), stdin);
	len = sizeof(str);

	for (int i = 0;i < len;i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int num;
			num = (str[i] - 'A') / 3;
			switch (num) {
			case 0:
				str[i] = '2';
				break;
			case 1:
				str[i] = '3';
				break;
			case 2:
				str[i] = '4';
				break;
			case 3:
				str[i] = '5';
				break;
			case 4:
				str[i] = '6';
				break;
			}
			if (str[i] - 'A' >= 15 && str[i] - 'A' <= 18) str[i] = '7';
			if (str[i] - 'A' >= 19 && str[i] - 'A' <= 21) str[i] = '8';
			if (str[i] - 'A' >= 22 && str[i] - 'A' <= 25) str[i] = '9';
		}
	}

	printf("%s", str);

	return 0;
}