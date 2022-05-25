#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Console_Operations.h"

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define MAP_HEIGHT 20
#define MAP_WIDTH 40

int score;

typedef struct {
    int x;
    int y;
} SnakeNode, Obstacle;

typedef struct {
    int x;
    int y;
    int val;
} Food;

typedef struct {
    SnakeNode snakeNode[1000];
    int length;
    int width;
    int speed;
} Snake;

Snake snake;
Food food;
Obstacle obs[6];
char now_Dir = RIGHT;
char direction = RIGHT;

void PrintFood() {
    int flag = 1;
    food.val = rand() % 5 + 1;
    while (flag) {
        flag = 0;
        food.x = rand() % (MAP_WIDTH - 2) + 1;
        food.y = rand() % (MAP_HEIGHT - 2) + 1;
        for (int k = 0; k < snake.length; k++) {
            if ((snake.snakeNode[k].x == food.x && snake.snakeNode[k].y == food.y)) {
                flag = 1;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (obs[i].x == food.x && obs[i].y == food.y) {
                flag = -1;
                break;
            }
        }
    }
    GotoXY(food.x, food.y);
    switch (food.val) {
        case 1:
            printf("A");
            break;
        case 2:
            printf("B");
            break;
        case 3:
            printf("C");
            break;
        case 4:
            printf("D");
            break;
        case 5:
            printf("$");
            break;
    }
}

void PrintObs() {
    for (int i = 0; i < 5; i++) {
        int flag = 1;
        while (flag) {
            flag = 0;
            obs[i].x = rand() % (MAP_WIDTH - 2) + 1;
            obs[i].y = rand() % (MAP_HEIGHT - 2) + 1;
            for (int k = 0; k < snake.length; k++) {
                if ((snake.snakeNode[k].x == obs[i].x && snake.snakeNode[k].y == obs[i].y) ||
                    (food.x == obs[i].x && food.y == obs[i].y)) {
                    flag = 1;
                    break;
                }
            }
        }
        GotoXY(obs[i].x, obs[i].y);
        printf("M");
    }
}

int IsCorrect() {
    if (snake.snakeNode[0].x == 0 || snake.snakeNode[0].y == 0 || snake.snakeNode[0].x == MAP_WIDTH - 1 ||
        snake.snakeNode[0].y == MAP_HEIGHT - 1) {//snake hit wall
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (snake.snakeNode[0].x == obs[i].x && snake.snakeNode[0].y == obs[i].y) {//snake hit obstacle
            return 0;
        }
    }
    for (int i = 1; i < snake.length; i++) {
        if (snake.snakeNode[0].x == snake.snakeNode[i].x && snake.snakeNode[0].y == snake.snakeNode[i].y) {
            for (int j = i + 1; j < snake.length; j++) {
                GotoXY(snake.snakeNode[j].x, snake.snakeNode[j].y);
                printf(" ");
            }
            snake.length -= (snake.length - i);
        }
    }
    return 1;//hit nothing
}

void SpeedControl() {
    switch (snake.length) {
        case 6:
            snake.speed = 200;
            break;
        case 9:
            snake.speed = 180;
            break;
        case 12:
            snake.speed = 160;
            break;
        case 15:
            snake.speed = 140;
            break;
        case 18:
            snake.speed = 120;
            break;
        case 21:
            snake.speed = 100;
            break;
        case 24:
            snake.speed = 80;
            break;
        case 27:
            snake.speed = 60;
            break;
        case 30:
            snake.speed = 40;
            break;
        default:
            break;
    }
}

void InitMap() {
    HideCursor();
    snake.snakeNode[0].x = MAP_WIDTH / 2 - 1;
    snake.snakeNode[0].y = MAP_HEIGHT / 2 - 1;
    GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y);
    printf("@");
    snake.length = 3;
    snake.speed = 250;
    now_Dir = RIGHT;
    for (int i = 1; i < snake.length; i++) {
        snake.snakeNode[i].y = snake.snakeNode[i - 1].y;
        snake.snakeNode[i].x = snake.snakeNode[i - 1].x - 1;
        GotoXY(snake.snakeNode[i].x, snake.snakeNode[i].y);
        printf("o");
    }
    for (int i = 0; i < MAP_WIDTH; i++) {
        GotoXY(i, 0);
        printf("-");
        GotoXY(i, MAP_HEIGHT - 1);
        printf("-");
    }
    for (int i = 1; i < MAP_HEIGHT - 1; i++) {
        GotoXY(0, i);
        printf("|");
        GotoXY(MAP_WIDTH - 1, i);
        printf("|");
    }
    PrintFood();
    PrintObs();
    GotoXY(50, 5);
    printf("Current Points: 0");
}

int MoveSnake() {
    SnakeNode tmp;
    int flag = 0;
    tmp = snake.snakeNode[snake.length - 1];
    for (int i = snake.length - 1; i >= 1; i--) {
        snake.snakeNode[i] = snake.snakeNode[i - 1];
    }
    GotoXY(snake.snakeNode[1].x, snake.snakeNode[1].y);
    printf("o");
    if (_kbhit()) {
        direction = _getch();
        switch (direction) {
            case UP:
                if (now_Dir != DOWN) {
                    now_Dir = direction;
                }
                break;
            case DOWN:
                if (now_Dir != UP) {
                    now_Dir = direction;
                }
                break;
            case LEFT:
                if (now_Dir != RIGHT) {
                    now_Dir = direction;
                }
                break;
            case RIGHT:
                if (now_Dir != LEFT) {
                    now_Dir = direction;
                }
                break;
            case 27://keyboard input = "esc"
                GotoXY(50, 6);
                printf("Game Paused.");
                GotoXY(50, 7);
                system("pause");
                GotoXY(50, 6);
                printf("            ");
                GotoXY(50, 7);
                printf("                           ");
                GotoXY(tmp.x, tmp.y);
                printf(" ");
                return 1;
        }
    }
    switch (now_Dir) {
        case UP:
            snake.snakeNode[0].y--;
            break;
        case DOWN:
            snake.snakeNode[0].y++;
            break;
        case LEFT:
            snake.snakeNode[0].x--;
            break;
        case RIGHT:
            snake.snakeNode[0].x++;
            break;
    }
    GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y);
    printf("@");
    if (snake.snakeNode[0].x == food.x && snake.snakeNode[0].y == food.y) {
        snake.length += food.val;
        score += food.val;
        flag = 1;
        snake.snakeNode[snake.length - 1] = tmp;
    }
    if (!flag) {
        GotoXY(tmp.x, tmp.y);
        printf(" ");
    } else {
        PrintFood();
        GotoXY(50, 5);
        printf("Current Points: %d", score);
        GotoXY(tmp.x, tmp.y);
        printf(" ");
    }
    if (!IsCorrect()) {
        system("cls");
        GotoXY(45, 16);
        printf("Final Points: %d", score);
        GotoXY(48, 14);
        printf("You Died!");
        return 0;
    }
    SpeedControl();
    Sleep(snake.speed);
    return 1;
}

void CheatFood() {
    int flag = 1;
    food.val = 5;
    while (flag) {
        flag = 0;
        food.x = rand() % (MAP_WIDTH - 2) + 1;
        food.y = rand() % (MAP_HEIGHT - 2) + 1;
        for (int k = 0; k < snake.length; k++) {
            if ((snake.snakeNode[k].x == food.x && snake.snakeNode[k].y == food.y)) {
                flag = 1;
                break;
            }
        }
    }
    GotoXY(food.x, food.y);
    printf("$");
}

void CheatInit() {
    HideCursor();
    snake.snakeNode[0].x = MAP_WIDTH / 2 - 1;
    snake.snakeNode[0].y = MAP_HEIGHT / 2 - 1;
    GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y);
    printf("@");
    snake.length = 3;
    snake.speed = 250;
    now_Dir = RIGHT;
    for (int i = 1; i < snake.length; i++) {
        snake.snakeNode[i].y = snake.snakeNode[i - 1].y;
        snake.snakeNode[i].x = snake.snakeNode[i - 1].x - 1;
        GotoXY(snake.snakeNode[i].x, snake.snakeNode[i].y);
        printf("o");
    }
    for (int i = 0; i < MAP_WIDTH; i++) {
        GotoXY(i, 0);
        printf("-");
        GotoXY(i, MAP_HEIGHT - 1);
        printf("-");
    }
    for (int i = 1; i < MAP_HEIGHT - 1; i++) {
        GotoXY(0, i);
        printf("|");
        GotoXY(MAP_WIDTH - 1, i);
        printf("|");
    }
    CheatFood();
//    PrintObs();
    GotoXY(50, 5);
    printf("Current Points: 0");
}


int Cheated() {
    GotoXY(50, 4);
    printf("Current Speed: %d", snake.speed);
    SnakeNode tmp;
    int flag = 0;
    tmp = snake.snakeNode[snake.length - 1];
    for (int i = snake.length - 1; i >= 1; i--) {
        snake.snakeNode[i] = snake.snakeNode[i - 1];
    }
    GotoXY(snake.snakeNode[1].x, snake.snakeNode[1].y);
    printf("o");
    if (_kbhit()) {
        direction = _getch();
        switch (direction) {
            case UP:
                if (now_Dir != DOWN) {
                    now_Dir = direction;
                }
                break;
            case DOWN:
                if (now_Dir != UP) {
                    now_Dir = direction;
                }
                break;
            case LEFT:
                if (now_Dir != RIGHT) {
                    now_Dir = direction;
                }
                break;
            case RIGHT:
                if (now_Dir != LEFT) {
                    now_Dir = direction;
                }
                break;
            case 27://keyboard input = "esc"
                GotoXY(50, 6);
                printf("Game Paused.");
                GotoXY(50, 7);
                printf("Press any key to continue.");
                char ch = _getch();
                GotoXY(50, 6);
                printf("            ");
                GotoXY(50, 7);
                printf("                                  ");
                GotoXY(tmp.x, tmp.y);
                printf(" ");
                return 1;
        }
    }
    switch (now_Dir) {
        case UP:
            snake.snakeNode[0].y--;
            break;
        case DOWN:
            snake.snakeNode[0].y++;
            break;
        case LEFT:
            snake.snakeNode[0].x--;
            break;
        case RIGHT:
            snake.snakeNode[0].x++;
            break;
    }
    GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y);
    printf("@");
    if (snake.snakeNode[0].x == food.x && snake.snakeNode[0].y == food.y) {
        snake.length += food.val;
        score += food.val;
        flag = 1;
        snake.snakeNode[snake.length - 1] = tmp;
    }
    if (!flag) {
        GotoXY(tmp.x, tmp.y);
        printf(" ");
    } else {
        CheatFood();
        GotoXY(50, 5);
        printf("Current Points: %d", score);
        GotoXY(tmp.x, tmp.y);
        printf(" ");
    }
    if (snake.snakeNode[0].x == 0 || snake.snakeNode[0].y == 0 || snake.snakeNode[0].x == MAP_WIDTH - 1 ||
        snake.snakeNode[0].y == MAP_HEIGHT - 1) {
        system("cls");
        GotoXY(45, 16);
        printf("Final Points: %d", score);
        GotoXY(48, 14);
        printf("You Died!");
        char ch = _getch();
        return 0;
    }
    SpeedControl();
    Sleep(snake.speed);
    return 1;
}

#endif //SNAKE_SNAKE_H
