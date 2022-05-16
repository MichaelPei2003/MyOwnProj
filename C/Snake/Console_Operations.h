#ifndef SNAKE_CONSOLE_OPERATIONS_H
#define SNAKE_CONSOLE_OPERATIONS_H

#include <windows.h>

void GotoXY(int x, int y) {
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);
}

void HideCursor() {
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cor_info = {1, 0};
    SetConsoleCursorInfo(hout, &cor_info);
}

#endif //SNAKE_CONSOLE_OPERATIONS_H
