#ifndef IDIOM_H
#define IDIOM_H

#define HEIGHT 20
#define WID 40
#define MAX 50

void GotoXY(int x, int y);    //指定光标位置
void Hide();                //隐藏光标
int Menu();

void Help();

void About();

void IdiomRead();

int IdiomChoose();

void InitMap();

bool GameStart();

//PXY EDITED
int LevelSelection();

bool GameStart2();

void List();
//END OF PXY EDITED

#endif

