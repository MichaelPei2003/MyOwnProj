#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Snake.h"
#include "Console_Operations.h"
#include "Snake.h"

#define MAP_HEIGHT 20
#define MAP_WIDTH 402

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

int Menu() {
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
    printf("up: w");
    GotoXY(40, 16);
    printf("down: s");
    GotoXY(40, 18);
    printf("left: a");
    GotoXY(40, 20);
    printf("right: d");
    GotoXY(35, 22);
    printf("Press any key to return.");
    HideCursor();
    char ch = _getch();
    system("cls");
}

void About() {
    GotoXY(40, 12);
    printf("This is nothing other than a Snake game.");
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
        }
    }
}
