#include "console.h"

int Console_Init(Console* con) {
    con->hInput = GetStdHandle(STD_INPUT_HANDLE);
    if (con->hInput == INVALID_HANDLE_VALUE) return 0;
    if (!GetConsoleMode(con->hInput, &con->oldMode)) return 0;

    DWORD mode = con->oldMode | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    if (!SetConsoleMode(con->hInput, mode)) return 0;

    con->ready = 1;
    return 1;
}

void Console_Restore(Console* con) {
    if (con->ready) {
        SetConsoleMode(con->hInput, con->oldMode);
        con->ready = 0;
    }
}

void Console_CursorHome(void) {
    COORD home = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), home);
}

int Console_WaitCellClick(Console* con, CellPos* pos) {
    INPUT_RECORD ir;
    DWORD n;
    while (ReadConsoleInput(con->hInput, &ir, 1, &n) && n == 1) {
        if (ir.EventType != MOUSE_EVENT) continue;

        MOUSE_EVENT_RECORD* m = &ir.Event.MouseEvent;
        if (m->dwEventFlags != 0) continue;                    /* 只要按下/抬起 */
        if ((m->dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) == 0) continue;

        int x = m->dwMousePosition.X;
        int y = m->dwMousePosition.Y;
        int col = x / 4;
        int row = y / 2;
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) continue;

        pos->row = row;
        pos->col = col;
        return 1;
    }
    return 0;
}