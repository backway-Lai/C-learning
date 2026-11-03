#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"

void Game_Init(Game* game_p) {
	game_p->current_player = 'X';
	for (int i = 0;i < BOARD_SIZE;i++) {               //初始化棋盘为空
		for (int j = 0;j < BOARD_SIZE;j++) {
			game_p->cells[i][j] = EMPTY_CELL;
		}
	}
	game_p->move_count = 0;
	game_p->status = GAME_RUNNING;
}

void Draw_the_Board(Game* game_p) {
	int r, c;
	for (r = 0;r < BOARD_SIZE;r++) {
		printf("+");
		for (int i = 0;i < BOARD_SIZE;i++) {
			printf("---+");
		}
		printf("\n|");
		for (c = 0;c < BOARD_SIZE;c++) {
			printf(" %c |", game_p->cells[r][c]);
		}
		printf("\n");
	}
	printf("+");
	for (int i = 0;i < BOARD_SIZE;i++) {
		printf("---+");
	}
	printf("\n");
}
