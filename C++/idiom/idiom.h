#ifndef IDIOM_H
#define IDIOM_H

#define HEIGHT 20	//高度
#define WID 40		//宽度
#define MAX 50		//成语数量

void GotoXY(int x, int y);	//定位光标
void Hide();				//隐藏光标
int Menu();					//显示菜单
void Help();				//显示帮助
void About();				//关于信息
void IdiomRead();           //文件读取成语
int IdiomChoose();         //随机选取成语
void InitMap();             //初始化游戏界面
bool GameStart();           //成语出现


#endif

