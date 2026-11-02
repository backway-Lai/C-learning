#pragma once
#include <Windows.h>
#include "game.h"

typedef struct {
    HANDLE hInput;
    DWORD  oldMode;
    int    ready;
} Console;

typedef struct {
    int row;   /* 0 .. BOARD_SIZE-1 */
    int col;
} CellPos;

int  Console_Init(Console* con);                        /* 成功 1，失败 0 */
void Console_Restore(Console* con);                     /* 退出前恢复 */
int  Console_WaitCellClick(Console* con, CellPos* pos); /* 点到有效格返回 1 */
void Console_CursorHome(void);                          /* 光标回 (0,0) */