#ifndef IDIOM_H
#define IDIOM_H

#define HEIGHT 20   //游戏界面高度
#define WID 40      //游戏界面宽度
#define MAX 50      //最多成语数量，测试时使用此宏

void GotoXY(int x, int y);       //指定光标位置
void Hide();                    //隐藏光标
int Menu();
void Help();
void About();
void IdiomRead();
int IdiomChoose();
void InitMap();
bool GameStart();
void Result(); 
//PXY EDITED
int LevelSelection();
bool GameStart2();
void color(short x);
//END OF PXY EDITED

#endif

