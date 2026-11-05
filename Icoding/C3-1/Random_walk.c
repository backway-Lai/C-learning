//随机步法（Random Walk）
//
//编写程序，生成一种贯穿10×10字符数组（初始时全为字符'.'）的“随机步法”。程序必须随机地从一个元素“走到”另一个元素，每次都向上、向下、向左或向右移动一个元素位置。已访问过的元素按访问顺序用字母A到Z进行标记。
//
//下面是一个输出示例：
//
//A	.	.	.	.	.	.	.	.	.
//B	C	D	.	.	.	.	.	.	.
//.F	E	.	.	.	.	.	.	.
//H	G	.	.	.	.	.	.	.	.
//I	.	.	.	.	.	.	.	.	.
//J	.	.	.	.	.	..Z	.
//K	..R	S	T	U	V	Y	.
//L	M	P	Q	.	..W	X	.
//.N	O	.	.	.	.	.	.	.
//利用srand函数和rand函数产生随机数，然后查看次数除以4的余数。余数一共有4种可能的值（0、1、2和3），指示下一次移动的4种可能方向。在执行移动之前，需要检查两项内容：一是不能走到数组外面，二是不能走到已有字母标记的位置。只要一个条件不满足，就得尝试换一个方向移动。如果4个方向都堵住了，程序就必须终止了。下面是提前结束的一个示例:
//
//A	B	G	H	I	.	.	.	.	.
//.C	F	O	J	K	.	.	.	.
//.D	E	N	M	L	.	.	.	.
//.	.	.	.	.	.	.	.	.	.
//.	.	.	.	.	.	.	.	.	.
//.	.	.	.	.	.	.	.	.	.
//.	.	.	.	.	.	.	.	.	.
//.	.	.	.	.	.	.	.	.	.
//.	.	.	.	.	.	.	.	.	.
//因为Y的4个方向都堵住了，所以没有地方可以放置下一步的Z了。

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 12
#define EMPTY '.'

int main() {
	srand((unsigned)time(NULL));
	char map[SIZE][SIZE];

	for (int i = 1;i < 11;i++) {
		for (int j = 1;j < 11;j++) {
			map[i][j] = '.';
		}
	}
	map[1][1] = 'A';
	for (int x = 1, y = 1, num = 1;num < 'Z'- 'A' + 1;) {
		

		if (map[x + 1][y] == EMPTY || map[x - 1][y] == EMPTY || map[x][y + 1] == EMPTY || map[x][y - 1] == EMPTY) {
			int direction = rand() % 4;
			int preX = x;
			int preY = y;

			switch (direction) {
			case 0:
				x = x - 1;
				break;
			case 1:
				x = x + 1;
				break;
			case 2:
				y = y - 1;
				break;
			case 3:
				y = y + 1;
				break;
			}

			if (x > 0 && x < 11 && y > 0 && y < 11 && map[x][y] == EMPTY) {
				map[x][y] = 'A' + num++;
			}
			else {
				x = preX;
				y = preY;
			}
		}
		else break;
	}

	for (int i = 1;i < 11;i++) {
		for (int j = 1;j < 11;j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
