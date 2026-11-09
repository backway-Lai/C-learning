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

MoveResult Game_Place(Game* game, int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        return MOVE_OUT_OF_BOUNDS;
    if (game->cells[row][col] != EMPTY_CELL)
        return MOVE_OCCUPIED;
	
	game->cells[row][col] = game->current_player;
	game->move_count++;
	game->current_player = (game->current_player == 'X') ? 'O' : 'X';
	return MOVE_ACCEPTED;
}

/* 从 (row, col) 沿 (dr, dc) 数连续同色棋子，不包含起点 */
static int CountDirection(const Game* game, int row, int col,
    int dr, int dc, char player) {
    int count = 0;
    int r = row + dr;
    int c = col + dc;

    while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE &&
        game->cells[r][c] == player) {
        count++;
        r += dr;
        c += dc;
    }
    return count;
}

void Game_Over(Game* game, int row, int col) {
    static const int dirs[4][2] = {
        {1, 0},    /* 竖直 */
        {0, 1},    /* 水平 */
        {1, 1},    /* 左上-右下 */
        {1, -1}    /* 右上-左下 */
    };
    char player;
    int i;

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        return;

    player = game->cells[row][col];
    if (player == EMPTY_CELL)
        return;

    for (i = 0; i < 4; i++) {
        int dr = dirs[i][0];
        int dc = dirs[i][1];
        int total = 1
            + CountDirection(game, row, col, dr, dc, player)   //包含了一条线上两个方向上的棋子
            + CountDirection(game, row, col, -dr, -dc, player);

        if (total >= WIN_LENGTH) {
            game->status = (player == 'X') ? GAME_X_WINS : GAME_O_WINS;
            return;
        }
    }

    if (game->move_count == BOARD_SIZE * BOARD_SIZE)
        game->status = GAME_DRAW;
}


