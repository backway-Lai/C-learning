#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include "console.h"

int main(void) {

	Game game;
	Console con;
	CellPos pos;

	Game_Init(&game);

	if (!Console_Init(&con)) {
		printf("Console init failed");
		return 1;
	}

	while (game.status == GAME_RUNNING) {
		Console_CursorHome();
		Draw_the_Board(&game);

		pos.row = -1;
		pos.col = -1;

		if (!Console_WaitCellClick(&con, &pos)) {
			break;
		}

		if (game.cells[pos.row][pos.col] != EMPTY_CELL) {
			continue;
		}

		MoveResult result = Game_Place(&game, pos.row, pos.col);
	    if (result == MOVE_ACCEPTED) Game_Over(&game, pos.row, pos.col);

	}
	Console_CursorHome();
	Draw_the_Board(&game);

	switch (game.status) {
	    case GAME_X_WINS: printf("X wins!\n"); break;
	    case GAME_O_WINS: printf("O wins!\n"); break;
	    case GAME_DRAW:   printf("Draw!\n");   break;
	    default: break;
	}
	printf("Valid move account:%d\n", game.move_count);
	Console_Restore(&con);

	return 0;
}

