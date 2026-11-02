#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"

Game game;
int* game_p = &game;
int r;
int c;

void Game_Init() {
	game.current_player = 'X';
	for (int i = 0;i < BOARD_SIZE;i++) {               //初始化棋盘为空
		for (int j = 0;j < BOARD_SIZE;j++) {
			game.cells[i][j] = EMPTY_CELL;
		}
	}
	game.move_count = 0;
	game.status = GAME_RUNNING;
}

void Draw_the_Board() {
	for (r = 0;r < BOARD_SIZE;r++) {
		printf("+");
		for (int i = 0;i < BOARD_SIZE;i++) {
			printf("---+");
		}
		printf("\n|");
		for (c = 0;c < BOARD_SIZE;c++) {
			printf(" %c |", game.cells[r][c]);
		}
		printf("\n");
	}
	printf("+");
	for (int i = 0;i < BOARD_SIZE;i++) {
		printf("---+");
	}
}
