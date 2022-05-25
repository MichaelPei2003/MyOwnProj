#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Snake.h"
#include "Console_Operations.h"

//Caution: variable named "score" already exists in <Snake.h> !

typedef struct {
    int score;
    char name[20];
    int isUsed;
} Score;

Score rank[11];

int Menu() {
    system("cls");
    GotoXY(38, 8);
    printf("Please use full screen.");
    GotoXY(40, 12);
    printf("SNAKE!");
    GotoXY(39, 14);
    printf("Start(1)");
    GotoXY(39, 16);
    printf("Rank(2)");
    GotoXY(39, 18);
    printf("Help(3)");
    GotoXY(39, 20);
    printf("About(4)");
    GotoXY(39, 22);
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
        case '4':
            result = 4;
    }
    system("cls");
    return result;
}

void RankSort() {
    int i, j;
    Score tmp;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (rank[j + 1].isUsed == 0) {
                continue;
            }
            if (rank[j].score < rank[j + 1].score) {
                tmp = rank[j + 1];
                rank[j + 1] = rank[j];
                rank[j] = tmp;
            }
        }
    }
}

void Rank() {
    RankSort();
    system("cls");
    GotoXY(30, 10);
    printf("The newest 10 games are shown here.Every time you quit the game, the records would be cleared.");
    GotoXY(40, 12);
    printf("-----------------------------RANKS-----------------------------");
    int y = 14, cnt = 0;
    while (cnt < 10) {
        GotoXY(40, y);
        printf("Rank %d:", cnt + 1);
        if(rank[cnt].isUsed == 0) {
            GotoXY(69, y);
            printf("EMPTY");
            y += 2;
            cnt++;
            continue;
        }
        GotoXY(50, y);
        printf("PlayerName: ");
        puts(rank[cnt].name);
        GotoXY(80, y);
        printf("Score: %d", rank[cnt].score);
        y += 2;
        cnt++;
    }
    HideCursor();
    char ch = _getch();
    system("cls");
}

void Help() {
    system("cls");
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
    printf("Food Value: 'A' 1 Point, 'B' 2 Points, 'C' 3Points, 'D' 4 Points, '$' 5 Points.");
    GotoXY(40, 24);
    printf("Press ESC to pause game");
    HideCursor();
    char ch = _getch();
    system("cls");
}

void About() {
    system("cls");
    GotoXY(40, 12);
    printf("This is nothing other than a open-source Snake game.");
    GotoXY(40, 14);
    printf("Part of the game is from hdu's textbook.")
    GotoXY(40, 16);
    printf("Source code can be found at https://github.com/MichaelPei2003/MyOwnProjects/tree/main/C/Snake");
    GotoXY(40, 18);
    printf("Press any key to return.");
    HideCursor();
    char ch = _getch();
    system("cls");
}

int main() {
    int rkCnt = 0;
    srand((unsigned int) time(0));
    int end = 1, result;
    while (end) {
        result = Menu();
        switch (result) {
            case 1:
                InitMap();
                while (MoveSnake());
                GotoXY(45, 18);
                printf("Player name(Less than 20 characters):");
                ShowCursor(TRUE);
                scanf("%s", rank[rkCnt].name);
                rank[rkCnt].score = score;
                rank[rkCnt].isUsed = 1;
                rkCnt++;
                if (rkCnt == 10) {
                    rkCnt = 0;
                }
                HideCursor();
                system("cls");
                break;
            case 2:
                Rank();
                break;
            case 3:
                Help();
                break;
            case 4:
                About();
                break;
            case 0:
                end = 0;
                break;
        }
    }
    return 0;
}
