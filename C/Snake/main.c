#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Snake.h"
#include "Console_Operations.h"

int Menu() {
    GotoXY(38, 8);
    printf("Please use full screen.");
    GotoXY(40, 12);
    printf("SNAKE!");
    GotoXY(39, 14);
    printf("Start(1)");
    GotoXY(39, 16);
    printf("Help(2)");
    GotoXY(39, 18);
    printf("About(3)");
    GotoXY(39, 20);
    printf("Press any other key to exit.");
    HideCursor();
    int result = 0;
    char ch;
    ch = _getch();
    switch (ch) {
        case '1':
            result = 1;
            break;
        case '2':
            result = 2;
            break;
        case '3':
            result = 3;
            break;
    }
    system("cls");
    return result;
}

void Help() {
    GotoXY(40, 12);
    printf("HELP");
    GotoXY(40, 14);
    printf("Press W to go upward");
    GotoXY(40, 16);
    printf("Press S to go downward");
    GotoXY(40, 18);
    printf("Press A to go leftward");
    GotoXY(40, 20);
    printf("Press D to go rightward");
    GotoXY(40, 22);
    printf("Press ESC to pause game");
    HideCursor();
    char ch = _getch();
    system("cls");
}

void About() {
    GotoXY(40, 12);
    printf("This is nothing other than a open-source Snake game.");
    GotoXY(40, 14);
    printf("Source code can be found at https://github.com/MichaelPei2003/MyOwnProjects/tree/main/C/Snake");
    GotoXY(40, 17);
    printf("Press any key to return.");
    char ch = _getch();
    system("cls");
}

int main() {
    srand((unsigned int) time(0));
    int end = 1, result;
    while (end) {
        result = Menu();
        switch (result) {
            case 1:
                InitMap();
                while (MoveSnake());
                break;
            case 2:
                Help();
                break;
            case 3:
                About();
                break;
            case 0:
                end = 0;
                break;
        }
    }
    return 0;
}
