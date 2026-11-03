#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include "console.h"

int main(void) {

	Game game;
	Game* game_p = &game;

	Game_Init(game_p);
	Draw_the_Board(game_p);

	Console console;
	Console* con = &console;
	CellPos position;
	CellPos* pos = &position;

	Console_Init(con);

	Console_WaitCellClick(con, pos);
	game_p->cells[pos->row][pos->col] = 'X';

	Draw_the_Board(game_p);

	return 0;
}

